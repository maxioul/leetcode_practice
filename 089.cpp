class Solution {
public:
    vector<int>output;
    void setCode(bitset<16>& num,int n){
        if(n==0){
            output.push_back(num.to_ulong());
            num.flip(0);
            output.push_back(num.to_ulong());
            return;
        }
        setCode(num,n-1);
        num.flip(n);
        setCode(num,n-1);
        return;
    }
    vector<int> grayCode(int n) {
        if(n==0){
            return output;
        }
        bitset<16>num;
        setCode(num,n-1);
        return output;
    }
};
