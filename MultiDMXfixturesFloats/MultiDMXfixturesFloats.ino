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

// define each fixture by channel

// Strip Light 1
int fix_1_red = 1;
int fix_1_green = 2;
int fix_1_blue = 3;
int fix_1_amber = 4;
int fix_1_white = 5;
int fix_1_ints = 6;

// Strip Light 1
int fix_2_red = 7;
int fix_2_green = 8;
int fix_2_blue = 9;
int fix_2_amber = 10;
int fix_2_white = 11;
int fix_2_ints = 12;

// Par Light 1
int fix_3_red = 13;
int fix_3_green = 14;
int fix_3_blue = 15;
int fix_3_white = 16;
int fix_3_amber = 17;
int fix_3_uv = 18;

// Par Light 2
int fix_4_red = 19;
int fix_4_green = 20;
int fix_4_blue = 21;
int fix_4_white = 22;
int fix_4_amber = 23;
int fix_4_uv = 24;

// for-loop floats

float dmxLevelUp;
float dmxLevelDown;

// for-loop multipliers

int brighten;
int dim;

//output color assignments

int red_A;
int green_A;
int blue_A;
int amber_A;
int white_A;
int ints_A;
int uv_A;

int red_B;
int green_B;
int blue_B;
int amber_B;
int white_B;
int ints_B;
int uv_B;

//color values

//color_A
int r_A = 255;
int g_A = 255;
int b_A = 255;
int a_A = 0;
int w_A = 255;
int i_A = 0;
int u_A = 0;

//color_B
int r_B = 0;
int g_B = 0;
int b_B = 0;
int a_B = 212;
int w_B = 121;
int i_B = 0;
int u_B = 0;

//color diffs

int r_diff = (r_A - r_B);
int g_diff = (g_A - g_B);
int b_diff = (b_A - b_B);
int a_diff = (a_B - a_A);
int w_diff = (w_A - w_B);
int i_diff = (i_A - i_B);
int u_diff = (u_A - u_B);

int comb_r;
int comb_g;
int comb_b;
int comb_a;
int comb_w;
int comb_u;



//fade controlls
float loopSpeed = .005; //increase amount <--- use this to control rate of fade up and down
int delaySpeed = 5; //ms


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



//////////////////////////////// PRINT INITIALIZED COLOR VALUES /////////////////////////////




void printInitialColors() {
  Serial.print(" | r_A: ");
  Serial.print(r_A);
  Serial.print(" | g_A: ");
  Serial.print(g_A);
  Serial.print(" | b_A: ");
  Serial.print(b_A);
  Serial.print(" | w_A: ");
  Serial.print(w_A);
  Serial.print(" | a_A: = ");
  Serial.print(a_A);

  //color_B print
  Serial.print(" | r_B: ");
  Serial.print(r_B);
  Serial.print(" | g_B: ");
  Serial.print(g_B);
  Serial.print(" | b_B: ");
  Serial.print(b_B);
  Serial.print(" | w_B: ");
  Serial.print(w_B);
  Serial.print(" | a_B: ");
  Serial.println(a_B);

}





//////////////////////////////// PRINT CALCULATED COLOR VALUES /////////////////////////////




void printColors() {

  Serial.print(" | red_A: ");
  Serial.print(red_A);
  Serial.print(" | green_A: ");
  Serial.print(green_A);
  Serial.print(" | blue_A: ");
  Serial.print(blue_A);
  Serial.print(" | white_A: ");
  Serial.print(white_A);
  Serial.print(" | amber_A: = ");
  Serial.print(amber_A);

  //color_B print
  Serial.print(" | red_B: ");
  Serial.print(red_B);
  Serial.print(" | green_B: ");
  Serial.print(green_B);
  Serial.print(" | blue_B: ");
  Serial.print(blue_B);
  Serial.print(" | white_B: ");
  Serial.print(white_B);
  Serial.print(" | amber_B: ");
  Serial.println(amber_B);

}



//////////////////////////////// PRINT COMBINATION COLORS //////////////////////




void printCombColors() {


  Serial.print(" comb_r: ");
  Serial.print(comb_r);
  Serial.print(" comb_g: ");
  Serial.print(comb_g);
  Serial.print(" comb_b: ");
  Serial.print(comb_b);
  Serial.print(" comb_w: ");
  Serial.print(comb_w);
  Serial.print(" comb_a: ");
  Serial.println(comb_a);



}




//////////////////////////////// STATIC COLORS ////////////////////////////////

void staticColors() {



  // Fixture 1 values
  DmxMaster.write(fix_1_red, r_A);
  DmxMaster.write(fix_1_green, g_A);
  DmxMaster.write(fix_1_blue, b_A);
  DmxMaster.write(fix_1_amber, a_A);
  DmxMaster.write(fix_1_white, w_A);
  DmxMaster.write(fix_1_ints, i_A);

  // Fixture 2 values
  DmxMaster.write(fix_2_red, r_B);
  DmxMaster.write(fix_2_green, g_B);
  DmxMaster.write(fix_2_blue, b_B);
  DmxMaster.write(fix_2_amber, a_B);
  DmxMaster.write(fix_2_white, w_B);
  DmxMaster.write(fix_2_ints, i_B);

  // Fixture 3 values
  DmxMaster.write(fix_3_red, r_A);
  DmxMaster.write(fix_3_green, g_A);
  DmxMaster.write(fix_3_blue, b_A);
  DmxMaster.write(fix_3_amber, a_A);
  DmxMaster.write(fix_3_white, w_A);
  //DmxMaster.write(fix_3_ints, i_A);

  // Fixture 4 values
  DmxMaster.write(fix_4_red, r_B);
  DmxMaster.write(fix_4_green, g_B);
  DmxMaster.write(fix_4_blue, b_B);
  DmxMaster.write(fix_4_amber, a_B);
  DmxMaster.write(fix_4_white, w_B);
  //DmxMaster.write(fix_4_ints, i_B);


}







//////////////////////////////// FADE UP THEN DOWN /////////////////////////////







void fadeUpDown() {

  Serial.println("running fadeUpDown");

  for (dmxLevelUp = 0; dmxLevelUp <= 1.0; dmxLevelUp += loopSpeed) {

    //color_A
    red_A = (int) (dmxLevelUp * r_A);
    green_A = (int) (dmxLevelUp * g_A);
    blue_A = (int) (dmxLevelUp * b_A);
    white_A = (int) (dmxLevelUp * w_A);
    amber_A = (int) (dmxLevelUp * a_A);
    ints_A = (int)(dmxLevelUp * i_A);
    uv_A = (int) (dmxLevelUp * u_A);

    //color_B
    red_B = (int) (dmxLevelUp * r_B);
    green_B = (int) (dmxLevelUp * g_B);
    blue_B = (int) (dmxLevelUp * b_B);
    white_B = (int) (dmxLevelUp * w_B);
    amber_B = (int) (dmxLevelUp * a_B);
    ints_B = (int)(dmxLevelUp * i_B);
    uv_B = (int) (dmxLevelUp * u_B);

    Serial.print("dmxLevelUp = ");
    Serial.print(dmxLevelUp);


    printColors();



    // Fixture 1 values
    DmxMaster.write(fix_1_red, red_A);
    DmxMaster.write(fix_1_green, green_A);
    DmxMaster.write(fix_1_blue, blue_A);
    DmxMaster.write(fix_1_amber, amber_A);
    DmxMaster.write(fix_1_white, white_A);
    DmxMaster.write(fix_1_ints, ints_A);

    // Fixture 2 values
    DmxMaster.write(fix_2_red, red_A);
    DmxMaster.write(fix_2_green, green_A);
    DmxMaster.write(fix_2_blue, blue_A);
    DmxMaster.write(fix_2_amber, amber_A);
    DmxMaster.write(fix_2_white, white_A);
    DmxMaster.write(fix_2_ints, ints_A);

    // Fixture 3 values
    DmxMaster.write(fix_3_red, red_A);
    DmxMaster.write(fix_3_green, green_A);
    DmxMaster.write(fix_3_blue, blue_A);
    DmxMaster.write(fix_3_white, white_A);
    DmxMaster.write(fix_3_amber, amber_A);
    DmxMaster.write(fix_3_uv, uv_A);

    // Fixture 4 values
    DmxMaster.write(fix_4_red, red_A);
    DmxMaster.write(fix_4_green, blue_A);
    DmxMaster.write(fix_4_blue, green_A);
    DmxMaster.write(fix_4_white, white_A);
    DmxMaster.write(fix_4_amber, amber_A);
    DmxMaster.write(fix_4_uv, uv_A);

    delay(delaySpeed);

  }

  delay(2000);

  for (dmxLevelDown = 1; dmxLevelDown >= 0; dmxLevelDown -= loopSpeed) {


    red_A = (int) (dmxLevelDown * r_A);
    green_A = (int) (dmxLevelDown * g_A);
    blue_A = (int) (dmxLevelDown * b_A);
    white_A = (int) (dmxLevelDown * w_A);
    amber_A = (int) (dmxLevelDown * a_A);
    ints_A = (int)(dmxLevelDown * i_A);
    uv_A = (int) (dmxLevelDown * u_A);

    red_B = (int) (dmxLevelDown * r_B);
    green_B = (int) (dmxLevelDown * g_B);
    blue_B = (int) (dmxLevelDown * b_B);
    white_B = (int) (dmxLevelDown * w_B);
    amber_B = (int) (dmxLevelDown * a_B);
    ints_B = (int)(dmxLevelDown * i_B);
    uv_B = (int) (dmxLevelDown * u_B);


    Serial.print("dmxLevelDown = ");
    Serial.print(dmxLevelDown);


    printColors();


    // Fixture 1 values
    DmxMaster.write(fix_1_red, red_A);
    DmxMaster.write(fix_1_green, green_A);
    DmxMaster.write(fix_1_blue, blue_A);
    DmxMaster.write(fix_1_amber, amber_A);
    DmxMaster.write(fix_1_white, white_A);

    // Fixture 2 values
    DmxMaster.write(fix_2_red, red_A);
    DmxMaster.write(fix_2_green, green_A);
    DmxMaster.write(fix_2_blue, blue_A);
    DmxMaster.write(fix_2_amber, amber_A);
    DmxMaster.write(fix_2_white, white_A);

    // Fixture 3 values
    DmxMaster.write(fix_3_red, red_A);
    DmxMaster.write(fix_3_green, green_A);
    DmxMaster.write(fix_3_blue, blue_A);
    DmxMaster.write(fix_3_white, white_A);
    DmxMaster.write(fix_3_amber, amber_A);
    DmxMaster.write(fix_3_uv, uv_A);

    // Fixture 4 values
    DmxMaster.write(fix_4_red, red_A);
    DmxMaster.write(fix_4_green, blue_A);
    DmxMaster.write(fix_4_blue, green_A);
    DmxMaster.write(fix_4_white, white_A);
    DmxMaster.write(fix_4_amber, amber_A);
    DmxMaster.write(fix_4_uv, uv_A);
    delay(delaySpeed);

  }

  delay(2000);


}



//////////////////////////////// FADE BETWEEN COLORS ///////////////////////////





void fadeBetween() {

  // Fixture 1 values
  DmxMaster.write(fix_1_red, r_A);
  DmxMaster.write(fix_1_green, g_A);
  DmxMaster.write(fix_1_blue, b_A);
  DmxMaster.write(fix_1_amber, a_A);
  DmxMaster.write(fix_1_white, w_A);


  Serial.println("colors set");

  delay(1000);



  Serial.println("running fadeBetween");



  //fade up
  for (dmxLevelUp = 0; dmxLevelUp <= 1.0; dmxLevelUp += loopSpeed) {

    //color_A
    red_A = (int) (dmxLevelUp * r_diff);
    green_A = (int) (dmxLevelUp * g_diff);
    blue_A = (int) (dmxLevelUp * b_diff);
    white_A = (int) (dmxLevelUp * w_diff);
    amber_A = (int) (dmxLevelUp * a_diff);


    comb_r = (r_A - red_A);
    comb_g = (g_A + green_A);
    comb_b = (b_A - blue_A);
    comb_w = (w_A + white_A);
    comb_a = (a_A + amber_A);


    //color_A print
    Serial.print("dmxLevelUp = ");
    Serial.print(dmxLevelUp);


    // Fixture 1 values
    DmxMaster.write(fix_1_red, comb_r);
    DmxMaster.write(fix_1_green, comb_g);
    DmxMaster.write(fix_1_blue, comb_b);
    DmxMaster.write(fix_1_amber, comb_a);
    DmxMaster.write(fix_1_white, comb_w);


    //Fixture 2 values
    DmxMaster.write(fix_2_red, comb_r);
    DmxMaster.write(fix_2_green, comb_g);
    DmxMaster.write(fix_2_blue, comb_b);
    DmxMaster.write(fix_2_amber, comb_a);
    DmxMaster.write(fix_2_white, comb_w);


    // Fixture 3 values
    DmxMaster.write(fix_3_red, comb_r);
    DmxMaster.write(fix_3_green, comb_g);
    DmxMaster.write(fix_3_blue, comb_b);
    DmxMaster.write(fix_3_white, comb_w);
    DmxMaster.write(fix_3_amber, comb_a);


    // Fixture 4 values
    DmxMaster.write(fix_4_red, comb_r);
    DmxMaster.write(fix_4_green, comb_g);
    DmxMaster.write(fix_4_blue, comb_b);
    DmxMaster.write(fix_4_white, comb_w);
    DmxMaster.write(fix_4_amber, comb_a);


    printCombColors();

    delay(delaySpeed);

  }

  //  delay(2000);
  //
  //     // Fixture 1 values
  //    DmxMaster.write(fix_1_red, r_B);
  //    DmxMaster.write(fix_1_green, g_B);
  //    DmxMaster.write(fix_1_blue, b_B);
  //    DmxMaster.write(fix_1_amber, a_B);
  //    DmxMaster.write(fix_1_white, w_B);
  //    DmxMaster.write(fix_1_ints, i_B);
  //
  //
  //    Serial.println("colors set");
  //
  //    delay(2000);


  //fade down
  for (dmxLevelDown = 0; dmxLevelDown <= 1; dmxLevelDown += loopSpeed) {

    //color_A
    red_A = (int) (dmxLevelDown * r_diff);
    green_A = (int) (dmxLevelDown * g_diff);
    blue_A = (int) (dmxLevelDown * b_diff);
    white_A = (int) (dmxLevelDown * w_diff);
    amber_A = (int) (dmxLevelDown * a_diff);
    ints_A = (int)(dmxLevelDown * i_diff);
    uv_A = (int) (dmxLevelDown * u_diff);

    //tested
    comb_r = (r_B + red_A);
    comb_g = (g_B - green_A);
    comb_b = (b_B + blue_A);
    comb_w = (w_B - white_A);
    comb_a = (a_B - amber_A);
    comb_u = (u_B - uv_A);




    //color_A print
    Serial.print("dmxLevelDown = ");
    Serial.print(dmxLevelDown);



    // Fixture 1 values
    DmxMaster.write(fix_1_red, comb_r);
    DmxMaster.write(fix_1_green, comb_g);
    DmxMaster.write(fix_1_blue, comb_b);
    DmxMaster.write(fix_1_amber, comb_a);
    DmxMaster.write(fix_1_white, comb_w);


    //Fixture 1 values
    DmxMaster.write(fix_2_red, comb_r);
    DmxMaster.write(fix_2_green, comb_g);
    DmxMaster.write(fix_2_blue, comb_b);
    DmxMaster.write(fix_2_amber, comb_a);
    DmxMaster.write(fix_2_white, comb_w);


    // Fixture 1 values
    DmxMaster.write(fix_3_red, comb_r);
    DmxMaster.write(fix_3_green, comb_g);
    DmxMaster.write(fix_3_blue, comb_b);
    DmxMaster.write(fix_3_white, comb_w);
    DmxMaster.write(fix_3_amber, comb_a);


    // Fixture 4 values
    DmxMaster.write(fix_4_red, comb_r);
    DmxMaster.write(fix_4_green, comb_g);
    DmxMaster.write(fix_4_blue, comb_b);
    DmxMaster.write(fix_4_white, comb_w);
    DmxMaster.write(fix_4_amber, comb_a);

    printCombColors();




    delay(delaySpeed);

  }

  delay(2000);


}


void loop() {






  fadeUpDown();




}

