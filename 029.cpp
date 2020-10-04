class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN){
            if(divisor==-1)return INT_MAX;
            if(divisor==1)return INT_MIN;
        }
        bool sign = true;
        if(dividend<0){
            dividend = abs(dividend);
            sign = !sign;
        }
        if(divisor<0){
            divisor = abs(divisor);
            sign = !sign;
        }
        unsigned int did = abs(dividend), dir = abs(divisor);
        int mul = 1;
        int output = 0;
        bool hit_max = true;
        while(mul>0){
            if(did>=dir){
                did-=dir;
                output+=mul;
                if(hit_max&&did>=dir){
                    dir<<=1;
                    mul<<=1;
                }
            }else{
                hit_max = false;
                dir>>=1;
                mul>>=1;
            }
        }
        return sign?output:-1*output;
    }
};
