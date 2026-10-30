class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();

        if(n<m) return "";

        vector<int>freq(256,0);
        for(char c: t) freq[c]++;

        int left=0;
        int need=m;
        int minLen=INT_MAX;
        int start=0;

        for(int right=0; right<n; right++){
            if(freq[s[right]] > 0) need--;
            freq[s[right]]--;

            while(need == 0){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    start = left;
                }

                freq[s[left]]++;
                if(freq[s[left]]>0) need++;
                left++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};