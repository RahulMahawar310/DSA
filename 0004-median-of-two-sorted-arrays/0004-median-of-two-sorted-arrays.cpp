class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        if(n > m) return findMedianSortedArrays(arr2,arr1); 
        
        int totResEle = n + m; 
        int eleOnLeftHalf = (totResEle+1)/2; 
        int low = 0, high = n;

        while(low <= high){
            int eleFromArr1_onLeft = low + (high - low)/2; 
            int eleFromArr2_onLeft = eleOnLeftHalf - eleFromArr1_onLeft; 

            int left1 = INT_MIN, left2 = INT_MIN;
            int right1 = INT_MAX, right2 = INT_MAX;

            if(eleFromArr1_onLeft - 1 >= 0) left1 = arr1[eleFromArr1_onLeft - 1];
            if(eleFromArr1_onLeft < n) right1 = arr1[eleFromArr1_onLeft];

            if(eleFromArr2_onLeft - 1 >= 0) left2 = arr2[eleFromArr2_onLeft - 1];
            if(eleFromArr2_onLeft < m) right2 = arr2[eleFromArr2_onLeft];


            if(left1 <= right2 && left2 <= right1){
                if(totResEle % 2 == 0){
                    return (min(right1,right2) + max(left1,left2))/2.0;
                }
                else{
                    return max(left1,left2);
                }
            }
            else if(left1 > right2){
                high = eleFromArr1_onLeft - 1;
            }
            else if(left2 > right1){
                low = eleFromArr1_onLeft + 1;
            }
        }
        return 0.0;
    }
};