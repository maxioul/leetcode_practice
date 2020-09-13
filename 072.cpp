class Solution {
public:
    int minDistance(string word1, string word2) {
        int a = word1.length();
        int b = word2.length();
        vector<vector<int>>output;
        output.resize(a+1);
        for(int i =0;i<b+1;i++){
            output[0].push_back(i);
        }
        for(int i=1;i<a+1;i++){
            output[i].push_back(i);
            for(int j=1;j<b+1;j++){
                int temp;
                if(word1[i-1]==word2[j-1]){
                    temp = 1+min(output[i][j-1],min(output[i-1][j],(output[i-1][j-1]-1)));
                }else{
                    temp = 1+min(output[i][j-1],min(output[i-1][j],output[i-1][j-1]));
                }
                output[i].push_back(temp);
            }
        }
        return output[a][b];
    }
};
