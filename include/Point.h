#ifndef POINT
#define POINT

struct Point {
    int x;
    int y;

    Point(){
        x = 0;
        y = 0;
    }

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

static bool operator==(const Point& a, const Point& b){
    return (a.x==b.x && a.y==b.y);
}

#endif
