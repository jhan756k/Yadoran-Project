double temp;
bool fire = false;
int buzzerPin = 2;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  int val = analogRead(A0);
  temp = val*0.48828125;
  
  if (!fire){
    digitalWrite(buzzerPin, LOW);
  }
  else {
    digitalWrite(buzzerPin, HIGH);
  }

  if (temp>50){
    fire = true;
  }
  else fire = false;

  delay(500);
}