const int numLeds = 8;
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; 
const int delayTime = 1000; 

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  secuenciaNormal();
  delay(delayTime); 

  secuenciaReversa();
  delay(delayTime);

  parpadeoConjunto(3);
  delay(delayTime);

  secuenciaSalto();
  delay(delayTime);
}

void secuenciaNormal() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}

void secuenciaReversa() {
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}

void parpadeoConjunto(int times) {
  for (int j = 0; j < times; j++) {
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(delayTime);
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    delay(delayTime);
  }
}

void secuenciaSalto() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = 1; i < numLeds; i += 2) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}