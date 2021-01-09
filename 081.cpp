class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i =0;i<nums.size();i++){
            if((i>0&&nums[i-1]>nums[i])||nums[i]>target){
                break;
            }
            if(nums[i]==target){
                return true;
            }
        }
        for(int i =nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                return true;
            }
            if((i>0&&nums[i-1]>nums[i])||nums[i]<target){
                break;
            }
            
        }
        return false;
    }
};
