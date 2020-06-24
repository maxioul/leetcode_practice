class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> >output;
        int size = intervals.size();
        int min = newInterval[0];
        int max = newInterval[1];
        int left =0;
        for(;left<size;left++){
            if(min>intervals[left][1]){
                output.push_back(intervals[left]);
            }else{
                break;
            }
        }
        if(left==size){
            output.push_back(newInterval);
            return output;
        }
        vector<int>newOne;
        newOne.resize(2);
        int right = left;
        while(right<size&&max>=intervals[right][0])right++;
        min = min < intervals[left][0]?min:intervals[left][0];
        if(right != 0){
            max = max>intervals[right-1][1]?max:intervals[right-1][1];
        }
        newOne[0]=min;
        newOne[1]=max;
        output.push_back(newOne);
        for(;right<size;right++){
            output.push_back(intervals[right]);
        }
        
        return output;
    }
};
