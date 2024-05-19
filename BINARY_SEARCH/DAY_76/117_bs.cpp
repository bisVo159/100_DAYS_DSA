#include<bits/stdc++.h>
using namespace std;

// brute force

double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n=arr.size();
	vector<int>howMany(n-1,0);

	for(int i=1;i<=k;i++){
		int maxInd=0;
		double maxSection=0;
		for(int j=0;j<n-1;j++){
			double dist=arr[j+1]-arr[j];
			double sectionLength=dist/(howMany[j]+1);

			if(sectionLength>maxSection){
				maxSection=sectionLength;
				maxInd=j;
			}
		}

		howMany[maxInd]++;
	}	

	double maxAns=-1;

	for(int i=0;i<n-1;i++){
		double dist=arr[i+1]-arr[i];
		double sectionLength=dist/(howMany[i]+1);
		maxAns=max(maxAns,sectionLength);
	}

	return maxAns;
}

// using priority queue
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n=arr.size();
	vector<int>howMany(n-1,0);
	priority_queue<pair<double,int>>pq;

	for(int i=0;i<n-1;i++) pq.push({arr[i+1]-arr[i],i});

	for(int gasStation=1;gasStation<=k;gasStation++){
		auto tp=pq.top();
		pq.pop();
		int secInd=tp.second;
		howMany[secInd]++;

		double intDiff=arr[secInd+1]-arr[secInd];
		double newSecLen=intDiff/(howMany[secInd]+1);

		pq.push({newSecLen,secInd});
	}	


	return pq.top().first;
}

int main(){
    //  Minimize Max Distance to Gas Station -> https://www.naukri.com/code360/problems/minimise-max-distance_7541449

    // do the most optimal
    
    return 0;
}