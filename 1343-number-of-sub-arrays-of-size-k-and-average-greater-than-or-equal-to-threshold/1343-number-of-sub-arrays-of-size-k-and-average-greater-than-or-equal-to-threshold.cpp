class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int target= threshold *k;      //  sum/k >= threshold
        int sum=0;                     //  sum >= threshold * k
        int count=0;

        for(int i=0; i<k; i++){
            sum += arr[i];
        }

        if(sum >= target) count++;

        for(int i=k; i<n; i++){
            sum =sum + arr[i]- arr[i-k];
            if(sum>=target) count++;
        }
        return count;
    }
};