/*
 * Project: Gas Leakage Detection System
 * Author: Nelavai Usha
 * Description:
 * Detects gas leakage using MQ-2 sensor and alerts users
 * through an LED, buzzer, and LCD display.
 */

/*MQ2 sensor with Arduino.
 * https://srituhobby.com
 */
 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define LED 2
#define Buzzer 3
#define Sensor A1

void setup() {
  Serial.begin(9200);
  lcd.init();
  lcd.backlight();
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  int value = analogRead(Sensor);
  lcd.setCursor(0, 0);
  lcd.print("Value :");
  lcd.print(value);
  lcd.print("  ");

  if (value > 400) {
    digitalWrite(LED, HIGH);
    digitalWrite(Buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("GAS Detected!");
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(Buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("             ");
  }
}   can i write this code doirectly in github
