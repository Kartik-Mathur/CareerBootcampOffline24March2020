// https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return nums;
        deque<int> q;
        vector<int> ans;
        
        for(int i =0;i<k;i++){
            while(!q.empty() && nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        
        for(int i=k;i<n;i++){
            ans.push_back(nums[q.front()]);
            
            while(!q.empty() && q.front()<=i-k){
                q.pop_front();
            }
            while(!q.empty() && nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        return ans;
    }
};