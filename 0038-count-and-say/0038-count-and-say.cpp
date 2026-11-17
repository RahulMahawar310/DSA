class Solution {
public:
    string countAndSay(int n) {
        // 2231 -> 221311 (two times 2, one times 3, two times 1)

        if(n==1)
            return "1";
        
        string say = countAndSay(n-1);

        string result="";

        for(int i=0; i<say.length(); i++){
            char ch = say[i];
            int count = 1;

            while(i<say.length()-1 && say[i]==say[i+1]){
                count++;
                i++;
            }

            result += to_string(count) + string(1, ch);
        }
        return result;
    }
};