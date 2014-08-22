// Libreria para transmitir la señal
#include <VirtualWire.h>

char *signal;             // Codigo a transmitir
int coffeeButton = 5;     // Pin del botón de cafés
int teaButton = 6;        // Pin del botón de tés
int flagCoffeeButton = 0; // Flag para saber si hemos pulsado el botón de cafés
int flagTeaButton = 0;    // Flag para saber si hemos pulsado el botón de tés

void setup() {
  // Inicializamos el monitor serie  
  Serial.begin(9600);

  // Inicializamos los pines de lectura
  pinMode(coffeeButton, INPUT);
  pinMode(teaButton, INPUT);

  // Marcamos el pin del LED como salida para tenerlo de referencia
  pinMode(13, OUTPUT);

  // Configuramos el pin 1 como salida de datos
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(1);

  // Velocidad de transmision de la señal
  vw_setup(4000);
}

void loop() {
  // Leemos el botón de cafés
  flagCoffeeButton = digitalRead(coffeeButton);

  // Leemos el botón de tés
  flagTeaButton = digitalRead(teaButton);

  if(flagCoffeeButton == 1) {
    Serial.println(flagCoffeeButton); 

    // Marcamos la variable a "1" para enviar la señal de café
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

  if(flagTeaButton == 1) {
    Serial.println(flagTeaButton); 

    // Marcamos la variable a "0" para enviar la señal de té
    signal = "0";

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