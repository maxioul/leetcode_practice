class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int output = 0;
        int size = nums.size();
        if(size<2){
            return size;
        }
        int count =1;
        for(int i = 1;i<size;i++){
            if(nums[i]>nums[i-1]){
                count++;
            }else{
                output = output>count?output:count;
                count=1;
            }
        }
        output = output>count?output:count;
        return output;
    }
};
