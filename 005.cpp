class Solution {
public:
    string longestPalindrome(string s) {
        map<char,vector<int>> poi;
        for(int i =s.length()-1;i>=0;i--){
            poi[s[i]].push_back(i);
        }
        string output;
        int size = s.length();
        int output_size = 0;
        for(int i =0;i<size;i++){
            char now = s[i];
            vector<int>temp=poi[now];
            for(int j=0;j<temp.size();j++){
                if(temp[j] - i<output.length())break;
                int left = i;
                int right = temp[j];
                bool same = true;
                while(left<right){
                    same = (s[left]==s[right])&&same;
                    left++;
                    right--;
                }
                if(same){
                    output = s.substr(i,temp[j]-i+1);
                    output_size = temp[j]-i+1;
                    break;
                }
            }
            if(i>size-output_size)break;
        }
        return output;
    }
};
