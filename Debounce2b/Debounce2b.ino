#define BUTTON 2
#define DELAY 50

bool led = false;
byte state = false;
byte last = false;
unsigned long debounce = 0;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  byte reading = digitalRead(BUTTON);

  // New reading, so start the debounce timer.
  if (reading != last) {
    debounce = millis();
  } else if ((millis() - debounce) > DELAY) {
    // Use reading if we have the same reading for > DELAY ms.
    
    // If button not pressed but was pressed.
    if(reading && !state) { 
      led = !led;
      digitalWrite(LED_BUILTIN, led);
    }

    state = reading;
  }

  last = reading;
}
