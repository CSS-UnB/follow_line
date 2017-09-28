#define LINHA_PRETA 0
#define BRANCO 1

// Sensor
int LED = 13;
int SensorR = A0;
int SensorL = A3;

// Motor
//Definicoes pinos Arduino ligados a entrada da Ponte H
int CH1 = 4;
int CH1_pwm = 5;
int CH2_pwm = 6;
int CH2 = 7;

int valorMotorR = 125;
int valorMotorL = 125;


void setup() {
  // put your setup code here, to run once:

  pinMode(SensorL, INPUT);
  pinMode(SensorR, INPUT);

  Serial.begin(9600);

  pinMode(CH1, OUTPUT);
  pinMode(CH1_pwm, OUTPUT);
  pinMode(CH2, OUTPUT);
  pinMode(CH2_pwm, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorReadR = digitalRead(SensorR);
  int sensorReadL = digitalRead(SensorL);

  if (sensorReadL == LINHA_PRETA) {
    valorMotorR = 2 * valorMotorR;
  }
  else {
    valorMotorR = 125;
  }

    if (sensorReadR == LINHA_PRETA) {
    valorMotorL = 2 * valorMotorL;
  }
  else {
    valorMotorL = 125;
  }

  giraMotorL(valorMotorL);
  giraMotorR(valorMotorR);
  
}

//---------------------------------------------
void giraMotorL(int valorMotor) {
    //Gira o Motor A no sentido horario
    analogWrite(CH1_pwm, valorMotor);
    digitalWrite(CH1, LOW);
}

void giraMotorR(int valorMotor) {
    //Gira o Motor B no sentido horario
    analogWrite(CH2_pwm, valorMotor);
    digitalWrite(CH2, LOW);
}
