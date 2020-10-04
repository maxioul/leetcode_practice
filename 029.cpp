class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;
        long long Max,Min;
        if(b>0){
            Max = INT_MAX*b;
            Min = INT_MIN*b;
        }
        if(b<0){
            Min = INT_MAX*b;
            Max = INT_MIN*b;
        }
        if(dividend>Max){
            return INT_MAX;
        }
        if(dividend<Min){
            return INT_MAX;
        }
        return dividend/b;
    }
};
