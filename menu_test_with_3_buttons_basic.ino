/*
  Basic Menu for 0.96 I2C OLED displays on Arduino.
*/

#include <Button.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> 
#include <Fonts/FreeSans9pt7b.h>
//#include <Fonts/FreeSans12pt7b.h>

// make sure the you choose the correct address for your display
#define OLED_ADDR   0x3C
#define OLED_RESET 4
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Button upBtn(12); // Pin 12
Button selectBtn(3); // Pin 3
Button downBtn(11); // Pin 11

byte menuCount = 1;

void setup() {
  // setup buttons
	upBtn.begin();
	selectBtn.begin();
	downBtn.begin();
	
	// setup display
	Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.display();
  display.clearDisplay();
}

void loop() {
  // updates display based on input from the buttons
  getButtonInput();
  staticMenu();
  menuInteract();
  display.clearDisplay();
}

void staticMenu() {
  // change text display here
  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(10, 0);
  // menu title
  display.println("Menu Test");
  //---------------------------------
  display.setTextSize(1);
  display.setCursor(10, 20);
  // edit menu item here
  display.println("Function 1");
  display.setCursor(60, 20);

  display.setCursor(10, 30);
  // edit menu item here
  display.println("Function 2");
  display.setCursor(60, 30);

  display.setCursor(10, 40);
  // edit menu item here
  display.println("Function 3");
  display.setCursor(60, 40);

  display.setCursor(10, 50);
  // edit menu item here
  display.println("Function 4");
  display.setCursor(45, 50);
  
  // prints the cursor to highlight menu items
  display.setCursor(2, (menuCount * 10) + 10);
  display.println(">");

  display.display();
}



void getButtonInput() {
  // handles menu scrolling
  if (upBtn.pressed()) {
    if (menuCount <= 1)
      menuCount = 4;
    else
      menuCount--; 
  }
	
	if (downBtn.pressed()) {
	  if (menuCount >= 4)
	    menuCount = 1;
	  else
	    menuCount++;
	}
}

void menuInteract() {
  // handles select button input when a menu item is highlighted
  if (menuCount == 1 && selectBtn.pressed())
    // menu item 1 clicked
    function_one();
  else if (menuCount == 2 && selectBtn.pressed())
    // menu item 2 clicked
    function_two();
  else if (menuCount == 3 && selectBtn.pressed())
    // menu item 2 clicked
    function_three();
  else if (menuCount == 4 && selectBtn.pressed())
    // menu item 3 clicked
    function_four();
}

void function_one() {
  // insert fuction code form menu item 1 here
  Serial.println('Function 1 Firing;');
}

void function_two() {
  // insert fuction code form menu item 2 here
  Serial.println('Function 2 Firing;');
}

void function_three() {
  // insert fuction code form menu item 3 here
  Serial.println('Function 3 Firing;');
}

void function_four() {
  // insert fuction code form menu item 4 here
  Serial.println('Function 4 Firing;');
}







