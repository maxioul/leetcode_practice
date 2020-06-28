class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int now = size-2;
        int test  = size-1;
        int count = 1;
        while(now>-1){
            if(count<=nums[now]){
                test = now;
                count =0;
            }
            now--;
            count++;
        }
        if(test==0){
            return true;
        }else{
            return false;
        }
    }
};
