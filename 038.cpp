class Solution {
public:
    string countAndSay(int n) {
        string now,next;
        now.push_back('1');
        for(int i = 1; i<n; i++){
            int count = 0;
            char temp = now[0];
            for(int i =0;i<now.length();i++){
                if(now[i]==temp){
                    count++;
                }else{
                    next.push_back('0'+count);
                    next.push_back(temp);
                    temp=now[i];
                    count=1;
                }
            }
            next.push_back('0'+count);
            next.push_back(temp);
            now=next;
            next="";
        }
        return now;
    }
};
