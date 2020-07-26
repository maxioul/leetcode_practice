class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> output;
        map<int, vector<char>>dig;
        int num =2;
        int count =1;
        for(int i='a';i<'z'+1;i++){
            dig[num].push_back(i);
            if(i=='r'){
                dig[7].push_back('s');
                i++;
            }
            num +=count/3;
            count =count%3+1;
        }
        dig[9].push_back('z');
        string temp;
        if(digits.length()!=0)output.push(temp);
        for(int i =0;i<digits.length();i++){
            int now = digits[i]-'0';
            int size = output.size();
            for(int j=0;j<size;j++){
                temp = output.front();
                output.pop();
                for(int k=0;k<dig[now].size();k++){
                    string Temp = temp;
                    Temp.push_back(dig[now][k]);
                    output.push(Temp);
                }
            }
        }
        vector<string>Output;
        while(!output.empty()){
            temp = output.front();
            Output.push_back(temp);
            output.pop();
        }
        return Output;
    }
};
