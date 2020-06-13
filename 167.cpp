class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = numbers[0];
        vector<int>output;
        output.push_back(0);
        output.push_back(0);
        for(int i=numbers.size()-1;i>0;i--){
            if(numbers[i] + first == target){
                output[1]=i;
                break;
            }
            if(numbers[i]+first <target){
                output[0]++;
                first = numbers[output[0]];
                i++;
            }
        }
        output[0]++;
        output[1]++;
        return output;
    }
};
