#include "TVout.h"
#include <fontALL.h>
#include "schematic.h"
#include "TVOlogo.h"

TVout TV;

int zOff = 150;
int xOff = 0;
int yOff = 0;
int cSize = 50;
int view_plane = 64;
float angle = PI/60;
int interval = 1000
  

void setup() {
  TV.begin(NTSC,120,96);
  Serial.begin(9600);
  //circles
  TV.clear_screen();
  TV.draw_circle(TV.hres()/2,TV.vres()/2,TV.vres()/3,WHITE);
  TV.delay(500);
  TV.draw_circle(TV.hres()/2,TV.vres()/2,TV.vres()/2,WHITE,INVERT);
  TV.delay(500);
  
  //rectangles and lines
  TV.clear_screen();
  TV.draw_rect(20,20,80,56,WHITE);
  TV.delay(500);
  TV.draw_rect(10,10,100,76,WHITE,INVERT);
  TV.delay(500);
  TV.draw_line(60,20,60,76,INVERT);
  TV.draw_line(20,48,100,48,INVERT);
  TV.delay(500);
  TV.draw_line(10,10,110,86,INVERT);
  TV.draw_line(10,86,110,10,INVERT);
  TV.delay(500);
  
}

void loop() {
//draw dancing triangles
//t1 is triangle 1
int potRead = analogRead(A0); //use 10k pot - Values should be 0 - 1023
int t1x1 = 10;
int t1y1 = 10;
int t1x2 = 10;
int t1y2 = 90;
int t1x3 = 80;    //For now, picked consant. Should aim for values between 80 - 100
int t1y3 = (t1y1+(potRead*(t1y2/1023)));   //Should aim for values between t1y1 and t1y2


  
TV.draw_tri(t1x1,t1y1,t1x2,t1y2,t1x3,t1y3,WHITE,BLACK)
delay(100)
  //End dancing triangles
}

