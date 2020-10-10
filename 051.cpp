class Solution {
public:
    vector<vector<string>>output;
    vector<string>now;
    vector<bool>xmap;
    vector<bool>pulsmap;//(x+y)
    vector<bool>minusmap;//(x-y+n-1)
    int size;
    void find(int x,int y){
        if(xmap[x]||pulsmap[x+y]||minusmap[x-y+size-1]){
            return;
        }
        now[x][y]='Q';
        if(y == size-1){
            output.push_back(now);
            now[x][y]='.';
            return;
        }
        xmap[x]=true;
        pulsmap[x+y]=true;
        minusmap[x-y+size-1]=true;
        for(int i =0;i<size;i++){
            find(i,y+1);
        }
        xmap[x]=false;
        pulsmap[x+y]=false;
        minusmap[x-y+size-1]=false;
        now[x][y]='.';
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        xmap.resize(n,false);
        pulsmap.resize(2*n,false);
        minusmap.resize(2*n,false);
        string temp;
        for(int i =0;i<n;i++){
            temp.push_back('.');
        }
        for(int i =0;i<n;i++){
            now.push_back(temp);
        }
        for(int i =0;i<n;i++){
            find(i,0);
        }
        return output;
    }
};
