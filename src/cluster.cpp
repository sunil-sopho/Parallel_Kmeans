#include <cluster.h>

cluster::cluster(int val){
	k = val; // setting k for kmeans
}

void cluster::readData(){
	
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
		if(Converge()){
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
}

void cluster::updateCentroids(){
}


