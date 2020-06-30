class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        if(size ==1){
            if(flowerbed[0]==0){
                n--;
            }
            if(n>0){
                return false;
            }else{
                return true;
            }
        }
        if(flowerbed[0]==0&&flowerbed[1]==0){
            flowerbed[0]=1;
            n--;
        }
        for(int i =1;i<flowerbed.size()-1;i++){
            if(flowerbed[i-1]==0&&flowerbed[i]==0&&flowerbed[i+1]==0){
                flowerbed[i]=1;
                n--;
            }
        }
        if(size>2&&flowerbed[size-2]==0&&flowerbed[size-1]==0){
            n--;
        }
        if(n>0){
            return false;
        }else{
            return true;
        }
    }
};
