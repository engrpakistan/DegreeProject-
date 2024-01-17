#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  
//color
// Define color sensor pins
#define S0 27
#define S3 25
#define S1 26
#define S2 12
#define sensorOut 14

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;
//voltage
// Define analog input
#define ANALOG_IN_PIN 32     
 
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 30000;
float R2 = 7500; 
 
// Float for Reference Voltage
float ref_voltage = 3.3;
 
// Integer for ADC value
int adc_value = 0;
 //

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("MES");

	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);

	digitalWrite(S0,HIGH);
	digitalWrite(S1,LOW);
	pinMode(sensorOut, INPUT);
}

void loop() {
float current,voltage;
current=getAnalogAmp();
voltage=volt();
color();
lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("VOLTAGE : ");
  lcd.setCursor(9,0);
  lcd.print(voltage);
  lcd.setCursor(0, 1);
  lcd.print("CURRENT : ");
  lcd.setCursor(9, 1);
  lcd.print(current);
}
