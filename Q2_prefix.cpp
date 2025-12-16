#include<iostream>
#include<vector>
using namespace std;
vector<string> getprefix(string s) {
    int n = s.length();
    vector<string> ans;

    ans.push_back("ε"); // empty string

    for(int i = 1; i <= n; i++) {
        ans.push_back(s.substr(0, i));
    }
    return ans;
}
int main()
{
    string str;
    cout<<"Enter a string ";
    cin>>str;
    vector<string>prefix=getprefix(str);
    for(auto i:prefix)
        cout<<i<<" ";
    return 0;
}