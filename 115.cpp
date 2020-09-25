class Solution {
public:
    string S,T;
    int numDistinct(string s, string t) {
        vector<long long>work;
        int temp = 0;
        for(int i =0;i<=s.length();i++){
            work.push_back(1);
        }
        for(int i =0;i<t.length();i++){
            temp = work[0];
            work[0] = 0;
            int Temp = temp;
            for(int j =0;j< s.length();j++){
                int Temp = work[j+1];
                if(s[j]==t[i]){
                    work[j+1]=work[j]+temp;
                }else{
                    work[j+1] = work[j];
                }
                temp = Temp;
            }
        }
        return work[s.length()];
    }
};
