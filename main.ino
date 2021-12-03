


// KEYPAD //

#include <Keypad.h>

const byte ROWS = 4; // four rows
const byte COLS = 4; // three columns

char keys[ROWS][COLS] = {

     {'1','2','3','A'},
     {'4','5','6','B'},
     {'7','8','9','C'},
     {'*','0','#','D'},
  };
  
 byte rowPins[ROWS] = {46,48,50,52};
 byte colPins[COLS] = {53,51,49,47};
 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int midC = 60; // MIDI note value for middle C on a standard keyboard

const int transposePin1 = 22; // pins for the switch controlling transposing
const int transposePin2 = 23;
int transpose = 0;  // if = 0 no transposing
int transposeLeft = 0;
int transposeRight = 0;
int oldTransposeLeft = 0;
int oldTransposeRight = 0;
unsigned long transposeTimer = 0;  // for debouncing


// ROTARY ENCODER //

#define ENCODER_DO_NOT_USE_INTERRUPTS
#include <Encoder.h>

Encoder myEnc1(26, 27);
Encoder myEnc2(24, 25);
long position1  = -999;
long position2  = -999;
int encVals[12] = {64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64}; // set initial value of encoder to mid range of 0-127


// ROTARY SWITCH //

const int rotSwitch1 = 30;  // rotary switch pins
const int rotSwitch2 = 32;
const int rotSwitch3 = 34;
const int rotSwitch4 = 36;
const int rotSwitch5 = 38;
const int rotSwitch6 = 40;
int cVal = 1;


// POTENTIOMETERS //

 const int pot = A0; 
 const int pot1 = A1;
 const int pot2 = A2; 
 const int pot3 = A7; 
 const int pot4 = A4;
 const int pot5 = A5;

 int potVal = 0 ; 
 int potVal1 = 0 ;
 int potVal2 = 0 ;
 int potVal3 = 0 ;
 int potVal4 = 0 ; 
 int potVal5 = 0 ;

  int lastPotVal = 0 ; 
 int lastPotVal1 = 0 ;
 int lastPotVal2 = 0 ;
 int lastPotVal3 = 0 ;
 int lastPotVal4 = 0 ; 
 int lastPotVal5 = 0 ;


// JOYSTICK //

const int joyX = A5;  // joystick pins
const int joyY = A4;

const int Xswitch = 52;  // axis switche pins
const int Yswitch = 50;

int joyXval = 0;
int joyYval = 0;
int lastJoyXval = 0;
int lastJoyYval = 0;


void setup() {

  Serial.begin(9600); // enable serial communication

  pinMode(transposePin1, INPUT_PULLUP);  // activate the input pullup resistor on all buttons/switches
  pinMode(transposePin2, INPUT_PULLUP);  // means you won't need external resistors to read the buttons
  pinMode(rotSwitch1, INPUT_PULLUP);
  pinMode(rotSwitch2, INPUT_PULLUP);
  pinMode(rotSwitch3, INPUT_PULLUP);
  pinMode(rotSwitch4, INPUT_PULLUP);
  pinMode(rotSwitch5, INPUT_PULLUP);
  pinMode(rotSwitch6, INPUT_PULLUP);
  pinMode(Xswitch, INPUT_PULLUP);
  pinMode(Yswitch, INPUT_PULLUP);

}


void loop() {

 
  readEncoder();      // read roraty encoder
  readKeyPad();       // read keypad + transpose switch
  readPots();         // read potentiometers
  
}
