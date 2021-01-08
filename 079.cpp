class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        m = board.size();
        n = board[0].size();
        w =word;
        for(int i =0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(exist_in(i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<vector<char>>b;
    string w;
    int m,n;
    bool exist_in(int x, int y,int pos){
        
        if(x<0||y<0||x>=m||y>=n||b[x][y]!=w[pos]){
            return false;
        }
        
        if(pos==w.size()-1){
            return true;
        }
        b[x][y]='0';
        char t = w[pos];
        bool output=exist_in(x-1,y,pos+1)||
            exist_in(x+1,y,pos+1)||
            exist_in(x,y-1,pos+1)||
            exist_in(x,y+1,pos+1);
        b[x][y]=t;
        return output;
    }
};
