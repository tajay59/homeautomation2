
#include <SoftwareSerial.h>


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#include <ctype.h>
   
//**********ENTER IP ADDRESS OF SERVER******************//

#define HOST_IP     "localhost"       // EDIT HERE IP ADDRESS OF SERVER (YOUR COMPUTER'S IP ADDRESS) 
#define HOST_PORT   "80"              // SERVER PORT (BACKEND FLASK API PORT)
#define route       "api/update"      // LEAVE UNCHANGED 
#define idNumber    "620012345"       // EDIT HERE WITH YOUR ID NUMBER 

// WIFI CREDENTIALS
#define SSID        "YOUR WIFI"       // "REPLACE WITH YOUR WIFI's SSID"   
#define password    "YOUR PASSWORD"   // "REPLACE WITH YOUR WiFi's PASSWORD" 

#define stay        100
 
//**********PIN DEFINITIONS******************//



/*Function Declarations*/
 bool isNumber(double number);


/* Init class Instances */

 
#define espRX         10
#define espTX         11
#define espTimeout_ms 300


SoftwareSerial mySerial(8, 9);  // PIN 8 = RX, PIN 9 = TX, MODIFY IF NECESSARY
SoftwareSerial esp(espRX, espTX);


 

void setup(){
   
  Serial.begin(115200);   //  OPEN SERIAL COMMUNICATION,HARDWARE SERIAL, BAUD RATE = 115200,  MODIFY IF NECESSARY.                          
                          //  USE FOR SERIL MONITOR TO ARDUINO NANO COMMUNICATION 
  esp.begin(115200); 
  mySerial.begin(9600);   //  OPEN SERIAL COMMUNICATION,SOFTWARE SERIAL, BAUD RATE = 9600.  MODIFY IF NECESSARY.                          
                          //  USED FOR ARDUINO NANO WITH HM-10(PERIPHERAL) TO MOBILE(CENTRAL) COMMUNICATION
    
  espInit();  
 
}

void loop(){ 
  
  
    
  delay(1000);
  
}

 
void espSend(char command[] ){   
    esp.print(command); // send the read character to the esp    
    while(esp.available()){ Serial.println(esp.readString());}    
}


void espUpdate(char mssg[]){ 
    char espCommandString[50] = {0};
    char post[290]            = {0};

    snprintf(espCommandString, sizeof(espCommandString),"AT+CIPSTART=\"TCP\",\"%s\",%s\r\n",HOST_IP,HOST_PORT); 
    espSend(espCommandString);    //starts the connection to the server
    delay(stay);

    // GET REQUEST 
    // snprintf(post,sizeof(post),"GET /%s HTTP/1.1\r\nHost: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %d\r\n\r\n%s\r\n\r\n",route,HOST_IP,strlen(mssg),mssg);

    // POST REQUEST
    snprintf(post,sizeof(post),"POST /%s HTTP/1.1\r\nHost: %s\r\nContent-Type: application/json\r\nContent-Length: %d\r\n\r\n%s\r\n\r\n",route,HOST_IP,strlen(mssg),mssg);
  
    snprintf(espCommandString, sizeof(espCommandString),"AT+CIPSEND=%d\r\n", strlen(post));
    espSend(espCommandString);    //sends post length
    delay(stay);
    Serial.println(post);
    espSend(post);                //sends POST request with the parameters 
    delay(stay);
    espSend("AT+CIPCLOSE\r\n");   //closes server connection
   }

void espInit(){
    char connection[100] = {0};
    // esp.begin(115200); 
    Serial.println("Initiallizing");
    esp.println("AT"); 
    delay(1000);
    esp.println("AT+CWMODE=1");
    delay(1000);
    while(esp.available()){ Serial.println(esp.readString());} 

    snprintf(connection, sizeof(connection),"AT+CWJAP=\"%s\",\"%s\"\r\n",SSID,password);
    esp.print(connection);

    delay(3000);  //gives ESP some time to get IP

    if(esp.available()){   Serial.print(esp.readString());}
    
    Serial.println("\nFinish Initializing");    
   
}

//***** Design and implement all util functions below ******
 bool isNumber(double number){     
        char item[20];
        // snprintf();  This is not implemented for the UNO and Nano
        dtostrf(number,3,3,item); 
        if( isdigit(item[0]) )
          return true;
        return false; 
} 
 