#include<iostream>

using namespace std;


class point{
	public:
		point(int x1,int y1, int z1);
		long distance(point p);
		int x,y,z;
		void runningMean(point p,int num);
};
