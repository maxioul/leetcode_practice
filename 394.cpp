class Solution {
public:
    string decodeString(string s) {
        string output;
        int num = 0;
        int count=0;
        if(s.length()){
            int i = 0;
            while(i < s.length()){
                if(s[i] >= '0'&&s[i] <= '9'){
                    num = s[i]-'0';
                    string temp_str;
                    i++;
                    while(s[i] >= '0'&&s[i] <= '9'){
                        num = num *10+s[i]-'0';
                        i++;
                    }
                    if(s[i]=='['){
                        i++;
                        count++;
                        int temp = i;
                        while(temp < s.length()&&count){
                            if(s[temp]==']'){
                                count--;
                            }else if(s[temp]=='['){
                                count++;
                            }
                            temp++;
                        }
                        temp_str = decodeString(s.substr(i,temp-i - 1));
                        i=temp;
                    }
                    for(int k=0;k<num;k++){
                        output.append(temp_str);
                    }
                    
                }else{
                    output.push_back(s[i]);
                    i++;
                }
                
            }
        }
        return output;
    }
};

//Maybe replace for with while will be better.
//
