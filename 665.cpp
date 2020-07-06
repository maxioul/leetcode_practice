class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool output =true;
        
        if(nums.size()<3){
            return true;
        }
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                vector<int>temp1;
                vector<int>temp2;
                temp1=nums;
                temp1[i]=temp1[i+1];
                temp2=nums;
                temp2[i+1]=temp2[i];
                return isPoss(temp1)||isPoss(temp2);
            }
        }
        return true;
    }
    bool isPoss(vector<int>a){
        for(int i=0;i<a.size()-1;i++){
            if(a[i]>a[i+1]){
                return false;
            }
        }
        return true;
    }
};
