#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h

#define BT_RX 1  
#define BT_TX 0   

SoftwareSerial BTSerial(BT_RX, BT_TX);

LiquidCrystal_I2C lcd(0x27, 16, 2);  
void setup() {
  lcd.init();            
  lcd.backlight();       


  BTSerial.begin(9600);
  printDefaultFace();
  for (int i = 0; i < 3; i++) {
    blinkEyes();
  }
}

void loop() {
  if (BTSerial.available()) {
    String command = BTSerial.readStringUntil('\n');
    command.trim(); 
    
    
    if (command == "hello") {
      updateLCD("Hello!");
    } else if (command == "blink") {
      blinkEyes();
   
    }
    
  }
}


void printDefaultFace() {
 
  lcd.setCursor(5, 0);
  lcd.print("o . o");

  lcd.setCursor(7, 1);
  lcd.print("_");
}


void blinkEyes() {
 
  lcd.setCursor(5, 0);  
  lcd.print("-");      
  lcd.setCursor(9, 0);
  lcd.print("-");    
  
  delay(500);        
  
  lcd.setCursor(5, 0);  
  lcd.print("o");     
  lcd.setCursor(9, 0); 
  lcd.print("o");     
}

void updateLCD(String message) {
  lcd.clear();
  lcd.setCursor(0, 0);  
  lcd.print(message);    
  delay(5000);        
  lcd.clear();
  printDefaultFace();
}
