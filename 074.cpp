class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool output = false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        if(target<matrix[0][0]){
            return false;
        }
        if(target>matrix[m-1][n-1]){
            return false;
        }
        int line = m/2-1;
        if(m==1){
            line = 0;
        }else{
            int small =0;
            int big = m-1;
            line = (small+big)/2;
            while(small<big){
                if(target>matrix[line][0]){
                    
                    small = line+1;
                    line = (small+big)/2;
                }else if(matrix[line][0]==target){
                    return true;
                }else{
                    big = line;
                    line = (small+big)/2;
                    
                }
            }
        }
        if (target < matrix[line][0]&&line>0) {
        line--;
    }
        int small = 0;
        int big = n-1;
        int row = (small+big)/2;
        while(small!=big){
            if(target>matrix[line][row]){
                
                small = row+1;
                row = (small+big)/2;
            }else if(target == matrix[line][row]){
                return true;
            }else{
                big = row;
                row=(small+big)/2;
            }
        }
        if(target==matrix[line][row]){
            return true;
        }
        return false;
    }
};


//Use two binary search, trick part is in first search, line will stop at next line.
