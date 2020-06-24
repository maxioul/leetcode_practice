class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int output=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]){
                count++;
            }else{
                if(count>output){
                    output=count;
                }
                count=0;
            }
        }
        if(count>output){
                    output=count;
                }
        return output;
    }
    
};
