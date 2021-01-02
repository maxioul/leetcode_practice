class Solution {
public:
    int climbStairs(int n) {
        int small = 0;
        int big = 1;
        for(int i =0;i<n-1;i++){
            int temp = big;
            big = small +big;
            small = temp;
        }
        return(small+big);
    }
};
