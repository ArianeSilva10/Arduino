#define led    4
#define button 3

int buttonPress = 0;
int buttonFree = 0;

void chooseLed(){
// se o led estiver aceso, apaga
  if(digitalRead(led)){
    digitalWrite(led, LOW);
  }else{
// se estiver apagado, o led acende
    digitalWrite(led, HIGH);
  }
}

void keyUp(){
  if(buttonPress and buttonFree){
    buttonPress = 0;
    buttonFree = 0;
    chooseLed();
  }
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  if(digitalRead(button)){
    buttonPress = 1;
    buttonFree = 0;
  }else{
    buttonFree = 1;
  }
  keyUp();
}
