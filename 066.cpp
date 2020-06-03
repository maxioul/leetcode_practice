class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int now = digits.size()-1;
        digits[now] ++;
        while(now>0 && digits[now] > 9){
            digits[now]=0;
            digits[now-1]++;
            now--;
        }
        if(digits[0]>9){
            digits[0]=0;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};

//easy;
