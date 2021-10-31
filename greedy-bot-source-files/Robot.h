/*
* AUTHOR: HUY NGUYEN
* 11/2/2020
*/
#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <string>

using namespace std;

/*
* This class represents a Robot that can move from point A to Z on a 2D plane
* given A's coodinates and Z's coordinates. The Robot can only move horrizontally and
* vertically
*/
class Robot
{
    friend ostream& operator<<(ostream &outStream, const Robot &myRobot)
    {
        outStream << "Robot position is: " << myRobot.get_xr() << "," << myRobot.get_yr()
        << "\nTreasure position is: " << myRobot.get_xt() << "," << myRobot.get_yt() << endl;

        return outStream;
    }

    public:
    //CONSTRUCTOR
    Robot();
    Robot(int xr, int yr, int xt, int yt, int max);
    Robot(const Robot& other);

    //GETTERS
    int get_xr() const;
	int get_yr() const;
    int get_xt() const;
	int get_yt() const;
    int get_max() const;
	int get_paths() const;

    //SETTERS
    void set_xr(int xr);
	void set_yr(int yr);
    void set_xt(int xt);
	void set_yt(int yt);
    void set_max(int max);

    //OPERATOR OVERLOAD
    bool operator == (const Robot& rhs);
	bool operator != (const Robot& rhs);

    //FUNCTIONS

    /*
    * This function initiates the robot and calls different functions
    * in the correct order to help the robot find the paths 
    */
    void StartProgram();

    /*
    * This function calculates the shortest amount of steps
    * the robot needs to take in order to get from the starting 
    * postion (x_r_, y_r_) to the treasure (x_t_, y_t_)
    */
    void ShortestPossibleDistance();

    /*
    * POE stands for Process of Elimination. This function helps
    * increase efficiency by pre-determining the general direction
    * of the treasure relative to the position. For example, the 
    * general direction of treasure (x_t_, y_t_) is North East, thus
    * the robot only needs to move either North and East and not considering
    * South of West
    */
    void POE();

    /*
    * This recursive function is what makes the robot move from
    * the starting postion (x_r_, y_r_) to the treasure (x_t_, y_t_)
    *
    * Parameters:
    * v and h are for determining the general direction 
    * max and spd are robot movement's pre-defined constraints
    * direction is to show the directions that the robot took to
    * get to the treasure
    */
    void Excute(int xr, int yr, int xt, int yt, 
    int v, int h, 
    int max, int spd, string direction);

    private:
    //INSTANCE VARIABLES
    int x_r_, y_r_, x_t_, y_t_;
    int max_distance_;
    int spd_;
    int horizontal_, vertical_;
    int total_;
};

#endif