#define pwm 5
#define direction1 8
#define direction2 9
#define pot A0



void setup() {
  pinMode(pot,INPUT);
  pinMode(pwm,OUTPUT);
  pinMode(direction1,OUTPUT);
  pinMode(direction2,OUTPUT);
  Serial.begin(9600);
  

}

void Controle_velocidade(float tensao, int potenciometro){
  Serial.print("Tensao= ");
  Serial.println(tensao);
  digitalWrite(pwm,potenciometro);
  digitalWrite(direction1,LOW);
  digitalWrite(direction2,HIGH);
 
  }

void loop() {
 int potenciometro = 0;
 int duty_cycle = 0;
 float vout = 0;
 
 potenciometro = analogRead(pot);
 

 potenciometro = map(potenciometro, 0, 1023, 0, 255);

 duty_cycle = map(potenciometro,0,255,0,100);

 vout = (duty_cycle/100.0)*6.0;

 Controle_velocidade(vout,potenciometro);
 

 
}
