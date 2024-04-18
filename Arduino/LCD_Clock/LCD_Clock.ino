#include <LiquidCrystal_I2C.h>

class TimeManager;
typedef void(*ElapsedTimeCallback)(const TimeManager*);

enum Mode
{
    ShowTime = 0,
    SetAlarm = 1,
    SetTime = 2,
    Default = ShowTime
};

enum TimeSetContext
{
    Hour = 0,
    Minute = 1,
};

struct Time
{
    short Hour;
    short Minute;
    short Second;
    short Millisecond;

    bool operator==(Time other)
    {
        return
            Hour == other.Hour &&
            Minute == other.Minute &&
            Second == other.Second;
    }
};

class TimeManager
{
public:
    TimeManager() = default;
    void Init(ElapsedTimeCallback callback, unsigned long long interval)
    {
        _callback = callback;
        _interval = interval;
    }

    void Tick()
    {
        _tick += millis() - _lastMills;
        _accumulator += millis() - _lastMills;
        if (_accumulator > _interval)
        {
            _callback(this);
            _accumulator = 0;
        }
        _lastMills = millis();
        if (_tick > 86399000)
            _tick = 0;
    }

    void SyncTime(const Time& tm)
    {
        unsigned long long hrMill = tm.Hour * 3600000ull;
        unsigned long long minMill = tm.Minute * 60000ull;
        unsigned long long secMill = tm.Second * 1000ull;
        _tick = hrMill + minMill + secMill + tm.Millisecond;
    }

    Time GetTime() const
    {
        Time time = {};
        time.Hour = _tick / 3600000;
        time.Minute = (_tick / 60000) % 60;
        time.Second = (_tick / 1000) % 60;
        time.Millisecond = _tick % 1000;
        return time;
    }

private:
    unsigned long long _tick;
    unsigned long long _lastMills;
    unsigned long long _accumulator;
    unsigned long long _interval;
    ElapsedTimeCallback _callback = nullptr;
};

class UserInterface
{
public:
    UserInterface(TimeManager* timeManagerPtr, int modePin, int startPin, int resetPin, int lightPin)
        :_mode(Mode::Default), _modeButton(modePin), _startButton(startPin),
        _resetButton(resetPin), _timeManager(timeManagerPtr), _lcd(0x27, 16, 2)
    {}

    void Init()
    {
        pinMode(_modeButton, INPUT_PULLUP);
        pinMode(_resetButton, INPUT_PULLUP);
        pinMode(_startButton, INPUT_PULLUP);
        pinMode(_resetButton, INPUT_PULLUP);
        _lcd.init();
        _lcd.backlight();
    }

    void Render()
    {
        _lcd.setCursor(0, 0);
        _lcd.clear();

        _lcd.print(_timeManager->GetTime().Hour);
        _lcd.print(":");
        _lcd.print(_timeManager->GetTime().Minute);
        _lcd.print(":");
        _lcd.print(_timeManager->GetTime().Second);

        _lcd.setCursor(0, 1);
        switch (_mode)
        {
        case ShowTime:
            _lcd.print("Time(HH:mm:ss)");
            break;

        case SetAlarm:
            _lcd.print("Set alarm.");
            break;

        case SetTime:
            _lcd.print("Sync time.");
            break;
        }
    }

    void Update()
    {
        _timeManager->Tick();
        if (digitalRead(_modeButton) == HIGH)
        {
            _mode++;
            if (_mode > Mode::SetTime)
                _mode = Mode::Default;
        }
        else if (digitalRead(_resetButton) == HIGH && _mode != Mode::ShowTime)
        {
            _subMode++;
            if (_subMode > TimeSetContext::Minute)
                _subMode = TimeSetContext::Hour;
        }
        else if (digitalRead(_startButton) == HIGH && _mode != Mode::ShowTime)
        {
            Time tm = _timeManager->GetTime();
            switch (_subMode)
            {
            case TimeSetContext::Hour:
                tm.Hour += 1;
                break;

            case TimeSetContext::Minute:
                tm.Minute += 1;
                break;
            }
            _timeManager->SyncTime(tm);
        }
        else if (digitalRead(_lightButton) == HIGH)
        {
            _lcd.backlight();
        }
    }

private:
    int _modeButton;
    int _startButton;
    int _resetButton;
    int _lightButton;
    int _mode;
    int _subMode;
    LiquidCrystal_I2C _lcd;
    TimeManager* _timeManager;
};

int modePin = 2;
int resetPin = 3;
int startPin = 4;
int lightPin = 5;

TimeManager timeManager;
UserInterface ui(&timeManager, modePin, resetPin, startPin, lightPin);

void SecondElapsed(const TimeManager* manager)
{
    ui.Render();
}

void setup()
{
    timeManager.Init(SecondElapsed, 1000);
    ui.Init();
}

void loop()
{
    ui.Update();
}
