#define AN5 A5

void setup() {
  pinMode(AN5, INPUT);
  Serial.begin(9600); 
  /*Inicia a comunicação serial com o monitor serial do Arduino a uma taxa de 9600 bits por segundo (bps). Essa configuração é usada para enviar dados para o computador e visualizar no Monitor Serial do Arduino IDE.*/
}

void loop() {
  Serial.println(analogRead(AN5)); /* Lê o valor analógico do pino A5 e imprime no monitor serial*/
  delay(100);
}


/*
Lê o valor analógico do pino AN5 (pino A5). Este valor será um número entre 0 e 1023, onde:

- 0 representa 0V.
- 1023 representa 5V (ou a tensão de referência do Arduino).
*/