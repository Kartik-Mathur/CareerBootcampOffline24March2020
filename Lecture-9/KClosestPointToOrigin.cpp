// KClosestPointToOrigin: https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    vector<vector<int> > kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<double,int> > q;
        int count = 0;
        for(int i=0;i<points.size();i++){
            double dist = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            if(count == K){
                if(q.top().first>dist){
                   q.pop();
                    q.push({dist,i});
                }
            }
            else{
                q.push({dist,i});
                count++;
            }
        }
        
        vector<vector<int> > ans;
        while(!q.empty()){
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};