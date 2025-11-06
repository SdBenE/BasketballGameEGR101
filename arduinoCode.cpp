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
const int ledPin = 2;

void countDown(){
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

  //TODO: REMOVE AFTER DEBUG
  //FIXME #2 : Move LCD wires over to timer SCL and SDA
}

void loop() {
  rtc.refresh();
  int sensorValue = digitalRead(infaredPin);

  countDown();

  if (sensorValue == LOW){
    celebrate();
  }
  else {
    // Serial.println("Not Detected");
    digitalWrite(ledPin, LOW);
  }
}