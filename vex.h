using namespace "vex";
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include <include vex/mkrules.mk>

#include "v5.h"
#include "v5_vcs.h"
//
const int RIGHT_PORT = PORT1;
const int LEFT_PORT = PORT2;
const int ROLLER = PORT3;
brain Brain = brain();
controller Controller = controller();
competition comp = competition();
motor Rightmotor = motor(RIGHT_PORT, true);
motor Leftmotor = motor(RIGHT_PORT, false);
motor Roller = motor(ROLLER, false);
