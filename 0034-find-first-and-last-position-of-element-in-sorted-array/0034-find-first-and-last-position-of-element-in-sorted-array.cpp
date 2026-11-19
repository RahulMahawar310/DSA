class Solution {
public:
int FirstOccurence(vector<int>& nums ,int target)
{
    int n = nums.size();
    int low=0;
    int high=n-1;
    int result =-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(nums[mid]==target)
        {
            result=mid;
            high=mid-1;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else high=mid-1;
    }
    return result;
}

int LastOccurence(vector<int>& nums ,int target){
    int n =nums.size();
    int low =0;
    int high=n-1;
    int result =-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(nums[mid]==target)
        {
            result=mid;
            low=mid+1;
        }
        else if(nums[mid]>target)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
        return result;

}
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = FirstOccurence(nums , target);
        int last = LastOccurence(nums , target);
        
        return {first , last};
    }
};