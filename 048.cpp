class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i =0;i<size/2;i++){
            swap(matrix[i],matrix[size-i-1]);
        }
        for(int i=0;i<size;i++){
            for(int j =i+1;j<size;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

//Function reverse is faster than swap?
