class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1.0;
        }
        long long max;
        if(n<0){
            x = 1/x;
            max = n;
            max = -max;
        }else{
            max = n;
        }
        double output = 1.0;
        stack<double>cross;
        cross.push(x);
        long long multi = 1;
        long long now = 0;
        bool full = false;
        while(now<max){
            if(now+multi<=max){
                output*=cross.top();
                now+=multi;
                if(!full){
                    double temp = cross.top();
                    temp*=temp;
                    cross.push(temp);
                    multi*=2;
                }
            }else{
                full=true;
                cross.pop();
                multi=multi/2;
            }
        }
        return output;
    }
};
