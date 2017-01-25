#include <Adafruit_MotorShield.h>

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor = AFMS.getMotor(1);

void motorOn();
void motorOff();

long data;


boolean isRunning;

void setup()
{
  Serial.begin(9600);
  Serial.println("Auto-Coffee Grinder starting up");

  isRunning = false;
  AFMS.begin();
  motor->setSpeed(255);
}

void loop()
{
  if (Serial.available() > 0)
  {
    long data = Serial.parseInt();
    Serial.print(data);
    Serial.print("\n");
    if (data == 1)
    {
      motor->run(FORWARD);
      isRunning = true;
      Serial.print("Motor On");
      Serial.print("\n");
    } else if (data == 0)
    {
      motor->run(RELEASE);
      isRunning = false;
      Serial.print("Motor Off");
    }
  }
}


void motorOn()
{
  motor->run(FORWARD);
  isRunning = true;
}

void motorOff()
{
  motor->run(RELEASE);
  isRunning = false;
}
