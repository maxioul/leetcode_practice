class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length();
        int output=0;
        while(size>0&&s[size-1]==' ')size--;
        for(int i=size-1;i>=0;i--){
            if(s[i]==' '){
                break;
            }else{
                output++;
            }
        }
        return output;
    }
};

//iterator from back need to erase space at last.
