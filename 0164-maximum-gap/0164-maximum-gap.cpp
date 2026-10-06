class Solution {
public:

    struct Bucket {
        bool used = false;
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
    };

    int maximumGap(vector<int>& nums) {

        int n = nums.size();

        if (n < 2)
            return 0;

        int minElement = INT_MAX;
        int maxElement = INT_MIN;

        // Find minimum and maximum element.
        for (int num : nums) {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
        }

        if (minElement == maxElement)
            return 0;

        int bucketWidth =
            ceil((double)(maxElement - minElement) / (n - 1));

        int bucketCount =
            (maxElement - minElement) / bucketWidth + 1;

        vector<Bucket> buckets(bucketCount);

        // Put every element into its bucket.
        for (int num : nums) {

            int bucketIndex =
                (num - minElement) / bucketWidth;

            buckets[bucketIndex].used = true;

            buckets[bucketIndex].minValue =
                min(buckets[bucketIndex].minValue, num);

            buckets[bucketIndex].maxValue =
                max(buckets[bucketIndex].maxValue, num);
        }

        int previousMax = 0;

        // Find first non-empty bucket.
        for (int i = 0; i < bucketCount; i++) {
            if (buckets[i].used) {
                previousMax = buckets[i].maxValue;
                break;
            }
        }

        int answer = 0;

        // Calculate maximum gap.
        for (int i = 0; i < bucketCount; i++) {

            if (!buckets[i].used)
                continue;

            answer = max(answer,
                         buckets[i].minValue - previousMax);

            previousMax = buckets[i].maxValue;
        }

        return answer;
    }
};
