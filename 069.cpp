class Solution {
public:
    int mySqrt(int x) {
        x = sqrt(x);
        return x;
    }
};

//tried Carmack way, but not run will.

class Solution {
public:
    int mySqrt(int x) {
        return(sqrt(x));
    }
};

class Solution {
public:
    int mySqrt(int x) {
        return (sqrt(x));// this way is slower than upper one, why???? just a space?
    }
};
