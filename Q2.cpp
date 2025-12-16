#include<iostream>
#include<vector>
using namespace std;
vector<string> getprefix(string s) {
    int n = s.length();
    vector<string> ans;

    ans.push_back("\u03B5"); // empty string

    for(int i = 1; i <= n; i++) {
        ans.push_back(s.substr(0, i));
    }
    return ans;
}
vector<string> getsuffix(string s) {
    int n = s.length();
    vector<string> ans;

    for(int i = 0; i < n; i++) {
        ans.push_back(s.substr(i, n - i));
    }

    ans.push_back("\u03B5"); // empty string
    return ans;
}
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
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout<<endl<<"Prefixes of given string: "<<endl;
    vector<string>prefix=getprefix(str);
    for (int i = 0; i < prefix.size(); i++) 
        cout<<prefix[i]<<" ";
    cout<<endl<<"Suffixes of given string: "<<endl;
    vector<string> suffix = getsuffix(str);
    for (int i = 0; i < suffix.size(); i++)
        cout << suffix[i] << " ";
    cout<<endl<<"Substrings of given string: "<<endl;
    vector<string>ans=substrings(str);
    for (int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<" ";
        
    cout<<endl<<endl<<"Lab No.: 2 / Name: Dinesh Prasad Panta / Roll No. 03 / Section:A ";
    return 0;
}

