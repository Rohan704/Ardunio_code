/*
 Example sketch for the PS4 Bluetooth library - developed by Kristian Lauszus
 For more information visit my blog: http://blog.tkjelectronics.dk/ or
 send me an e-mail:  kristianl@tkjelectronics.com
 */

#define d1 12
#define p1 11

#define d2 4
#define p2 5

#define d3 7
#define p3 6

#define d4 2
#define p4 9
int i=70;
#include <PS4BT.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the PS4BT class in two ways */
// This will start an inquiry and then pair with the PS4 controller - you only have to do this once
// You will need to hold down the PS and Share button at the same time, the PS4 controller will then start to blink rapidly indicating that it is in pairing mode
PS4BT PS4(&Btd, PAIR);

// After that you can simply create the instance like so and then press the PS button on the device
//PS4BT PS4(&Btd);

bool printAngle, printTouch;
uint8_t oldL2Value, oldR2Value;

void setup() {

  pinMode(d1, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(p4, OUTPUT);
  
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
  Serial.print(F("\r\nPS4 Bluetooth Library Started"));
}
void loop() {
  Usb.Task();

  if (PS4.connected()) {
    if (PS4.getAnalogHat(LeftHatX) > 137 || PS4.getAnalogHat(LeftHatX) < 117 || PS4.getAnalogHat(LeftHatY) > 137 || PS4.getAnalogHat(LeftHatY) < 117 || PS4.getAnalogHat(RightHatX) > 137 || PS4.getAnalogHat(RightHatX) < 117 || PS4.getAnalogHat(RightHatY) > 137 || PS4.getAnalogHat(RightHatY) < 117) {
      Serial.print(F("\r\nLeftHatX: "));
      Serial.print(PS4.getAnalogHat(LeftHatX));
      Serial.print(F("\tLeftHatY: "));
      Serial.print(PS4.getAnalogHat(LeftHatY));
      Serial.print(F("\tRightHatX: "));
      Serial.print(PS4.getAnalogHat(RightHatX));
      Serial.print(F("\tRightHatY: "));
      Serial.print(PS4.getAnalogHat(RightHatY));
    }

    if (PS4.getAnalogButton(L2) || PS4.getAnalogButton(R2)) { // These are the only analog buttons on the PS4 controller
      
      //Serial.print(F("\r\nL2: "));
      //Serial.print(PS4.getAnalogButton(L2));
      //Serial.print(F("\tR2: "));
      //Serial.print(PS4.getAnalogButton(R2));
    }
    if (PS4.getAnalogButton(L2) != oldL2Value || PS4.getAnalogButton(R2) != oldR2Value) // Only write value if it's different
     // PS4.setRumbleOn(PS4.getAnalogButton(L2), PS4.getAnalogButton(R2));
    //oldL2Value = PS4.getAnalogButton(L2);
    oldR2Value = PS4.getAnalogButton(R2);

    if (PS4.getButtonClick(PS)) {
      Serial.print(F("\r\nPS"));
      PS4.disconnect();
    }
    else {
      if (PS4.getButtonPress(TRIANGLE) ) {
        //PS4.getAnalogButton(R2);
        diagonalleftfront();
        Serial.print(F("\r\nTraingle"));
        //PS4.setRumbleOn(RumbleLow);
      }
      else{
        halt();
      }
      if (PS4.getButtonPress(CIRCLE) ) {
        //PS4.getAnalogButton(R2);
        diagonalleftback();
        Serial.print(F("\r\nCircle"));
        //PS4.setRumbleOn(RumbleHigh);
      }
      else{
        halt();
      }
      if (PS4.getButtonPress(CROSS)) {
        //PS4.getAnalogButton(R2);
        diagonalrightback();
        Serial.print(F("\r\nCross"));
        //PS4.setLedFlash(10, 10); // Set it to blink rapidly
      }
      else{
        halt();
      }
      if (PS4.getButtonPress(SQUARE)) {
        //PS4.getAnalogButton(R2);
        diagonalrightfront();
        Serial.print(F("\r\nSquare"));
       // PS4.setLedFlash(0, 0); // Turn off blinking
      }
      else{
        halt();
      }

      if (PS4.getButtonPress(UP) ) {
        //PS4.getAnalogButton(R2);
        forward();
        Serial.print(F("\r\nUp"));
        //PS4.setLed(Red);
      }
      else{
        halt();
      }
      if (PS4.getButtonPress(RIGHT)) {
        //PS4.getAnalogButton(R2);
        rightshift();
        Serial.print(F("\r\nRight"));
        //PS4.setLed(Blue);
      }
      else{
        halt();
      }
      if (PS4.getButtonPress(DOWN)) {
       // PS4.getAnalogButton(R2);
        backward();
        Serial.print(F("\r\nDown"));
       // PS4.setLed(Yellow);
      }
      else{
        halt();
      }
      if (PS4.getButtonPress(LEFT)) {
        //PS4.getAnalogButton(R2);
        leftshift();
        Serial.print(F("\r\nLeft"));
       // PS4.setLed(Green);
      }
      else{
        halt();
      }

      if (PS4.getButtonClick(L1))
        Serial.print(F("\r\nL1"));
      if (PS4.getButtonClick(L3))
        Serial.print(F("\r\nL3"));
      if (PS4.getButtonClick(R1))
        Serial.print(F("\r\nR1"));
      if (PS4.getButtonClick(R3))
        Serial.print(F("\r\nR3"));

      if (PS4.getButtonClick(SHARE))
        Serial.print(F("\r\nShare"));
      if (PS4.getButtonClick(OPTIONS)) {
        Serial.print(F("\r\nOptions"));
        printAngle = !printAngle;
      }
      if (PS4.getButtonClick(TOUCHPAD)) {
        Serial.print(F("\r\nTouchpad"));
        printTouch = !printTouch;
      }

      if (printAngle) { // Print angle calculated using the accelerometer only
        Serial.print(F("\r\nPitch: "));
        Serial.print(PS4.getAngle(Pitch));
        Serial.print(F("\tRoll: "));
        Serial.print(PS4.getAngle(Roll));
      }

      if (printTouch) { // Print the x, y coordinates of the touchpad
        if (PS4.isTouching(0) || PS4.isTouching(1)) // Print newline and carriage return if any of the fingers are touching the touchpad
          Serial.print(F("\r\n"));
        for (uint8_t i = 0; i < 2; i++) { // The touchpad track two fingers
          if (PS4.isTouching(i)) { // Print the position of the finger if it is touching the touchpad
            Serial.print(F("X")); Serial.print(i + 1); Serial.print(F(": "));
            Serial.print(PS4.getX(i));
            Serial.print(F("\tY")); Serial.print(i + 1); Serial.print(F(": "));
            Serial.print(PS4.getY(i));
            Serial.print(F("\t"));
          }
        }
      }
    }
  }
}
