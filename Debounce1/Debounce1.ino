#define BUTTON 2

bool led = false;
bool state = false;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  bool reading = digitalRead(BUTTON);

  // If button not pressed but was pressed.
  if(reading && !state) { 
    led = !led;
    digitalWrite(LED_BUILTIN, led);
  }

  state = reading;
}
