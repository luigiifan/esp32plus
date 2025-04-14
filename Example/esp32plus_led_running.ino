#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define SCREEN_ADDRESS 0x3C
#define OLED_RESET     -1
#define BUZZER 32
#define S1 34
#define S2 35

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int led[] = {17, 16, 4, 2};
bool is_running;
bool is_done;
unsigned long previousMillis = 0;
unsigned long interval = 100; 
int counter;

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
  if(digitalRead(S1) == LOW){
    is_running = true;
    Serial.println("S1 pressed!");
  }
  if(digitalRead(S2) == LOW){
    is_running = false;
    Serial.println("S2 pressed!");
  }

  if(is_running == true){
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      static int ledIndex = 0;
      if(ledIndex >= 0 && is_done == false){
        digitalWrite(led[ledIndex], HIGH);
        ledIndex++;
      }

      if(ledIndex > 3 && is_done == false){
        digitalWrite(BUZZER, HIGH);
        delay(100);
        digitalWrite(BUZZER, LOW);
        counter++;
        is_done = true;
      }

      if (ledIndex <= 4 && is_done == true) {
        digitalWrite(led[ledIndex], LOW);
        ledIndex--;
      }

      if(ledIndex < 0 && is_done == true){
        is_done = false;
        ledIndex = 0;
      }
    }
  }
  showDisplay();
}
