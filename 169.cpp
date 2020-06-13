class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>work;
        int size = nums.size()/2 +nums.size()%2;
        for(int i =0;i<nums.size();i++){
            int now = nums[i];
            if(work[now]){
                work[now]++;
                if(work[now]>=size){
                    return now;
                }
            }else{
                work[now] = 1;
            }
        }
        return nums[0];
    }
};
