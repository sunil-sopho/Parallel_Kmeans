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

void point::runningMean(point p,int num){
	float ratio1 = (float)(num-1)/(float)num;
	float ratio2 = (float)1/(float)num;
	x = ratio1*x + ratio2*p.x;
	y = ratio1*y + ratio2*p.y;
	z = ratio1*z + ratio2*p.z; 
}
