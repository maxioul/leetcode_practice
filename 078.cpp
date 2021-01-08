class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>output(1,vector<int>());
        for(int i=0;i<nums.size();i++){
            int size = output.size();
            for(int j=0;j<size;j++){
                
                output.push_back(output[j]);
                output.back().push_back(nums[i]);
            }
        }
        return output;
    }
};

