/*
 * Arduino PS2 Example Program for PSX2 Library
 * Made by Michael Geraghty 2018
 * Email me at: hungrymike@live.com
 */

#include <PS2X_lib.h>

#define PS2_DAT 13
#define PS2_CMD 11
#define PS2_SEL 10
#define PS2_CLK 12

#define pressures false
#define rumble false

PS2X ps2x;

int error = 0;
byte type = 0;
byte vibrate = 0;

void setup()
{
  Serial.begin(9600); // Natively, should be 57600 (56kbps)
  delay(300); // For wireless PS2 controller module to startup
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  if (error == 0)
  {
    Serial.println("Found PS2 Controller, Configuration Successful!");
  }
  // Extra code for PS2 Error code goes above
  type = ps2x.readType(); // Check what type of controller the controller connected is
  switch (type)
  {
    case 0:
      Serial.println("Unknown PS2 Controller type found!");
      break;
    case 1:
      Serial.println("DualShock Controller found!");
      break;
    case 3:
      Serial.println("Wireless DualShock Controller Found!");
      break;
  }
}

void loop()
{
  // If no controller found, just halt the arduino's ATMEGA328P
  if (error == 1)
  {
    return;
  }
  ps2x.read_gamepad(false, vibrate);
  // Middle buttons
  if (ps2x.Button(PSB_START))
  {
    Serial.println("Start Pressed");
  }
  if (ps2x.Button(PSB_SELECT))
  {
    Serial.println("Select Pressed");
  }
  // DPAD Buttons
  if (ps2x.Button(PSB_PAD_UP))
  {
    Serial.println("DPAD UP Pressed!");
  }
  if (ps2x.Button(PSB_PAD_DOWN))
  {
    Serial.println("DPAD DOWN Pressed!");
  }
  if (ps2x.Button(PSB_PAD_RIGHT))
  {
    Serial.println("DPAD RIGHT Pressed!");
  }
  if (ps2x.Button(PSB_PAD_LEFT))
  {
    Serial.println("DPAD LEFT Pressed!");
  }
  // XOST Buttons
  if (ps2x.Button(PSB_CROSS))
  {
    Serial.println("X Pressed!");
  }
  if (ps2x.Button(PSB_CIRCLE))
  {
    Serial.println("Circle Pressed!");
  }
  if (ps2x.Button(PSB_SQUARE))
  {
    Serial.println("Square Pressed!");
  }
  if (ps2x.Button(PSB_TRIANGLE))
  {
    Serial.println("Triangle Pressed!");
  }
  // LR Buttons
  if (ps2x.Button(PSB_L1))
  {
    Serial.println("L1 Pressed!");
  }
  if (ps2x.Button(PSB_R1))
  {
    Serial.println("R1 Pressed!");
  }
  if (ps2x.Button(PSB_L2))
  {
    Serial.println("L2 Pressed!");
  }
  if (ps2x.Button(PSB_R2))
  {
    Serial.println("R2 Pressed!");
  }
  // Stick buttons
  if (ps2x.Button(PSB_L3))
  {
    Serial.print("Left Stick: ");
    Serial.print(ps2x.Analog(PSS_LY), DEC);
    Serial.print(", ");
    Serial.print(ps2x.Analog(PSS_LX), DEC);
    Serial.println(""); // Newline
  }
  if (ps2x.Button(PSB_R3))
  {
    Serial.print("Right Stick: ");
    Serial.print(ps2x.Analog(PSS_RY), DEC);
    Serial.print(", ");
    Serial.print(ps2x.Analog(PSS_RX), DEC);
    Serial.println(""); // Newline
  }
  delay(50);
}

