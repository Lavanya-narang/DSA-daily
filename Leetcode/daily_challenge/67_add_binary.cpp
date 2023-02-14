class Solution {
public:
    string addBinary(string a, string b) {
         bool carry = false;
        string ans = "";
        for (int i = a.size()-1, j = b.size()-1; i >= 0 || j >= 0; i--, j--) {
            int n1 = 0, n2 = 0, n3 = 0;
            
            if (i >= 0) n1 = a[i] - '0';
            if (j >= 0) n2 = b[j] - '0';
            if (carry)  n3 = 1;
            
            if (n1+n2+n3 == 3) {
                ans = "1" + ans;
                carry = true;
            }
            else if (n1+n2+n3 == 2) {
                ans = "0" + ans;
                carry = true;
            }
            else if (n1+n2+n3 == 1){
                ans = "1" + ans;
                carry = false;
            }
            else {
                ans = "0" + ans;
                carry = false;
            }
        }
        if (carry)
            ans = "1" + ans;
        return ans;
    }
};
