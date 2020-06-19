
// ================================== loop() ==================================
void loop() {
  static int lastState;                        //Just send changed states
  if (digitalRead(pirPin) == HIGH) {    //check if the sensor is HIGH
    digitalWrite(ledPin, HIGH);         //turn LED ON

    if (lastState == 0) {
      lastState = 1;
      Serial.println("Motion detected!");
      client.publish(pirTopic, "on");
      delay(100);                         //delay 100 milliseconds
    }

  }
  else {
    digitalWrite(ledPin, LOW);          //turn LED OFF
    if (lastState == 1) {
      lastState = 0;
      Serial.println("Motion stopped!");
      client.publish(pirTopic, "off");
      delay(100);                         //delay 100 milliseconds
    }
  }

  //Make sure we stay connected to the mqtt broker
  if (!client.connected()) {
    mqttConnect();
  }
  if (!client.loop()) {
    client.connect(connectName);
  }
}
