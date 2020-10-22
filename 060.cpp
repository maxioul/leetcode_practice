class Solution {
public:

    
    string getPermutation(int n, int k) {
    bool nums[10] = { false };
    string output;
    long long fac = 1;
    for (int i = 1; i <= n; i++) {
        nums[i] = true;
        fac *= i;
    }
    fac = fac / n;
    nums[0] = false;
    for (int i = n; i > 0; i--) {
        int index = 0;
        if (fac == 0) {
            index = 1;
        }else{ index = (k-1) / fac + 1; }
        
        int temp = 1;
        int count = 0;
        int take = -1;
        bool findfirstone = false;
        while (count < index) {
            if (nums[temp]) {
                if (!findfirstone) {
                    take = temp;
                    findfirstone = true;
                }
                else {
                    take++;
                }
                count++;
                temp++;
            }
            else {
                temp++;
                take++;
            }
        }
        nums[take] = false;
        output.push_back(take + '0');
        k = k % fac;
        if (k == 0) {
            k = fac;
        }
        if (i > 1) {
            fac = fac / (i - 1);
        }
    }
    return output;
}
};
