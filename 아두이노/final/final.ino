#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);

int gas = 0;
int temp = 0;
int buz_digital = 6;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(buz_digital, OUTPUT);
}

void check() {
  gas = analogRead(A0);
  temp = analogRead(A1);

  Serial.print(gas);
  Serial.println(" gas");
  Serial.print(temp);
  Serial.println(" temp");
  Serial.println();
}

void lcdPrint(){
  lcd.setCursor(0,0);
  lcd.print("Gas: ");
  lcd.print(gas);
  lcd.print(" Temp: ");
  lcd.println(temp);
}

void loop() {
  check();
  digitalWrite(buz_digital, LOW);

  lcdPrint();

  while (gas > 370){
    digitalWrite(buz_digital, HIGH);
    delay(500);
    digitalWrite(buz_digital, LOW);
    delay(500);
    check();
    lcdPrint();
  }

  delay(500);
}
