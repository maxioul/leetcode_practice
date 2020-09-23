class Solution {
public:
    bool Test(string test){
        long long num =0;
        int size = test.length();
        if(size<1||size>3){
           return false;
        }
        if(size>1&&test[0]=='0'){
            return false;
        }
        
        for(int i =0;i<test.length();i++){
            num*=10;
            num+=(test[i]-'0');
        }
        return num>=0&&num<=255;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>output;
        int size = s.length();
        if(size<4){
            return output;
        }
        for(int i =0;i<3;i++){
            string temp;
            string first_num = s.substr(0,i+1);
            if(!Test(first_num)){
                continue;
            }
            temp.append(first_num);
            temp.append(".");
            string temp1 = temp;
            for(int j = i+1;j<i+4&&j<size;j++){
                temp = temp1;
                string sec_num = s.substr(i+1,j-i);
                if(!Test(sec_num)){
                    continue;
                }
                temp.append(sec_num);
                temp.append(".");
                string temp2 = temp;
                for(int k = j+1;k<j+4&&k<size;k++){
                    temp = temp2;
                    string third_num = s.substr(j+1,k-j);
                    if(!Test(third_num)){
                        continue;
                    }
                    temp.append(third_num);
                    temp.append(".");
                    string last_num = s.substr(k+1,size-k);
                    if(!Test(last_num)){
                        continue;
                    }
                    temp.append(last_num);
                    output.push_back(temp);
                    
                }
            }
        }
        return output;
    }
};
