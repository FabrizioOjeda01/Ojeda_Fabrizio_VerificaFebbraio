//prime variabili
int rosso = 12;
int verde = 10;

//seconde variabili
int blu    = 8; 
int giallo  = 6;

//variabili per la durata
int tempoRossoVerde = 0;
int tempoBluGiallo = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(rosso, OUTPUT);
pinMode(giallo, OUTPUT);
pinMode(blu, OUTPUT);
pinMode(verde, OUTPUT);

tempoBluGiallo   = Seriale ("Quanti millisecondi devono rimanere accesi i led blu e giallo?", tempoBluGiallo);
tempoRossoVerde  = Seriale ("Quanti millisecondi devono rimanere accesi i led rosso e verde?", tempoRossoVerde);
}

void loop() {
  // put your main code here, to run repeatedly:
  
SequenzaLed(rosso, verde, giallo, blu);
delay(tempoBluGiallo);
SequenzaLed(giallo, blu, rosso, verde);
delay(tempoRossoVerde);

}


void SequenzaLed(int led, int led1, int led2, int led3){ //metodo per la sequenza di accensione/spegnimento dei led
digitalWrite(led, LOW);
digitalWrite (led1, LOW);
digitalWrite (led2, HIGH);
digitalWrite (led3, HIGH);
}

int Seriale(String frase, int var){  //Metodo per richiedere in seriale la durata dei led
  Serial.println(frase); 
  while (Serial.available() == 0) {};
  var = Serial.readString().toInt();
  return var;
}


