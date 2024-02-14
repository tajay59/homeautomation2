#include <SoftwareSerial.h>     // INCLUDE SOFTWARESERIAL LIBRARY
SoftwareSerial mySerial(8, 9);  // PIN 8 = RX, PIN 9 = TX, MODIFY IF NECESSARY

void setup() {
  Serial.begin(115200);   //  OPEN SERIAL COMMUNICATION,HARDWARE SERIAL, BAUD RATE = 115200,  MODIFY IF NECESSARY.                          
                          //  USE FOR SERIL MONITOR TO ARDUINO NANO COMMUNICATION 

  mySerial.begin(9600);   //  OPEN SERIAL COMMUNICATION,SOFTWARE SERIAL, BAUD RATE = 9600.  MODIFY IF NECESSARY.                          
                          //  USED FOR ARDUINO NANO WITH HM-10(PERIPHERAL) TO MOBILE(CENTRAL) COMMUNICATION
}

void loop() {
  if (mySerial.available()) {             // CHECKS IF CENTRAL DEVICE SENT ARDUINO NANO ANY DATA
    char received[100]    = {0};          // BUFFER TO STORE INCOMING MESSAGES AS CHAR ARRAY 
    const int BUFFER_SIZE = 100;          // MAX SIZE EXPECTED FOR INCOMING MESSAGES
    char buff[BUFFER_SIZE];               // BUFFER USED TO STORE INCOMING MESSAGES AS BYTES
    int rlen  = mySerial.readBytesUntil('\n',buff,BUFFER_SIZE); // READ INCOMING MESSAGE, STORE IN BUFF
    
    for(int i = 0; i < rlen; i++){        // CONVERT MESSAGE FROM BYTES TO CHAR ARRAY
      received[i] = (char)buff[i];
    }

    // PRINT RECEIVED MESSAGE. 'received' CAN THEN BE MANIPULATED TO DO ANYTHING USEFUL   
    Serial.print(received);
    Serial.println(); 
  }

  if (Serial.available()) {               // CHECKS IF SERIAL MONITOR SENT ANY DATA TO ARDUINO NANO
    char received[100]    = {0};          // BUFFER TO STORE INCOMING MESSAGES AS CHAR ARRAY 
    const int BUFFER_SIZE = 100;          // MAX SIZE EXPECTED FOR INCOMING MESSAGES
    char buff[BUFFER_SIZE];               // BUFFER USED TO STORE INCOMING MESSAGES AS BYTES
    int rlen  = Serial.readBytesUntil('\n',buff,BUFFER_SIZE); // READ INCOMING MESSAGE, STORE IN BUFF
    
    for(int i =0; i < rlen; i++){
      received[i] = (char)buff[i];
    }

    // 'received' CAN THEN BE MANIPULATED TO DO ANYTHING USEFUL     
    mySerial.print(received);            // IN THIS CASE SEND 'received' TO CENTRAL DEVICE
    mySerial.println(); 
  } 
}
