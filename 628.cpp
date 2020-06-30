class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max=INT_MIN;
        int mid=INT_MIN;
        int min=INT_MIN;
        int max_n=INT_MAX;
        int min_n=INT_MAX;
        int output1=1;
        int output2=1;
        int size = nums.size();
        if(size<4){
            for(int i =0;i<size;i++){
                output1*=nums[i];
            }
            return output1;
        }
        for(int i =0;i<nums.size();i++){
            if(nums[i]>max){
                min = mid;
                mid = max;
                max = nums[i];
            }else if(nums[i]>mid){
                min = mid;
                mid = nums[i];
            }else if(nums[i]>min){
                min = nums[i];
            }
            if(nums[i]<max_n){
                min_n=max_n;
                max_n=nums[i];
            }else if(nums[i]<min_n){
                min_n = nums[i];
            }
        }
        output1*=max;
        output1*=mid;
        output1*=min;
        output2*=max;
        output2*=max_n;
        output2*=min_n;
        int output = output1<output2?output2:output1;
        return output;
    }
};
