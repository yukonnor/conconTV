
//Define Analog Potentiometer Pins
const int pot1Pin = 0;
const int pot2Pin = 2; //note here that the stripboard wires cross, hence out of order
const int pot3Pin = 1;
const int pot4Pin = 3;

//Define Digial Button Pins
const int button1Pin = 13;
const int button2Pin = 12;
const int button3Pin = 11;
const int button4Pin = 10;

//Initialize button value variables:
int button1 = 0;
int button2 = 0;
int button3 = 0;
int button4 = 0;

void setup() {
  //Start serial
  Serial.begin(9600); 

  //Set button pins to use internal Pullup resistors
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
}

void loop() {

  //Read pot values:
  int potRead1 = analogRead(pot1Pin);
  int potRead2 = analogRead(pot2Pin);
  int potRead3 = analogRead(pot3Pin);
  int potRead4 = analogRead(pot4Pin);

  //Display pot values:
  Serial.print("Pot1 = "); 
  Serial.println(potRead1); 
  Serial.print("Pot2 = "); 
  Serial.println(potRead2); 
  Serial.print("Pot3 = "); 
  Serial.println(potRead3); 
  Serial.print("Pot4 = "); 
  Serial.println(potRead4); 
  Serial.println(); //add some spacing
  Serial.println();
  
  
  //Read button values:
  //NOTE: Button press == LOW
  int buttonRead1 = digitalRead(button1Pin);
  int buttonRead2 = digitalRead(button2Pin);
  int buttonRead3 = digitalRead(button3Pin);
  int buttonRead4 = digitalRead(button4Pin);

  //if button pressed, increase value of button variable
  if (buttonRead1 == LOW) {
     button1 = button1 + 1;
     delay(20);
  }

  if (buttonRead2 == LOW) {
     button2 = button2 + 1;
     delay(20);
  }

  if (buttonRead3 == LOW) {
     button3 = button3 + 1;
     delay(20);
  }

  if (buttonRead4 == LOW) {
     button4 = button4 + 1;
     delay(20);
  }

  //Display button values:
  Serial.print("Button1 = "); 
  Serial.println(button1); 
  Serial.print("Button2 = "); 
  Serial.println(button2); 
  Serial.print("Button3 = "); 
  Serial.println(button3); 
  Serial.print("Button4 = "); 
  Serial.println(button4); 
  Serial.println(); //add some spacing
  Serial.println();

  delay(100);

}
