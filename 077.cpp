class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>output={{}};
        for(int i=1;i<n+1;i++){
            int size = output.size();
            for(int j=0;j<size;j++){
                if (output[j].size() == k) {
                    continue;
                }
                if(output[j].size()+n-i+1==k){
                    output[j].push_back(i);
                }else{
                    vector<int>temp = output[j];
                    temp.push_back(i);
                    output.push_back(temp);
                }
                
            }
        }
        return output;
    }
};
