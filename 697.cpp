class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int size = nums.size();
        int degree = 0;
        map<int,int>count;
        vector<int>num;
        if(size<2){
            return size;
        }
        for(int i =0;i<size;i++){
            if(count[nums[i]]==0){
                num.push_back(nums[i]);
            }
            count[nums[i]]++;
            degree = max(degree,count[nums[i]]);
        }
        int output=size;
        for(int i =0;i<num.size();i++){
            if(count[num[i]]==degree){
                int now = num[i];
                int left = 0;
                int right = size-1;
                while(left<size&&nums[left]!=now)left++;
                while(right>0&&nums[right]!=now)right--;
                int temp = right-left+1;
                output =  min(output,temp);
            }
        }
        return output;
    }
};

//Time order O(n^2), too bad, use two map to save left and right for every number;
