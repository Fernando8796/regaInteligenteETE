/*************************************************************
========= Código projeto rega inteligente ETEMERB ============

Criado por: José Fernando; Davidson Wisllety
*************************************************************/

#define pinoLigarSensor 8 // Pino para ligar/desligar o sensor de umidade
#define pinoSensor A0 // Pino para ler a umidade do sensor
#define pinoValvula 10  // Pino para ligar/desligar a válvula solenoide
#define limiarSeco 74
#define tempoRega 50 // Tempo de rega em segundos

int umidadeSolo = 0;

void setup() {

  Serial.begin(115200);
  pinMode(pinoLigarSensor, OUTPUT);
  pinMode(pinoSensor, INPUT);
  pinMode(pinoValvula, OUTPUT);


}

void loop() {

  digitalWrite(pinoValvula, LOW);
  digitalWrite(pinoSensorLD, HIGH);
  delay(1000);

  umidadeSolo = analogRead(pinoSensor);

  umidadeSolo = map(umidadeSolo , 1023, 290, 0, 100);

  Serial.print(umidadeSolo);

  if(umidadeSolo < limiarSeco) {
    Serial.print("    Regando     ");
    digitalWrite(pinoValvula, HIGH);
    delay(tempoRega*1000);
    digitalWrite(pinoValvula, LOW);
  }
  else {
   Serial.print("Solo Encharcado ");
  }
  digitalWrite(pinoSensorLD, LOW);
  delay(60000);

}
