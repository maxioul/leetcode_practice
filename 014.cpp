class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output;
        if(strs.empty()){
            return output;
        }
        int min_size=INT_MAX;
        for(int i =0;i<strs.size();i++){
            min_size = strs[i].length()<min_size?strs[i].length():min_size;
        }
        for(int i = 0; i < min_size; i++){
            bool con = true;
            char temp = strs[0][i];
            for(int j=1;j<strs.size();j++){
                con = (strs[j][i] == temp) && con;
            }
            if(con){
                output.push_back(temp);
            }else{
                break;
            }
        }
        return output;
    }
};
