
//Definicoes pinos Arduino ligados a entrada da Ponte H
int CH1 = 4;
int CH1_pwm = 5;
int CH2_pwm = 6;
int CH2 = 7;
  
void setup()
{
  //Define os pinos como saida
 pinMode(CH1, OUTPUT);
 pinMode(CH1_pwm, OUTPUT);
 pinMode(CH2, OUTPUT);
 pinMode(CH2_pwm, OUTPUT);
}
  
void loop()
{
  for (int valor = 0; valor <= 255; valor++)
  {
     //Gira o Motor A no sentido horario
     analogWrite(CH1_pwm, valor); 
     digitalWrite(CH1, LOW);
     analogWrite(CH2_pwm, valor); 
     digitalWrite(CH2, LOW);
     delay(20);
    }

  delay(5000);

   for (int valor = 255; valor >= 0; valor--)
  {
     //Gira o Motor A no sentido horario
     analogWrite(CH1_pwm, valor); 
     digitalWrite(CH1, LOW);
     analogWrite(CH2_pwm, valor); 
     digitalWrite(CH2, LOW);
     delay(20);
    }


}
