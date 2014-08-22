#include <VirtualWire.h>

void setup() {
  // Inicializamos el monitor serie  
  Serial.begin(9600);

  // Marcamos el pin del LED como salida para tenerlo de referencia
  pinMode(13, OUTPUT);

  // Inicializamos el receptor de señal
  vw_set_ptt_inverted(true); 
  vw_setup(2000); 
  vw_rx_start();
}
    
void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  // Si recibimos señal ejecutamos las acciones que deseemos
  if (vw_get_message(buf, &buflen)) 
  {

    Serial.print("Recibimos un ");
    Serial.println(buf[0]);
    // Si recibimos un 1 es que hemos pulsado el botón de café
    if(buf[0] == '1') {
      // "Endendemos" el LED para mostrar que la señal se ha enviado
      digitalWrite(13,1);
      // Esperamos un segundo
      delay(1000);
      // Apagamos el LED
      digitalWrite(13,0);
    }


    // Si recibimos un 0 es que hemos pulsado el botón de té
    if(buf[0] == '0') {
      // "Endendemos" el LED para mostrar que la señal se ha enviado
      digitalWrite(13,1);
      // Esperamos un segundo
      delay(1000);
      // Apagamos el LED
      digitalWrite(13,0);
    }
  }
}