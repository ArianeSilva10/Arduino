#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10      // Pino SDA/SS do RFID
#define RST_PIN 9      // Pino de Reset do RFID
#define BUZZER_PIN 7   // Pino do Buzzer

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo servo;

String UID, RUID = "57307863";  // UID esperado
bool Acesso;

MFRC522::StatusCode status;

void setup() {
  Serial.begin(115200);
  servo.attach(6);  // Controle do servo
  servo.write(130); // Posição inicial do servo
  SPI.begin();
  mfrc522.PCD_Init(); // Inicializa o módulo MFRC522

  pinMode(BUZZER_PIN, OUTPUT); // Define o pino do buzzer como saída

  Serial.println("Sistema de reconhecimento de UID iniciado.");
}

void loop() {
  // Verifica se há um novo cartão presente
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.println("Cartão Detectado");

  // Lê o UID do cartão
  UID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    UID += String(mfrc522.uid.uidByte[i], HEX);
  }

  Serial.print("UID Lido: ");
  Serial.println(UID);

  // Compara o UID lido com o UID esperado
  if (UID == RUID) {
    Serial.println("UID verificado com sucesso.");
    Acesso = true;
    Ring(true);      // Toca o som de sucesso imediatamente
    servo.write(0);  // Abre o servo
    delay(5000);     // Mantém aberto por 5 segundos
    servo.write(130); // Fecha o servo
  } else {
    Serial.println("UID não reconhecido.");
    Acesso = false;
    Ring(false);     // Toca o som de erro
  }

  // Finaliza a comunicação com o cartão
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}

void Ring(bool access) {
  if (access) {
    tone(BUZZER_PIN, 330, 200);  // Primeiro tom de sucesso
    delay(200);                  // Pequena pausa entre os tons
    tone(BUZZER_PIN, 494, 250);  // Segundo tom de sucesso
  } else {
    tone(BUZZER_PIN, 75, 150);   // Primeiro tom de erro
    delay(200);                  // Pequena pausa entre os tons
    tone(BUZZER_PIN, 75, 150);   // Segundo tom de erro
  }
}
