class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        pair<int,int>now,opp;
        int xMax = matrix.size();
        int yMax;
        if(xMax)yMax = matrix[0].size();
        int output = 0;
        for(int i =0;i<xMax;i++){
            for(int j =0;j<yMax;j++){
                if(matrix[i][j] == '1'){
                    opp.first = i;
                    opp.second = yMax;
                    now.first = i;
                    
                    while(now.first < xMax){
                        now.second = j;
                        while(now.second<opp.second && matrix[now.first][now.second] == '1'){
                            now.second++;
                        }
                        opp.second = now.second;
                        int area = (now.first - i + 1) * (now.second - j);
                        output = area>output?area:output;
                        now.first++;
                    }
                }
            }
        }
        return output;
    }
};

//time complexity is O(n^3). = =
//maybe could use solution in 84.
//anyway, it takes some time to understand how to apply 84 on it.
