#include <DmxMaster.h>
#include <NewPing.h>


// input and output pins
#define scentyPin     8 // closes circuit on transistor
#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     10  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define buttonPress  12 // button to affect scentyPin write state

int buttonState = 0; // button state for checking if pressed

#define MAX_uSANCE 400 // Maximum uSance we want to ping for (in centimeters). Maximum sensor uSance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_uSANCE); // NewPing setup of pins and maximum uSance.


//int rgbMode = 218; //dmx channel
//int red = 6; // dmx channel for red
//int green = 7; // dmx channel for green
//int blue = 8; // dmx channel for

int x; // change for debugging

boolean closeEnough = false; // bool for running DMX/Scenty block

int brighten = 0; // number that will grow for dmx fade in
int dim = 0; // number that will shink for dmx fade out

//dmx fixtures + channels per fixtures
int fix_1_red = 1;
int fix_1_green = 2;
int fix_1_blue = 3;
int fix_1_white = 4;
int fix_1_amber = 5;
int fix_1_uv = 6;

int fix_2_red = 7;
int fix_2_green = 8;
int fix_2_blue = 9;
int fix_2_white = 10;
int fix_2_amber = 11;
int fix_2_uv = 12;



void setup() {

  Serial.begin(9600);

  pinMode(scentyPin, OUTPUT); //set scentyPin as an output
  pinMode(buttonPress, INPUT); // set buttonPress pin as an input

  DmxMaster.usePin(3); // set pin for DMX shield
  DmxMaster.maxChannel(12); // max number of channels for dmx

}



////////////////// BLOCKS FOR DMX ////////////////////////////////////


//run this if the sensor has been triggered
void isClose () {

   for (brighten = 10; brighten < 255; brighten++) {
    
    Serial.print("brighten = ");
    Serial.println(brighten);

    //DmxMaster.write([channel],[value]);
    DmxMaster.write(fix_1_red, brighten);
    DmxMaster.write(fix_1_green, brighten);
    DmxMaster.write(fix_1_blue, brighten);
    DmxMaster.write(fix_1_white, brighten);
    DmxMaster.write(fix_1_amber, brighten);
    DmxMaster.write(fix_1_uv, brighten);

    DmxMaster.write(fix_2_red, brighten);
    DmxMaster.write(fix_2_green, brighten);
    DmxMaster.write(fix_2_blue, brighten);
    DmxMaster.write(fix_2_white, brighten);
    DmxMaster.write(fix_2_amber, brighten);
    DmxMaster.write(fix_2_uv, brighten); 
    
//    DmxMaster.write(fix_3_red, 170-brighten);
//    DmxMaster.write(fix_3_green, 170-brighten);
//    DmxMaster.write(fix_3_blue, 170-brighten);
//    DmxMaster.write(fix_3_white, 170-brighten);
//    DmxMaster.write(fix_3_amber, 170-brighten);
//    DmxMaster.write(fix_3_uv, 170-brighten);
//
//    DmxMaster.write(fix_4_red, 255-brighten);
//    DmxMaster.write(fix_4_green, 255-brighten);
//    DmxMaster.write(fix_4_blue, 255-brighten);
//    DmxMaster.write(fix_4_white, 180-brighten);
//    DmxMaster.write(fix_4_amber, 255-brighten);
//    DmxMaster.write(fix_4_uv, 255-brighten);     
    /* Small delay to slow down the ramping */
    delay(5);

  }
  
  delay(5000);
  
    for (brighten = 255; dim > 10; dim--) {
      
      Serial.print("dim = ");
      Serial.println(dim);

   // DmxMaster.write([channel],[value]);
    DmxMaster.write(fix_1_red, 255-dim);
    DmxMaster.write(fix_1_green, 255-dim);
    DmxMaster.write(fix_1_blue, 255-dim);
    DmxMaster.write(fix_1_white, 255-dim);
    DmxMaster.write(fix_1_amber, 255-dim);
    DmxMaster.write(fix_1_uv, 255-dim);
    
    DmxMaster.write(fix_2_red, 255-dim);
    DmxMaster.write(fix_2_green, 255-dim);
    DmxMaster.write(fix_2_blue, 255-dim);
    DmxMaster.write(fix_2_white, 255-dim);
    DmxMaster.write(fix_2_amber, 255-dim);
    DmxMaster.write(fix_2_uv, 255-dim);
    
//    DmxMaster.write(fix_3_red, 80-dim);
//    DmxMaster.write(fix_3_green, 80-dim);
//    DmxMaster.write(fix_3_blue, 80-dim);
//    DmxMaster.write(fix_3_white, 80-dim);
//    DmxMaster.write(fix_3_amber, 80-dim);
//    DmxMaster.write(fix_3_uv, 80-dim);
//    
//    DmxMaster.write(fix_4_red, dim);
//    DmxMaster.write(fix_4_green, dim);
//    DmxMaster.write(fix_4_blue, dim);
//    DmxMaster.write(fix_4_white, dim);
//    DmxMaster.write(fix_4_amber, dim);
//    DmxMaster.write(fix_4_uv, dim);
   /* Small delay to slow down the ramping */
    delay(5);
   

 }


  closeEnough = false;

}

void loop() {

  buttonState = digitalRead(buttonPress); // look at the read of buttonPress and call it buttonState

  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.

 // unsigned int uS = sonar.ping_in(); // Send ping, get ping time in microseconds (uS).


  Serial.println(x); // read for debugging changed in below statements

  // press button go scenty
  if (buttonState == HIGH) {
    digitalWrite(scentyPin, HIGH);
    x = 1;
    
    closeEnough = true;
  }

  //if button isn't pressed no scenty
  else {
    digitalWrite(scentyPin, LOW);
    x = 0;
    closeEnough = false;
  }
  
/*   if (uS < 50 ) {

    closeEnough = true;

  }

  else {

    closeEnough = false;

  }
*/
  if (closeEnough == true) {

      isClose();

  }
  else {


  //DmxMaster.write([channel],[value]);
    DmxMaster.write(fix_1_red, 10);
    DmxMaster.write(fix_1_green, 10);
    DmxMaster.write(fix_1_blue, 10);
    DmxMaster.write(fix_1_white, 10);
    DmxMaster.write(fix_1_amber, 10);
    DmxMaster.write(fix_1_uv, 10);

    DmxMaster.write(fix_2_red, 10);
    DmxMaster.write(fix_2_green, 10);
    DmxMaster.write(fix_2_blue, 10);
    DmxMaster.write(fix_2_white, 10);
    DmxMaster.write(fix_2_amber, 10);
    DmxMaster.write(fix_2_uv, 10);
  }

}
