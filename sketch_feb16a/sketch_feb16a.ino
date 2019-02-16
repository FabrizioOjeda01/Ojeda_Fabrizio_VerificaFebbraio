int rosso = 12;
int giallo = 6;
int blu    = 8;
int verde  = 10;
int tempoAccens = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(rosso, OUTPUT);
pinMode(giallo, OUTPUT);
pinMode(blu, OUTPUT);
pinMode(verde, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Sequenza(rosso, verde, giallo, blu);
delay(2000);
Sequenza(giallo, blu, rosso, verde);
delay(2000);
}

void Sequenza(int led, int led1, int led2, int led3){
digitalWrite(led, LOW);
digitalWrite (led1, LOW);
digitalWrite (led2, HIGH);
digitalWrite (led3, HIGH);
}



