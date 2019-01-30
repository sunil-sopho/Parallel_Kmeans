#include <bits/stdc++.h>
#include <point.h>
#include <omp.h>
#include <pthread.h>

using namespace std;

class cluster{
	public:
		// mode = 0 for serial
		// mode = 1 for pthread
		// mode = 2 for openmp
		cluster(int val,int mode=0);
		~cluster();
		void readData();
		void train();
		void printData();
		double kScore();
	private:
//		int k;
		int mod;
//		int pointsChange;
		int dataPoints;
//		vector<int> clusters;
//		vector<point> centroids;
		void init_random();
//		vector<point> vec;
		void getClusters();
		void updateCentroids();
		bool Converge(int iterationNumber);
//		float getDistance(point p1,point p2);	
		void printCentroids();
//		void* clusterSetter(void* tid);
//		int classChecker(int i);

};
