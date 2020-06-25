class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>output;
        sort(candidates.begin(),candidates.end());
        if(target == 0){
            vector<int>temp;
            output.push_back(temp);
            return output;
        }
        
        return searchSum(candidates,target);
        
        
    }
    vector<vector<int>> searchSum(vector<int> candidates,int target){
        vector<vector<int>>output;
        
        if(target == 0){
            vector<int>temp;
            output.push_back(temp);
            return output;
        }
        
        while(!candidates.empty()&&candidates.back()>target)candidates.pop_back();
        if(candidates.empty()){
            return output;
        }
        //with
        int now = candidates.back();
        vector<vector<int>>tempOutput;
        candidates.pop_back();
        int tempTarget = target - now;
        tempOutput = searchSum(candidates,tempTarget);
        for(int i=0;i<tempOutput.size();i++){
            tempOutput[i].push_back(now);
            output.push_back(tempOutput[i]);
        }
        //without
        while(!candidates.empty()&&candidates.back()==now)candidates.pop_back();
        tempOutput = searchSum(candidates,target);
        for(int i=0;i<tempOutput.size();i++){
            output.push_back(tempOutput[i]);
        }
        return output;
    }
};
