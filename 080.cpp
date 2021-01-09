class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)return 1;
        int pre = nums[0];
        int count = 1;
        bool dup = false;
        for(int i =1;i<nums.size();i++){
            if(nums[i]==pre){
                if(!dup){
                    nums[count]=nums[i];
                    count++;
                }
                dup = true;
            }else{
                if(count!=i){
                    nums[count]=nums[i];
                }
                count++;
                dup = false;
            }
            pre = nums[i];
        }
        return count;
    }
};
