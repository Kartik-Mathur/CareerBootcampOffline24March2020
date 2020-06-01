// PatchingArray
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int miss =1;
        int i = 0,add=0;
        
        while(miss<=n){
            if(i<nums.size() && miss>=nums[i]){
                miss+=nums[i];
                i++;
            }
            else{
                add++;
                miss+=miss;
            }
        }
        return add;
    }
};