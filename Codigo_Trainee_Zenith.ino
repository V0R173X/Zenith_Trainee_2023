#define pinTermo 13
#define TRIG_1 12
#define ECHO_1 14
#define pinR 27
#define pinY 26
#define pinG 25
#define pinB 33
#define buzzer 32



const float BETA = 3950; //coeficiente beta do termistor

void setup() {
  Serial.begin(115200);
  pinMode(pinTermo,INPUT);
  pinMode(TRIG_1, OUTPUT);
  pinMode(ECHO_1, INPUT);
  pinMode(pinR,OUTPUT);
  pinMode(pinY,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
}

void loop() {
  int analogValue = analogRead(pinTermo);
  float celsius = 1 / (log(1 / (4095. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;

  // Inicia uma nova medição do sensor ultrassonico
  digitalWrite(TRIG_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_1, LOW);

  // Distância do ultrassonico em centimetros
  int distance1 = pulseIn(ECHO_1, HIGH)/58;
  
  //Definindo a cor do LED baseado na temperatura em celsius
  if(celsius<=2){
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinB, HIGH);
  }else if(celsius<=28){
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinB, LOW);
  }else if(celsius<=54){
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, HIGH);
    digitalWrite(pinG, LOW);
    digitalWrite(pinB, LOW);
  }else{
    digitalWrite(pinR, HIGH);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinB, LOW);
  }

  // Verificação da distância do sensor utrassônico para tocar (ou não) o buzzer
  if(distance1<=150){
    tone(buzzer,500);
    delay(250);
    noTone(buzzer);
  }
}
