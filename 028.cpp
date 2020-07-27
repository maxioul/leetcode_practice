class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        if(haystack.length()==0){
            return -1;
        }
        int k = haystack.length() - needle.length() + 1;
        for(int i =0;i < k;i++){
            bool yes=true;
            for(int j=0;j<needle.length();j++){
                yes = yes&&(haystack[i+j]==needle[j]);
            }
            if(yes)return i;
        }
        return -1;
    }
};
