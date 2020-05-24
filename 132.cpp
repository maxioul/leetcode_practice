class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        vector<pair<int,int> > work;
        stack<int>min,max;
        min.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            int now = nums[i];
            if(now < min.top()){
                if(!max.empty()){
                    pair<int,int>temp;
                    temp.first = min.top();
                    temp.second = max.top();
                    max.pop();
                    work.push_back(temp);
                }
                min.pop();
                min.push(now);
                
            }else if(!max.empty()){
                if(now>max.top()){
                    max.pop();
                    max.push(now);
                }else if(now>min.top()&&now<max.top()){
                    return true;
                }
            }else if(max.empty()){
                if(now>min.top()){
                    max.push(now);
                }
            }
            for(int i =0;i<work.size();i++){
                if(now>work[i].first&&now<work[i].second){
                    return true;
                }
            }
        }
        return false;
    }
    
};

//Not simple....
//If try to find a sequnence with order, use stack.
