class Solution {
public:
    string work;
    int size;
    int numDecodings(string s) {
        work = s;
        size = work.length();
        if(s[0]=='0'){
            return 0;
        }
        return Numd(0);
        
    }
    int Numd(int k){
        if(work[k]=='0'){
            return 0;
        }
        if(k>size-2){
            return 1;
        }
        if(work[k]=='1'||(work[k]=='2'&&work[k+1]<'7')){
            return Numd(k+1)+Numd(k+2);
        }else{
            return Numd(k+1);
        }return 0;
    }
    
};

// too slow, maybe there have a DP way to solve it;
