// Placa părinte COM9
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int ledPin = 3;
const int vibrationMotorPin = 9;

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

char mesaj[32];
unsigned long lastReceivedTime = 0;
const unsigned long timeout = 1000; 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(vibrationMotorPin, OUTPUT);

  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.setChannel(100);
  radio.openReadingPipe(1, address);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&mesaj, sizeof(mesaj));
    Serial.println(mesaj);
    lastReceivedTime = millis();  // actualizăm DOAR când primim ceva
        digitalWrite(ledPin, LOW);
    digitalWrite(vibrationMotorPin, LOW);
  } else {
    Serial.println("nu");
        digitalWrite(ledPin, HIGH);
    digitalWrite(vibrationMotorPin, HIGH);
  }
}