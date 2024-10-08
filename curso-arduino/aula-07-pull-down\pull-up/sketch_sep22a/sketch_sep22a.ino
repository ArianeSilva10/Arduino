#define led 4
#define button 3

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);

}

void loop() {
  if(digitalRead(button)){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }

}
