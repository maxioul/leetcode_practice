class Solution {
public:
    queue<string>now;
    vector<string>output;
    int width=0;
    int Width =0;
    int Max;
    
    void getline(){
        int veca = now.size()-1;
        width = 0;
        int base;
        int time;
        if(veca){
            base = (Max - Width)/veca;
            time = (Max - Width)%veca;
        }else{
            base = Max-Width;
            time =0;
        }
        string temp;
        while(!now.empty()){
            temp.append(now.front());
            now.pop();
            int num = base;
            if(time){
                num ++;
                time--;
            }
            if(!now.empty()){
                for(int i =0;i<num;i++){
                    temp.push_back(' ');
                }
            }
        }
        for(int i =temp.length();i<Max;i++){
            temp.push_back(' ');
        }
        output.push_back(temp);
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        Max = maxWidth;
        for(int i =0;i<words.size();i++){
            if(now.empty()){
                width +=words[i].length();
            }else{
                width +=words[i].length() + 1;
            }
            
            if(width<=maxWidth){
                now.push(words[i]);
                Width +=words[i].length();
            }else{
                getline();
                width = words[i].length();
                Width = words[i].length();
                now.push(words[i]);
            }
        }
        string temp;
        temp.append(now.front());
        now.pop();
        while(!now.empty()){
            temp.push_back(' ');
            temp.append(now.front());
            now.pop();
        }
        for(int i =temp.length();i<maxWidth;i++){
            temp.push_back(' ');
        }
        output.push_back(temp);
        return output;
    }
};
