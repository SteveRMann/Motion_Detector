// ================================== setup() ==================================
void setup() {
  pinMode(ledPin, OUTPUT);             //initalize LED as an output
  pinMode(pirPin, INPUT);              //initialize sensor as an input
  Serial.begin(115200);                //initialize serial

  connectWiFi();
  
  // Call the setServer method on the PubSubClient object, passing as first argument the
  // address and as second the port.
  client.setServer(mqttServer, 1883);
  mqttConnect();
}
