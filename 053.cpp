class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        bool hasNonNega =false;
        int MAX,now;
        MAX = 0;
        now = 0;
        int maxNega=nums[0];
        for(int i =0;i<nums.size();i++){
            now = now + nums[i];
            MAX = MAX > now?MAX:now;
            if(now < 0){
                now =0;
            }
            if(!hasNonNega&&nums[i]>=0){
                hasNonNega = true;
            }else{
                maxNega = maxNega>nums[i]?maxNega:nums[i];
            }
        }
        if(!hasNonNega){
            return maxNega;
        }else{
            return MAX;
        }
    }
};

//divide and conquer approach is a little hard.
