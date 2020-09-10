class Solution {
public:
    string addBinary(string a, string b) {
        int dirty = 0;
        string min,max,output;
        max = a.length()>b.length()?a:b;
        min = a.length()<=b.length()?a:b;
        int Max = max.length();
        int Min = min.length();
        for(int i =1;i<=min.length();i++){
            int a0,b0,sum;
            a0 = max[Max-i] - '0';
            b0 = min[Min-i] - '0';
            sum = a0+b0+dirty;
            dirty = sum/2;
            output.push_back(sum%2 + '0');
        }
        for(int i = Max-Min-1;i>=0;i--){
            int a0 = max[i] - '0';
            int sum = a0 + dirty;
            dirty = sum/2;
            output.push_back(sum%2 + '0');
        }
        if(dirty){
            output.push_back('1');
        }
        reverse(output.begin(),output.end());
        return output;
    }
};
