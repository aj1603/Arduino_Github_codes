#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

////////////////////Configuration for keypad
const int ROW_NUM    = 4; // four rows
const int COLUMN_NUM = 4; // four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};      // connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; // connect to the column pinouts of the keypad
////////////////////

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

////////////////////Some variable and integer for value
String inputString;
long inputInt;
int cursorColumn = 0;
const int button_1 = 10;
const int button_2 = 11;
const int relay_pin = 13;

int button_1_state = 0;
int button_2_state = 0;
int button_count = 0;
int prestate = 0;
int print_count = 0;
////////////////////

void setup() {
  Serial.begin(9600);
  inputString.reserve(10);

  ////////////////////Pins configuration
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(relay_pin, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  ////////////////////Reading value
  button_1_state = digitalRead(button_1);
  button_2_state = digitalRead(button_2);
  char key = keypad.getKey();

  if (key) {
    if (key >= '0' && key <= '9') {     // only act on numeric keys
      inputString += key;               // append new character to input string
      lcd.setCursor(cursorColumn, 0);
      lcd.print(key);
      cursorColumn++;
    }
    else if (key == '#') {
      if (inputString.length() > 0) {
        inputInt = inputString.toInt();
        print_count = inputInt;
        if (inputString) {
          lcd.setCursor(0, 0);
          lcd.print("Print : ");
          lcd.print(inputInt);
          cursorColumn = 0;
        }
      }
      else if (key == '*') {
        inputString = "";
        lcd.clear();
        cursorColumn = 0;
        key = 0;
      }
    }
    else if (key == '*') {
      inputString = "";
      button_count = 0;
      lcd.clear();
      cursorColumn = 0;
    }
  }
  if (button_1_state == 0 && button_2_state == 0) {
    delay(500);
    button_count++;
    if (button_count) {
      lcd.setCursor(0, 1);
      lcd.print("Printed : ");
      lcd.print(button_count);
      if (button_count == print_count) {
        digitalWrite(relay_pin, HIGH);
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Finish");
        button_count = 0;
        print_count = 0;
      }
    }
  }
}
