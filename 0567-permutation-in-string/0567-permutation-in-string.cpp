class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int k= s1.size();
       int n= s2.size();

       if(n < k) return false;

       vector<int> s1freq(26,0);
       vector<int > wfreq(26,0);

       for(int i=0; i<k; i++){
        s1freq[s1[i]-'a']++;
        wfreq[s2[i]-'a']++;
       }
        if(s1freq==wfreq) return true;

        for(int i=k; i<n; i++){
            wfreq[s2[i]-'a']++;
            wfreq[s2[i-k]-'a']--;

            if(s1freq==wfreq) return true;
        }
        return false;
    }
};