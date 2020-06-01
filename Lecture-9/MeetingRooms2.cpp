// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
// find the minimum number of conference rooms required.

// Example 1:

// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
// Example 2:

// Input: [[7,10],[2,4]]
// Output: 1
// NOTE: input types have been changed on April 15, 2019. Please reset to default code 
// definition to get new method signature.
// problem link : https://leetcode.com/problems/meeting-rooms-ii/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& v) {
        if(v.empty()) return 0;
        priority_queue<int,vector<int>,greater<int> > q;
        
        sort(v.begin(),v.end(),[=](vector<int> a,vector<int> b){
            return a[0]<b[0];
        });
        
        q.push(v[0][1]);
        
        for(int i=1;i<v.size();i++){
            if(v[i][0]>=q.top()){
                q.pop();
                q.push(v[i][1]);
            }
            else{
                q.push(v[i][1]);
            }
        }
        return q.size();
    }
};