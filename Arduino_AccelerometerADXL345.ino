// Arduino code and library is available to download - link below the video.
 
/* Accelerometer connection pins (I2C) to Arduino are shown below:

Arduino     Accelerometer ADXL345
  A5            SCL
  A4            SDA
  3.3V          CS
  3.3V          VCC
  GND           GND
*/ 

#include <Wire.h>
#include <ADXL345.h>


ADXL345 adxl; //variable adxl is an instance of the ADXL345 library

int x,y,z;  
int rawX, rawY, rawZ;
float X, Y, Z;
float rollrad, pitchrad;
float rolldeg, pitchdeg;

void setup(){
  Serial.begin(9600);
  adxl.powerOn();
}

void loop(){
  adxl.readAccel(&x, &y, &z); //read the accelerometer values and store them in variables  x,y,z
  // Output (x,y,z) on horizontal plane should be approximately (0,0,255) 
  // the following 3 lines is for an offset
  rawX=x-7;
  rawY=y-6;
  rawZ=z+10;
   
  X = rawX/256.00; // used for angle calculations
  Y = rawY/256.00; // used for angle calculations
  Z = rawZ/256.00; // used for angle calculations
   
  rollrad = atan(Y/sqrt(X*X+Z*Z));  // calculated angle in radians
  pitchrad = atan(X/sqrt(Y*Y+Z*Z)); // calculated angle in radians
  
  rolldeg = 180*(atan(Y/sqrt(X*X+Z*Z)))/PI; // calculated angle in degrees
  pitchdeg = 180*(atan(X/sqrt(Y*Y+Z*Z)))/PI; // calculated angle in degrees
  // print out values:
   Serial.println(z);     // raw data without offset

  delay(1000);
}
