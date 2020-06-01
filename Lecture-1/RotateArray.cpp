class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        if( n== 0 || n==1){
            return;
        }
        k = k%n;

        int i = 0;
        int j = n-1;
        
        // 1. Reverse the array
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        
        // 2. Swap first k elements
        i = 0;
        j = k-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        
        // 3. Swap the last n-k elements
        i = k;
        j = n-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};