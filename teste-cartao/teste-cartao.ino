#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9
#define SS_PIN          10

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

void setup() {
    Serial.begin(9600);
    SPI.begin();
    mfrc522.PCD_Init();

    // Configurar chave padrão FFFFFFFFFFFFh
    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }

    Serial.println("Aproxime o cartão para leitura...");
}

void loop() {
    if (!mfrc522.PICC_IsNewCardPresent()) return;
    if (!mfrc522.PICC_ReadCardSerial()) return;

    Serial.print("Card UID: ");
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    Serial.println();

    Serial.print("PICC Type: ");
    Serial.println(mfrc522.PICC_GetTypeName(mfrc522.PICC_GetType(mfrc522.uid.sak)));

    byte blockAddr = 4; // Endereço do bloco para leitura
    byte buffer[18];
    byte size = sizeof(buffer);

    Serial.print("Lendo bloco "); Serial.println(blockAddr);
    MFRC522::StatusCode status = mfrc522.PCD_Authenticate(
        MFRC522::PICC_CMD_MF_AUTH_KEY_A, blockAddr, &key, &(mfrc522.uid)
    );

    if (status != MFRC522::STATUS_OK) {
        Serial.print("Falha na autenticação: ");
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }

    status = mfrc522.MIFARE_Read(blockAddr, buffer, &size);
    if (status != MFRC522::STATUS_OK) {
        Serial.print("Falha na leitura: ");
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }

    Serial.print("Dados do bloco "); Serial.print(blockAddr); Serial.print(": ");
    dump_byte_array(buffer, 16);
    Serial.println();

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
}

void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}
