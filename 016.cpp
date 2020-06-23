class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int output = nums[0]+nums[1]+nums[2];
        int min_dif = abs(output-target);
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(right > left){
                int sum = nums[i]+nums[left]+nums[right];
                int dif = sum-target;
                if(abs(dif)<min_dif){
                    output = sum;
                    min_dif = abs(dif);
                }
                if(dif==0){
                    return target;
                }else if(dif>0){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return output;
    }
};
