#include <string.h>
#include "uRTCLib.h" //Timer
#include <LiquidCrystal_I2C.h> //LCD
// On my queen shid

/*
  Components:
  Motion Sensor (ARDUINO) KEEP??
  Line Tracking Sensor
  Color Sensor (SPIKE)
  Timer (ARDUINO)
  LCD Screen (ARDUINO)
  Lights (ARDUINO WRITE TO SPIKE)
  Passive Buzzer (SPIKE/ARDUINO??)
  Button for Game Start??
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);
uRTCLib rtc(0x68);


const int infaredPin = 9; //IR for scoring detection
const int ledPin = 2; //LED Pin for Communication with Spike


const int SECONDS_START = 30; //Total time allowed for the game
int points{}; //Simple points count for the Arduino
int celebrateTime;
bool fullCelebrate{true}; //Determine if the program has celebrated for CELEBRATE_DURATION seconds, starts as true until the player scores.
bool done{false};


const int CELEBRATE_DURATION = 2; //Number of seconds the robot celebrates for

bool countDown(){ //This will take up the top line unless the points refresh
  rtc.refresh(); //TODO: Check to make sure there are no controversies with refresh in loop()
  int secondsCount = (rtc.minute() * 60) + (rtc.second());

  // lcd.clear();

  int center;

  if (secondsCount >=100){
    center = 6;
  }
  else {
    center = 7;
  }

  if (SECONDS_START - secondsCount <= 0){
    lcd.setCursor(0,0);
    lcd.print("!! GAME OVER !!");
    return true;
  }

  lcd.setCursor(0, 0);
  for (int i = 0; i < 17; i++){
    if (i == center){
      lcd.print(SECONDS_START - secondsCount);
    }
    else {lcd.print(" ")}
  }

}

void showPoints(){
  lcd.setCursor(0,1);
  lcd.print("Points: ");
  lcd.print(points);
}

void celebrate_1(){
  // Serial.println("Detected!");
  // digitalWrite(ledPin, HIGH);
  // \/\BOOYAKASHA/\/
  //      BABY
  const short delay_var = 50;
  lcd.clear();
  lcd.setCursor(15, 0);
  lcd.print("\\");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(14, 0);
  lcd.print("\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(13, 0);
  lcd.print("\\/\\");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(12, 0);
  lcd.print("\\/\\B");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(11, 0);
  lcd.print("\\/\\BO");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(10, 0);
  lcd.print("\\/\\BOO");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(9, 0);
  lcd.print("\\/\\BOOY");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("\\/\\BOOYA");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("\\/\\BOOYAK");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("\\/\\BOOYAKA");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("\\/\\BOOYAKAS");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("\\/\\BOOYAKASH");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("\\/\\BOOYAKASHA");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("\\/\\BOOYAKASHA/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("\\/\\BOOYAKASHA/\\");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("\\/\\BOOYAKASHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("/\\BOOYAKASHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("\\BOOYAKASHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BOOYAKASHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("OOYAKASHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("OYAKASHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("YAKASHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AKASHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("KASHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ASHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SHA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HA/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("/\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("\\/");
  delay(delay_var);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("/");
  delay(delay_var);
  lcd.clear();
}

void celebrate_2(){
  // Serial.println("Detected!");
  // digitalWrite(ledPin, HIGH);
  // Buckets (flashing)
  const short i = 200;

  for (int j = 0; j < 4; j++){
    lcd.clear();
    delay(i);
    lcd.setCursor(4, 0);
    lcd.print("BUCKETS");
    delay(i);
  }
}

void celebrate_3(){
  // Serial.println("Detected!");
  // digitalWrite(ledPin, HIGH);
  //
  // First: fill screen with "~"
  // Then: Write "BOOM" on 2nd row
  // Finally: Explode from "boom" with lcd.write((char)255);

  lcd.clear();
  for (int i = 0; i < 16; i++){
    lcd.setCursor(i, 1);
    lcd.print(">");
    lcd.setCursor((15 - i), 0);
    lcd.print("<");
    delay(25);
  }
  for (int i = 0; i < 16; i++){
    lcd.setCursor(i, 1);
    lcd.print(" ");
    lcd.setCursor((15 - i), 0);
    lcd.print(" ");
    delay(25);
  }
  const short f = 45;
  lcd.clear();
  lcd.setCursor(6, 1);
  lcd.print("boom");
  delay(500);
  lcd.clear();
  lcd.setCursor(6, 1);
  lcd.write((char)255);
  lcd.setCursor(7, 1);
  lcd.write((char)255);
  lcd.setCursor(8, 1);
  lcd.write((char)255);
  lcd.setCursor(9, 1);
  lcd.write((char)255);
  delay(f);
  lcd.setCursor(5, 1);
  lcd.write((char)255);
  lcd.setCursor(10, 1);
  lcd.write((char)255);
  lcd.setCursor(6, 0);
  lcd.write((char)255);
  lcd.setCursor(7, 0);
  lcd.write((char)255);
  lcd.setCursor(8, 0);
  lcd.write((char)255);
  lcd.setCursor(9, 0);
  lcd.write((char)255);
  delay(f);
  lcd.setCursor(4, 1);
  lcd.write((char)255);
  lcd.setCursor(5, 0);
  lcd.write((char)255);
  lcd.setCursor(11, 1);
  lcd.write((char)255);
  lcd.setCursor(10, 0);
  lcd.write((char)255);
  
  lcd.setCursor(6, 1);
  lcd.print(" ");
  lcd.setCursor(7, 1); // whitespace
  lcd.print(" ");
  lcd.setCursor(8, 1);
  lcd.print(" ");
  lcd.setCursor(9, 1);
  lcd.print(" ");

  delay(f);
  lcd.setCursor(3, 1);
  lcd.write((char)255);
  lcd.setCursor(4, 0);
  lcd.write((char)255);
  lcd.setCursor(12, 1);
  lcd.write((char)255);
  lcd.setCursor(11, 0);
  lcd.write((char)255);

  lcd.setCursor(5, 1);
  lcd.print(" ");
  lcd.setCursor(10, 1);
  lcd.print(" ");
  lcd.setCursor(6, 0);
  lcd.print(" ");       // whitespace
  lcd.setCursor(7, 0);
  lcd.print(" ");
  lcd.setCursor(8, 0);
  lcd.print(" ");
  lcd.setCursor(9, 0);
  lcd.print(" ");

  delay(f);
  lcd.setCursor(2, 1);
  lcd.write((char)255);
  lcd.setCursor(3, 0);
  lcd.write((char)255);
  lcd.setCursor(13, 1);
  lcd.write((char)255);
  lcd.setCursor(12, 0);
  lcd.write((char)255);

  lcd.setCursor(4, 1);
  lcd.print(" ");
  lcd.setCursor(5, 0);
  lcd.print(" ");    // whitespace
  lcd.setCursor(11, 1);
  lcd.print(" ");
  lcd.setCursor(10, 0);
  lcd.print(" ");

  delay(f);
  lcd.setCursor(1, 1);
  lcd.write((char)255);
  lcd.setCursor(1, 0);
  lcd.write((char)255);
  lcd.setCursor(2, 0);
  lcd.write((char)255);
  lcd.setCursor(14, 1);
  lcd.write((char)255);
  lcd.setCursor(14, 0);
  lcd.write((char)255);
  lcd.setCursor(13, 0);
  lcd.write((char)255);

  lcd.setCursor(3, 1);
  lcd.print(" ");
  lcd.setCursor(4, 0);
  lcd.print(" ");   // whitespace
  lcd.setCursor(12, 1);
  lcd.print(" ");
  lcd.setCursor(11, 0);
  lcd.print(" ");

  delay(f);
  lcd.setCursor(0, 1);
  lcd.write((char)255);
  lcd.setCursor(0, 0);
  lcd.write((char)255);
  lcd.setCursor(15, 1);
  lcd.write((char)255);
  lcd.setCursor(15, 0);
  lcd.write((char)255);

  lcd.setCursor(2, 1);
  lcd.print(" ");
  lcd.setCursor(3, 0);
  lcd.print(" ");   // whitespace
  lcd.setCursor(13, 1);
  lcd.print(" ");
  lcd.setCursor(12, 0);
  lcd.print(" ");

  delay(f);

  lcd.setCursor(1, 1);
  lcd.print(" ");
  lcd.setCursor(1, 0);
  lcd.print(" ");
  lcd.setCursor(2, 0);
  lcd.print(" ");   // whitespace
  lcd.setCursor(14, 1);
  lcd.print(" ");
  lcd.setCursor(14, 0);
  lcd.print(" ");
  lcd.setCursor(13, 0);
  lcd.print(" ");
  delay(f);
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 0);
  lcd.print(" ");   // whitespace
  lcd.setCursor(15, 1);
  lcd.print(" ");
  lcd.setCursor(15, 0);
  lcd.print(" ");
  delay(f);
}

void setup() {
  Serial.begin(9600);
  pinMode(infaredPin, INPUT); //Init for Infared and LED
  pinMode(ledPin, OUTPUT);

  URTCLIB_WIRE.begin(); //Initialize timer
  rtc.set(0,0,12,2,19,9,25); //THE BATTLE OF SARATOGA??!!!
  rtc.refresh();
  const int TIME_START[2] = {rtc.minute(), rtc.second()};

  lcd.init();//Init for LCD
  lcd.backlight();
  lcd.clear();
}

void loop() {
  rtc.refresh();
  int infaredValue = digitalRead(infaredPin);
  int now = rtc.second();
  
  done = countDown();

  if (done){
    delay(10000);
    return 0;
  }

  if ((now - celebrateTime >= CELEBRATE_DURATION) && fullCelebrate == false){ //Returns to previous count after showing that you scored
    digitalWrite(ledPin, LOW);
    fullCelebrate = true;
  }

  showPoints();


  if ((infaredValue == LOW) && (now - celebrateTime >= 2)){
    celebrate();
    fullCelebrate = false;
    celebrateTime = rtc.second();
    points++;
  }

  delay(100);
}