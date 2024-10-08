#define LED_RED 2
#define LED_GREEN 4
#define LED_BLUE 3
#define BUTTON 7

class Btn{
public:
  int buttonPress, buttonFree, pin;
  Btn(int p){
    pin = p;
    buttonFree = buttonPress = 0;
  }

  bool press(){
    if (digitalRead(pin) == HIGH)
    {
      buttonPress = 1;
      buttonFree = 0;
    }
    else
    {
      buttonFree = 1;
    }
    if ((buttonPress == 1) and (buttonFree == 1))
    {
      buttonPress = 0;
      buttonFree = 0;
      return true;
    }else
    {
      return false;
    }
  }
};

class Color
{
public:

  int pinR, pinG, pinB, period, max;

  Color(int pr, int pg, int pb):pinR(pr), pinG(pg), pinB(pb){
    period = 0;
    max = 3;
  }

  void chooseLed(){
    if (period == 0)
    {
      colorLed(1, 0, 0);
    }else if (period == 1)
    {
      colorLed(0, 1, 0);
    }
    else if (period == 2)
    {
      colorLed(0, 0, 1);
    }
    period++;
    if (period > max-1)
    {
      period = 0;
    }
    
    
  }

private:
  void colorLed(int r, int g, int b){
    digitalWrite(pinR, r); //High == 1 | LOW == 0
    digitalWrite(pinG, g);
    digitalWrite(pinB, b);
  }
};

Btn btn(BUTTON);

Color color(LED_RED, LED_GREEN, LED_BLUE);

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BUTTON, INPUT);

}

void loop() {
  if (btn.press())
  {
    color.chooseLed();
  }
  

}
