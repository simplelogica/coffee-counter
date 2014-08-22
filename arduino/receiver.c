// Libreria para transmitir la señal
#include <VirtualWire.h>

int dataPin = 0;  // Pin donde hemos conectado el receptor de la señal del otro arduino

void setup() {
  // Marcamos el pin del LED como salida para tenerlo de referencia
  pinMode(13, OUTPUT);

  // Configuramos el pin 0 como salida de datos
  vw_set_ptt_inverted(true); 
  vw_set_rx_pin(dataPin);

  // Velocidad de transmision de la señal
  vw_setup(4000); 
  vw_rx_start();
}
    
void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  // Si recibimos señal ejecutamos las acciones que deseemos
  if (vw_get_message(buf, &buflen)) 
  {
    if(buf[0] == '1') {
      // "Endendemos" el LED para mostrar que la señal se ha enviado
      digitalWrite(13,1);
      // Esperamos un segundo
      delay(1000);
      // Apagamos el LED
      digitalWrite(13,0);
    }
  }
}