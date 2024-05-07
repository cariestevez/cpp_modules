#include "Point.hpp"
#include <cstdio>

//take two axis of the triangle to create a plane dividing line
//(edge of the triangle between this two coords is on the line)
//returns true if the point is on the same side of the plane as the 3rd axis(=rest of the triangle)
// Ax + By + C = 0
// y = mx + c
bool    isOnSameSide(Point const &axisA, Point const &axisB, Point const &thirdAxis, Point const &point)
{
    Fixed   A = axisB.getY() - axisA.getY();
    Fixed   B = axisA.getX() - axisB.getX();
    Fixed   C = Fixed(-1) * (A * axisA.getX() + B * axisA.getY());
  
    Fixed   thirdAxisValue = A * thirdAxis.getX() + B * thirdAxis.getY() + C;
    Fixed   pointValue = A * point.getX() + B * point.getY() + C;

    // Fixed   slope;
    // slope = (axisB.getY() - axisA.getY()) / (axisB.getX() - axisA.getX());
    // Fixed   B;
    // //axisA.getY() = slope * axisA.getX() + B;
    // B = axisA.getY() - (slope * axisA.getX());
    // Fixed   A;
    // A = Fixed(-1) / slope;
    // Fixed   anotherC = Fixed(-1) * (A * point.getX() + B * point.getY());
    // if (anotherC == C)
    //     std::cout << "is same " << std::endl;

    // std::cout << std::endl;
    // std::cout << "A: " << A << std::endl;
    // std::cout << "B: " << B << std::endl;
    // std::cout << "C: " << C << std::endl;


    // std::cout << "point value " << pointValue << std::endl;
    //printf("result of line equ of point: %d\n", pointValue.getRawBits());
    // float threshold = 0.001;
    // //float cero
    // // Tolerance threshold for zero comparison
    // Fixed tolerance = threshold; // Adjust as needed

    // // Check if the result is within tolerance of zero
    // if (thirdAxisValue < tolerance && thirdAxisValue > Fixed(-1) * tolerance &&
    //     pointValue < tolerance && pointValue > Fixed(-1) * tolerance)
    //     return false;
    // // if line equation result is 0, point is on the line(=> outside or on edge of triangle)
    if (thirdAxisValue == 0 || pointValue == 0)
        return false;
    //if both have the same sign, point is on the same side of the plane as the triangle
    if ((thirdAxisValue > 0.0f && pointValue > 0.0f) || (thirdAxisValue < 0.0f && pointValue < 0.0f))
        return true;
    return false;
}

// a, b and c hold the coordinates of the 3 axis of the triangle
// if checking from each of the edges, the point is on the same plane as the rest of the triangle
// the point can't but be inside of it
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if (isOnSameSide(a, b, c, point) && isOnSameSide(b, c, a, point)
        && isOnSameSide(c, a, b, point))
        return true;
    return false;
}

/*
1. Use the line equation to create a dividing line (one for each of the sides of the triangle)
Ax + By + C = 0
A = ax - bx
B = ay- by
by calculating this, we can find any of the points that are on that line,
just by substituting x an y for the coordinates of the point
2. After finding out the C coeficient, use the line equation again substituting x and y by the 3rd
axis of the triangle and once more for the point
If the value of the equation is 0 it means the point is ON the line
Depending on the sign of the value, it means it is on one or the other side of the line
3. Do it for the other two sides of the triangle. If the point is always on the same plane (side)
it means it is inside of the triangle.
*/
// a, b, c: The vertices of our beloved triangle.
// • point: The point to check.
// • Returns: True if the point is inside the triangle. False otherwise.
// Thus, if the point is a vertex or on edge, it will return False.


// Fixed   crossProduct(Point const &axisA, Point const &axisB, Point const &point)
// {
//     Fixed   abX = axisB.getX() - axisA.getX();
//     Fixed   abY = axisB.getY() - axisA.getY();
//     Fixed   apX = point.getX() - axisA.getX();
//     Fixed   apY = point.getY() - axisA.getY();

//     Fixed result = abX * apY - apX * abY;

//     return result;
// }

// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
//     Fixed resultAB = crossProduct(a, b, point);
//     Fixed resultBC = crossProduct(b, c, point);
//     Fixed resultCA = crossProduct(c, a, point);

//     if ((resultAB > 0 && resultBC > 0 && resultCA > 0) || (resultAB < 0 && resultBC < 0 && resultCA < 0))
//        return true;
//     return false;
  
// }