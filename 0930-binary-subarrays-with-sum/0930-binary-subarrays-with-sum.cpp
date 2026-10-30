class Solution {
public:
    int atMost(vector<int>& nums, int x){
        if(x<0) return 0;

        int n=nums.size();
        int left=0 , sum=0, count=0;

        for(int right=0; right<n; right++){
            sum+= nums[right];

            while(sum > x){
                sum -= nums[left];
                left++;
            }

            count += right-left+1;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal) - atMost(nums, goal-1);
    }
};