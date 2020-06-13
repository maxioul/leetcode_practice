class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,bool>work;
        for(int i =0;i<nums.size();i++){
            if(i > k){
                work[nums[i-k-1]]=false;
            }
            if(work[nums[i]]){
                return true;
            }else{
                work[nums[i]]=true;
            }
        }
        return false;
    }
};
