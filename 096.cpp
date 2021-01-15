class Solution {
public:
    int numTrees(int n) {
        long long output = 1;
        for(int i =0;i<n;i++){
            output = 2 * output * (2*i+1)/(i+2);
        }
        return output;
    }
};
