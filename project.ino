  // These constants won't change:
        const int analogPin = A0;    // pin that the sensor is attached to
        const int LedBiru = 13;       // pin that the LED is attached to
        const int LedHijau = 12;
        const int LedMerah = 11;
        const int Buzzer = 10;
        const int BatasBawah = 200 ; // an arbitrary threshold level that's in the range of the analoginput
        const int BatasAtas = 550;

        void setup() {
        // initialize the LED pin as an output:
        pinMode(LedMerah, OUTPUT);
        pinMode(LedHijau, OUTPUT) ;
        pinMode(LedBiru, OUTPUT) ;
        pinMode (Buzzer, OUTPUT);
        // initialize serial communications:
        Serial.begin(9600);
        }

        void loop() {
        // read the value of the potentiometer:
        int analogValue = analogRead(analogPin);

        // if the analog value is high enough, turn on the LED:
        if (analogValue < BatasBawah) {
         digitalWrite(LedBiru, HIGH);
        } else {
         digitalWrite(LedBiru, LOW);
        }

        if (analogValue > BatasBawah ) {
        digitalWrite(LedHijau, HIGH);
        } else {
        digitalWrite(LedHijau, LOW);
        }

       if (analogValue > BatasAtas) {
       digitalWrite(LedMerah, HIGH);
       digitalWrite(Buzzer , HIGH);
        digitalWrite(LedHijau, LOW);
   
      } else {
       digitalWrite(LedMerah, LOW);
       digitalWrite(Buzzer , LOW);

      }
      // print the analog value:
      Serial.println(analogValue);
      delay(200);        // delay in between reads for stability
    }
