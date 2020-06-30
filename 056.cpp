class Solution {
public:
    static bool arc(vector<int>a,vector<int>b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>work;
        sort(intervals.begin(),intervals.end(),arc);
        int size = intervals.size();
        if(size<2){
            return intervals;
        }
        int i =0;
        while(i<size){
            vector<int> now;
            now=intervals[i];
            int next = i+1;
            while(next<size){
                if(intervals[next][0]<=now[1]){
                    now[1]=intervals[next][1]>now[1]?intervals[next][1]:now[1];
                    next++;
                }else{
                    break;
                }
            }
            work.push_back(now);
            i=next;
        }
        return work;
    }
};
