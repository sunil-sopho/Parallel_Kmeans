/*
Author - Sunil Kumar
gitid - sunil-sopho
Projectname - Kmeans
*/

#include<kmeans.h>
using namespace std;



int main(){
	cluster kmeanSerial(1100);
	kmeanSerial.readData();
//	kmeanSerial.printData();
	kmeanSerial.train();
	kmeanSerial.kScore();
	return 0;
}
