/*****************************************************************
XBee_Remote_Control.ino
Write your Arduino's pins (analog or digital) or read from those
pins (analog or digital) using a remote XBee.
Jim Lindblom @ SparkFun Electronics
Original Creation Date: May 7, 2014

This sketch requires an XBee, XBee Shield and another XBee tied to
your computer (via a USB Explorer). You can use XCTU's console, or
another serial terminal program (even the serial monitor!), to send
commands to the Arduino. 

Example usage (send these commands from your computer terminal):
    w#nnn - analog WRITE pin # to nnn
      e.g. w6088 - write pin 6 to 88
    d#v   - digital WRITE pin # to v
      e.g. ddh - Write pin 13 High
    r#    - digital READ digital pin #
      e.g. r3 - Digital read pin 3
    a#    - analog READ analog pin #
      e.g. a0 - Read analog pin 0

    - Use hex values for pins 10-13
    - Upper or lowercase works
    - Use 0, l, or L to write LOW
    - Use 1, h, or H to write HIGH

Multiple commands are stringed together with the first digit
indicating the number of commands in a string

Hardware Hookup:
  The Arduino shield makes all of the connections you'll need
  between Arduino and XBee. Make sure the SWITCH IS IN THE 
  "DLINE" POSITION.

Development environment specifics:
    IDE: Arduino 1.0.5
    Hardware Platform: SparkFun RedBoard
    XBee Shield & XBee Series 1 1mW (w/ whip antenna)
        XBee USB Explorer connected to computer with another
          XBee Series 1 1mW connected to that.

This code is beerware; if you see me (or any other SparkFun 
employee) at the local, and you've found our code helpful, please 
buy us a round!

Distributed as-is; no warranty is given.
*****************************************************************/
// SoftwareSerial is used to communicate with the XBee
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial XBee(2, 3); // Arduino RX, TX (XBee Dout, Din)
Servo testservo1;
Servo testservo2;
uint32_t incr = 100;
uint32_t i1 = 0;
uint32_t i2 = 0;
bool hl;
int pls1 = 1;
int pls2 = 1;

void setup()
{
  // Initialize XBee Software Serial port. Make sure the baud
  // rate matches your XBee setting (9600 is default).
  XBee.begin(9600);
  testservo1.attach(10, 1000, 2000);
  testservo2.attach(11, 1000, 2000);
}

void loop(){
  if (i1 > 0 && i1 < 18000){
    i1 = i1 + (pls1 - 1);

    }
  if (i2 > 0 && i2 < 18000){
    i2 = i2 + (pls2 - 1);

    }
    testservo1.writeMicroseconds(i1 / incr);
    testservo2.writeMicroseconds(i2 / incr);
  // In loop() we continously check to see if a command has been
  //  received.
  char N = XBee.read();
  // The first digit correspond to the number of commands stringed together
  for(int i = 1; i <= N; i++){
      if (XBee.available()){
      //testservo.detach();
        char c = XBee.read();
        if((c == 's') || (c == 'S')){
            writeServoPin();
        } //if
      } //if
  } //for
} //voidloop



void writeServoPin()
{
  while (XBee.available() < 2)
    ; // Wait for pin and value to become available
  pls1 = ASCIItoInt(XBee.read());
  pls2 = ASCIItoInt(XBee.read());
}

void writeDPin()
{
  while (XBee.available() < 2)
    ; // Wait for pin and value to become available
  char pin = XBee.read();
  hl = ASCIItoHL(XBee.read());
  pin = ASCIItoInt(pin); // Convert ASCCI to a 0-13 value
  pinMode(pin, OUTPUT); // Set pin as an OUTPUT
  digitalWrite(pin, hl); // Write pin accordingly

 }




// ASCIItoHL
// Helper function to turn an ASCII value into either HIGH or LOW
int ASCIItoHL(char c)
{
  // If received 0, byte value 0, L, or l: return LOW
  // If received 1, byte value 1, H, or h: return HIGH
  if ((c == '0') || (c == 0) || (c == 'L') || (c == 'l'))
    return LOW;
  else if ((c == '1') || (c == 1) || (c == 'H') || (c == 'h'))
    return HIGH;
  else
    return -1;
}

// ASCIItoInt
// Helper function to turn an ASCII hex value into a 0-15 byte val
int ASCIItoInt(char c)
{
  if ((c >= '0') && (c <= '9'))
    return c - 0x30; // Minus 0x30
  else if ((c >= 'A') && (c <= 'F'))
    return c - 0x37; // Minus 0x41 plus 0x0A
  else if ((c >= 'a') && (c <= 'f'))
    return c - 0x57; // Minus 0x61 plus 0x0A
  else
    return -1;
}

int ASCIItoSigInt(char c, int i)
{

  if ((c == '1') && i < 18000)
    return 1;
  else if ((c == '2') && i > 0)
    return -1;
  else
    return 0;
}
