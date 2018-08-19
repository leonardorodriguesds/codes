#include <bits/stdc++.h>
using namespace std;
#define EPS             (1e-9)

bool equals(double a, double b){
    return fabs(a - b) < EPS;
}

typedef struct _Point{
    double x, y;
    _Point(double x, double y): x(x), y(y){};
    bool operator==(Point& other){
        return equals(this->x, other.x) && equals(this->y, other.y);
    };
    bool operator<(Point& other){
        return (equals(this->x, other.x)) ? (this->y - other.y) > EPS : this->x - other.x > EPS;
    };
    double distance(Point& other){
        return hypot(this->x - other.x, this->y - other.y);  
    };
} Point;

int main(){
    
    return 0;
}