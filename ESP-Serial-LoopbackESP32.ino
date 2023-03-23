// Example for loopback messages from the USB Serial over the Serial2 pins back to USB Serial
void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, 18, 19); // Pins D18 and D19 accoring an ESP32 DEVKITV1
  delay(1000);
  Serial.println("Loopback program started");
}
void loop() {
  if(Serial.available()){
    Serial.write("-");
    Serial2.write(Serial.read());  
  }
  if(Serial2.available()){
    Serial.write(".");
    Serial.write(Serial2.read());  
  }
}
