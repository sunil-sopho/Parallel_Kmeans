#include<iostream>

using namespace std;


class point{
	public:
		point(float x1,float y1, float z1);
		float distance(point p);
		float x,y,z;
		void runningMean(point p,int num);
		void print();
};
