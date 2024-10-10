#define LED 3
#define PORT A0

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PORT, INPUT);
}

void loop() {
  // Analógico = 0 a 1023
  // PWM = 0 a 255

  analogWrite(LED, analogRead(PORT) / 4);
  /*Sintaxe do map:
  map(leitura, 
  min_val_entrada, max_val_entrada,
   min_val_saida, max_val_saida)
  */

 analogWrite(LED, map(analogRead(PORT), 0, 1023, 0, 255));
}
