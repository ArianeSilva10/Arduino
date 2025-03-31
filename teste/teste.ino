#include <Servo.h>

// Pin Definitions
const int IR_SENSOR_PIN = 2;     // Sensor de obstáculos infravermelho
const int SERVO_PIN = 9;         // Pino do servo motor
const int LED_AZUL = 12;        // LED verde para indicar caminho livre
const int LED_VERMELHO = 13;     // LED vermelho para indicar obstáculo

// Tempo de passagem do carro (em milissegundos)
const int TEMPO_PASSAGEM = 5000;  // 5 segundos para o carro passar

Servo gateServo;  // Objeto servo para controlar o portão

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  
  gateServo.attach(SERVO_PIN);
  gateServo.write(0);  // Posição inicial fechada
  
  Serial.begin(9600);
}

void loop() {
  // Leitura do sensor infravermelho
  int obstaculo = digitalRead(IR_SENSOR_PIN);
  Serial.println(obstaculo);
  
  // Quando detecta obstáculo (carro esperando)
  if (obstaculo == LOW) {  
    // Abre o portão
    gateServo.write(90);
    
    // Aciona LED verde
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    
    Serial.println("Carro esperando. Portão abrindo.");
    delay(TEMPO_PASSAGEM);
  }
  else {  // Sem obstáculo
    // Fecha o portão
    gateServo.write(0);
    
    // Aciona LED vermelho
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AZUL, LOW);
    
    Serial.println("Sem obstáculo. Portão fechando.");
    delay(500);
  }
}
