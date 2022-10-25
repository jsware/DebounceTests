#define BUTTON 2
#define DELAY 0xff

bool led = false;
byte readings = 0;
bool state = 0;
byte debounce = 0;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if(!(++debounce & DELAY)) {
    readings = (readings<<1) | digitalRead(BUTTON);
  }

  if(readings == 0xff && !state) {
    state = true;
    led = !led;
    digitalWrite(LED_BUILTIN, led);
  } else if(readings == 0x00) {
    state = false;
  }
}
