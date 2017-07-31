//EXAMPLE CODE: IR Obstacle Collision Detection Module // Henry's Bench

int LED = 13; // Use the onboard Uno LED
int Sensor = A0; // This is our input pin
void setup() 
{
  pinMode(Sensor, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int sensorRead = analogRead(Sensor);
  
  Serial.println( sensorRead );
 
  delay(200);
}
