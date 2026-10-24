class Solution {
public:
    bool isVowels(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int maxVowels(string s, int k){
        int n=s.size();
        int count=0;

        for(int i=0;i<k; i++){
            if(isVowels(s[i])) count++;
        }

        int maxCount=count;

        for(int i=k;i<n;i++){
            if(isVowels(s[i])) count++;
            if(isVowels(s[i-k])) count--;
            maxCount= max(maxCount, count);
        }
        return maxCount;
    }
};