class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>>count;
        vector<vector<string>>output;
        map<vector<int>,int>NumMap;
        int size = strs.size();
        if(size<2){
            output.push_back(strs);
            return output;
        }
        vector<int>nums;
        nums.resize(26);
        for(int i =0;i<size;i++){
            string str = strs[i];
            vector<int>NumsNow = nums;
            for(int j=0;j<str.size();j++){
                NumsNow[str[j]-'a']++;
            }
            int dirty =-1;
            
            map<vector<int>,int>::iterator it;
            it = NumMap.find(NumsNow);
            if(it != NumMap.end()){
                dirty = it->second;
            }
            
            if(dirty == -1){
                NumMap[NumsNow]=output.size();
                vector<string>temp;
                temp.push_back(str);
                output.push_back(temp);
                
            }else{
                output[dirty].push_back(str);
            }
        }
        return output;
    }
};

// At first I used a vector<vector<int>> ot store the count information, and got a TLE. Then I tried map.
