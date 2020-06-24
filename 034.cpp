class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int>output;
        output.resize(2);
        if(size==0){
            output[0]=-1;
            output[1]=-1;
            return output;
        }
        if(nums[0]==target&&nums[size-1]==target){
            output[0]=0;
            output[1]=size-1;
            return output;
        }
        if(size==1){
            output[0]=-1;
            output[1]=-1;
            return output;
        }
        
        int mid = size/2;
        vector<int>Left,Right;
        Left.resize(2);
        Left[0]=-1;
        Left[1]=-1;
        Right.resize(2);
        Right[0]=-1;
        Right[1]=-1;
        
        if(nums[mid-1]>=target){
            vector<int>left;
            for(int i =0;i<mid;i++){
                left.push_back(nums[i]);
            }
            Left = searchRange(left,target);
        }
        if(nums[mid]<=target){
            vector<int>right;
            for(int i=mid;i<size;i++){
                right.push_back(nums[i]);
            }
            Right = searchRange(right,target);
            if(Right[0]!=-1){
                Right[0]+=mid;
                Right[1]+=mid;
            }
        }
        if(Left[0]==-1){
            if(Right[0]==-1){
                return Left;
            }else{
                return Right;
            }
        }else{
            if(Right[0]==-1){
                return Left;
            }else{
                output[0]=Left[0];
                output[1]=Right[1];
                return output;
            }
        }
    }
};

//とりあえず面倒。
