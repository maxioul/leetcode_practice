class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int>numCount;
        int size = nums.size();
        int output = 0;
        for(int i =0;i<size;i++){
            numCount[nums[i]]++;
        }
        if(k<0){
            return 0;
        }
        if(k==0){
            for(int i =0;i<size;i++){
                if(numCount[nums[i]]>1){
                    output++;
                    numCount[nums[i]]=0;
                }
            }
        }else{
            for(int i =0;i<size;i++){
                int temp =nums[i];
                if(numCount[temp]!=0){
                
                if(numCount[temp-k]!=0){
                    output++;
                }
                if(numCount[temp+k]!=0){
                    output++;
                }
                }
                numCount[temp]=0;
            }
        }
        return output;
    }
};
