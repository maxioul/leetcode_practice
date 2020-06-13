class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp;
        temp = nums1;
        int poi1=0,poi2=0;
        int poi=0;
        while(poi1<m&&poi2<n){
            if(temp[poi1] > nums2[poi2]){
                nums1[poi] = nums2[poi2];
                poi2++;
            }else{
                nums1[poi] = temp[poi1];
                poi1++;
            }
            poi++;
        }
        if(poi != m + n){
            while(poi1<m){
                nums1[poi] = temp[poi1];
                poi++;
                poi1++;
            }
            while(poi2<n){
                nums1[poi] = nums2[poi2];
                poi++;
                poi2++;
            }
        }
        
    }
};
