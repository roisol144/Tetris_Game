#include "Point.h"

// Figure out how to change it to const.
void Point::rotateClockwise(Point& pivot)
{
    int newX = pivot.getX() + (pivot.getY() - y);
    int newY = pivot.getY() - (pivot.getX() - x);
    this->x = newX;
    this->y = newY;
}

void Point::rotateCounterClockwise(Point& pivot)
{
    int newX = pivot.getX() - (pivot.getY() - y);
    int newY = pivot.getY() + (pivot.getX() - x);
    this->x = newX;
    this->y = newY;
}



