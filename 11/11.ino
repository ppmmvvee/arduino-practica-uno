int potPin = A1;  // Pin analógico para el potenciómetro
int ledPin1 = 6; // Pin para el primer LED
int ledPin2 = 7; // Pin para el segundo LED
int ledPin3 = 8; // Pin para el tercer LED

void setup() {
  for(int i = 6; i < 8; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int sensorValue = analogRead(potPin); // Leer el valor del potenciómetro
  int ledValue = map(sensorValue, 0, 1023, 0, 3); // Mapear el valor a 0, 1 o 2

  // Encender o apagar los LEDs según el valor del potenciómetro
  if (ledValue >= 1) {
    digitalWrite(ledPin1, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }
  
  if (ledValue >= 2) {
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }
  
  if (ledValue >= 3) {
    digitalWrite(ledPin3, HIGH);
  } else {
    digitalWrite(ledPin3, LOW);
  }
}