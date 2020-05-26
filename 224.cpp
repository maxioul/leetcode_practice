class Solution {
public:
    int calculate(string s) {
        int output = 0;
        int size = s.size();
        
        int sig = 1;
        stack<int>sigout;
        sigout.push(1);
        for(int i = 0;i < size; i++){
            if(s[i]=='('){
                sigout.push(sig*sigout.top());
                sig=1;
            }else if(s[i]==')'){
                sigout.pop();
            }else if(s[i]=='+'){
                sig = 1;
            }else if(s[i]=='-'){
                sig = -1;
            }else if(s[i]==' '){
                
            }else{
                int temp = 0;
                int posi = i;
                while(s[posi]>='0'&&s[posi]<='9'){
                    temp = temp*10 + (s[posi]-'0');
                    posi++;
                }
                output += sig * sigout.top() * temp;
                i = posi - 1;
            }
        }
        return output;
    }
};
