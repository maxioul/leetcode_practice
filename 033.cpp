class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size==0){
            return -1;
        }
        if(size == 1){
            if(nums[0]== target){
                return 0;
            }else{
                return -1;
            }
            
        }
        if(nums[0] > nums[size - 1]){
            int mid = size/2;
            vector<int>left;
            for(int i =0;i<mid;i++){
                left.push_back(nums[i]);
            }
            int temp = search(left, target);
            if(temp !=-1){
                return temp;
            }
            left.resize(0);
            for(int i =mid;i<size;i++){
                left.push_back(nums[i]);
            }
            temp = search(left,target);
            if(temp ==-1){
                return -1;
            }
            return temp + mid;
        }
        if(target < nums[0]){
            return -1;
        }else if(target > nums[size-1]){
            return -1;
        }
        int mid = size/2;
        if(target>nums[mid-1]){
            vector<int>right;
            for(int i =mid;i<size;i++){
                right.push_back(nums[i]);
            }
            int temp = search(right,target);
            if(temp==-1){
                return -1;
            }
            return temp + mid;
        }else{
            vector<int>left;
            for(int i=0;i<mid;i++){
                left.push_back(nums[i]);
            }
            return search(left,target);
        }
    }
};

//Still bad at bisection
