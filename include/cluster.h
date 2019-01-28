#include <bits/stdc++.h>

using namespace std;

class cluster{
	public:
		cluster();
		~cluster();
	
	private:
		int k;
		vector<int> centroids;
		void init_random();
		vector<int> vec;	
}
