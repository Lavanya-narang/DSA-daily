#include<iostream>
#include<vector>
using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) 
{
    if(sr==dr && sc==dc)
    {
        vector<string>bc;
        bc.push_back("");
        return bc;
    }
    vector<string>hp;
    vector<string>vp;
    vector<string>path;
    if(sc<dc)
    {
        hp=getMazePaths(sr, sc+1,  dr,  dc);
        for(string s:hp)
        {
            path.push_back("h"+s);
        }
    }
    if(sr<dr)
    {
        vp=getMazePaths( sr+1,  sc,  dr,  dc);
            for(string s:vp)
        {
            path.push_back("v"+s);
        }
    }
    return path;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}
int main()
{
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}
