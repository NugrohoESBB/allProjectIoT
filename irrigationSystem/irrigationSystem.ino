#define PIN_SOIL    A0
#define PIN_RELAY   5
#define PIN_RED     14
#define PIN_YELLOW  12
#define PIN_GREEN   13
#define PIN_BUZZER  4

#define RELAY_ON    LOW
#define RELAY_OFF   HIGH

const int SOIL_DRY = 800;
const int SOIL_WET = 350;

const int THRESHOLD_ON  = 35;
const int THRESHOLD_OFF = 60;

const unsigned long READ_INTERVAL = 1000;
const unsigned long PUMP_MAX_TIME = 30000;
const unsigned long PUMP_COOLDOWN = 60000;

bool pumpOn = false;
unsigned long pumpStart = 0;
unsigned long pumpStop = 0;
unsigned long lastRead = 0;

int readSoilPercent() {
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(PIN_SOIL);
    delay(5);
  }
  int raw = sum / 10;
  int pct = map(raw, SOIL_DRY, SOIL_WET, 0, 100);
  return constrain(pct, 0, 100);
}

void setLeds(bool r, bool y, bool g) {
  digitalWrite(PIN_RED, r);
  digitalWrite(PIN_YELLOW, y);
  digitalWrite(PIN_GREEN, g);
}

void beep(int times, int ms) {
  for (int i = 0; i < times; i++) {
    digitalWrite(PIN_BUZZER, HIGH);
    delay(ms);
    digitalWrite(PIN_BUZZER, LOW);
    delay(ms);
  }
}

void pumpControl(bool on) {
  pumpOn = on;
  digitalWrite(PIN_RELAY, on ? RELAY_ON : RELAY_OFF);
  if (on) {
    pumpStart = millis();
    beep(2, 100);
  } else {
    pumpStop = millis();
    beep(1, 300);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_RELAY, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  digitalWrite(PIN_RELAY, RELAY_OFF);
  digitalWrite(PIN_BUZZER, LOW);
  setLeds(LOW, LOW, LOW);

  setLeds(HIGH, LOW, LOW); delay(300);
  setLeds(LOW, HIGH, LOW); delay(300);
  setLeds(LOW, LOW, HIGH); delay(300);
  Serial.println("AquaSense siap.");
}

void loop() {
  unsigned long now = millis();

  if (now - lastRead >= READ_INTERVAL) {
    lastRead = now;
    int soil = readSoilPercent();
    Serial.printf("Kelembapan: %d%% | Pompa: %s\n", soil, pumpOn ? "ON" : "OFF");

    if (!pumpOn) {
      bool cooldownDone = (pumpStop == 0) || (now - pumpStop >= PUMP_COOLDOWN);
      if (soil < THRESHOLD_ON && cooldownDone) {
        pumpControl(true);
      }
    } else {
      if (soil >= THRESHOLD_OFF || (now - pumpStart >= PUMP_MAX_TIME)) {
        pumpControl(false);
      }
    }

    if (pumpOn)                      setLeds(LOW, HIGH, LOW);
    else if (soil < THRESHOLD_ON)    setLeds(HIGH, LOW, LOW);
    else                             setLeds(LOW, LOW, HIGH);
  }
}
