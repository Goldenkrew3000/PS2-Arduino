/*
 * Arduino PS2 Example Program for PS2X Library (Hexadecimal)
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
  Serial.begin(9600); // For normal projects, 9600 is normal
  delay(300); // For wireless PS2 controller module to start
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  if (error == 0)
  {
    Serial.println("Found PS2 Controller, Configuration Successful!");
  }
  type = ps2x.readType();
  switch (type)
  {
    case 0:
      Serial.println("Unknown PS2 Controller type found!");
      break;
    case 1:
      Serial.println("DualShock PS2 Controller found!");
      break;
    case 3:
      Serial.println("Wireless DualShock PS2 Contoller found!");
      break;
  }
}

void loop()
{
  // If no controller was found, just put the ATMEGA328P into an infinite loop until RESET
  if (error == 1)
  {
    return;
  }
  ps2x.read_gamepad(false, vibrate);
  // Start Button
  if (ps2x.Button(0x0008))
  {
    Serial.println("Start Button Pressed!");
  }
  // Select Button
  if (ps2x.Button(0x0001))
  {
    Serial.println("Select Button Pressed!");
  }
  // DPAD UP
  if (ps2x.Button(0x0010))
  {
    Serial.println("DPAD UP Pressed!");
  }
  // DPAD DOWN
  if (ps2x.Button(0x0040))
  {
    Serial.println("DPAD DOWN Pressed!");
  }
  // DPAD LEFT
  if (ps2x.Button(0x0080))
  {
    Serial.println("DPAD LEFT Pressed!");
  }
  // DPAD RIGHT
  if (ps2x.Button(0x0020))
  {
    Serial.println("DPAD RIGHT Pressed!");
  }
  // X
  if (ps2x.Button(0x4000))
  {
    Serial.println("X Pressed!");
  }
  // O
  if (ps2x.Button(0x2000))
  {
    Serial.println("O Pressed!");
  }
  // Triangle
  if (ps2x.Button(0x1000))
  {
    Serial.println("Triangle Pressed!");
  }
  // Square
  if (ps2x.Button(0x8000))
  {
    Serial.println("Square Pressed!");
  }
  // L1
  if (ps2x.Button(0x0400))
  {
    Serial.println("L1 Pressed!");
  }
  // R1
  if (ps2x.Button(0x0800))
  {
    Serial.println("R1 Pressed!");
  }
  // L2
  if (ps2x.Button(0x0100))
  {
    Serial.println("L2 Pressed!");
  }
  // R2
  if (ps2x.Button(0x0200))
  {
    Serial.println("R2 Pressed!");
  }
  delay(50);
}

