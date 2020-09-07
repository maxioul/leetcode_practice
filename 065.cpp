class Solution {
public:
    bool E;
    
    bool isTrueNumber(string s,bool D){
        
        int size = s.length();
        if(size == 0){
            return false;
        }
        int i = 0;
        if(s[i]=='-'||s[i]=='+'){
            i++;
        }
        if(s[i]=='e'){
            return false;
        }
        if(s[i]=='.'){
            if(size==i+1){
                return false;
            }else if(!(s[i+1]>='0'&&s[i+1]<='9')){
                return false;
            }
        }
        if(i==size){
            return false;
        }
        for(;i<size;i++){
            if(s[i]=='.'){
                if(D){
                    D = false;
                    
                }else{
                    return false;
                }
            }else if(s[i]=='e'){
                if(E){
                    string temp = s.substr(i+1);
                    if(temp.length()!=0&&temp[0]==' '){
                        return false;
                    }
                    E=false;
                    return isTrueNumber(temp,false);
                }else{
                    return false;
                }
            }else if(s[i]>='0'&&s[i]<='9'){
                
            }else if(s[i]==' '){
                bool temp = true;
                while(i<size){
                    temp = temp && (s[i]==' ');
                    i++;
                }
                return temp;
            }else{
                return false;
            }
        }
        return true;
    }
    bool isNumber(string s) {
        E = true;
        int size = s.length();
        if(size==0){
            return true;
        }
        int init = 0;
        while(init<size&&s[init]==' ')init++;
        string temp = s.substr(init);
        return isTrueNumber(temp,true);
        
    }
};


//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa, how to write state machine?
