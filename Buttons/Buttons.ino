/*
=== Arduino Code for Keytar Hero ===
This code is designed to be used with the Teensy 2.0 and is a modified version of the Buttons to USB Keyboard Example code.
Currently, the code is compatible with the game Clone Hero, which can be downloaded here: https://clonehero.net/
*/

//Include the necessary libraries
#include <Bounce.h>

//Define input pins and values for joystick (will be swapped to a more 'guitar-like' strum bar eventually)
#define joyX A3  
#define joyY A4
int xValue = 0,yValue = 0; 

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(2, 10);  // which is appropriate for most mechanical pushbuttons
Bounce button3 = Bounce(3, 10);  // if a button is too "sensitive" to rapid touch, you can
Bounce button4 = Bounce(4, 10);  // increase this time.

//Uncomment the follow buttons if you would like to add more buttons
Bounce button5 = Bounce(5, 10);  
Bounce button6 = Bounce(6, 10);  
Bounce button7 = Bounce(7, 10);
//Bounce button8 = Bounce(8, 10);
//Bounce button9 = Bounce(9, 10);

void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);

//Uncomment the follow buttons if you would like to add more buttons
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);  // Teensy++ LED, may need 1k resistor pullup
  pinMode(7, INPUT_PULLUP);
//  pinMode(8, INPUT_PULLUP);
//  pinMode(9, INPUT_PULLUP);

}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();

//Uncomment the follow buttons if you would like to add more buttons
  button5.update();
  button6.update();
//  button7.update();
//  button8.update();
//  button9.update();

// read analog values from the joystick's x axis and y axis and store the values
  xValue = analogRead(joyX);  
  yValue = analogRead(joyY);

  // Check each button for "falling" edge.
  // Type a message on the Keyboard when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (button0.fallingEdge()) {
    Keyboard.press(KEY_1);
  }
  if (button1.fallingEdge()) {
    Keyboard.press(KEY_2);
  }
  if (button2.fallingEdge()) {
    Keyboard.press(KEY_3);
  }
  if (button3.fallingEdge()) {
    Keyboard.press(KEY_4);
  }
  if (button4.fallingEdge()) {
    Keyboard.press(KEY_5);
  }

//Uncomment the follow buttons if you would like to add more buttons
  if (button5.fallingEdge()) {
    Keyboard.press(KEY_6);
  }
  if (button6.fallingEdge()) {
    Keyboard.press(KEY_7);
  }
//  if (button7.fallingEdge()) {
//    Keyboard.println("B7 press");
//  }
//  if (button8.fallingEdge()) {
//    Keyboard.println("B8 press");
//  }
//  if (button9.fallingEdge()) {
//    Keyboard.println("B9 press");
//  }

//determine directional inputs of joystick from x and y values
  if (xValue < 100) {
    Keyboard.press(KEY_LEFT);  
  }
  if (xValue > 700) {
    Keyboard.press(KEY_RIGHT);
  }
  if (xValue > 100 and xValue < 700) {
    Keyboard.release(KEY_LEFT);
    Keyboard.release(KEY_RIGHT);
  }
  if (yValue < 100) {
    Keyboard.press(KEY_UP);  
  }
  if (yValue > 700) {
    Keyboard.press(KEY_DOWN);
  }
  if (yValue > 100 and yValue < 700) {
    Keyboard.release(KEY_UP);
    Keyboard.release(KEY_DOWN);
  }
  
  // Check each button for "rising" edge
  // Type a message on the Keyboard when each button releases.
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button0.risingEdge()) {
    Keyboard.release(KEY_1);
  }
  if (button1.risingEdge()) {
    Keyboard.release(KEY_2);
  }
  if (button2.risingEdge()) {
    Keyboard.release(KEY_3);
  }
  if (button3.risingEdge()) {
    Keyboard.release(KEY_4);
  }
  if (button4.risingEdge()) {
    Keyboard.release(KEY_5);
  }

//Uncomment the follow buttons if you would like to add more buttons
  if (button5.risingEdge()) {
    Keyboard.release(KEY_6);
  }
  if (button6.risingEdge()) {
    Keyboard.release(KEY_7);
  }
//  if (button7.risingEdge()) {
//    Keyboard.println("B7 release");
//  }
//  if (button8.risingEdge()) {
//    Keyboard.println("B8 release");
//  }
//  if (button9.risingEdge()) {
//    Keyboard.println("B9 release");
//  }
}
