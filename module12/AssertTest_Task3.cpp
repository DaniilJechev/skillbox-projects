#include <iostream>
#include <cassert>

float travelTime(float distance, float speed)
{
    return (distance / speed);
}

int main()
{
    float distance, speed;
    std::cout << "Please enter the distance and speed: ";
    std::cin >> distance >> speed;
    assert(speed >= 330 && distance > 50 );

    std::cout << "Flight time is " <<travelTime(distance, speed) << " hours.";
}