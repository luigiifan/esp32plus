#define BUZZER 32
#define S1 34
#define S2 35

int led[] = {17, 16, 4, 2};
bool is_running;
bool is_done;
unsigned long previousMillis = 0;
unsigned long interval = 100; 

void setup() {
  Serial.begin(9600);
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
}
