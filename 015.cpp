class Solution {
public:
    vector<vector<int> >output;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int now = 0;
        int left;
        int size = nums.size();
        int right;
        while(now < size && nums[now]<=0){
            left = now + 1;
            right = size - 1;
            int sum = -1 * nums[now];
            while(left < right){
                if(sum == nums[left]+nums[right]){
                    Output(nums[now],nums[left],nums[right]);
                    while(left<right && nums[left+1]==nums[left])left++;
                    left++;
                }else if(sum > nums[left]+nums[right]){
                    while(left<right && nums[left+1]==nums[left])left++;
                    left++;
                }else{
                    while(left<right && nums[right]==nums[right-1])right--;
                    right--;
                }
            }
            while(now + 1 < size&& nums[now] == nums[now+1])now++;
            now++;
        }
        return output;
    }
    void Output(int a,int b,int c){
        vector<int>temp;
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        output.push_back(temp);
    }
    
};
