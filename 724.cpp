class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right =0;
        int size = nums.size();
        for(int i=0;i<size;i++){
            right+=nums[i];
        }
        for(int i = 0;i<size;i++){
            right = right - nums[i];
            if(left == right){
                return i;
            }
            left +=nums[i];
        }
        return -1;
    }
};
