
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()){
            return true;
        }
        int left = 0;
        int right =s.length()-1;
        while(left<right){
            while(left<right&&!isalnum(s[left])){
                left ++;
            }
            while(right>left&&!isalnum(s[right])){
                right--;
            }
            char temp1,temp2;
            temp1 = s[left];
            if(s[left]<='9'&&s[left]>='0'){
                temp2 = s[left];
            }
            else if(s[left]<='z'&&s[left]>='a'){
                temp2 = s[left]+'A'-'a';
            }else{
                temp2 = s[left]+'a'-'A';
            }
            
            if(s[right]!=temp1&&s[right]!=temp2){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
