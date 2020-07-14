class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> work;
        work.resize(numRows);
        int count=0;
        int sig = -1;
        for(int i=0;i<s.length();i++){
            work[count].push_back(s[i]);
            
            if(count==0){
                sig=-1*sig;
            }
            if(count==numRows-1){
                sig=-1*sig;
            }
            if(numRows!=1){
                count+=sig;
            }
        }
        string output;
        for(int i=0;i<numRows;i++){
            output.append(work[i]);
        }
        return output;
    }
};
