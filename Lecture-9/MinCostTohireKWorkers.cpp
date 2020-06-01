// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
#include <iostream>
using namespace std;

class Workers{
public:
	int quality;
	int wage;
	double ratio;
	Workers(){

	}
	Workers(int quality,int wage){
		this->quality = quality;
		this->wage = wage;
		ratio = (double)(wage)/quality;
	}
};

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
	int n = quality.size();
	Workers* w = new Workers[n+1];


	for(int i=0;i<n;i++){
		w[i] = Workers(quality[i],wage[i]);
	}

	sort(w,w+n,[=](Workers a, Workers b){
		return a.ratio<b.ratio;
	});

	
	priority_queue<int> q;
	int SUM = 0;
	double ans = 10000000001;

	for(int i=0;i<n;i++){
		SUM += w[i].quality;
		q.push(w[i].quality);

		if(q.size() > K){
			SUM -= q.top();
			q.pop();
			ans = min(ans,SUM*(w[i].ratio));
		}
		else if(q.size() == K){
			ans = min(ans,SUM*(w[i].ratio));
		}
	}
	return ans;
}	

int main(){
	


	cout<<endl;
	return 0;
}