#include <cluster.h>

cluster::cluster(int val){
	k = val; // setting k for kmeans
	pointsChange = -1; //For debugging purpose
	dataPoints = -1; // negative itialization
}

// Set dataPoints here @check @sunil
void cluster::readData(){
	cout << "data Points Collected :: "<<dataPoints<<endl;
}

cluster::~cluster(){
	clusters.clear();
	centroids.clear();
	vec.clear();
	cout << " Destroyer Called "<<endl;
}
void cluster::init_random(){
 	random_shuffle(vec.begin(),vec.end());
	if(centroids.size() > 0)
		throw invalid_argument("centroids are already fetched\n");
	if(k>vec.size())
		throw invalid_argument("groups is more than number of elements");
	
	for(int i=0;i<k;i++){
		centroids.push_back(vec[i]);
	}
}

void cluster::train(){
	bool run = true;
	int iterationNum=0;
	while(run){
		cout << "Iteration Number ::"<< ++iterationNum <<endl;
		getClusters();
		// now chose new centroids
		updateCentroids();
		// check for convergence
		if(Converge(iterationNum)){
			break;
		}
	}

}

void cluster::getClusters(){
	vector<int> clustersNew;
	int changedPoints = 0;
	for(int i=0;i<vec.size();i++){
		long distance = 1e12;
		int clas = clusters[i];
		for(int j=0;j<k;j++){
			long dist = getDistance(vec[i],centroids[j]);
			if(dist < distance){
				distance = dist;
				clas = j;
			}
		}
		if(clas == -1){
			cout << "exited due to class -1\n"; 
		}
		if(clusters[i] != clas)
			changedPoints++;
		clusters[i] = clas;	
	}
	pointsChange = changedPoints;	
}

void cluster::updateCentroids(){
	for(int i=0;i<k;i++){
		point pmean(0,0,0);
		int numPoints = 1;
		for(int j=0;j<dataPoints;j++){
			if(clusters[j]==i){
				pmean.runningMean(vec[j],numPoints);
				numPoints++;
			}
		}
		centroids[i] = pmean;
	}
}

long cluster::getDistance(point p1,point p2){
	return p1.distance(p2);
}

bool cluster::Converge(int iterationNumber){
	if(pointsChange < dataPoints*0.005)
		return true;
	if(iterationNumber > 100)
		return true;
	return false;

}
