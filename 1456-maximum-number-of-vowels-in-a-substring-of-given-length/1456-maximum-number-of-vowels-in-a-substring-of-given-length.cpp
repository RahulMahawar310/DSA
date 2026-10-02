class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        
        // count vowels
        int count =0; 
        for(int i=0; i<k; i++){
            if(isVowel(s[i]))
                count++;
        }

        int maxCount = count;
        //slide window
        for(int i=k; i<n; i++){
            if(isVowel(s[i])) count++;
            if(isVowel(s[i-k])) count--;
            maxCount =max(maxCount, count);
        }
        return maxCount;
    }
};