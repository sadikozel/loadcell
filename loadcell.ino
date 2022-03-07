#include <LiquidCrystal.h>
#include "HX711.h"
 #define DOUT 3
 #define CLK 2
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
 HX711 scale(DOUT, CLK);
 float calibration_factor = 95500;
 void setup() {
  lcd.begin(16,2);
  lcd.setCursor(6,0);
  lcd.print("kg");
Serial.begin(9600);
scale.set_scale(calibration_factor);
scale.tare();
}
void loop() {
 
Serial.print("Weight: ");
Serial.print(scale.get_units());
Serial.println(" kg");
 lcd.setCursor(0,0);
 lcd.print(scale.get_units());   

}
