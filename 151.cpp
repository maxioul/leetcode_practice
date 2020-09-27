class Solution {
public:
    string reverseWords(string s) {
        string output;
        int left = -1;
        stack<string>work;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '&&left!=-1){
                string temp = s.substr(left,i-left);
                work.push(temp);
                left =-1;
            }
            if(s[i]!=' '&&left==-1){
                left = i;
            }
        }
        if(left!=-1){
            string temp = s.substr(left);
            work.push(temp);
        }
        while(!work.empty()){
            output.append(work.top());
            work.pop();
            if(!work.empty())output.push_back(' ');
        }
        return output;
    }
};
