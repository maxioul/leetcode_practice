class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int output = 0;
        stack<pair<int,int>>work;
        if(heights.size()==0){
            return 0;
        }
        pair<int,int>temp;
        temp.first = heights[0];
        temp.second = 0;
        work.push(temp);
        int si = heights.size();
        for(int i =1;i<si;i++){
            
            while(!work.empty() && heights[i]<work.top().first){
                temp = work.top();
                work.pop();
                int le = -1;
                if(!work.empty()){
                    le = work.top().second;
                }
                int area = temp.first * (i - le - 1);
                if (area > output){
                    output = area;
                }
            }
        
            temp.first = heights[i];
            temp.second = i;
            work.push(temp);
        }
        
        while(!work.empty()){
            temp = work.top();
            work.pop();
            int le = -1;
            if(!work.empty()){
                le = work.top().second;
            }
            int area = temp.first * (si - le - 1);
            if (area > output){
                output = area;
            }
        }
        return output;
    }
};
