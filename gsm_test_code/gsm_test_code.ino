#include <RH_ASK.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

RH_ASK rf_driver(2000, 12); // Data pin = 12

const int buttonPin = 2;  // Pin for the push button
const int ledPin = 13;    // Pin for the LED

// Define the RX and TX pins for the GPS module
const int gpsRxPin = 2; // Connect GPS TX to Arduino pin 2
const int gpsTxPin = 3; // Connect GPS RX to Arduino pin 3

// Create a SoftwareSerial object to communicate with the GPS module
SoftwareSerial gpsSerial(gpsRxPin, gpsTxPin);

// Create a TinyGPS++ object
TinyGPSPlus gps;

// GSM function declaration
void gsm_send();

void setup() {
  Serial.begin(9600);
  rf_driver.init();
  pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);           // Set LED pin as output
  gpsSerial.begin(9600); // Initialize serial communication with the GPS module
  delay(3000); // Delay to ensure GSM module initialization
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {  // Check if button is pressed
    const char *msg = "Emergency";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    
    // GSM send function
    gsm_send();
    
    delay(1000);
    digitalWrite(ledPin, LOW);   // Turn off the LED
  }
}

// GSM SEND FUNCTION
void gsm_send() {
  // Read latitude and longitude from the GPS module
  float latitude = 0.0;
  float longitude = 0.0;
  
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      latitude = gps.location.lat();
      longitude = gps.location.lng();
      break; // Exit the loop once we have obtained the coordinates
    }
  }

  // GSM message construction
  Serial.print("AT+CMGF=1"); // Set SMS mode to text
  delay(100);
  Serial.write(0x0D); // Carriage return
  Serial.write(0x0A); // New line
  delay(1000);
  Serial.print("AT+CMGS=\"+916383803739\""); // Replace with your mobile number
  delay(100);
  Serial.write(0x0D); // Carriage return
  Serial.write(0x0A); // New line
  delay(1000);
  Serial.print("Emergency: http://maps.google.com/maps?q="); // Message content
  Serial.print(latitude, 6); // Include latitude in message
  Serial.print("+");
  Serial.print(longitude, 6); // Include longitude in message
  delay(1000);
  Serial.write(0x1A); // Send Ctrl+Z to indicate end of message
  delay(1000);
}
