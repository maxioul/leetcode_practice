class Solution {
public:
    vector<vector<int>>output;
    void per(vector<int>& nums,int now){
        if(now == nums.size()-1){
            output.push_back(nums);
            return;
        }
        int next = now;
        vector<int>cha;
        cha.push_back(nums[now]);
        for(int i = now;i<nums.size();i++){
            bool k = true;
            for(int j=0;j<cha.size();j++){
                if (nums[i]==cha[j]){
                    k =false;
                }
            }
            if(k){
                int temp = nums[i];
                nums[i]=nums[now];
                nums[now]=temp;
                per(nums,now+1);
                nums[now]=nums[i];
                nums[i]=temp;
                cha.push_back(nums[i]);
            }
        }
        per(nums,now+1);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        per(nums,0);
        return output;
    }
};
