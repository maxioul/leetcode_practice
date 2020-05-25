class Solution {
public:
    int trap(vector<int>& height) {
        int output = 0;
        int waterLevel=0;
        stack<pair<int, int> >work;
        for(int i =0;i<height.size();i++){
            while(!work.empty()&&height[i] >= work.top().first){
                output += (work.top().first - waterLevel) * (i - work.top().second - 1);
                waterLevel = work.top().first;
                work.pop();
            }
            pair<int,int>temp;
            temp.first = height[i];
            temp.second = i;
            if(work.empty()){
                waterLevel = 0;
            }else{
                if(waterLevel < temp.first){
                    output += (temp.first - waterLevel) * (temp.second - work.top().second - 1);
                    waterLevel = temp.first;
                }
            }
            work.push(temp);
        }
        return output;
    }
};
