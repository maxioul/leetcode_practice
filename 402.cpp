class Solution {
public:
    string removeKdigits(string num, int k) {
        string output;
        int left = 0;
        int right = k + 1;
        int size = num.length();
        for(int i = 0; i < size - k; i++){
            char min = num[left];
            int now = left;
            while(now < right && min!='0'){
                if(num[now]<min){
                    min = num[now];
                    left = now;
                }
                now++;
            }
            left++;
            output.push_back(min);
            right++;
        }
        for(int i =0;i<output.length();i++){
            if(output[0]=='0'){
                output.erase(0,1);
            }else{
                break;
            }
        }
        while(!output.empty()&&output[0]=='0'){
            output.erase(0,1);
        }
        if(output.empty()){
            output.push_back('0');
        }
        return output;
    }
};

//time complexity id O(n^2), use queue to reduce it to O(n).
//don't understand how to use stack on it
