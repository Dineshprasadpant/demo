#include<iostream>
#include<vector>
using namespace std;
string substring(string& s, int start, int end)
{
    int n=s.length();
    if(start<0 ||end>n || end<start)
        return "";
    string ans;
    for(int i=start;i<end;i++)
        ans+=s[i];  
    return ans;
}
vector<string> substrings(string s)
{
    int n=s.length();
    vector< string >list;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++)
        {
            list.push_back(s.substr(i,j-i));
        }
    }
    return list;
}
int main()
{
    string str;
    cout<<"Enter a sting: ";
    cin>>str;
    vector<string>ans=substrings(str);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}