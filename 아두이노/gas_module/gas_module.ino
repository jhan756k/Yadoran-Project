int sensorPin = A1;
int sensorValue = 0;

float value = 0;
float fixtemp = 20.;
int fixInput = 560;
float fixedDegreeValue = 5.5;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void ky028_read() {
  sensorValue = analogRead(A0);
  if (sensorValue > fixInput ) { 

    value = sensorValue - fixInput;
    value = value / fixedDegreeValue;
    
    fixtemp = fixtemp - value;    
    displayLCD(fixtemp);
    
  } else if (sensorValue < fixInput)  {
    value =  fixInput - sensorValue;
    value = value / fixedDegreeValue;

    fixtemp = fixtemp + value;
    displayLCD(fixtemp);
    
  }  else if (sensorValue == fixInput ) {
    displayLCD(sensorValue);
  }
  
  fixtemp = 20;
}

void loop() {
  ky028_read();
  int gas = analogRead(A0);
  Serial.print(gas);

  if (gas < 900){
    Serial.println(" Normal");
  }
  else {
    Serial.println(" Abnormal");
  }

  delay(500);
}
