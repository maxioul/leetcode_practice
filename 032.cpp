class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        stack<int>work;
        vector<bool>state;
        int size = s.length();
        state.resize(size);
        for(int i =0;i<size;i++){
            if(s[i]=='('){
                work.push(i);
            }else{
                if(work.empty()){
                    state[i]=false;
                }else{
                    state[i]=true;
                    state[work.top()]=true;
                    work.pop();
                }
            }
        }
        while(!work.empty()){
            state[work.top()]=false;
            work.pop();
        }
        int count=0;
        for(int i=0;i<size;i++){
            if(state[i]){
                count++;
            }else{
                max = count>max?count:max;
                count=0;
            }
        }
        max = count>max?count:max;
        return max;
    }
};
