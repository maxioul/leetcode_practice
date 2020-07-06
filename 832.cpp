class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int size = A.size();
        for(int i =0;i<size;i++){
            for(int j=0;j<size/2;j++){
                swap(A[i][j],A[i][size-j-1]);
                A[i][j] ^=1;
                A[i][size-j-1]^=1;
            }
            if(size%2){
                A[i][size/2] ^=1;
            }
        }
        return A;
    }
};
