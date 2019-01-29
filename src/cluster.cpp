#include <cluster.h>

cluster::cluster(int val){
	k = val; // setting k for kmeans
	pointsChange = -1; //For debugging purpose
	dataPoints = -1; // negative itialization
}

// Set dataPoints here @check @sunil
void cluster::readData(){
	cout <<"start\n";
	freopen("./dataset/input1.csv", "r", stdin);
	string s,delimiter=",";
	getline(cin,s);
	getline(cin,s);
	while(getline(cin,s)){
//		cout << s<<endl;
		size_t pos = 0;
		std::string token;
		vector<float> v;
		while ((pos = s.find(delimiter)) != std::string::npos) {
		    token = s.substr(0, pos);
//		    std::cout << token << std::endl;
		    v.push_back(stod(token));
		    s.erase(0, pos + delimiter.length());
		}
//		std::cout << s << std::endl;
		v.push_back(stod(s));
//		point pnew(stod(v[1]),stod(v[2]),stod(v[3]));
		point pnew(v[0],v[1],v[2]);
		vec.push_back(pnew);
		clusters.push_back(-1);
		dataPoints++;
	}
	cout << "data Points Collected :: "<<dataPoints+1<<endl;
}

void cluster::printData(){
	for(int i=0;i<dataPoints;i++){
		cout << vec[i].x <<" "<<vec[i].y<<" "<<vec[i].z<<endl;
	}
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
	init_random();
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
	
	//After Convergence print data centroid details
	printCentroids();
}

void cluster::getClusters(){
	int changedPoints = 0;
	for(int i=0;i<vec.size();i++){
		float distance = 1e7;
		int clas = clusters[i];
		for(int j=0;j<k;j++){
			float dist = getDistance(vec[i],centroids[j]);
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
	cout <<"Points Changed :: "<< pointsChange<<endl;
}

void cluster::updateCentroids(){
	for(int i=0;i<k;i++){
		point pmean(0.0,0.0,0.0);
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

void cluster::printCentroids(){
	for(int i=0;i<k;i++){
		centroids[i].print();
	}
}

float cluster::getDistance(point p1,point p2){
	return p1.distance(p2);
}

bool cluster::Converge(int iterationNumber){
	if(pointsChange <= dataPoints*0.00)
		return true;
	if(iterationNumber > 100)
		return true;
	return false;

}

double runningDistance(double tillNow,long num,float newdist){

	return ((float)(num-1)/num)*tillNow+ ( (float)(1)/(float)num )*newdist;
}
double cluster::kScore(){
	double kscore = 0;
	double subScore = 0;
	vector<int> clusterIdMap[k];
	for(int i=0;i<dataPoints;i++){
		clusterIdMap[clusters[i]].push_back(i);
	}
	for(int i=0;i<k;i++){
		cout << "Cluster ID "<<i+1<<" :: "<<clusterIdMap[i].size()<<endl;
		float dist =0;
		long count=0;
		for(int j=0;j<clusterIdMap[i].size();j++){
			for(int k=j+1;k<clusterIdMap[i].size();k++){
				dist = getDistance( vec.at(clusterIdMap[i][j]),vec[ clusterIdMap[i][k] ]);
				count++;
				subScore = runningDistance(subScore,count,dist);				
			}
		}
		subScore *= (float)(clusterIdMap[i].size())/4;
		cout << "SubScore :: "<<subScore<< endl;
		kscore += subScore;
	}
	cout << "KScore for K "<<k<<" :: "<<kscore<<endl;
	
}



