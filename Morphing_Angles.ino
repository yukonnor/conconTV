#include <TVout.h>
#include <video_gen.h>

#include "TVout.h"
#include <fontALL.h>

TVout TV;

long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

//Definie button variables
int shapePin    = 2;
int amntPin     = 3;
int movementPin = 4;

//Define states of Shape, Amount of Dots, Type of Movement
int shp   = 1;
int amnt  = 1;
int mvmt = 1;
int spd   = analogRead(A0); //use 10k pot - Values should be 0 - 1023

//Define the environment we're playing in
int TV_width = 120;
int TV_height = 96;

//Define dot arrays
#define AMOUNT_DOTS 9 //9 dots will be generated



int x_dot_array[AMOUNT_DOTS];
int y_dot_array[AMOUNT_DOTS];




void setup() {
  //Initialize buttons
  pinMode(shapePin, INPUT_PULLUP);  //toggle thru dots, lines, angles, dub-angles
  pinMode(amntPin, INPUT_PULLUP);   //amount of dots
  pinMode(movementPin, INPUT_PULLUP);
  
  
  TV.begin(NTSC,120,96); //Screen resolution
  Serial.begin(9600);
  TV.clear_screen(); 

}

void loop() {
int shape_read = digitalRead(shapePin);
int amnt_read = digitalRead(amntPin);
int movement_read = digitalRead(movementPin);
int spd   = analogRead(A0); 
int t = 0;


//MAKE DOTS  -- Using the Arrays defined above
for (int i = 0; i< AMOUNT_DOTS; i++)
    {
      int x_rand = random(TV_width);
      x_dot_array[i] = x_rand;
      int y_rand = random(TV_height);
      y_dot_array[i] = y_rand;
      
      TV.set_pixel(x_dot_array[i],y_dot_array[i],WHITE); //DRAW THE INITIAL DOTS
      TV.delay_frame(4); 
      //TV.clear_screen();  
    }

//DRAW ANGLE 1
TV.draw_line(x_dot_array[0],y_dot_array[0],x_dot_array[1],y_dot_array[1],WHITE);
TV.draw_line(x_dot_array[1],y_dot_array[1],x_dot_array[2],y_dot_array[2],WHITE);

//DRAW ANGLE 2
TV.draw_line(x_dot_array[3],y_dot_array[3],x_dot_array[4],y_dot_array[4],WHITE);
TV.draw_line(x_dot_array[4],y_dot_array[4],x_dot_array[5],y_dot_array[5],WHITE);

//DRAW ANGLE 3
TV.draw_line(x_dot_array[6],y_dot_array[6],x_dot_array[7],y_dot_array[7],WHITE);
TV.draw_line(x_dot_array[7],y_dot_array[7],x_dot_array[8],y_dot_array[8],WHITE);

TV.delay_frame(4);


//SET INITIAL VALUES OF MOVEMENT FOR EACH DOT
int xm_array[AMOUNT_DOTS];
int ym_array[AMOUNT_DOTS];

for (int i = 0; i< AMOUNT_DOTS; i++)
    {
      int xm = random(-1,1);
      if (xm == 0)
         {xm = -1;}    
      xm_array[i] = xm;
      int ym = random(-1,1);
      if (ym == 0)
         {ym = 1;}   
      ym_array[i] = ym;     
     
    }
xm_array[1] = 0;
xm_array[4] = 0;
xm_array[7] = 0;

while (t < 2000) 
    {   
      for (int i=0; i< AMOUNT_DOTS; i++) //cycle through array for each 't' step
         {
          // x coordinates!
              x_dot_array[i] = x_dot_array[i]-xm_array[i];
          
          if  (x_dot_array[i] <= (0))                 //If x is <= 0, bounce back
              {xm_array[i] = -xm_array[i];}

          if  (x_dot_array[i] >= (TV_width))           //If x is >= TV_width, bounce back
              {xm_array[i]=-xm_array[i];}


          // y coordinates!
             {y_dot_array[i] = y_dot_array[i]+ym_array[i];}     

          if  (y_dot_array[i] <= (0))                   //If y is <= 0, bounce back
              {ym_array[i]=-ym_array[i];}  

          if  (y_dot_array[i] >= (TV_height))           //If y is >= TV_height, bounce back
              {ym_array[i]=-ym_array[i];} 

    
         TV.set_pixel(x_dot_array[i],y_dot_array[i],WHITE);  //Now draw the newly moved or newly generated dots
         }
       
       t++;
      
        //DRAW ANGLE 1
        TV.draw_line(x_dot_array[0],y_dot_array[0],x_dot_array[1],y_dot_array[1],WHITE);
        TV.draw_line(x_dot_array[1],y_dot_array[1],x_dot_array[2],y_dot_array[2],WHITE);
        
        //DRAW ANGLE 2
        TV.draw_line(x_dot_array[3],y_dot_array[3],x_dot_array[4],y_dot_array[4],WHITE);
        TV.draw_line(x_dot_array[4],y_dot_array[4],x_dot_array[5],y_dot_array[5],WHITE);
        
        //DRAW ANGLE 3
        TV.draw_line(x_dot_array[6],y_dot_array[6],x_dot_array[7],y_dot_array[7],WHITE);
        TV.draw_line(x_dot_array[7],y_dot_array[7],x_dot_array[8],y_dot_array[8],WHITE);

       TV.delay_frame(4); 
       TV.clear_screen();    
      }



TV.delay_frame(4); 
TV.clear_screen();  
}
