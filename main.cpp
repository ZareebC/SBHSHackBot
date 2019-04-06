#include "vex.h"
using namespace vex;
const float WHEEL_DIAM = 4.125;
void pre_auton(void){

}
void driveFor( float tiles , int speed ){
    //calculates amount of required degrees based on wheel circumference and desired tile length
    const float TILE_LENGTH = 12.5;
    float length = tiles * TILE_LENGTH;
    float circum =  3.141592653589 * WHEEL_DIAM;
    float rotations = length / circum;
    float degrees = 360 * rotations;

    Rightmotor.startRotateFor(degrees, rotationUnits::deg, speed, velocityUnits::pct);
    Leftmotor.startRotateFor(degrees, rotationUnits::deg, speed, velocityUnits::pct);
}

int auton_rectangle(){
  Brain.Screen.clearScreen();
  Brain.Screen.drawRectangle(10, 10, 140, 75, color::red);
  Brain.Screen.drawRectangle(160, 10, 140, 75, color::red);
  Brain.Screen.printAt(31, 35, "Move Forward");
  Brain.Screen.printAt(183, 35, "Start");
  while(true){
    if(Brain.Screen.pressing()){
      int xPos = Brain.Screen.xPosition();
      int yPos = Brain.Screen.yPosition();
      if(yPos >= 10 && yPos <= 85) {
        if(xPos >= 10 && xPos <= 150) {
          return 1;
        }
        else if(xPos >= 160 && xPos <= 300) {
          return 2;
        }
      }
    }
  }
  pre_auton();
  int auton = auton_rectangle();
  Brain.Screen.clearScreen();
  task::sleep(1000);
  switch(auton){
    case 1: {
      driveFor(3.75, 100);
      break;
      }
  }
  
}
int main() {
    

    pre_auton();

    while(1) {
      task::sleep(100);
    }
}


