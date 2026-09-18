class Solution {
public:
    vector<vector<int>> result;

    void twoSum(vector<int>& nums, int target, int i, int j){
        while(i<j){
            int sum = nums[i]+nums[j];

            if(sum<target){
                i++;
            }else if(sum > target){
                j--;
            }else{
                result.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
                 
                 // for duplicate elements
                while(i<j && nums[i]==nums[i-1]) i++;
                while(i<j && nums[j]==nums[j+1]) j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        while(n<3){
            return {};
        }
        result.clear();

        sort(nums.begin(), nums.end());   // sort

        //fixing one elements
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int n1 = nums[i];
            int target = -n1;

            twoSum(nums, target, i+1, n-1 );  
        }

        return result;
    }
};