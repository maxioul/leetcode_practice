class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int nums_r = nums.size();
        int nums_c;
        if(nums_r==0){
            return nums;
        }else{
            nums_c = nums[0].size();
        }
        if(nums_c*nums_r!=r*c){
            return nums;
        }
        vector<vector<int> >output;
        vector<int>temp;
        
        temp.resize(c);
        int now=0;
        for(int i =0;i<nums_r;i++){
            for(int j=0;j<nums_c;j++){
                temp[now]=nums[i][j];
                
                if(now ==c-1){
                    output.push_back(temp);
                    now=-1;
                }
                now++;
                
            }
        }
        
        return output;
    }
};
