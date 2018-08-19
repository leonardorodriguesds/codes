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

int main(){
    auto a = Point(4.1, 5.1), b = Point(4.1, 5.1);
    if(a == b) printf("s\n");
    return 0;
}