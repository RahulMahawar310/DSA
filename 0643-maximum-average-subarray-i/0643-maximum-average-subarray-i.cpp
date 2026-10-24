class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();

        long long windowSum=0;
        for(int i=0; i<k; i++){
            windowSum += nums[i];
        }

        long long maxSum = windowSum;

        for(int i=k; i<n; i++){
            windowSum = windowSum + nums[i] - nums[i-k];
            maxSum = max(windowSum, maxSum);
        }
        return double(maxSum)/k;
    }
};