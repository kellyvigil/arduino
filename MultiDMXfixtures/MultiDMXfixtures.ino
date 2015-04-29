/* Welcome to DmxMaster. This library allows you to control DMX stage and
** architectural lighting and visual effects easily from Arduino. DmxMaster
** is compatible with the Tinker.it! DMX shield and all known DIY Arduino
** DMX control circuits.
**
** DmxMaster is available from: http:code.google.com/p/tinkerit/
** Help and support: http:groups.google.com/group/DmxMaster */

/* To use DmxMaster, you will need the following line. Arduino will
** auto-insert it if you select Sketch > Import Library > DmxMaster. */

#include <DmxMaster.h>
//#include <NewPing.h>



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

int fix_3_red = 13;
int fix_3_green = 14;
int fix_3_blue = 15;
int fix_3_white = 16;
int fix_3_amber = 17;
int fix_3_uv = 18;

int fix_4_red = 19;
int fix_4_green = 20;
int fix_4_blue = 21;
int fix_4_white = 22;
int fix_4_amber = 23;
int fix_4_uv = 24;

int brighten;
int dim;

float dmxLevelUp;
float dmxLevelDown;

int r = 255;
int g = 127;
int b = 120;
int w = 100;
int a = 202;
int u = 100;



int red;
int green;
int blue;
int amber;
int white;
int uv;


void setup() {
  /* The most common pin for DMX output is pin 3, which DmxMaster
  ** uses by default. If you need to change that, do it here. */
  DmxMaster.usePin(3);

  /* DMX devices typically need to receive a complete set of channels
  ** even if you only need to adjust the first channel. You can
  ** easily change the number of channels sent here. If you don't
  ** do this, DmxMaster will set the maximum channel number to the
  ** highest channel you DmxMaster.write() to. */
  DmxMaster.maxChannel(24);

  Serial.begin (57600);
}


void loop() {



  for (dmxLevelUp = 0; dmxLevelUp <= 1.0; dmxLevelUp += .01) {


     red = (int) (dmxLevelUp*r);
     green = (int) (dmxLevelUp*g);
     blue = (int) (dmxLevelUp*b);
     white = (int) (dmxLevelUp*w);
//     amber = (int) (dmxLevelUp*a);
//     uv = (int) (dmxLevelUp*u);

    Serial.print("dmxLevelUp = ");
    Serial.print(dmxLevelUp);
    Serial.print("  ||  red = ");
    Serial.print(red);
    Serial.print("  ||  green = ");
    Serial.print(green);
    Serial.print("  ||  blue = ");
    Serial.print(blue);
    Serial.print("  ||  white = ");
    Serial.print(white);
//    Serial.print("  ||  amber = ");
//    Serial.print(amber);
//    Serial.print("  ||  uv = ");
//    Serial.println(uv);
    


    DmxMaster.write(fix_1_red, red);
    DmxMaster.write(fix_1_green, green);
    DmxMaster.write(fix_1_blue, blue);
    DmxMaster.write(fix_1_white, white);
//    DmxMaster.write(fix_1_amber, amber);
//    DmxMaster.write(fix_1_uv, uv);

    DmxMaster.write(fix_2_red, red);
    DmxMaster.write(fix_2_green, green);
    DmxMaster.write(fix_2_blue, blue);
    DmxMaster.write(fix_2_white, white);
//    DmxMaster.write(fix_2_amber, amber);
//    DmxMaster.write(fix_2_uv, uv);

  }

  for (dmxLevelDown = 1; dmxLevelDown >= 0; dmxLevelDown -= .01) {
    
     red = (int) (dmxLevelDown*r);
     green = (int) (dmxLevelDown*g);
     blue = (int) (dmxLevelDown*b);
     white = (int) (dmxLevelDown*w);
//     amber = (int) (dmxLevelDown*a);
//     uv = (int) (dmxLevelDown*u);
     
    Serial.print("dmxLevelDown = ");
    Serial.print(dmxLevelDown);
    Serial.print("  ||  red = ");
    Serial.print(red);
    Serial.print("  ||  green = ");
    Serial.print(green);
    Serial.print("  ||  blue = ");
    Serial.print(blue);
    Serial.print("  ||  white = ");
    Serial.print(white);
//    Serial.print("  ||  amber = ");
//    Serial.print(amber);
//    Serial.print("  ||  uv = ");
//    Serial.println(uv);
    
     

    DmxMaster.write(fix_1_red, red);
    DmxMaster.write(fix_1_green, blue);
    DmxMaster.write(fix_1_blue, green);
    DmxMaster.write(fix_1_white, white);
//    DmxMaster.write(fix_1_amber, amber);
//    DmxMaster.write(fix_1_uv, uv);

    DmxMaster.write(fix_2_red, red);
    DmxMaster.write(fix_2_green, blue);
    DmxMaster.write(fix_2_blue, green);
    DmxMaster.write(fix_2_white, white);
//    DmxMaster.write(fix_2_amber, amber);
//    DmxMaster.write(fix_2_uv, uv);

  }








  //******************** FOR LOOP UP DOWN INTERGERS ********************


  /*
    // Simple loop to ramp up brighten
    for (brighten = 0; brighten <= 255; brighten++) {

      Serial.print("brighten = ");
      Serial.println(brighten);

      //DmxMaster.write([channel],[value]);
      //DmxMaster.write(1, rgbMode);
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
      // Small delay to slow down the ramping
      delay(5);



    }

    delay(2000);

      for (dim = 255; dim >= 0; dim--) {

        Serial.print("dim = ");
        Serial.println(dim);

      //DmxMaster.write([channel],[value]);
      //DmxMaster.write(1, rgbMode);
      DmxMaster.write(fix_1_red, dim);
      DmxMaster.write(fix_1_green, dim);
      DmxMaster.write(fix_1_blue, dim);
      DmxMaster.write(fix_1_white, dim);
      DmxMaster.write(fix_1_amber, dim);
      DmxMaster.write(fix_1_uv, dim);

      DmxMaster.write(fix_2_red, dim);
      DmxMaster.write(fix_2_green, dim);
      DmxMaster.write(fix_2_blue, dim);
      DmxMaster.write(fix_2_white, dim);
      DmxMaster.write(fix_2_amber, dim);
      DmxMaster.write(fix_2_uv, dim);

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
     //Small delay to slow down the ramping
    delay(5);


   }

   delay(2000);
  */

}

