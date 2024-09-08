#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address 0x27, 16 columns, and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();             // Turn on the LCD backlight
  
  // Display a setup message on the LCD
  lcd.setCursor(0, 0);         // Set the cursor to the first row, first column
  lcd.print("SET UP...");      // Print "SET UP..." on the LCD
  delay(2000);                 // Wait for 2 seconds
  lcd.clear();                 // Clear the display
}

void loop() {
  // Display text on the LCD
  lcd.setCursor(0, 0);         // Set the cursor to the first row, first column
  lcd.print("LCD");            // Print "LCD" on the first row
  lcd.setCursor(0, 1);         // Set the cursor to the second row, first column
  lcd.print("DISPLAY");        // Print "DISPLAY" on the second row
  
  delay(2000);                 // Wait for 2 seconds
  
  // Clear the display to prevent overwriting
  lcd.clear();
}
