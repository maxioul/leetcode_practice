class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int work=0;
        if(prices.size()==0){
            return 0;
        }
        int output=0;
        int min = prices[0];
        int max = prices[0];
        for(int i=1;i<prices.size();i++){
            int now = prices[i];
            if(now>max){
                max=now;
            }else{
                output+=max-min;
                min = now;
                max = now;
            }
        }
        output += max-min;
        return output;
    }
};
