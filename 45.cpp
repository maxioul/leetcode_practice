class Solution {
public:
    int jump(vector<int>& nums) {
        int now = nums.size()-1;
        int output=0;
        while(now>0){
            int dis=1;
            for(int i =now-1;i>=0;i--){
                if(nums[i]>=dis){
                    now = i;
                }
                dis++;
            }
            output++;
        }
        return output;
    }
};

//Time order O(N^2); didn't pass the time case;


class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>cost;
        int size = nums.size();
        cost.resize(nums.size());
        cost[0]=0;
        for(int i =1;i<cost.size();i++){
            cost[i]=-1;
        }
        int far = 0;
        for(int i =0;i<nums.size();i++){
            int steps = nums[i];
            int rage = min(steps+i+1,size);
            int start = max(far,i+1);
            for(int j = start;j < rage; j++){
                if(cost[j] == -1){
                    cost[j] = cost[i] + 1;
                    far = j;
                }
                if(j==size-1){
                    return cost[j];
                }
            }
        }
        return cost[nums.size()-1];
    }
};

//Time order is O(N)? because every element in cost only renew once;
