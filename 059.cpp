class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>output;
        output.resize(n);
        for(int i=0;i<n;i++){
            output[i].resize(n);
        }
        int left=0,up=0;
        int right=n,down=n;
        int num=1;
        while(left<right&&up<down){
            for(int i =left;i<right;i++){
                output[up][i]=num;
                num++;
            }
            up++;
            if(up==down)break;
            for(int i=up;i<down;i++){
                output[i][right-1]=num;
                num++;
            }
            right--;
            if(left==right)break;
            for(int i =right-1;i>=left;i--){
                output[down-1][i]=num;
                num++;
            }
            down--;
            if(up==down)break;
            for(int i =down-1;i>=up;i--){
                output[i][left]=num;
                num++;
            }
            left++;
            if(left==right)break;
            
        }
        return output;
    }
};
