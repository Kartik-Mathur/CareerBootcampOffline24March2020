#include<iostream> 
#include<vector>
using namespace std;
#define ll long long int
#define val 1000000100000

ll Hamburgers(char *in,int nb,int ns,int nc,int pb,int ps,int pc,ll r){

	ll s = 0;
	ll e = val;
	ll ans = -1;
	int cb=0,cs=0,cc=0;

	for(int i=0;in[i]!='\0';i++){
		if(in[i] =='B') cb++;
		else if(in[i] == 'S') cs++;
		else cc++;
	}

	while(s<=e){

		ll mid = (s+e)/2; // To check can we make mid burgers or not?

		ll bread,sausages,cheese;

		bread = (cb*mid-nb)*pb<0?0:(cb*mid-nb)*pb;
		sausages = (cs*mid-ns)*ps<0?0:(cs*mid-ns)*ps;
		cheese = (cc*mid-nc)*pc<0?0:(cc*mid-nc)*pc;

		ll price = bread + cheese + sausages; // we calculate the price needed to make mid burgers
		// if price is equals to r then usse jyada nahi bana skte toh return mid
		if(price == r){
			return mid;
		}
		else if(price < r){
			s = mid+1;
			ans = mid;
		}
		else{
			e = mid-1;
		}

	}
	return ans;
}


int main(){

	char in[10000];
	int nb,ns,nc,pb,ps,pc;

	ll  r;

	cin>>in;
	cin>>nb>>ns>>nc;
	cin>>pb>>ps>>pc;
	cin>>r;

	cout<<Hamburgers(in,nb,ns,nc,pb,ps,pc,r)<<endl;

	return 0; 
}
