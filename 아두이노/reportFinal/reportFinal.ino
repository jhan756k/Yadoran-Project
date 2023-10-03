int GasPin = A0;
int DegreePin = A1;
int FlamePin = A2;
bool Gas = false;
bool Deg = false;
bool Fla = false;

void setup() {
  pinMode(GasPin, INPUT);
  pinMode(FlamePin, INPUT);
  pinMode(DegreePin, INPUT);
  Serial.begin(9600);
} 

void log() {
  // Serial.println("Gas: " + String(analogRead(GasPin)));
  // Serial.println("Flame: " + String(analogRead(FlamePin)));
  // Serial.println("Degree: " + String(analogRead(DegreePin)));
  // Serial.println();
  Serial.println(analogRead(GasPin));
}

void detection() {
  if (analogRead(GasPin) > 480) {
    Gas = true;
  }
  else Gas = false;

  if (analogRead(FlamePin) > 940) { 
    Fla = true;
  }
  else Fla = false;

  if (analogRead(DegreePin)  < 150) {
    Deg= true;
  }
  else Deg = false;
}

void loop() {
  detection();
  log();
  delay(300);
}
