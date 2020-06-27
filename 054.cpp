class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int up = 0;
        vector<int>output;
        if(matrix.size()==0){
            return output;
        }
        int right = matrix[0].size();
        int down = matrix.size();
        while(left<right&&up<down){
            for(int i=left;i<right;i++){
                output.push_back(matrix[up][i]);
            }
            up++;
            if(up==down)break;
            for(int i = up;i<down;i++){
                output.push_back(matrix[i][right-1]);
            }
            right--;
            if(left==right)break;
            for(int i = right-1;i>=left;i--){
                output.push_back(matrix[down-1][i]);
                
            }
            for(int i=down-2;i>=up;i--){
                output.push_back(matrix[i][left]);
            }
            left++;
            
            down--;
        }
        return output;
    }
};
