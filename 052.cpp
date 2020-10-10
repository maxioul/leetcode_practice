class Solution {
public:
    int output;
    bool xmap[10]={false};
    bool pulsmap[20]={false};//(x+y)
    bool minusmap[20]={false};//(x-y+n-1)
    int size;
    void find(int x,int y){
        if(xmap[x]||pulsmap[x+y]||minusmap[x-y+size-1]){
            return;
        }
        if(y == size-1){
            output++;
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
        return;
    }
    int totalNQueens(int n) {
        output = 0;
        size = n;
        
        for(int i =0;i<n;i++){
            find(i,0);
        }
        return output;
    }
};
