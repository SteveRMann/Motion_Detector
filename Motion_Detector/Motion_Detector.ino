/*
   Motion_Detector
   This program monitors a PIR motion detector and publishes a
   status on MQTT.
*/

#define hostPrefix "pir-"
#include "D:\River Documents\Arduino\libraries\Kaywinnet.h"  \\ WiFi credentials
#include <ESP8266WiFi.h>        // Connect (and reconnect) an ESP8266 to the a WiFi network.
#include <PubSubClient.h>       // connect to a MQTT broker and publish/subscribe messages in topics.

// Declare an object of class WiFiClient, which allows to establish a connection to a specific IP and port
// Declare an object of class PubSubClient, which receives as input of the constructor the previously defined WiFiClient.
// The constructor MUST be unique on the network.
WiFiClient pirClient;
PubSubClient client(pirClient);



char macBuffer[24];             // Holds the last three digits of the MAC, in hex.
char hostNamePrefix[] = hostPrefix;
char hostName[12];              // Holds hostNamePrefix + the last three bytes of the MAC address.
IPAddress myIP;                 // Holds the IP address
int rssi;

#define NODENAME "motionSensor/studio"
const char *cmndTopic = NODENAME "/cmnd";                   // Incoming commands, payload is a command, such as hangup.
const char *pirTopic = NODENAME "/pir";                     // Topic for PIR status
const char *connectName =  NODENAME "1";                    // Must be unique on the network
const char *mqttServer = mqtt_server;                       // Local broker defined in Kaywinnet.h
const int mqttPort = 1883;


int ledPin = D5;                       //LED
int pirPin = D1;                       //Sensor
