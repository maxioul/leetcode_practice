class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0;
        int right = k-1;
        int size = nums.size();
        double output=0;
        for(int i =0;i<k;i++){
            output +=nums[i];
        }
        double now = output;
        while(right<size-1){
            right++;
            now-=nums[left];
            now+=nums[right];
            output = output>now?output:now;
            left++;
        }
        return output/k;
    }
};
