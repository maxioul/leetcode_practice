class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool>work;
        for(int i =0;i<nums.size();i++){
            if(work[nums[i]]){
                return true;
            }else{
                work[nums[i]]=true;
            }
        }
        return false;
    }
};
