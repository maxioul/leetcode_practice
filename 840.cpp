class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int output=0;
        
        int i=0,j=0;
        int max_i = grid.size()-2;
        int max_j = grid[0].size()-2;
        while(i<max_i){
            j=0;
            while(j<max_j){
                vector<int>temp;
                for(int a =0;a<3;a++){
                    for(int b=0;b<3;b++){
                        temp.push_back(grid[i+a][j+b]);
                        
                    }
                }
                output+=Check(temp);
                j++;
            }
            i++;
        }
        return output;
    }
    int Check(vector<int>a){
        int row[3]={0,0,0};
        int clo[3]={0,0,0};
        vector<int>check(10,1);
        for(int i=0;i<9;i++){
            if(a[i]>9||a[i]<1||check[a[i]]==0){
                return 0;
            }
            row[i/3]+=a[i];
            clo[i%3]+=a[i];
            check[a[i]]=0;
        }
        for(int i =0;i<3;i++){
            if(row[i]!=15||clo[i]!=15){
                return 0;
            }
            
        }
        if(a[0]+a[4]+a[8]!=15){
            return 0;
        }
        if(a[2]+a[4]+a[6]!=15){
            return 0;
        }
        return 1;
    }
};
