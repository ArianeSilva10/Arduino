#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  9
#define SS_PIN   10
#define BUZZER_PIN 5  // Pino onde o buzzer está conectado

MFRC522 mfrc522(SS_PIN, RST_PIN);
byte authorizedUID[] = {0x57, 0x30, 0x78, 0x63};  // UID do cartão autorizado

void setup() {
    Serial.begin(9600);
    SPI.begin();
    mfrc522.PCD_Init();
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);  // Garante que o buzzer comece desligado
    Serial.println("Aproxime o cartão...");
}

void loop() {
    if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) return;

    Serial.print("Cartão detectado, UID: ");
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    Serial.println();

    if (isAuthorized(mfrc522.uid.uidByte, mfrc522.uid.size)) {
        Serial.println("Cartão autorizado! Ativando buzzer...");
        tone(BUZZER_PIN, 1000, 500);  // Toca um beep de 500ms
    } else {
        Serial.println("Cartão não autorizado.");
    }

    mfrc522.PICC_HaltA();  // Para a comunicação com o cartão
    mfrc522.PCD_StopCrypto1();
}

// Verifica se o UID do cartão corresponde ao autorizado
bool isAuthorized(byte *uid, byte size) {
    if (size != sizeof(authorizedUID)) return false;
    for (byte i = 0; i < size; i++) {
        if (uid[i] != authorizedUID[i]) return false;
    }
    return true;
}

// Função para imprimir o UID na serial
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}
