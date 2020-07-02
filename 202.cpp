class Solution {
public:
    bool isHappy(int n) {
        map<int,bool>exist;
        int sum=n;
        while(!exist[sum]){
            exist[sum]=true;
            sum  = Calclu(sum);
            if(sum ==1){
                return true;
            }
        }
        return false;
    }
    int Calclu(int a){
        int sum = 0;
        while(a!=0){
            int temp = a%10;
            sum+=pow(temp,2);
            a= a/10;
        }
        return sum;
    }
};
