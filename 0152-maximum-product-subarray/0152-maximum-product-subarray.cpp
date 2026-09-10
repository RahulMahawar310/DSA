class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int pre = 1;
        int suff = 1;
        int maxProd = INT_MIN;

        for (int i = 0; i < n; i++) {

            if (pre == 0) {
                pre = 1;
            }

            if (suff == 0) {
                suff = 1;
            }

            pre *= nums[i];
            suff *= nums[n - 1 - i];

            maxProd = max(maxProd, max(pre, suff));
        }

        return maxProd;
    }
};