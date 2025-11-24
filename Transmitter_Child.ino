// Placa copilului COM5
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int ledPin = 3;
const int vibrationMotorPin = 9;

RF24 radio(7, 8); 
const byte address[6] = "00001";

char mesaj[32];
bool alarmActive = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(vibrationMotorPin, OUTPUT);

  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.setChannel(100);
  radio.openWritingPipe(address);
  radio.openReadingPipe(1, address);
  radio.startListening();
}

void loop() {
  radio.stopListening();
  const char msg[] = "OK";
  if(!radio.write(&msg, sizeof(msg))) {
    radio.begin();
    radio.setRetries(15,15);
    radio.setPALevel(RF24_PA_LOW);
    radio.setChannel(100);
    radio.openWritingPipe(address);
    radio.openReadingPipe(1, address);  
     digitalWrite(ledPin, HIGH);
    digitalWrite(vibrationMotorPin,HIGH );
  }else{
    digitalWrite(ledPin, LOW);
    digitalWrite(vibrationMotorPin, LOW);
  }
  radio.startListening();  
}




