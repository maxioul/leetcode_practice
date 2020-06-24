class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        vector<vector<int> >output;
        for(int first = 0;first<size-3;first++){
            for(int second = first+1;second<size-2;second++){
                int left = second+1;
                int right = size-1;
                int Tar = target - nums[first]-nums[second];
                while(left<right){
                    int sum = nums[left]+nums[right];
                    if(sum < Tar){
                        left++;
                    }else if (sum>Tar){
                        right--;
                    }else{
                        vector<int>temp;
                        temp.push_back(nums[first]);
                        temp.push_back(nums[second]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        output.push_back(temp);
                        while(left<right&&nums[left]==nums[left+1])left++;
                        left++;
                    }
                }
                while(second<size-2&&nums[second]==nums[second+1])second++;//
            }
             while(first<size-1&&nums[first]==nums[first+1])first++;//
        }
        return output;
    }
};

//haven't expected first and second renew.
