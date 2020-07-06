class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0;
        int second = -1;
        if(nums.size()==1){
            return 0;
        }
        for(int i =1;i<nums.size();i++){
            if(nums[i]>nums[max]){
                second = max;
                max=i;
            }else if(second == -1 || nums[i]>nums[second]){
                second = i;
            }
        }
        if(second==-1||nums[max]>=nums[second]*2){
            return max;
        }else{
            return -1;
        }
    }
};
