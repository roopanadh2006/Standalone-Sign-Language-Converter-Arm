#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int threshold = 256;
String lastGesture = "";

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  lcd.print("SIGN SYSTEM");
  delay(1500);
  lcd.clear();
}

void loop() {

  int f1 = analogRead(A0); // Index
  int f2 = analogRead(A1); // Middle
  int f3 = analogRead(A2); // Ring
  int f4 = analogRead(A3); // Little

  int s1 = (f1 < threshold) ? 1 : 0;
  int s2 = (f2 < threshold) ? 1 : 0;
  int s3 = (f3 < threshold) ? 1 : 0;
  int s4 = (f4 < threshold) ? 1 : 0;

  String gesture = "";

  // ---- SIGN LOGIC ----

  if(s1==0 && s2==0 && s3==0 && s4==0)
    gesture = "IDLE";

  else if(s1==1 && s2==0 && s3==0 && s4==0)
    gesture = "YES";

  else if(s1==0 && s2==1 && s3==0 && s4==0)
    gesture = "NO";

  else if(s1==0 && s2==0 && s3==1 && s4==0)
    gesture = "OK";

  else if(s1==0 && s2==0 && s3==0 && s4==1)
    gesture = "HI";

  else if(s1==1 && s2==1 && s3==0 && s4==0)
    gesture = "HELLO";

  else if(s1==0 && s2==1 && s3==1 && s4==0)
    gesture = "THANK YOU";

  else if(s1==0 && s2==0 && s3==1 && s4==1)
    gesture = "SORRY";

  else if(s1==1 && s2==0 && s3==0 && s4==1)
    gesture = "HELP";

  else if(s1==1 && s2==1 && s3==1 && s4==0)
    gesture = "PLEASE";

  else if(s1==0 && s2==1 && s3==1 && s4==1)
    gesture = "STOP";

  else if(s1==1 && s2==0 && s3==1 && s4==1)
    gesture = "GO";

  else if(s1==1 && s2==1 && s3==1 && s4==1)
    gesture = "EMERGENCY";

  else
    gesture = "UNKNOWN";

  // ---- DISPLAY ----

  if(gesture != lastGesture) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gesture:");
    lcd.setCursor(0,1);
    lcd.print(gesture);

    lastGesture = gesture;
  }

  // Debug
  Serial.print(s1); Serial.print(" ");
  Serial.print(s2); Serial.print(" ");
  Serial.print(s3); Serial.print(" ");
  Serial.println(s4);

  delay(150);
}
