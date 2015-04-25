#include <DmxMaster.h>
#include <NewPing.h>


// input and output pins
int scentyPin = 8; // closes circuit on transistor
int buttonPress = 12; // button to affect scentyPin write state
int buttonState = 0; // button state for checking if pressed



//int rgbMode = 218; //dmx channel
//int red = 6; // dmx channel for red
//int green = 7; // dmx channel for green
//int blue = 8; // dmx channel for

int x; // change for debugging

boolean closeEnough = false; // bool for running DMX/Scenty block

int brighten; // number that will grow for dmx fade in
int dim; // number that will shink for dmx fade out

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

   for (brighten = 0; brighten <= 255; brighten++) {
    
    Serial.print("brighten = ");
    Serial.println(brighten);

    //DmxMaster.write([channel],[value]);
    DmxMaster.write(fix_1_red, brighten);
    DmxMaster.write(fix_1_green, brighten);
    DmxMaster.write(fix_1_blue, brighten);
    DmxMaster.write(fix_1_white, brighten);
    DmxMaster.write(fix_1_amber, brighten);
    DmxMaster.write(fix_1_uv, brighten);

    DmxMaster.write(fix_2_red, 80-brighten);
    DmxMaster.write(fix_2_green, 80-brighten);
    DmxMaster.write(fix_2_blue, 80-brighten);
    DmxMaster.write(fix_2_white, 80-brighten);
    DmxMaster.write(fix_2_amber, 80-brighten);
    DmxMaster.write(fix_2_uv, 80-brighten); 
    
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
  
    for (dim = 0; dim <= 255; dim++) {
      
      Serial.print("dim = ");
      Serial.println(dim);

   // DmxMaster.write([channel],[value]);
    DmxMaster.write(fix_1_red, 255-dim);
    DmxMaster.write(fix_1_green, 255-dim);
    DmxMaster.write(fix_1_blue, 255-dim);
    DmxMaster.write(fix_1_white, 180-dim);
    DmxMaster.write(fix_1_amber, 255-dim);
    DmxMaster.write(fix_1_uv, 255-dim);
    
    DmxMaster.write(fix_2_red, 170-dim);
    DmxMaster.write(fix_2_green, 170-dim);
    DmxMaster.write(fix_2_blue, 170-dim);
    DmxMaster.write(fix_2_white, 170-dim);
    DmxMaster.write(fix_2_amber, 170-dim);
    DmxMaster.write(fix_2_uv, 170-dim);
    
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

  unsigned int uS = sonar.ping_in(); // Send ping, get ping time in microseconds (uS).


  Serial.println(x); // read for debugging changed in below statements

  // press button go scenty
  if (buttonState == HIGH) {
    digitalWrite(scentyPin, HIGH);
    x = 1;
  }

  //if button isn't pressed no scenty
  else {
    digitalWrite(scentyPin, LOW);
    x = 0;
  }
  
   if (uS < 50 ) {

    closeEnough = true;

  }

  else {

    closeEnough = false;

  }

  if (closeEnough == true) {

      isClose();

  }
  else {

  //DmxMaster.write([channel],[value]);
    DmxMaster.write(fix_1_red, 0);
    DmxMaster.write(fix_1_green, 0);
    DmxMaster.write(fix_1_blue, 0);
    DmxMaster.write(fix_1_white, 180);
    DmxMaster.write(fix_1_amber, 255);
    DmxMaster.write(fix_1_uv, 0);

    DmxMaster.write(fix_2_red, 0);
    DmxMaster.write(fix_2_green, 0);
    DmxMaster.write(fix_2_blue, 0);
    DmxMaster.write(fix_2_white, 180);
    DmxMaster.write(fix_2_amber, 255);
    DmxMaster.write(fix_2_uv, 0);
  }

}
