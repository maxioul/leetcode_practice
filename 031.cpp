class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int now = nums.size() - 1;
        int min = -1;
        while(now>0){
            if(nums[now] > nums[now-1]){
                min = now-1;
                break;
            }
            now--;
        }
        if(min==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int saw = min+1;
        for(int i =min+1;i<nums.size();i++){
            if(nums[i]<nums[saw]&&nums[i]>nums[min]){
                saw = i;
            }
        }
        int temp = nums[min];
        nums[min] = nums[saw];
        nums[saw] = temp;
        sort(nums.begin()+min+1,nums.end());
    }
};
