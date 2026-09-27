class Solution {
public:
    bool isPalindrome(string&s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){  
                return false;
            }
        i++, j--;
        }
        return true;
    }

    bool check(string&a , string& b){
        int n=a.length();  // b.length() ,can also use 
        int i=0; 
        int j=n-1;
        while(i<j && a[i]==b[j]){
            i++,j--;
        }

        return isPalindrome(a,i,j)|| isPalindrome(b,i,j);
    }

    bool checkPalindromeFormation(string a, string b) {
       return check(a,b) || check(b,a);
    }
};