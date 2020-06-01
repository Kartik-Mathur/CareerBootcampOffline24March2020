// MinCostToClimbStairs
#include <iostream>
using namespace std;

int Stairs(vector<int>& cost,int i,int n,int *dp){
    // Base case
    if(i>=n) return 0;

    int op1 = Stairs(cost,i+1,n,dp)+cost[i];
    int op2 = Stairs(cost,i+2,n,dp)+cost[i];

    return min(op1,op2);

}
int Stairs(vector<int>& cost,int i,int n,int *dp){
        // Base case
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int op1,op2;
        op1 = op2 = INT_MAX;
        op1 = Stairs(cost,i+1,n,dp)+cost[i];
        op2 = Stairs(cost,i+2,n,dp)+cost[i];

        dp[i] = min(op1,op2);
        return dp[i];
}
int minCostClimbingStairs(vector<int>& cost) {
        for(int i=0;i<cost.size();i++){
        	if(i>1){
        		cost[i] = min(cost[i-1],cost[i-2])+cost[i];
        	}        	
        }
        
        return min(cost[i-1],cost[i-2]);
}
int main(){
	


	cout<<endl;
	return 0;
}