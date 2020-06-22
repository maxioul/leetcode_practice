class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int now;
        for(int i =0;i<nums.size();i++){
            if(nums[i]){
                nums[now] = nums[i];
                now++;
            }
        }
        while(now<nums.size()){
            nums[now]=0;
            now++;
        }
        
        
    }
};
