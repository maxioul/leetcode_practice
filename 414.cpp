class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first=-1;
        int second=-1;
        int third=-1;
        for(int i =0;i<nums.size();i++){
            if(first == -1 || nums[i]>nums[first]){
                third=second;
                second=first;
                first=i;
            }else if((second == -1||nums[i]>nums[second])){
                if(nums[i]!=nums[first]){
                    third = second;
                    second = i;
                }
            }else if((third==-1||nums[i]>nums[third])){
                if(nums[i]!=nums[second]){
                    third = i;
                }
            }
        }
        if(third==-1){
            return nums[first];
        }else{
            return nums[third];
        }
    }
};
