#include <bits/stdc++.h>
using namespace std;
#define EPS             (1e-9)

bool equals(double a, double b){
    return fabs(a - b) < EPS;
}

typedef struct _Point{
    double x, y;
    _Point(double x, double y): x(x), y(y){};
    bool operator==(_Point& other){
        return equals(this->x, other.x) && equals(this->y, other.y);
    };
    bool operator<(_Point& other){
        return (equals(this->x, other.x)) ? (this->y - other.y) > EPS : this->x - other.x > EPS;
    };
    double distance(_Point& other){
        return hypot(this->x - other.x, this->y - other.y);  
    };
} Point;

class Vector{
    public:
        double x, y;

        Vector(double x, double y): x(x), y(y){};
        Vector(Point& a, Point& b): x(b.x - a.x), y(b.y - a.y){};
        void translate(double dx, double dy){
            x += dx, y += dy;
        };
        void rotate(double angle){
            x = cos(angle) * x - sin(angle) * y;
            y = sin(angle) * y + cos(angle) * y;
        }
};

Point translate(const Point& p, double dx, double dy){
    return Point{ p.x + dx, p.y + dy };
}
Point rotate(const Point& p, double angle){
    double x = cos(angle) * p.x - sin(angle) * p.y;
    double y = sin(angle) * p.y + cos(angle) * p.y;
    return Point{x, y};
}

int main(){
    
    return 0;
}