void setup() {
  pinMode(13, OUTPUT); // OUTPUT = saida - INPUT = Entrada
}

void loop() {
  digitalWrite(13, HIGH); //HIGH = ligada(5v) - LOW = desligada(0v)
  delay(2000);
   digitalWrite(13, LOW); //HIGH = ligada(5v) - LOW = desligada(0v)
  delay(2000);
}
