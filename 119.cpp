class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>work;
        vector<int>temp;
        if(rowIndex ==0){
            
            work.push_back(1);
            return work;
        }
        for(int i = 0;i < rowIndex; i++){
            temp = work;
            work.resize(0);
            work.push_back(1);
            for(int j = 1;j<temp.size();j++){
                work.push_back(temp[j] + temp[j-1]);
            }
            work.push_back(1);
        }
        return work;
    }
};
