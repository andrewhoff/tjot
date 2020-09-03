/*

*/

bool blinkOn = false; // for incoming serial data
String received = "";

void setup() {
  // 1 Setup Serial port
  Serial.begin(9600);
    // 2 Set up digital output pin
  pinMode(7, OUTPUT);    // sets the digital pin 7 as output
  digitalWrite(7, LOW);
}

void loop() {
    // check serial output for the string 'blink'
    // toggle digital output pin's state from LOW->HIGH or HIGH->LOW
    
    if (Serial.available() > 0) {
    // read the incoming byte:
      String received = Serial.readString();
      
      Serial.println("received: " + received);
      
      if (received.equals("blink\n")) {
        Serial.println("got a blink!");
        
        if (blinkOn) {
          digitalWrite(7, LOW);
          blinkOn = false;
        } else {
          digitalWrite(7, HIGH);
                    blinkOn = true;
        }
      }
  }
}

