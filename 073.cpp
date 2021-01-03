class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row = true;
        for(int i =0;i<n;i++){
            if(matrix[0][i]==0){
                row = false;
            }
        }
        for(int i =1;i<m;i++){
            for(int j =0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i =1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j =1;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0){
                for(int j =0;j<m;j++){
                    matrix[j][i]=0;
                }
            }
        }
        if(row == false){
            for(int i =0;i<n;i++){
                matrix[0][i]=0;
            }
        }
    }
};


//it required a constant space solution, so use first r and c to save reset this r(c) or not. 
