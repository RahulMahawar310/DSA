class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, 0);
        int max_len = 0;
        for (const auto& word : wordDict) {
            max_len = max(max_len,(int)word.size());
        }
        dp[0] = true;
        
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        for(int i = 0; i<=s.size(); i++){
            for(int j = i-1; j>=max(0, i-max_len); j--){
                if(dp[j] && set.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};