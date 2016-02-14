#include <VirtualWire.h>

int relay = 2;
int relayValue = 1;

byte message[VW_MAX_MESSAGE_LEN]; 
byte msgLength = VW_MAX_MESSAGE_LEN; 

char command[12];

void setup(){
 
  pinMode(relay, OUTPUT);
 
  vw_set_rx_pin(5); 
  vw_setup(2000);   
  vw_rx_start();    
 
  digitalWrite(relay, relayValue);
}

void loop() {
  
  uint8_t message[VW_MAX_MESSAGE_LEN];    
  uint8_t msgLength = VW_MAX_MESSAGE_LEN;   
  
  if (vw_get_message(message, &msgLength)) {
    
    for (int i = 0; i < msgLength; i++) {
      command[i] = message[i];
    }  
    
    String commandString = String(command);
    String mustBe = String("Switch rele0");

    if (commandString.equals(mustBe)){
      relayValue = !relayValue;
      digitalWrite(relay, relayValue);
    }
    
  }
  
} 
