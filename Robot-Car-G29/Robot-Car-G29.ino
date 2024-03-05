#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <Wire.h>
#include <Servo.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "ABB_Gym_IOT"
#define WIFI_PASSWORD "Welcome2abb"

// Insert Firebase project API Key
#define API_KEY "AIzaSyBE1C15MxYr7Xcg3gpfnMeiNcpsJnGGmxQ"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://robotic-car-g29-default-rtdb.europe-west1.firebasedatabase.app"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

const int pwmMotorA = D1;
const int dirMotorA = D3;
Servo servo;
int angle = 90;

bool signupOK = false;
int speed = 1023;
int dir = 2;

void setup() {
  Serial.begin(115200);
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

  pinMode(pwmMotorA, OUTPUT);
  pinMode(dirMotorA, OUTPUT);

  Wire.begin();        // Initialize I2C communication
  servo.attach(4);
}

void loop() {
  if (Firebase.RTDB.getInt(&fbdo, "motorSpeed/MotorSpeed")) {
    speed = fbdo.intData();
    // Set the position of the servo based on the retrieved value
  }
  if (Firebase.RTDB.getInt(&fbdo, "servoAngle/servoAngle")) {
    angle = fbdo.intData();
  }
  if (Firebase.RTDB.getInt(&fbdo, "motorDir/MotorDir")) {
    dir = fbdo.intData();

    switch (dir) {
      case 0:  // your hand is on the sensor
        driveBackwards(speed, angle);
        break;
      case 1:  // your hand is close to the sensor
        driveForward(speed, angle);
        break;
      case 2:  // your hand is a few inches from the sensor
        stop();
        break;
    }
    // Set the position of the servo based on the retrieved value
  }
  delay(1);
}

void driveForward(int speed, int angle) {
  Serial.println(speed);

  servo.write(angle);
  analogWrite(pwmMotorA, speed);
  digitalWrite(dirMotorA, LOW);
}

void driveBackwards(int speed, int angle) {
  Serial.println(speed);
  Serial.println(angle);

  servo.write(angle);
  analogWrite(pwmMotorA, speed);
  digitalWrite(dirMotorA, HIGH);
}

void stop() {
  Serial.println("standing still");

  digitalWrite(pwmMotorA, 0);
  digitalWrite(dirMotorA, LOW);
}
