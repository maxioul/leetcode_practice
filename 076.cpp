class Solution {
public:
    string minWindow(string s, string t) {
        map<char,pair<int,queue<int>>>count_part;
        for(int i =0;i<t.length();i++){
            count_part[t[i]].first++;
        }
        int count =0;
        const int max = t.length();
        string output;
        int front = 0;
        list<int>fronts;
        for(int i =0;i<s.length();i++){
            auto iter = count_part.find(s[i]);
            if(iter!=count_part.end()){
                
                auto *now = &iter->second;
                if(now->second.empty()){
                    fronts.push_back(i);
                    
                }
                now->second.push(i);
                if(now->first==0){
                    auto iter = fronts.begin();
                    while(*iter != now->second.front())++iter;
                    now->second.pop();
                    fronts.erase(iter);
                    fronts.push_back(now->second.front());
                    fronts.sort();//too slow, bad design
                    front = fronts.front();
                    
                    
                }else{
                    if(count == 0){
                        front = i;
                    }
                    count++;
                    now->first--;
                }
                
                if(count == max){
                    if(output.length()==0||(i-front+1)<output.length()){
                        output = s.substr(front,i-front+1);
                    }
                }
                
            }
        }
        return output;
    }
};

//This is fast one from github, I am the clown

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m (128, 0);
        for (char c : t) ++m[c];
        int n = s.size(), l = 0, r = 0, d = INT_MAX, ct = t.size(), st;
        while (r < n) {
            if (m[s[r++]]-- > 0) --ct;
            while (!ct) {
                if (r - l < d) d = r - (st = l);
                if (m[s[l++]]++ == 0) ++ct;
            }
        }
        return d == INT_MAX ? "" : s.substr(st, d);
    }
};
