#include <VirtualWire.h>

// define pin 2 as the push-button pin
int btn_port = 2;
 
void setup(){
  
  // Pin 8 will be the used for transmission
  vw_set_tx_pin(8);
  vw_setup(2000);   // Bits per sec

  pinMode(btn_port, INPUT); 
}
 
void loop(){
  
  char command[13] = "Switch rele0";
  
  if (digitalRead(btn_port) != 0) {
          
    // Force user to let go the button
    while(digitalRead(btn_port) != 0) {
      delay(100);
    }    
        
    send(command);
    
  } 
  
} 
 
void send (char *message){
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); 
}
