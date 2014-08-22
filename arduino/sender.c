// Libreria para transmitir la señal
#include <VirtualWire.h>

char *signal;         // Codigo a transmitir
int sensorPin = 2;    // Pin donde hemos conectado el sensor de presencia
int sensorValue = 9;  // Variable que contiene el valor del sensor

void setup() {
  // Inicializamos el monitor serie  
  Serial.begin(9600);

  // Inicializamos el pin del sensor de presencia
  pinMode(sensorPin, INPUT);

  // Marcamos el pin del LED como salida para tenerlo de referencia
  pinMode(13, OUTPUT);

  // Configuramos el pin 0 como salida de datos
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(0);

  // Velocidad de transmision de la señal
  vw_setup(4000);
}

void loop() {
  // Leemos el valor del sensor
  sensorValue = digitalRead(sensorPin);

  // Si el sensor retorna un 0, es que ha detectado algo
  if(sensorValue == 0) {
    Serial.print("sensor = " ); 
    Serial.println(sensorValue); 

    // Marcamos la variable a "1"
    signal = "1";

    // Enviamos la señal a traves del pin
    vw_send((uint8_t *)signal, strlen(signal));
    vw_wait_tx(); 

    // "Endendemos" el LED para mostrar que la señal se ha enviado
    digitalWrite(13,1);
    // Esperamos un segundo
    delay(1000);
    // Apagamos el LED
    digitalWrite(13,0);
  }
}