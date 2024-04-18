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

// You can change this values accourding to you pin configuration
// as long as you keep the order of parameters.
LED redLight(2, 3, 4);
LED greenLight(5, 6, 7);
LED blueLight(5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  redLight.Init();
  greenLight.Init();
  blueLight.Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  redLight.LightUp(255, 0 , 0);
  greenLight.LightUp(0, 0, 0);
  blueLight.LightUp(0, 0, 0);
  delay(5000);

  redLight.LightUp(0, 0 , 0);
  greenLight.LightUp(255, 255, 0);
  blueLight.LightUp(0, 0, 0);
  delay(5000);

  redLight.LightUp(0, 0 , 0);
  greenLight.LightUp(0, 0, 0);
  blueLight.LightUp(0, 255, 0);
  delay(5000);
}
