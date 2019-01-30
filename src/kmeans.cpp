/*
Author - Sunil Kumar
gitid - sunil-sopho
Projectname - Kmeans
*/

#include<kmeans.h>
using namespace std;



int main(int argc, char** argv){
	int mode=0;
	if(argc>2){
		cout <<"usage :: ./kmeans <mode>"<<endl;
	}
	if(argc==2){
		mode = stoi(argv[1]);
	}

	cluster kmeanSerial(10,mode);
	kmeanSerial.readData();
//	kmeanSerial.printData();
	kmeanSerial.train();
//	kmeanSerial.kScore();
	return 0;
}
