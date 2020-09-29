class Solution {
public:
    int reverse(int x) {
        long long output = 0;
        long long num = x;
        bool sign = true;
        if(x<0){
            sign = false;
            num = num * (-1);
        }
        while(num!=0){
            output*=10;
            output += num % 10;
            num = num/10;
            
        }
        if(!sign){
            output*=-1;
        }
        if(output>INT_MAX){
            output=0;
        }
        if(output<INT_MIN){
            output=0;
        }
        return output;
    }
};
