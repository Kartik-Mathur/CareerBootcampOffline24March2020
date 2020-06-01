bool canJump(vector<int>& nums) {
    int n = nums.size()-1;
    int x = n;
    for(int i =  nums.size()-2;i>=0;i--){
        if(i+nums[i]>=x){
            x = i;
        }
    }
    return x == 0;
}