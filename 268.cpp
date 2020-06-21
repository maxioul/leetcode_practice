class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool>verify;
        verify.resize(nums.size()+1);
        for(int i=0;i<nums.size();i++){
            verify[nums[i]] = true;
        }
        for(int i=0;i<verify.size();i++){
            if(!verify[i]){
                return i;
            }
        }
        return -1;
    }
};
