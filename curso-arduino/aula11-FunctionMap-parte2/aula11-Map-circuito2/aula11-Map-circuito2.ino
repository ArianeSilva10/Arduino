int LEDS[] = {2, 3, 4};
#define PORT A0
int val;

void setup()
{
  for (int i = 0; i < 3; i++)
  {
    pinMode(LEDS[i], OUTPUT);
  }

  pinMode(PORT, INPUT);
}

void blink(int x)
{
  int i;
  for (i = 0; i < x; i++)
  {
    digitalWrite(LEDS[i], HIGH);
  }
  for (i = x; i < 3; i++)
  {
    digitalWrite(LEDS[i], LOW);
  }
}

void loop()
{
  val = analogRead(PORT);

  blink(map(val, 0, 1023, 0, 3));
}
