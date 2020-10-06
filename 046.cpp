class Solution {
public:
    vector<bool>dirty;
    vector<int>num;
    vector<vector<int>> permute(vector<int>& nums) {
        dirty.resize(nums.size());
        num = nums;
        return per();
    }
    vector<vector<int>> per(){
        vector<vector<int>>output;
        bool is_last = true;
        for(int i =0;i<dirty.size();i++){
            if(!dirty[i]){
                dirty[i]=true;
                is_last = false;
                vector<vector<int>>temp = per();
                for(int j=0;j<temp.size();j++){
                    temp[j].push_back(num[i]);
                    output.push_back(temp[j]);
                }
                dirty[i]=false;
            }
        }
        if(is_last){
            output.resize(1);
        }
        return output;
    }
};
