class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = height[0];
        for(int i =0;i<height.size()-1;i++){
            if(height[i]>=max){
                search(i,height);
                max = height[i];
            }
        }
        return max_area;
    }
    int max_area=0;
    void search(int start, vector<int>& height){
        for(int i = start + 1; i < height.size(); i++){
            int temp = (i-start)*min(height[start],height[i]);
            max_area = temp>max_area?temp:max_area;
        }
    }
};

// time order O(N^2), very bad.
// Using double pointer can optimize it.
