/*
 * C++ program designed to calculate the time it will take to mow a lawn around a house, given certain dimensions
 * @Brady Butcher
 * @1.12.2023
 * CPS 171-01 Machine Problem 01
 */
#include <iostream>
using namespace std;

int main()
{
    double lawn_length;      // measured in ft
    double lawn_width;       // measured in ft
    double lawn_area;        // measured in ft
    double house_length;     // measured in ft
    double house_width;      // measured in ft
    double mowing_speed;     // measured in fpm
    double amount_mowed;     // measured in sq. fpm
    double blade_width = 18; // measured in inches
    double walking_speed;    // measured in mph
    double mowing_time;      // measured in minutes

    /*Receiving dimensions by entering input*/
    cout << "Enter the length of the lawn in feet: ";
    cin >> lawn_length;
    cout << "Enter the width of the lawn in feet: ";
    cin >> lawn_width;
    cout << "Enter the length of the house in feet: ";
    cin >> house_length;
    cout << "Enter the width of the house in feet: ";
    cin >> house_width;
    cout << "Enter your walking speed in mph: ";
    cin >> walking_speed;

    /*The calculations step*/
    lawn_area = (lawn_length * lawn_width) - (house_length * house_width); // finding the area of the lawn available to mow by subtracting the area of the house from the area of the lawn
    amount_mowed = ((walking_speed * 5280) / 60) * (blade_width / 12);     // finding the area that can be mowed per minute by multiplying the speed at which the lawn can be mowed by the width of the blade
    mowing_time = lawn_area / amount_mowed;                                // finding the time it will take to mow the lawn by dividing the area of the lawn by the area that can be mowed per minute

    /*Output*/
    cout << "\nThe lawn is " << lawn_length << " by " << lawn_width << " feet." << endl;
    cout << "The house is " << house_length << " by " << house_width << " feet." << endl;
    cout << "Your walking speed is " << walking_speed << " mph." << endl;

    cout << "\nThe area of the lawn to mow is " << lawn_area << " square feet." << endl;
    cout << "You can mow " << amount_mowed << " square feet per minute." << endl;
    cout << "It will take " << mowing_time << " minutes to mow the lawn." << endl;
}