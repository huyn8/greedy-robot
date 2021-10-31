/*
* AUTHOR: HUY NGUYEN
* 11/2/2020
*/
#include "Robot.h"

//CONSTRUCTORS
Robot::Robot()
{
    x_r_ = 0;
    y_r_ = 0;
    x_t_ = 0;
    y_t_ = 0;
    max_distance_ = 0;
    total_ = 0;
}

Robot::Robot(int xr, int yr, int xt, int yt, int max)
{
    x_r_ = xr;
    y_r_ = yr;
    x_t_ = xt;
    y_t_ = yt;
    max_distance_ = max;
    total_ = 0;
}

Robot::Robot(const Robot& other)
{
    x_r_ = other.get_xr();
    y_r_ = other.get_yr();
    x_t_ = other.get_xt();
    y_t_ = other.get_yt();
    max_distance_ = other.get_max();
    total_ = other.get_paths();
}


//GETTERS
int Robot::get_xr() const
{
    return x_r_;
}
int Robot::get_yr() const
{
    return y_r_;
}
int Robot::get_xt() const
{
    return x_t_;
}
int Robot::get_yt() const
{
    return y_t_;
}
int Robot::get_max() const
{
    return max_distance_;
}
int Robot::get_paths() const
{
    return total_;
}

//SETTERS
void Robot::set_xr(int xr)
{
    x_r_ = xr;
}
void Robot::set_yr(int yr)
{
    y_r_ = yr;
}
void Robot::set_xt(int xt)
{
    x_t_ = xt;
}
void Robot::set_yt(int yt)
{
    y_t_ = yt;
}
void Robot::set_max(int max)
{
    max_distance_ = max;
}

//OPERATORS OVERLOAD
bool Robot::operator == (const Robot& rhs)
{
    if(x_r_ == rhs.get_xr() && y_r_ == rhs.get_yr() &&
        x_t_ == rhs.get_xt() && y_t_ == rhs.get_yt() &&
        max_distance_ == rhs.get_max())
        {
            return true;
        }
    return false;
}

bool Robot::operator != (const Robot& rhs)
{
    if(x_r_ != rhs.get_xr() && y_r_ != rhs.get_yr() &&
        x_t_ != rhs.get_xt() && y_t_ != rhs.get_yt() &&
        max_distance_ != rhs.get_max())
        {
            return true;
        }
    return false;
}

/*
* This function calculates the shortest amount of steps
* the robot needs to take in order to get from the starting 
* postion (x_r_, y_r_) to the treasure (x_t_, y_t_)
*/
//Calculate the least steps needed to take
void Robot::ShortestPossibleDistance()
{
    spd_ =  abs(x_r_ - x_t_) + abs(y_r_ - y_t_);
}

/*
* POE stands for Process of Elimination. This function helps
* increase efficiency by pre-determining the general direction
* of the treasure relative to the position. For example, the 
* general direction of treasure (x_t_, y_t_) is North East, thus
* the robot only needs to move either North and East and not considering
* South of West
*/
void Robot::POE()
{
    if(x_t_ > x_r_)
    {
        horizontal_ = 1;
    }
    else
    {
        horizontal_ = -1;
    }

    if(y_t_ > y_r_)
    {
        vertical_ = 1;
    }
    else
    {
        vertical_ = -1;
    }
}

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
void Robot::Excute(int xr, int yr, int xt, int yt, 
int v, int h, 
int max, int spd, string direction = "")
{
    //BASE CASE 1
    if(xr == xt && yr == yt)
    {
  
        total_++;
        cout << direction << endl;
        return;
    }

    //BASE CASE 2
    if(spd == 0)
    {        
        return;
    }

    else
    {
        //Checking all relavant conditions to see if it's possible to move North
        if(yr+1 <= yt && v > 0 && (v <= max))
        {
            //Move up or North
            //Reseting horrizontal direction 
            Excute(xr, yr+1, xt, yt, v+1, horizontal_, max, spd-1, direction + "N");
        }

        //Checking all relavant conditions to see if it's possible to move South
        if(yr-1 >= yt && v < 0 && v >= (-max))
        {
            //Move down or South
            Excute(xr, yr-1, xt, yt, v-1, horizontal_, max, spd-1, direction + "S");
        }


        //Checking all relavant conditions to see if it's possible to move East
        if(xr+1 <= xt && h > 0 && (h <= max))
        {
            //Move right or East
            //Resetting vertical direction
            Excute(xr+1, yr, xt, yt, vertical_, h+1, max, spd-1, direction + "E");   
        }

        //Checking all relavant conditions to see if it's possible to move West
        if(xr-1 >= xt && h < 0 && h >= (-max))
        {
            //Move left or West
            Excute(xr-1, yr, xt, yt, vertical_, h-1, max, spd-1, direction + "W");
        }
    }
    return;
}

/*
* This function initiates the robot and calls different functions
* in the correct order to help the robot find the paths 
*/
void Robot::StartProgram()
{
    //Taking in user input (integers only)
    // cout << "Enter 5 integers seprated by a space: ";
    // cin >> x_r_ >> y_r_ >> x_t_ >> y_t_ >> max_distance_;

    //Robot's path finding processes
    ShortestPossibleDistance();
    POE();
    Excute(x_r_, y_r_, x_t_, y_t_, 
    vertical_, horizontal_, 
    max_distance_, spd_, "");

    if(total_ != 0)
    {
        cout << "Total paths found: " << total_ << endl;
    }

    else
    {
        cout << "No paths were found" << endl;
    }
}