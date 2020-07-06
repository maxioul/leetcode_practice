class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int size = bits.size();
        if(size<2)return bits[0]==0;
        if(bits[size-2]==0){
            return true;
        }
        int i =0;
        for(;i<size-2;i++){
            if(bits[i]==1){
                i++;
            }
        }
        
        return i != size-2;
    }
};

// It also depends on how many continuous 1 right before last 0;
