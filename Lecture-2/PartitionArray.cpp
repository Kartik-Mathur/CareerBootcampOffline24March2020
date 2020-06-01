#include<iostream> 
using namespace std;
int partitionDisjoint(vector<int>& A) {
	
	int n = A.size();
	int length = 0;
	int c_max = A[0],l_max = A[0];
	for(int i=1;i<n;i++){
		c_max = max(c_max,A[0]);
		if(A[i]<l_max){
			length = i;
			left_max = c_max;
		}
	}
	return length+1;
}

int main(){



	return 0; 
}
