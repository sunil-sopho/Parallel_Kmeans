#include<point.h>
#include<cmath>

using namespace std;

point::point(int x1,int y1,int z1){
	x = x1;
	y = y1;
	z = z1;
}
long point::distance(point p){
	long t1 = x-p.x;
	long t2 = y-p.y;
	long t3 = z-p.z;
	return sqrt(t1*t1+t2*t2+t3*t3);
}
