#include <DmxMaster.h>
#include <NewPing.h>


// input and output pins
int scentyPin = 8; // closes circuit on transistor
int buttonPress = 12; // button to affect scentyPin write state
int buttonState = 0; // button state for checking if pressed

int dmx_[]_

int rgbMode = 218; //dmx channel
int red = 6; // dmx channel for red
int green = 7; // dmx channel for green
int blue = 8; // dmx channel for

int x; // change for debugging

boolean closeEnough = false; // bool for running DMX/Scenty block

int brighten; // number that will grow for dmx fade in
int dim; // number that will shink for dmx fade out



void setup() {

  Serial.begin(9600);

  pinMode(scentyPin, OUTPUT); //set scentyPin as an output
  pinMode(buttonPress, INPUT); // set buttonPress pin as an input

  DmxMaster.usePin(3); // set pin for DMX shield
  DmxMaster.maxChannel(4); // max number of channels for dmx

2
}



////////////////// BLOCKS FOR DMX ////////////////////////////////////


//run this if the sensor has been triggered
void isClose () {

  DmxMaster.write(5, rgbMode);
  DmxMaster.write(red, 255);
  DmxMaster.write(green, 0);
  DmxMaster.write(blue, 0);
  delay(100);

  DmxMaster.write(5, rgbMode);
  DmxMaster.write(red, 0);
  DmxMaster.write(green, 255);
  DmxMaster.write(blue, 0);
  delay(100);

  DmxMaster.write(5, rgbMode);
  DmxMaster.write(red, 0);
  DmxMaster.write(green, 0);
  DmxMaster.write(blue, 255);
  delay(100);

  DmxMaster.write(5, rgbMode);
  DmxMaster.write(red, 0);
  DmxMaster.write(green, 0);
  DmxMaster.write(blue, 0);
  delay(50);


  // loop to ramp up 'brighten'
  for (brighten = 0; brighten <= 255; brighten++) {

    //DmxMaster.write([channel],[value]);
    DmxMaster.write(5, rgbMode);
    DmxMaster.write(red, brighten);
    DmxMaster.write(green, brighten);
    DmxMaster.write(blue, brighten);
    /* Small delay to slow down the ramping */
    delay(5);

  }

  delay(5000); // wait 5 seconds

  // loop to ramp down 'dim'
  for (dim = 0; dim <= 255; dim++) {

    //DmxMaster.write([channel],[value]);
    DmxMaster.write(5, rgbMode);
    DmxMaster.write(red, 255 - dim);
    DmxMaster.write(green, 255 - dim);
    DmxMaster.write(blue, 255 - dim);
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
    DmxMaster.write(5, rgbMode);
    DmxMaster.write(red, 0);
    DmxMaster.write(green, 0);
    DmxMaster.write(blue, 0);
  }

}
