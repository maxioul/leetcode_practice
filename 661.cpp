class Solution {
public:
    vector<vector<int>>work;
    int x,y;
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        work=M;
        x = work.size();
        y=work[0].size();
        int select[3]={-1,0,1};
        for(int i =0;i<x;i++){
            for(int j=0;j<y;j++){
                int Sum=0;
                int count=0;
                for(int a=0;a<3;a++){
                    for(int b=0;b<3;b++){
                        int temp_x=i+select[a];
                        int temp_y=j+select[b];
                        if(Value(temp_x,temp_y)){
                            Sum+=M[temp_x][temp_y];
                            count++;
                        }
                    }
                }
                work[i][j]=Sum/count;
            }
        }
        return work;
    }
    bool Value(int i,int j){
        if(i<0||j<0){
            return false;
        }
        if(i==x){
            return false;
        }
        if(j==y){
            return false;
        }
        return true;
    }
};
