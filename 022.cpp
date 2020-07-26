class Solution {
public:
    struct Node{
        int max;
        int min;
        string now;
        Node(){
            max=0;
            min=0;
        }
    };
    vector<string> generateParenthesis(int n) {
        queue<Node>output;
        if(n){
            Node temp;
            output.push(temp);
        }
        
        for(int i=0;i<2*n;i++){
            Node temp;
            int size = output.size();
            for(int j=0;j<size;j++){
                temp=output.front();
                if(temp.max<n){
                    Node Temp;
                    Temp = temp;
                    Temp.max++;
                    Temp.min++;
                    Temp.now.push_back('(');
                    output.push(Temp);
                }
                if(temp.min>0){
                    Node Temp;
                    Temp = temp;
                    Temp.min--;
                    Temp.now.push_back(')');
                    output.push(Temp);
                }
                output.pop();
            }
        }
        vector<string>Output;
        while(!output.empty()){
            Output.push_back(output.front().now);
            output.pop();
        }
        return Output;
    }
};
