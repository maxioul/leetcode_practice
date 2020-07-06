class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        char now = S.front();
        int count =1;
        vector<vector<int>>output;
        int poi =0;
        for(int i =1;i<S.length();i++){
            if(S[i]==now){
                count++;
            }else{
                if(count>2){
                    vector<int>temp;
                    temp.push_back(poi);
                    temp.push_back(i-1);
                    output.push_back(temp);
                    
                }
                poi=i;
                count = 1;
                now = S[i];
            }
        }
        if(count>2){
            vector<int>temp;
            temp.push_back(poi);
            temp.push_back(S.length()-1);
            output.push_back(temp);
        }
        return output;
    }
};
