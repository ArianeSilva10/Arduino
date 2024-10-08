#define ledRed   2
#define ledGreen 4
#define ledBlue  3
#define BUTTON   7
#define MAX      7

int buttonPress = 0;
int buttonFree = 0;
int period = 0;

void red(){
  digitalWrite(ledRed, 1);
  digitalWrite(ledGreen, 0);
  digitalWrite(ledBlue, 0);

}

void green(){
  digitalWrite(ledRed, 0);
  digitalWrite(ledGreen, 1);
  digitalWrite(ledBlue, 0);

}
void blue(){
  digitalWrite(ledRed, 0);
  digitalWrite(ledGreen, 0);
  digitalWrite(ledBlue, 1);

}

void amarelo(){
  digitalWrite(ledRed, 1);
  digitalWrite(ledGreen, 1);
  digitalWrite(ledBlue, 0);
}

void lilas(){
  digitalWrite(ledRed, 1);
  digitalWrite(ledGreen, 0);
  digitalWrite(ledBlue, 1);

}

void ciano(){
  digitalWrite(ledRed, 0);
  digitalWrite(ledGreen, 1);
  digitalWrite(ledBlue, 1);

}

void branco(){
  digitalWrite(ledRed, 1);
  digitalWrite(ledGreen, 1);
  digitalWrite(ledBlue, 1);

}

void chooseLed(){
  if(period == 0){
    red();
  }else if(period == 1){
    green();
  }else if(period == 2){
    blue();
  }else if(period == 3){
    amarelo();
  }else if(period == 4){
    lilas();
  }else if(period == 5){
    ciano();
  }else if(period == 6){
    branco();
  }
  period++;
  if(period > MAX - 1){
    period = 0;
  }
}

void CheckButton(){
  if(digitalRead(BUTTON)){
    buttonPress = 1;
    buttonFree = 0;
    chooseLed();
  }
}

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  CheckButton();
}
