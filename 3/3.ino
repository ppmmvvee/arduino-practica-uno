int pinArray [] = { 2,3,4,5,6,7,8,9,10,11,12 };//Declara un arreglo de enteros llamado pinArray que almacena los números de los pines a los que están conectados los LEDs
int controlLed = 13;//Declara una variable entera llamada controlLed que almacena el número de pin al que está conectado un LED que actúa como el control de la secuencia.
int waitNextLed = 100; //Declara una variable entera llamada waitNextLed que representa el tiempo en milisegundos que se espera antes de encender el siguiente LED en la secuencia.
int tailLength = 4;//Declara una variable entera llamada tailLength que representa la longitud de la "cola" de la estrella fugaz, es decir, cuántos LEDs se mantienen encendidos al final de la secuencia.
int lineSize = 11;//Declara una variable entera llamada lineSize que representa la cantidad total de LEDs en la secuencia.

void setup() {
int i;//Se declara una variable entera i que se utilizará para realizar un bucle a través de los pines del arreglo
pinMode (controlLed, OUTPUT);

for (i=0; i< lineSize; i++) {
  pinMode(pinArray[i], OUTPUT);
  }

}

void loop() {

  int i;
  int tailCounter = tailLength;//Declara una variable entera tailCounter que inicializa con el valor de tailLength. Esta variable se usa para rastrear la longitud de la "cola" actual de la estrella fugaz
  
  digitalWrite(controlLed, HIGH);
  
  for (i=0; i<lineSize; i++) {
  digitalWrite(pinArray[i],HIGH); 
  delay(waitNextLed);
  
  if (tailCounter == 0) {
  digitalWrite(pinArray[i-tailLength],LOW);
  }//verifica si tailCounter ha llegado a cero. Si es así, apaga el LED que estaba encendido en la posición anterior al inicio de la "cola"

  else if (tailCounter > 0)
  tailCounter--;
  }
  
  for (i=(lineSize-tailLength); i<lineSize; i++){
  digitalWrite(pinArray[i],LOW);
  delay(waitNextLed);
  }

}