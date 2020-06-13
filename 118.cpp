class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> temp;
        vector<int> save;
        vector<vector<int> > work;
        for(int i = 0; i < numRows; i++){
            save = temp;
            for(int j = 1;j < temp.size();j++){
                temp[j] = save[j]+save[j-1];
            }
            
            temp.push_back(1);
            work.push_back(temp);
            
        }
        return work;
    }
};
