class Solution {
public:
    
    stack<char> set(int x,int y,vector<vector<char>>& work){
        vector<bool>temp(9,false);
        for(int i=0;i<9;i++){
            if(work[i][y]!='.'){
                temp[work[i][y]-'1']=true;
            }
            if(work[x][i]!='.'){
                temp[work[x][i]-'1']=true;
            }
        }
        int bisx = x/3,bisy=y/3;
        bisx*=3;
        bisy*=3;
        for(int i=bisx;i<bisx+3;i++){
            for(int j = bisy;j<bisy+3;j++){
                if(work[i][j]!='.'){
                    temp[work[i][j]-'1']=true;
                }
            }
        }
        stack<char>output;
        for(int i =0;i<9;i++){
            if(temp[i]==false){
                output.push(i+'1');
                
            }
        }
        return output;
    }
    bool GETIT=false;
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    stack<char> work = set(i,j,board);
                    if(work.empty()){
                        return;
                    }else{
                        while(!work.empty()){
                            board[i][j]=work.top();
                            solveSudoku(board);
                            if(GETIT){
                                return;
                            }
                            work.pop();
                            board[i][j] = '.';
                        }
                        return;
                    }
                }
            }
        }
        GETIT=true;
    }
};
