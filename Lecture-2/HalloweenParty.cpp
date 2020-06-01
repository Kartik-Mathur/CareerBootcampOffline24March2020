#include<iostream> 
using namespace std;

#define PFS(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

int main(){

	int c,n;

	while(true){
		cin>>c>>n;
		if(c == 0){
			break;
		}
		int *a = new int[n];

		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i-1>=0){
				a[i] = a[i] + a[i-1];
			}
			a[i] %= c;
		}
		// PFS(a,n);
		int *visited = new int[c+1];
		for(int i =0;i<=c;i++){
			visited[i] = -1;
		}
		visited[0] = 0;

		for(int i=0;i<n;i++){

			if(visited[a[i]]!=-1){
				int val;
				a[i] == 0?(val = visited[a[i]]):(val=visited[a[i]]+1);

				for(int k=val;k<=i;k++){
					cout<<k+1<<' ';
				}
				break;
			}
			else{
				visited[a[i]] = i;
			}
		}
	}

	return 0; 
}
