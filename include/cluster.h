#include <bits/stdc++.h>
#include <point.h>
using namespace std;

class cluster{
	public:
		cluster(int val);
		~cluster();
		void readData();
		void train();
	private:
		int k;
		vector<int> clusters;
		vector<point> centroids;
		void init_random();
		vector<point> vec;
		void getClusters();
		void updateCentroids();
		bool Converge();
		int getDistance(point p1,point p2);	
};
