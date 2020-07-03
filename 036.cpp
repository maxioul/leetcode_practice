class Solution {
public:
    vector<bool>vaild;
    void resetVaild(){
        for(int i =0;i<10;i++){
            vaild[i]=false;
        }
    }
    int temp;
    bool isValidSudoku(vector<vector<char>>& board) {
        vaild.resize(10);
        for(int i = 0;i<9;i++){
            for(int j =0;j<9;j++){
                
                if(board[i][j]!='.'){
                    temp=board[i][j]-'0';
                    if(vaild[temp]==true){
                        return false;
                    }else{
                        vaild[temp]=true;
                    }
                }
            }
            resetVaild();
        }
        for(int i = 0;i<9;i++){
            for(int j =0;j<9;j++){
                
                if(board[j][i]!='.'){
                    temp=board[j][i]-'0';
                    if(vaild[temp]==true){
                        return false;
                    }else{
                        vaild[temp]=true;
                    }
                }
            }
            resetVaild();
        }
        for(int i =1;i<9;i+=3){
            for(int j=1;j<9;j+=3){
                for(int a=-1;a<2;a++){
                    for(int b=-1;b<2;b++){
                        if(board[i+a][j+b]!='.'){
                            temp = board[i+a][j+b]-'0';
                            if(vaild[temp]==true){
                                return false;
                            }else{
                                vaild[temp]=true;
                            }
                        }
                    }
                }
                resetVaild();
            }
            
        }
        return true;
    }
};
