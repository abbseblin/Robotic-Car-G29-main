#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "Sebastian_iphone"
#define WIFI_PASSWORD "Sebbe101"

#define forwardPin 16
#define reversePin 5
#define VRX_PIN  A0 // Arduino pin connected to VRX pin
int forwardButtonState = 0;
int reverseButtonState = 0;
int xValue = 0; // To store value of the X axis

// Insert Firebase project API Key
#define API_KEY "AIzaSyBE1C15MxYr7Xcg3gpfnMeiNcpsJnGGmxQ"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://robotic-car-g29-default-rtdb.europe-west1.firebasedatabase.app"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

bool signupOK = false;

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  } else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback;  //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  pinMode(forwardPin, INPUT);
  pinMode(reversePin, INPUT);
}

void loop() {
  forwardButtonState = digitalRead(forwardPin);
  Serial.println(forwardButtonState);
  reverseButtonState = digitalRead(reversePin);
  xValue = analogRead(VRX_PIN);
  float xValToDeg = (xValue * 140 / 1023) + 20;


  if(forwardButtonState == 1 && reverseButtonState == 0){
    Serial.println("forward");
    Firebase.RTDB.setInt(&fbdo, "/motorDir/MotorDir", 1);
  }
  if(reverseButtonState == 1 && forwardButtonState == 0){
    Serial.println("reverse");
    Firebase.RTDB.setInt(&fbdo, "/motorDir/MotorDir", 0);
  }  
  if(forwardButtonState != 1 && reverseButtonState != 1){
    Firebase.RTDB.setInt(&fbdo, "/motorDir/MotorDir", 2);
  }
  Firebase.RTDB.setInt(&fbdo, "/servoAngle/servoAngle", xValToDeg);
}
