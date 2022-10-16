// #####################      Libraries      #####################


// For the display:
#include <LiquidCrystal_I2C.h>

// --------------------------------------------------------------

// For the display:


// #####################      Variables      #####################

// ----- For the Display: 

// Set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// Set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

String introMessage1 = "Blue&Go";
String introMessage2 = "Connecting...";

// --------------------------------------------------------------

// ###############################################################
// ###############################################################

void setup(){
  // _____________   Display    _____________
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void loop(){
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print static message
  lcd.print(introMessage1);
  // print scrolling message
  scrollText(1, introMessage2, 250, lcdColumns);
}

// ###############################################################
// ###############################################################


// #####################      Functions      #####################

// ----- For the Display:


// Function to scroll text
// @row: row number where the text will be displayed
// @message: message to scroll
// @delayTime: delay between each character shifting
// @lcdColumns: number of columns of your LCD
void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}

// --------------------------------------------------------------

