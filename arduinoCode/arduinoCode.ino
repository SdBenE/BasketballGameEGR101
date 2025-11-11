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


const int infaredPin = 9;
const int ledPin = 2; //LED Pin for Communication with Spike


int secondsStart = 30; //Total time allowed for the game
int points{}; //Simple points count for the Arduino
int celebrateTime;
bool fullCelebrate{true};


const int CELEBRATE_DURATION = 2; //Number of seconds the robot celebrates for

void countDown(){ //This will take up the top line unless the points refresh
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

  lcd.setCursor(center, 0);
  lcd.print(secondsCount);
}

void showPoints(){
  lcd.setCursor(0,1);
  lcd.print("Points: ")
  lcd.print(points);
}

void celebrate(){
  // Serial.println("Detected!");
  digitalWrite(ledPin, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("!!!SCORED!!!");
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
  int now = rtc.seconds();

  if ((now - celebrateTime >= CELEBRATE_DURATION) && fullCelebrate = false){ //Returns to previous count after showing that you scored
    countDown();
    fullCelebrate = true;
  }

  showPoints();


  if (infaredValue == LOW){
    celebrate();
    fullCelebrate = false;
    celebrateTime = rtc.seconds();
    points++;
  }
  else {
    // Serial.println("Not Detected");
    digitalWrite(ledPin, LOW);

  }
}