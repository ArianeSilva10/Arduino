
#define led1 6
#define led2 5
#define led3 4
#define led4 3

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(1000);                       // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led3, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led4, LOW);    // turn the LED off by making the voltage LOW

  delay(100);                       // wait for a second
}
