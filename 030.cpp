class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,queue<int>>hit;
        map<string,bool>vaild;
        vector<int>output;
        for(int i =0;i<words.size();i++){
            hit[words[i]].push(-1);
            vaild[words[i]]=true;
            
        }
        int low = 0;
        int wordSize;
        if(!words.empty()){
            wordSize = words[0].length();
        }else{
            return output;
        }
        
        for(int i =0;i<s.length();i+=wordSize){
            string temp = s.substr(i,wordSize);
            if(vaild[temp]){
                if(hit[temp].front()<low){
                    hit[temp].push(i);
                    hit[temp].pop();
                    
                }else{
                    low = hit[temp].front() + wordSize;
                    hit[temp].push(i);
                    hit[temp].pop();
                    
                }
            }else{
                low = i + wordSize;
                
            }
            if((i-low)/wordSize + 1 == words.size()){
                output.push_back(low);
                low +=wordSize;
                
            }
        }
        return output;
    }
};
