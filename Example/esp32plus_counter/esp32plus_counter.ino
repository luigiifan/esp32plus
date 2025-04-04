#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define SCREEN_ADDRESS 0x3C
#define OLED_RESET     -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BUZZER 32
#define S1 34
#define S2 35

int led[] = {17, 16, 4, 2};
int counter = -1;
bool s1Pressed;
bool s2Pressed;
bool is_done;

void showDisplay(){
  display.clearDisplay();
  display.setTextColor(1);
  display.setTextWrap(false);
  display.setCursor(59, 12);
  display.print(counter);
  display.setCursor(9, 12);
  display.print("Counter:");
  display.display();
}

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.display();
  display.clearDisplay();
  for(int i=0; i <= 3; i++){
    pinMode(led[i], OUTPUT);
  }
  pinMode(BUZZER, OUTPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
}

void loop() {
  for (int i = 0; i <= 3; i++) {
    if (i <= counter) {
      digitalWrite(led[i], HIGH);
    } else {
      digitalWrite(led[i], LOW);
    }
  }

  if(counter == 3 && is_done == false){
    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
    is_done = true;
  }
  else if(counter != 3){
    is_done = false;
  }

  if (digitalRead(S1) == LOW && !s1Pressed) {
    if (counter < 3) {
      counter++;
    }
    s1Pressed = true;
  }

  if (digitalRead(S2) == LOW && !s2Pressed) {
    if (counter > -1) {
      counter--;
    }
    s2Pressed = true;
  }

  if (digitalRead(S1) == HIGH) {
    s1Pressed = false;
  }

  if (digitalRead(S2) == HIGH) {
    s2Pressed = false;
  }

  showDisplay();
}
