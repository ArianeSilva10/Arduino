

#include <Wire.h> // Biblioteca utilizada para fazer a comunicação com o I2C
#include <LiquidCrystal_I2C.h> // Biblioteca utilizada para fazer a comunicação com o display 20x4 

#define col 16 // Serve para definir o numero de colunas do display utilizado
#define lin  2 // Serve para definir o numero de linhas do display utilizado
#define ende 0x27 // Serve para definir o endereço do display.

LiquidCrystal_I2C lcd(ende,col,lin); // Chamada da funcação LiquidCrystal para ser usada com o I2C

void setup() //Incia o display
{  
  lcd.init(); // Serve para iniciar a comunicação com o display já conectado
  lcd.backlight(); // Serve para ligar a luz do display
  lcd.clear(); // Serve para limpar a tela do display
}
void loop() 
{
  lcd.setCursor(1,0); // Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Eu te amo"); // Comando de saída com a mensagem que deve aparecer na coluna 2 e linha 1.
  lcd.setCursor(1, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("lindooo");  // Comando de saida com a mensagem que deve aparecer na coluna 2 e linha 2
  lcd.setCursor(1,2); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("meu amor");  // Comando de saida com a mensagem que deve aparecer na coluna 2 e linha 3
  lcd.setCursor(1 ,3); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("Elivelton");  // Comando de saida com a mensagem que deve aparecer na coluna 2 e linha 4
  delay(3000);  // delay de 5 segundos com todas as mensagens na tela
  lcd.clear(); // Limpa o display até o loop ser reiniciado 
}
