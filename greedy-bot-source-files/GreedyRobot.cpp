/*
* AUTHOR: HUY NGUYEN
* 11/2/2020
*/

#include <iostream>
#include <string>
#include "Robot.h"
#include "Point.h"

using namespace std;
/*
* Driver class used for running Robot and Point
*/

int main(int argc, char *argv[])
{
    //Robot myRobot(1, 2, 3 ,5, 2);
    Point startingPoint(atoi(argv[1]), atoi(argv[2]));
    Point endingPoint(atoi(argv[3]), atoi(argv[4]));

    Robot myRobot (startingPoint.get_x(),startingPoint.get_y(),
    endingPoint.get_x(),endingPoint.get_y(),atoi(argv[5]));

    myRobot.StartProgram(); 
}

