class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> output={{}};
        for(int i =0;i<nums.size();){
            int count=0;
            int now = nums[i];
            while(i<nums.size()&&nums[i]==now){
                i++;
                count++;
            }
            int size = output.size();
            
            for(int k =0;k<size;k++){
            vector<int>temp = output[k];
                for(int j=0;j<count;j++){
                    temp.push_back(now);
                    output.push_back(temp);
                }
            }
            
        }
        return output;
    }
};
