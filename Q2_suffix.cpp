#include <iostream>
#include <vector>
using namespace std;

vector<string> getsuffix(string s) {
    int n = s.length();
    vector<string> ans;

    for(int i = 0; i < n; i++) {
        ans.push_back(s.substr(i, n - i));
    }

    ans.push_back("ε"); // empty string
    return ans;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    vector<string> suffix = getsuffix(str);
    for(auto i : suffix)
        cout << i << " ";

    return 0;
}
