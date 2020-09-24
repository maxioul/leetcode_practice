class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != (s1.length() + s2.length())) {
            return false;
        }
        bool output[202][102] = {false};
        output[0][0]=true;
        for(int i = 1;i<=s3.length();i++){
            //k==0
            if(i < s2.length() + 1){
                output[i][0]=(s2[i - 1]==s3[i - 1]&&output[i - 1][0]);
            }
            int temp = max(1,i-(int)s2.length());
        
            for(int k = temp;k<i&&k<=s1.length();k++){
                output[i][k]=(s1[k-1]==s3[i-1]&&output[i-1][k-1])||(s2[i-k-1]==s3[i-1]&&output[i-1][k]);
            }
            if(i < s1.length() + 1){
                output[i][i]=output[i-1][i-1]&&s1[i-1]==s3[i-1];
            }
        }
        
        return output[s3.length()][s1.length()];
    }
};
