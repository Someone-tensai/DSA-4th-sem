#include<iostream>
using namespace std;

double calc_angle(double h, double m)
{
    // Invalid times
    if( h < 0 || m < 0 || h > 12 || m > 60)
    {
        cout << "Invalid Input\n";
    }

    // If its 12th hour, default to 0
    if(h == 12) h = 0;
    // If its 60th minute, default to 0 minutes and add an hour
    if(m == 60)
    {
        m = 0;
        h = h+1;
        // If hour greater than 12, bring it down by 12
        if(h > 12)
        {
            h = h-12;
        }
    }
    // Hour hand travels 360 degrees in 12 hours
    // i.e. 0.5 degrees in one minute(360/720)
    double angle_hour = (h*60+m) * 0.5;

    // Minute hand travels 360 degrees in 60 minutes
    // i.e. 6 degrees in one minute(360/60)
    double angle_minute = m * 6;

    // Angle between them
    double angle = abs(angle_hour - angle_minute);
    
    return  angle < (360 - angle)?angle: 360-angle;
}
int main()
{
    double hour, minute;
    cout << "Enter the hour: ";
    cin >> hour;
    cout << "Enter the minute: ";
    cin >> minute;
    double angle = calc_angle(hour, minute);
    cout << "Angle between hour and minute hands is: " << angle;
}   