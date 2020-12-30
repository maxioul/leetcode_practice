class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int temp =1;
        int m =obstacleGrid[0].size();
        int n = obstacleGrid.size();
        for(int i = 0;i<m;i++){
            
            if(obstacleGrid[0][i] == 0){
                obstacleGrid[0][i] = temp;
            }else{
                obstacleGrid[0][i] = 0;
                temp = 0;
            }
        }
        for( int i=1;i<n;i++){
            for(int j =0;j<m;j++){
                if(obstacleGrid[i][j]){
                    obstacleGrid[i][j] = 0;
                }else{
                    obstacleGrid[i][j] += obstacleGrid[i-1][j];
                    if(j>0){
                        obstacleGrid[i][j]+=obstacleGrid[i][j-1];
                    }
                }
            }
        }
        return obstacleGrid[n-1][m-1];
    }
};
