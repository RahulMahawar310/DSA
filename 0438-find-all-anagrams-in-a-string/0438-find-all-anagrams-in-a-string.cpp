class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n=s.size();
        int k=p.size();

        if(n<k) return ans;

        vector<int> pfreq(26,0);
        vector<int> wfreq(26,0);

        for(int i=0; i<k; i++){
            pfreq[p[i]-'a']++;
            wfreq[s[i]-'a']++;
        }

        if(pfreq==wfreq) ans.push_back(0);

        for(int i=k; i<n; i++){
            wfreq[s[i]-'a']++;
            wfreq[s[i-k]-'a']--;

            if(pfreq==wfreq) ans.push_back(i-k+1);
        }
        return ans;
    }
};