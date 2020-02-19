const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  for(int pinNumber = 2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0)*5.0;

  Serial.print(", Voltage: ");
  Serial.print(voltage);

  float temp = (voltage - 0.5)*100;

  Serial.print(", degrees C: ");
  Serial.println(temp);

  if (temp < baselineTemp+2)
    for(int pinNumber = 2; pinNumber<5; pinNumber++)
        digitalWrite(pinNumber, LOW);
  else if (temp < baselineTemp+4)
    for(int pinNumber = 2; pinNumber<5; pinNumber++)
      if(pinNumber>2)
        digitalWrite(pinNumber, LOW);
      else
        digitalWrite(pinNumber, HIGH);
   else if (temp < baselineTemp+6)
    for(int pinNumber = 2; pinNumber<5; pinNumber++)
      if(pinNumber>3)
        digitalWrite(pinNumber, LOW);
      else
        digitalWrite(pinNumber, HIGH);
  else
    for(int pinNumber = 2; pinNumber<5; pinNumber++)
      digitalWrite(pinNumber, HIGH);
      
  delay(1000);
}
