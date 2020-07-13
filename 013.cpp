class Solution {
public:
    int romanToInt(string s) {
        int output = 0;
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
                case 'V':
                output+=5;
                break;
                case 'L':
                output+=50;
                break;
                case 'D':
                output+=500;
                break;
                case 'M':
                output+=1000;
                    break;
                case 'I':
                if(s[i+1]=='X'||s[i+1]=='V'){
                    output-=1;
                }else{
                    output+=1;
                }
                break;
                case 'X':
                if(s[i+1]=='L'||s[i+1]=='C'){
                    output-=10;
                }else{
                    output+=10;
                }
                break;
                case 'C':
                if(s[i+1]=='D'||s[i+1]=='M'){
                    output-=100;
                }else{
                    output+=100;
                }
                break;
            }
        }
        return output;
    }
};
