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

//************** ZONE 1 **************


// Strip Light 1
int fix_1_red = 1;
int fix_1_green = 2;
int fix_1_blue = 3;
int fix_1_amber = 4;
int fix_1_white = 5;

// Strip Light 2
int fix_2_red = 6;
int fix_2_green = 7;
int fix_2_blue = 8;
int fix_2_amber = 9;
int fix_2_white = 10;

// Strip Light 3
int fix_3_red = 11;
int fix_3_green = 12;
int fix_3_blue = 13;
int fix_3_amber = 14;
int fix_3_white = 15;

// Strip Light 4
int fix_4_red = 16;
int fix_4_green = 17;
int fix_4_blue = 18;
int fix_4_amber = 19;
int fix_4_white = 20;

// Strip Light 5
int fix_5_red = 21;
int fix_5_green = 22;
int fix_5_blue = 23;
int fix_5_amber = 24;
int fix_5_white = 25;

// Strip Light 6
int fix_6_red = 26;
int fix_6_green = 27;
int fix_6_blue = 28;
int fix_6_amber = 29;
int fix_6_white = 30;

// Strip Light 7
int fix_7_red = 31;
int fix_7_green = 32;
int fix_7_blue = 33;
int fix_7_amber = 34;
int fix_7_white = 35;

// Strip Light 8
int fix_8_red = 36;
int fix_8_green = 37;
int fix_8_blue = 38;
int fix_8_amber = 39;
int fix_8_white = 40;


//************** ZONE 2 **************

// Strip Light 9
int fix_9_red = 41;
int fix_9_green = 42;
int fix_9_blue = 43;
int fix_9_amber = 44;
int fix_9_white = 45;

// Strip Light 10
int fix_10_red = 46;
int fix_10_green = 47;
int fix_10_blue = 48;
int fix_10_amber = 49;
int fix_10_white = 50;

// Strip Light 11
int fix_11_red = 51;
int fix_11_green = 52;
int fix_11_blue = 53;
int fix_11_amber = 54;
int fix_11_white = 55;

// Strip Light 12
int fix_12_red = 56;
int fix_12_green = 57;
int fix_12_blue = 58;
int fix_12_amber = 59;
int fix_12_white = 60;



//************** ZONE 3 **************


//Par Light 13

int fix_13_red = 61;
int fix_13_green = 62;
int fix_13_blue = 63;
int fix_13_white = 64;
int fix_13_amber = 65;
int fix_13_uv = 66;

//Par Light 14

int fix_14_red = 67;
int fix_14_green = 68;
int fix_14_blue = 69;
int fix_14_white = 70;
int fix_14_amber = 71;
int fix_14_uv = 72;


//Par Light 15

int fix_15_red = 73;
int fix_15_green = 74;
int fix_15_blue = 75;
int fix_15_white = 76;
int fix_15_amber = 77;
int fix_15_uv = 78;

//Par Light 16

int fix_16_red = 79;
int fix_16_green = 80;
int fix_16_blue = 81;
int fix_16_white = 82;
int fix_16_amber = 83;
int fix_16_uv = 84;



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
int r_A = 160;
int g_A = 255;
int b_A = 200;
int a_A = 255;
int w_A = 255;
int i_A = 200;
int u_A = 0;

//color_B
int r_B = 240;
int g_B = 255;
int b_B = 255;
int a_B = 255;
int w_B = 255;
int u_B = 0;

//color diffs

int r_diff = (r_A - r_B);
int g_diff = (g_A - g_B);
int b_diff = (b_A - b_B);
int a_diff = (a_B - a_A);
int w_diff = (w_A - w_B);
int u_diff = (u_A - u_B);

int comb_r;
int comb_g;
int comb_b;
int comb_a;
int comb_w;
int comb_u;

//color ballancing

int strip_r = 0;
int strip_g = 0;
int strip_b = 0;
int strip_a = 20;
int strip_w = 0;
//int strip_i = 0;

int par_r = 70;
int par_g = 0;
int par_b = 0;
int par_a = 180;
int par_w = 0;
int par_u = 0;



//fade controlls
float loopSpeed = .005; //increase amount <--- use this to control rate of fade up and down
int delaySpeed = 5; //ms
float basePercent = 0;


void setup() {
  /* The most common pin for DMX output is pin 3, which DmxMaster
  ** uses by default. If you need to change that, do it here. */
  DmxMaster.usePin(3);

  /* DMX devices typically need to receive a complete set of channels
  ** even if you only need to adjust the first channel. You can
  ** easily change the number of channels sent here. If you don't
  ** do this, DmxMaster will set the maximum channel number to the
  ** highest channel you DmxMaster.write() to. */
  DmxMaster.maxChannel(90);

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


  //************************  COLOR A ************************



  // Fixture 1 values
  DmxMaster.write(fix_1_red, r_A + strip_r);
  DmxMaster.write(fix_1_green, g_A + strip_g);
  DmxMaster.write(fix_1_blue, b_A + strip_b);
  DmxMaster.write(fix_1_amber, a_A + strip_a);
  DmxMaster.write(fix_1_white, w_A + strip_w);


  // Fixture 2 values
  DmxMaster.write(fix_2_red, r_A + strip_r);
  DmxMaster.write(fix_2_green, g_A + strip_g);
  DmxMaster.write(fix_2_blue, b_A + strip_b);
  DmxMaster.write(fix_2_amber, a_A + strip_a);
  DmxMaster.write(fix_2_white, w_A + strip_w);


  // Fixture 3 values
  DmxMaster.write(fix_3_red, r_A + strip_r);
  DmxMaster.write(fix_3_green, g_A + strip_g);
  DmxMaster.write(fix_3_blue, b_A + strip_b);
  DmxMaster.write(fix_3_amber, a_A + strip_a);
  DmxMaster.write(fix_3_white, w_A + strip_w);


  // Fixture 4 values
  DmxMaster.write(fix_4_red, r_A + strip_r);
  DmxMaster.write(fix_4_green, g_A + strip_g);
  DmxMaster.write(fix_4_blue, b_A + strip_b);
  DmxMaster.write(fix_4_amber, a_A + strip_a);
  DmxMaster.write(fix_4_white, w_A + strip_w);



  // Fixture 5 values
  DmxMaster.write(fix_5_red, r_A + strip_r);
  DmxMaster.write(fix_5_green, g_A + strip_g);
  DmxMaster.write(fix_5_blue, b_A + strip_b);
  DmxMaster.write(fix_5_amber, a_A + strip_a);
  DmxMaster.write(fix_5_white, w_A + strip_w);


  // Fixture 6 values
  DmxMaster.write(fix_6_red, r_A + strip_r);
  DmxMaster.write(fix_6_green, g_A + strip_g);
  DmxMaster.write(fix_6_blue, b_A + strip_b);
  DmxMaster.write(fix_6_amber, a_A + strip_a);
  DmxMaster.write(fix_6_white, w_A + strip_w);



  // Fixture 7 values
  DmxMaster.write(fix_7_red, r_A + strip_r);
  DmxMaster.write(fix_7_green, g_A + strip_g);
  DmxMaster.write(fix_7_blue, b_A + strip_b);
  DmxMaster.write(fix_7_amber, a_A + strip_a);
  DmxMaster.write(fix_7_white, w_A + strip_w);


  // Fixture 8 values
  DmxMaster.write(fix_8_red, r_A + strip_r);
  DmxMaster.write(fix_8_green, g_A + strip_g);
  DmxMaster.write(fix_8_blue, b_A + strip_b);
  DmxMaster.write(fix_8_amber, a_A + strip_a);
  DmxMaster.write(fix_8_white, w_A + strip_w);


  // Fixture 9 values
  DmxMaster.write(fix_9_red, r_A + strip_r);
  DmxMaster.write(fix_9_green, g_A + strip_g);
  DmxMaster.write(fix_9_blue, b_A + strip_b);
  DmxMaster.write(fix_9_amber, a_A + strip_a);
  DmxMaster.write(fix_9_white, w_A + strip_w);


  // Fixture 10 values
  DmxMaster.write(fix_10_red, r_A + strip_r);
  DmxMaster.write(fix_10_green, g_A + strip_g);
  DmxMaster.write(fix_10_blue, b_A + strip_b);
  DmxMaster.write(fix_10_amber, a_A + strip_a);
  DmxMaster.write(fix_10_white, w_A + strip_w);


  // Fixture 11 values
  DmxMaster.write(fix_11_red, r_A + strip_r);
  DmxMaster.write(fix_11_green, g_A + strip_g);
  DmxMaster.write(fix_11_blue, b_A + strip_b);
  DmxMaster.write(fix_11_amber, a_A + strip_a);
  DmxMaster.write(fix_11_white, w_A + strip_w);


  // Fixture 12 values
  DmxMaster.write(fix_12_red, r_A + strip_r);
  DmxMaster.write(fix_12_green, g_A + strip_g);
  DmxMaster.write(fix_12_blue, b_A + strip_b);
  DmxMaster.write(fix_12_amber, a_A + strip_a);
  DmxMaster.write(fix_12_white, w_A + strip_w);
  
  /*

  // Fixture 13 values
  DmxMaster.write(fix_13_red, r_A + par_r);
  DmxMaster.write(fix_13_green, g_A + par_g);
  DmxMaster.write(fix_13_blue, b_A + par_b);
  DmxMaster.write(fix_13_white, w_A + par_w);
  DmxMaster.write(fix_13_amber, a_B + par_a);
  DmxMaster.write(fix_13_uv, u_B + par_u);
 
  // Fixture 14 values
  DmxMaster.write(fix_14_red, r_B + par_r);
  DmxMaster.write(fix_14_green, g_B + par_g);
  DmxMaster.write(fix_14_blue, b_B + par_b);
  DmxMaster.write(fix_14_white, w_B + par_w);
  DmxMaster.write(fix_14_amber, a_B + par_a);
  DmxMaster.write(fix_14_uv, u_B + par_u);

  // Fixture 15 values
  DmxMaster.write(fix_15_red, r_B + par_r);
  DmxMaster.write(fix_15_green, g_B + par_g);
  DmxMaster.write(fix_15_blue, b_B + par_b);
  DmxMaster.write(fix_15_white, w_B + par_w);
  DmxMaster.write(fix_15_amber, a_B + par_a);
  DmxMaster.write(fix_15_uv, u_B + par_u);
  
  // Fixture 16 values
  DmxMaster.write(fix_16_red, r_B + par_r);
  DmxMaster.write(fix_16_green, g_B + par_g);
  DmxMaster.write(fix_16_blue, b_B + par_b);
  DmxMaster.write(fix_16_white, w_B + par_w);
  DmxMaster.write(fix_16_amber, a_B + par_a);
  DmxMaster.write(fix_16_uv, u_B + par_u);
*/


}







//////////////////////////////// FADE UP THEN DOWN /////////////////////////////







void fadeUpDown() {

  Serial.println("running fadeUpDown");

  for (dmxLevelUp = basePercent; dmxLevelUp <= 9.0; dmxLevelUp += loopSpeed) {

    //color_A
    red_A = (int) (dmxLevelUp * r_A);
    green_A = (int) (dmxLevelUp * g_A);
    blue_A = (int) (dmxLevelUp * b_A);
    white_A = (int) (dmxLevelUp * w_A);
    amber_A = (int) (dmxLevelUp * a_A);
    //ints_A = (int)(dmxLevelUp * i_A);
    uv_A = (int) (dmxLevelUp * u_A);

    //color_B
    red_B = (int) (dmxLevelUp * r_B);
    green_B = (int) (dmxLevelUp * g_B);
    blue_B = (int) (dmxLevelUp * b_B);
    white_B = (int) (dmxLevelUp * w_B);
    amber_B = (int) (dmxLevelUp * a_B);
    //ints_B = (int)(dmxLevelUp * i_B);
    uv_B = (int) (dmxLevelUp * u_B);

    Serial.print("dmxLevelUp = ");
    Serial.print(dmxLevelUp);


    printColors();

    //*************** BOTTLE LIGHTS ***************

    // Fixture 1 values
    DmxMaster.write(fix_1_red, red_A + strip_r);
    DmxMaster.write(fix_1_green, green_A + strip_g);
    DmxMaster.write(fix_1_blue, blue_A + strip_b);
    DmxMaster.write(fix_1_amber, amber_A + strip_a);
    DmxMaster.write(fix_1_white, white_A + strip_w);
    

    // Fixture 2 values
    DmxMaster.write(fix_2_red, red_A + strip_r);
    DmxMaster.write(fix_2_green, green_A + strip_g);
    DmxMaster.write(fix_2_blue, blue_A + strip_b);
    DmxMaster.write(fix_2_amber, amber_A + strip_a);
    DmxMaster.write(fix_2_white, white_A + strip_w);
    
    
    // Fixture 3 values
    DmxMaster.write(fix_3_red, red_B + strip_r);
    DmxMaster.write(fix_3_green, green_B + strip_g);
    DmxMaster.write(fix_3_blue, blue_B + strip_b);
    DmxMaster.write(fix_3_amber, amber_B + strip_a);
    DmxMaster.write(fix_3_white, white_B + strip_w);
   

    // Fixture 4 values
    DmxMaster.write(fix_4_red, red_B + strip_r);
    DmxMaster.write(fix_4_green, green_B + strip_g);
    DmxMaster.write(fix_4_blue, blue_B + strip_b);
    DmxMaster.write(fix_4_amber, amber_B + strip_a);
    DmxMaster.write(fix_4_white, white_B + strip_w);
    
        // Fixture 5 values
    DmxMaster.write(fix_5_red, red_A + strip_r);
    DmxMaster.write(fix_5_green, green_A + strip_g);
    DmxMaster.write(fix_5_blue, blue_A + strip_b);
    DmxMaster.write(fix_5_amber, amber_A + strip_a);
    DmxMaster.write(fix_5_white, white_A + strip_w);
    

    // Fixture 6 values
    DmxMaster.write(fix_6_red, red_A + strip_r);
    DmxMaster.write(fix_6_green, green_A + strip_g);
    DmxMaster.write(fix_6_blue, blue_A + strip_b);
    DmxMaster.write(fix_6_amber, amber_A + strip_a);
    DmxMaster.write(fix_6_white, white_A + strip_w);
    
    
    // Fixture 7 values
    DmxMaster.write(fix_7_red, red_B + strip_r);
    DmxMaster.write(fix_7_green, green_B + strip_g);
    DmxMaster.write(fix_7_blue, blue_B + strip_b);
    DmxMaster.write(fix_7_amber, amber_B + strip_a);
    DmxMaster.write(fix_7_white, white_B + strip_w);
   

    // Fixture 8 values
    DmxMaster.write(fix_8_red, red_B + strip_r);
    DmxMaster.write(fix_8_green, green_B + strip_g);
    DmxMaster.write(fix_8_blue, blue_B + strip_b);
    DmxMaster.write(fix_8_amber, amber_B + strip_a);
    DmxMaster.write(fix_8_white, white_B + strip_w);
    
    
    //*************** TOP LIGHTS ***************
    
    
        // Fixture 9 values
    DmxMaster.write(fix_9_red, red_B + strip_r);
    DmxMaster.write(fix_9_green, green_B + strip_g);
    DmxMaster.write(fix_9_blue, blue_B + strip_b);
    DmxMaster.write(fix_9_amber, amber_B + strip_a);
    DmxMaster.write(fix_9_white, white_B + strip_w);
    

    // Fixture 10 values
    DmxMaster.write(fix_10_red, red_B + strip_r);
    DmxMaster.write(fix_10_green, green_B + strip_g);
    DmxMaster.write(fix_10_blue, blue_B + strip_b);
    DmxMaster.write(fix_10_amber, amber_B + strip_a);
    DmxMaster.write(fix_10_white, white_B + strip_w);
    
    
    // Fixture 11 values
    DmxMaster.write(fix_11_red, red_B + strip_r);
    DmxMaster.write(fix_11_green, green_B + strip_g);
    DmxMaster.write(fix_11_blue, blue_B + strip_b);
    DmxMaster.write(fix_11_amber, amber_B + strip_a);
    DmxMaster.write(fix_11_white, white_B + strip_w);
   

    // Fixture 12 values
    DmxMaster.write(fix_12_red, red_B + strip_r);
    DmxMaster.write(fix_12_green, green_B + strip_g);
    DmxMaster.write(fix_12_blue, blue_B + strip_b);
    DmxMaster.write(fix_12_amber, amber_B + strip_a);
    DmxMaster.write(fix_12_white, white_B + strip_w);
    
    
    //*************** PAR LIGHTS *************** 
    
    
    // Fixture 13 values
    DmxMaster.write(fix_13_red, red_B + par_r);
    DmxMaster.write(fix_13_green, green_B + par_g);
    DmxMaster.write(fix_13_blue, blue_B + par_b);
    DmxMaster.write(fix_13_amber, amber_B + par_a);
    DmxMaster.write(fix_13_white, white_B + par_w);
    
        // Fixture 14 values
    DmxMaster.write(fix_14_red, red_A + par_r);
    DmxMaster.write(fix_14_green, green_A + par_g);
    DmxMaster.write(fix_14_blue, blue_A + par_b);
    DmxMaster.write(fix_14_amber, amber_A + par_a);
    DmxMaster.write(fix_14_white, white_A + par_w);
    
        // Fixture 15 values
    DmxMaster.write(fix_15_red, red_A + par_r);
    DmxMaster.write(fix_15_green, green_B + par_g);
    DmxMaster.write(fix_15_blue, blue_A + par_b);
    DmxMaster.write(fix_15_amber, amber_A + par_a);
    DmxMaster.write(fix_15_white, white_A + par_w);
    
    
        // Fixture 16 values
    DmxMaster.write(fix_16_red, red_A + par_r);
    DmxMaster.write(fix_16_green, green_A + par_g);
    DmxMaster.write(fix_16_blue, blue_A + par_b);
    DmxMaster.write(fix_16_amber, amber_A + par_a);
    DmxMaster.write(fix_16_white, white_A + par_w);
    
    
    



    delay(delaySpeed);

  }

  delay(2000);

  for (dmxLevelDown = 9.1; dmxLevelDown >= basePercent; dmxLevelDown -= loopSpeed) {


    red_A = (int) (dmxLevelDown * r_A);
    green_A = (int) (dmxLevelDown * g_A);
    blue_A = (int) (dmxLevelDown * b_A);
    white_A = (int) (dmxLevelDown * w_A);
    amber_A = (int) (dmxLevelDown * a_A);
    //ints_A = (int)(dmxLevelDown * i_A);
    uv_A = (int) (dmxLevelDown * u_A);

    red_B = (int) (dmxLevelDown * r_B);
    green_B = (int) (dmxLevelDown * g_B);
    blue_B = (int) (dmxLevelDown * b_B);
    white_B = (int) (dmxLevelDown * w_B);
    amber_B = (int) (dmxLevelDown * a_B);
    //ints_B = (int)(dmxLevelDown * i_B);
    uv_B = (int) (dmxLevelDown * u_B);


    Serial.print("dmxLevelDown = ");
    Serial.print(dmxLevelDown);


    printColors();


    // Fixture 1 values
    DmxMaster.write(fix_1_red, red_A + strip_r);
    DmxMaster.write(fix_1_green, green_A + strip_g);
    DmxMaster.write(fix_1_blue, blue_A + strip_b);
    DmxMaster.write(fix_1_amber, amber_A + strip_a);
    DmxMaster.write(fix_1_white, white_A + strip_w);
    //DmxMaster.write(fix_1_ints, ints_A + strip_i);

    // Fixture 2 values
    DmxMaster.write(fix_2_red, red_A + strip_r);
    DmxMaster.write(fix_2_green, green_A + strip_g);
    DmxMaster.write(fix_2_blue, blue_A + strip_b);
    DmxMaster.write(fix_2_amber, amber_A + strip_a);
    DmxMaster.write(fix_2_white, white_A + strip_w);
    //DmxMaster.write(fix_2_ints, ints_A + strip_i);

    // Fixture 3 values
    DmxMaster.write(fix_3_red, red_B + strip_r);
    DmxMaster.write(fix_3_green, green_B + strip_g);
    DmxMaster.write(fix_3_blue, blue_B + strip_g);
    DmxMaster.write(fix_3_amber, amber_B + strip_a);
    DmxMaster.write(fix_3_white, white_B + strip_w);
    //DmxMaster.write(fix_3_ints, uv_A + strip_u);

    // Fixture 4 values
    DmxMaster.write(fix_4_red, red_B + strip_r);
    DmxMaster.write(fix_4_green, green_B + strip_g);
    DmxMaster.write(fix_4_blue, blue_B + strip_g);
    DmxMaster.write(fix_4_amber, amber_B + strip_a);
    DmxMaster.write(fix_4_white, white_B + strip_w);
    //DmxMaster.write(fix_4_ints, uv_A + strip_u);
    
    delay(delaySpeed);

  }

  delay(2000);


}
/*


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
*/

void loop() {






  staticColors();
  
 //fadeUpDown();
  
 // fadeBetween();



}

