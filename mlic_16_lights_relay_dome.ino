/*
This script is written for the open hardware 16 LED dome that utilizes a 16 relay board and an Arduino MEGA controller.
This script incorporates two major modes of the device: Multi light imaging & constant light
The wiring can be found in the GitHub repository.
Any changes to the wiring need to be accomodated in the script.
Feel free to modify and redistribute this script (attribution appreciated).
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);  // contributes to turn on half of the lights
  pinMode(12, OUTPUT);  // contributes to turn on half of the lights
  pinMode(13, OUTPUT);  // contributes to turn on half of the lights
  pinMode(14, OUTPUT);  // contributes to turn on half of the lights
  pinMode(16, OUTPUT);  // closing the LED power cuircit
  pinMode(15, OUTPUT);  // camera trigger

  pinMode(10, INPUT);      // input for the camera trigger button/cable
  digitalWrite(10, HIGH);  // activating the internal pull up resistor

  pinMode(9, INPUT);
  digitalWrite(9, HIGH);
}


void loop() {

  int camera_trigger_delay = 100; // time the trigger is "pressed"
  // this timing is critical and device specific (100 ms works for a Nikon mirrorless camera)
  // wrongly specified camera_trigger_delay may result in capturing more or less images than intended
  
  int after_camera_trigger_delay = 600; // time the camera has to capture an image
  // this is device and shutterspeed dependent (risk of insufficient illumination)
  
  if (digitalRead(9) == HIGH) {  // HIGH means switch is on 0
    // Turn on half of the LEDs
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);  // upper or lower ring

    digitalWrite(11, LOW);  // connecting switches
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(14, LOW);
    
    digitalWrite(15, HIGH);
    
    digitalWrite(16, LOW);  // close the 3V power cuircit (turn on the light)


  }

  else {
    while (digitalRead(9) == LOW) {

      digitalWrite(16, HIGH);  // make sure that at the start all lights are off
      digitalWrite(11, HIGH);  // open connecting switches
      digitalWrite(12, HIGH);  // open connecting switches
      digitalWrite(13, HIGH);  // open connecting switches
      digitalWrite(14, HIGH);  // open connecting switches


      if (digitalRead(10) == LOW) {
        // MLIC sequence

        // Turn on LED 1
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(8, HIGH);  // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit (turn on the light)

        digitalWrite(15, LOW);  // trigger camera ON
        
        delay(camera_trigger_delay);
        
        digitalWrite(15, HIGH);  // trigger camera OFF
        
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit (turn off the light)

        if (digitalRead(9) == HIGH) { // for faster switching between the MLI and the constant light mode
          break;
        }

        // Turn on LED 2
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(8, HIGH);  // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 3
        digitalWrite(1, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(8, HIGH);  // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 4
        digitalWrite(1, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(5, LOW);
        digitalWrite(8, HIGH);  // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 5
        digitalWrite(1, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(8, HIGH);  // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 6
        digitalWrite(1, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(8, HIGH);  // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 7
        digitalWrite(1, LOW);
        digitalWrite(3, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);  // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 8
        digitalWrite(1, LOW);
        digitalWrite(3, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);  // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 9
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(8, LOW);   // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 10
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(8, LOW);   // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 11
        digitalWrite(1, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(8, LOW);   // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 12
        digitalWrite(1, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(5, LOW);
        digitalWrite(8, LOW);   // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 13
        digitalWrite(1, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(8, LOW);   // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 14
        digitalWrite(1, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(8, LOW);   // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 15
        digitalWrite(1, LOW);
        digitalWrite(3, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);   // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit

        if (digitalRead(9) == HIGH) {
          break;
        }

        // Turn on LED 16
        digitalWrite(1, LOW);
        digitalWrite(3, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);   // upper or lower ring
        digitalWrite(16, LOW);  // close the 3V power cuircit

        digitalWrite(15, LOW);  // trigger camera ON
        delay(camera_trigger_delay);
        digitalWrite(15, HIGH);  // trigger camera OFF
        delay(after_camera_trigger_delay);

        digitalWrite(16, HIGH);  // open the 3V power cuircit
      }
    }
  }
}




// void loop() {

//     // Turn on half of the LEDs
//     digitalWrite(1, HIGH);
//     digitalWrite(2, HIGH);
//     digitalWrite(3, HIGH);
//     digitalWrite(4, HIGH);
//     digitalWrite(5, HIGH);
//     digitalWrite(6, HIGH);
//     digitalWrite(7, HIGH);
//     digitalWrite(8, HIGH);  // upper or lower ring

//     digitalWrite(11, LOW); // connecting switches
//     digitalWrite(12, LOW);
//     digitalWrite(13, LOW);
//     digitalWrite(14, LOW);

//     digitalWrite(16, LOW);  // close the 3V power cuircit

// }





// the loop function runs over and over again forever
// void loop() {

//   int camera_trigger_delay = 200;
//   int after_camera_trigger_delay = 1000;

//   digitalWrite(16, HIGH);

//   if (digitalRead(10) == LOW) {
//     // MLIC sequence

//     // Turn on LED 1
//     digitalWrite(1, HIGH);
//     digitalWrite(2, HIGH);
//     digitalWrite(4, HIGH);
//     digitalWrite(8, HIGH);  // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 2
//     digitalWrite(1, HIGH);
//     digitalWrite(2, HIGH);
//     digitalWrite(4, LOW);
//     digitalWrite(8, HIGH);  // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 3
//     digitalWrite(1, HIGH);
//     digitalWrite(2, LOW);
//     digitalWrite(5, HIGH);
//     digitalWrite(8, HIGH);  // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 4
//     digitalWrite(1, HIGH);
//     digitalWrite(2, LOW);
//     digitalWrite(5, LOW);
//     digitalWrite(8, HIGH);  // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 5
//     digitalWrite(1, LOW);
//     digitalWrite(3, HIGH);
//     digitalWrite(6, HIGH);
//     digitalWrite(8, HIGH);  // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 6
//     digitalWrite(1, LOW);
//     digitalWrite(3, HIGH);
//     digitalWrite(6, LOW);
//     digitalWrite(8, HIGH);  // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 7
//     digitalWrite(1, LOW);
//     digitalWrite(3, LOW);
//     digitalWrite(7, HIGH);
//     digitalWrite(8, HIGH);  // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 8
//     digitalWrite(1, LOW);
//     digitalWrite(3, LOW);
//     digitalWrite(7, LOW);
//     digitalWrite(8, HIGH);  // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 9
//     digitalWrite(1, HIGH);
//     digitalWrite(2, HIGH);
//     digitalWrite(4, HIGH);
//     digitalWrite(8, LOW);   // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 10
//     digitalWrite(1, HIGH);
//     digitalWrite(2, HIGH);
//     digitalWrite(4, LOW);
//     digitalWrite(8, LOW);   // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 11
//     digitalWrite(1, HIGH);
//     digitalWrite(2, LOW);
//     digitalWrite(5, HIGH);
//     digitalWrite(8, LOW);   // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 12
//     digitalWrite(1, HIGH);
//     digitalWrite(2, LOW);
//     digitalWrite(5, LOW);
//     digitalWrite(8, LOW);   // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 13
//     digitalWrite(1, LOW);
//     digitalWrite(3, HIGH);
//     digitalWrite(6, HIGH);
//     digitalWrite(8, LOW);   // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 14
//     digitalWrite(1, LOW);
//     digitalWrite(3, HIGH);
//     digitalWrite(6, LOW);
//     digitalWrite(8, LOW);   // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 15
//     digitalWrite(1, LOW);
//     digitalWrite(3, LOW);
//     digitalWrite(7, HIGH);
//     digitalWrite(8, LOW);   // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit


//     // Turn on LED 16
//     digitalWrite(1, LOW);
//     digitalWrite(3, LOW);
//     digitalWrite(7, LOW);
//     digitalWrite(8, LOW);   // upper or lower ring
//     digitalWrite(16, LOW);  // close the 3V power cuircit

//     digitalWrite(15, LOW);  // trigger camera ON
//     delay(camera_trigger_delay);
//     digitalWrite(15, HIGH);  // trigger camera OFF
//     delay(after_camera_trigger_delay);

//     digitalWrite(16, HIGH);  // open the 3V power cuircit
//   }
// }
