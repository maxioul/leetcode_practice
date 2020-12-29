class Solution {
public:
    int uniquePaths(int m, int n) {
        int big = m+n-2;
        int small = min(m,n);
        long long up =1;
        long long down = 1;
        for(int i=1;i<small;i++){
            down *= i;
            up *= (big--);
            
        }
        return up/down;
    }
};
