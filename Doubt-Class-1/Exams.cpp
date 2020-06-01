// Exams
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

bool KyaExamsDePaayeSaare(int n,int m,const vector<int> ExamsDayMap[],int *prep,int total_days){
	vector<pair<int,int> > x;

	for(int i=1;i<=m;i++){
		auto it = upper_bound(ExamsDayMap[i].begin(),ExamsDayMap[i].end(),total_days);
		if(it == ExamsDayMap[i].begin()) return false;
		x.push_back(make_pair(*(--it),i));
	}

	// for(auto y: x){
	// 	cout<<y.first<<' '<<y.second<<endl;
	// }
	// return true;
	sort(x.begin(),x.end());
	int buffer_days = 0, earlier_exam_day = 0,prep_days=0,exam_day=0,available_days=0;

	for(auto y:x){
		exam_day = y.first;
		prep_days = prep[y.second]+1;
		available_days = exam_day - earlier_exam_day+buffer_days;
		if(prep_days>available_days){
			return false;
		}
		buffer_days = available_days-prep_days;
		earlier_exam_day = exam_day;
	}
	return true;
}

int Exams(int n,int m,const vector<int> ExamsDayMap[],int *prep){
	int s = 1;
	int e = n+1;
	int ans = -1;

	while(s<e){ // Ek point par ho skta hai s and e both become equals to n+1
		int mid = (s+e)/2;
		if(KyaExamsDePaayeSaare(n,m,ExamsDayMap,prep,mid)){
			ans = mid;
			e = mid;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	int *prep = new int[m+1];
	int *d = new int[n+1];

	vector<int> ExamsDayMap[100002];

	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i] == 0) continue;
		ExamsDayMap[d[i]].push_back(i);
	}

	F1(prep,m);
	cout<<Exams(n,m,ExamsDayMap,prep)<<endl;
	// KyaExamsDePaayeSaare(n,m,ExamsDayMap,prep,6);

	return 0;
}