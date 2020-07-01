class Solution {
public:
    vector<int>work;
    int findMin(vector<int>& nums) {
        work=nums;
        int min = Find(0,nums.size());
        return  min;
    }
    int Find(int a,int b){
        if(a+1==b){
            return work[a];
        }
        return min(Find(a,(a+b)/2),Find((a+b)/2,b));
    }
};
