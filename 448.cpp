class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            nums[abs(nums[i])-1]=-1*abs(nums[abs(nums[i])-1]);
        }
        vector<int>output;
        for(int i = 0;i < nums.size(); i++){
            if(nums[i]>0){
                output.push_back(i+1);
            }
            
        }
            
        return output;
    }
};
