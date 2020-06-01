// CircularArray
class Solution {
    int next(vector<int>& nums,int x){
        return (x+nums[x]+nums.size())%nums.size();
    }
    
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0;i<n;i++){
            int slow = i,fast = i;
            
            if(nums[i] == 0){
                continue;
            }
            
            // This is check whether cycle exists or not
            while(nums[i]*nums[next(nums,slow)]>0 && nums[i]*nums[next(nums,fast)]>0 && nums[i]*nums[next(nums,next(nums,fast))] > 0){
                slow = next(nums,slow);
                fast = next(nums,next(nums,fast));
                
                if(slow == fast){
                    if(slow == next(nums,slow)) {
                        break;
                    }
                    return true; 
                }
            }
            
            // Make the path that cannot contribute to our cycle as 0
            slow = i;
            int x = nums[i];
            while(x*nums[slow]>0){
                int y = next(nums,slow);
                nums[slow] = 0;
                slow = y;
            }
        } 
        return false;
    }
};