#include<point.h>
#include<cmath>

using namespace std;

point::point(float x1,float y1,float z1){
//	cout <<"point constructer\n";
	x = x1;
	y = y1;
	z = z1;
}

float point::distance(point p){
	float t1 = x-p.x;
	float t2 = y-p.y;
	float t3 = z-p.z;
	return sqrt(t1*t1+t2*t2+t3*t3);
}

void point::runningMean(point p,int num){
	float ratio1 = (float)(num-1)/(float)num;
	float ratio2 = (float)1/(float)num;
	x = ratio1*x + ratio2*p.x;
	y = ratio1*y + ratio2*p.y;
	z = ratio1*z + ratio2*p.z; 
}

void point::print(){
	cout << "point print :: "<<x <<" "<< y << " " <<z<<endl;
}
