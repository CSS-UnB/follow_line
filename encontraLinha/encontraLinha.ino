#define LINHA_PRETA 1
#define BRANCO 0

// Sensor
int LED = 13; // Use the onboard Uno LED
int Sensor = A0; // This is our input pin

// Motor
//Definicoes pinos Arduino ligados a entrada da Ponte H
int CH1 = 4;
int CH1_pwm = 5;
int CH2_pwm = 6;
int CH2 = 7;

int valorMotor = 130;

void setup()
{
  pinMode(Sensor, INPUT);
  Serial.begin(9600);

   //Define os pinos de controle do motor
   pinMode(CH1, OUTPUT);
   pinMode(CH1_pwm, OUTPUT);
   pinMode(CH2, OUTPUT);
   pinMode(CH2_pwm, OUTPUT);
}

void loop()
{
  int sensorRead = digitalRead(Sensor);

  Serial.println( sensorRead );

  if (sensorRead == LINHA_PRETA) {
     valorMotor = 0;
  }
  else
  {
      valorMotor = 130;
  }
  giraMotor(valorMotor);

  delay(200);
}

void giraMotor(int valorMotor)
{
    //Gira o Motor A no sentido horario
    analogWrite(CH1_pwm, valorMotor);
    digitalWrite(CH1, LOW);
    analogWrite(CH2_pwm, valorMotor);
    digitalWrite(CH2, LOW);
    delay(20);
}
