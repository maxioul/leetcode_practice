class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        if(size<2){
            return 0;
        }
        int min_poi=0;
        int max_poi=size-1;
        int now =1;
        while(now<size&&nums[now]>=nums[now-1])now++;
        min_poi=now-1;
        while(now<size&&min_poi>-1){
            if(nums[now]<nums[min_poi]){
                min_poi--;
                now--;
            }
            now++;
        }
        now =size-2;
        while(now>-1&&nums[now]<=nums[now+1])now--;
        max_poi = now+1;
        while(now>-1&&max_poi<size){
            if(nums[now]>nums[max_poi]){
                max_poi++;
                now++;
            }
            now--;
        }
        
        if(min_poi<max_poi)return max_poi-min_poi-1;
        return 0;
        
        
    }
};
