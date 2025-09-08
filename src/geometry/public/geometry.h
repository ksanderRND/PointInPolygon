#pragma once

#include <vector>

#define eps 0.0001

struct Point
{
    double X;
    double Y;
};

typedef std::vector<Point> Polygon;

bool isInside(Polygon polygon, Point p);