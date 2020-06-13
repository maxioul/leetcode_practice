class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int output=0;
        int min = prices[0];
        for(int i = 1;i<prices.size();i++){
            if(prices[i]<min){
                min = prices[i];
            }else{
                output = output<(prices[i]-min)?(prices[i]-min):output;
            }
        }
        return output;
    }
};
