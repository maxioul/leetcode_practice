class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        map<char,int>post,pre,test;
        int size = s1.length();
        for(int i=0;i<size-1;i++){
            post[s1[size-i-1]]++;
            pre[s1[i]]++;
            test[s2[i]]++;
            bool temp = false;
            if(Test(post,test)){
                string s11 = s1.substr(0, size - i - 1);
                string s12 = s1.substr(size - i - 1);
                string s21 = s2.substr(0, i+1);
                string s22 = s2.substr(i+1);
                temp = temp || isScramble(s11,s22)&&isScramble(s12,s21);
            }
            if(Test(pre, test)){
                string s11 = s1.substr(0,i+1);
                string s12 = s1.substr(i+1);
                string s21 = s2.substr(0,i+1);
                string s22 = s2.substr(i+1);
                temp = temp || isScramble(s11,s21)&&isScramble(s12,s22);
            }
            if(temp){
                return true;
            }
        }
        return false;
    }
    
    bool Test(map<char,int>map1,map<char,int>map2){
        for(const auto &x :map1){
            if(map2[x.first]!=x.second){
                return false;
            }
        }
        return true;
    }
};
