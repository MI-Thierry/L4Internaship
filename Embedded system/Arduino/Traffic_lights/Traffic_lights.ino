class LED
{
  public:
    LED(int redChannelPin, int greenChannelPin, int blueChannelPin)
      : _redChannelPin(redChannelPin), _greenChannelPin(greenChannelPin),
        _blueChannelPin(blueChannelPin)
    {}
    void Init()
    {
      pinMode(_redChannelPin, OUTPUT);
      pinMode(_greenChannelPin, OUTPUT);
      pinMode(_blueChannelPin, OUTPUT);
    }

    void LightUp(unsigned red, unsigned green, unsigned blue)
    {
      // Remember the inverting problem.
      analogWrite(_redChannelPin, 255 - red);
      analogWrite(_greenChannelPin, 255 - green);
      analogWrite(_blueChannelPin, 255 - blue);
    }
  private:
    int _redChannelPin;
    int _greenChannelPin;
    int _blueChannelPin;
};

LED redLight(10, 9, 8);
LED yellowLight(7, 6, 5);
LED greenLight(4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  redLight.Init();
  yellowLight.Init();
  greenLight.Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  redLight.LightUp(255, 0, 0);
  yellowLight.LightUp(0, 0, 0);
  greenLight.LightUp(0, 0, 0);
  delay(2000);

  redLight.LightUp(0, 0, 0);
  yellowLight.LightUp(255, 255, 0);
  greenLight.LightUp(0, 0, 0);
  delay(500);

  redLight.LightUp(0, 0, 0);
  yellowLight.LightUp(0, 0, 0);
  greenLight.LightUp(0, 255, 0);
  delay(1000);
}