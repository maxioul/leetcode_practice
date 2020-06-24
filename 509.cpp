class Solution {
public:
    int fib(int N) {
        int min=0,max=1;
        if(N==1){
            return 1;
        }
        if(N==0){
            return 0;
        }
        for(int i =1;i<N;i++){
            int temp = min+max;
            min=max;
            max=temp;
        }
        return max;
    }
};
