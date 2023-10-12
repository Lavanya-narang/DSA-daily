class Solution {
public:
void solve(string digits,vector<string>&op,string &temp,vector<string>&pad,int ind)
{
    if(ind==digits.size())
    {
        op.push_back(temp);
        return;
    }
    string val=pad[digits[ind]-'0'];
    for(int i=0;i<val.size();i++)
    {
        temp.push_back(val[i]);
        solve(digits,op,temp,pad,ind+1);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty())
        {
            return {};
        }
        vector<string>pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>op;
        string temp;
        solve(digits,op,temp,pad,0);
        return op;
    }
};
