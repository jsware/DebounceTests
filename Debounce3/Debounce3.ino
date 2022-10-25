#define BUTTON 2

bool led = false;
byte readings = 0;
bool state = 0;
unsigned long debounce = 0;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if(millis() - debounce >= 5) {
    readings = (readings<<1) | digitalRead(BUTTON);
    debounce = millis();
  }

  // If button not pressed but was pressed.
  if(readings == 0xff && !state) {
    state = true;
    led = !led;
    digitalWrite(LED_BUILTIN, led);
  } else if(readings == 0x00) {
    state = false;
  }
}
