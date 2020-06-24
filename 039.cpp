class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>output;
        int size = candidates.size();
        if(target == 0){
            vector<int>temp;
            output.push_back(temp);
            return output;
        }
        int now = size-1;
        if(candidates.size()==0){
            return output;
        }
        //with last;
        if(target>=candidates[size-1]){
            vector<vector<int>>temp = combinationSum(candidates,target-candidates[size-1]);
            for(int i =0;i<temp.size();i++){
                temp[i].push_back(candidates[size-1]);
                output.push_back(temp[i]);
            }
        }
        //without last;
        vector<int>temp;
        temp = candidates;
        temp.pop_back();
        vector<vector<int>>tempOutput = combinationSum(temp,target);
        for(int i=0;i<tempOutput.size();i++){
            output.push_back(tempOutput[i]);
        }
        return output;
    }
};
