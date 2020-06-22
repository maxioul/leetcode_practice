class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, bool>verify;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                verify[nums[i]]=true;
            }
        }
        int now =1;
        while(verify[now])now++;
        return now;
    }
};

//good enough on time, not good enough on space
//there have an idea using symbol to save verify, but needs to loop array 4 times. 2 more times loop to trade off extra space used to save verify information.
