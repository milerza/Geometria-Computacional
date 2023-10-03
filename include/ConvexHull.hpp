#ifndef CONVEX_HULL
#define CONVEX_HULL

#include <vector>
#include "Point.hpp"

class convexHull {
    private:
        std::vector<point> points;
    
    public:
        std::vector<point> giftWrapping();

    private:
        int orientation(point p1, point p2, point p3);
};

#endif