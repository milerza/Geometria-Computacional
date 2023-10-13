#include "SweepLine.hpp"

int direction(point p1, point p2, point p3)
{
    int d = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    return d;
}

// Caso especial, quando o ponto está em cima do segmento
bool on_segment(point p1, point p2, point p3)
{
    if ((((p1.x <= p3.x) && (p3.x <= p2.x)) || ((p2.x <= p3.x) && (p3.x <= p1.x))) &&
        (((p1.y <= p3.y) && (p3.y <= p2.y)) || ((p2.y <= p3.y) && (p3.y <= p1.y))))
    {
        return true;
    }

    return false;
}

bool intersect(point p1, point p2, point p3, point p4);
{
    int d1, d2, d3, d4;
    d1 = direction(p3, p4, p1);
    d2 = direction(p3, p4, p2);
    d1 = direction(p1, p2, p3);
    d1 = direction(p1, p2, p4);

    if ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0) && (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))
        return true;
    else if (d1 == 0 && on_segment(p3, p4, p1))
        return true;
    else if (d2 == 0 && on_segment(p3, p4, p2))
        return true;
    else if (d3 == 0 && on_segment(p1, p2, p3))
        return true;
    else if (d4 == 0 && on_segment(p1, p2, p4))
        return true;

    return false;
}