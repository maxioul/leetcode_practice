class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        string mun = num;
        reverse(mun.begin(),mun.end());
        if(num == mun){
            return true;
        }else{
            return false;
        }
    }
};
