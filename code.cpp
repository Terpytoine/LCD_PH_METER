#include <LiquidCrystal_I2C.h>

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensorPin = A0; // pH sensor connected to A0

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1023.0); // Convert analog reading to voltage
  float pH = 3.5 * voltage; // Simple conversion to pH value, calibration may be needed

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V, pH: ");
  Serial.println(pH);
  
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(voltage);
  lcd.print(" V");
  
  lcd.setCursor(0, 1);
  lcd.print("pH: ");
  lcd.print(pH);

  delay(1000); // Delay for 1 second before the next reading
}
