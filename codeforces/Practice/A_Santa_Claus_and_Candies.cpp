#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> ans;
    int c = 1;
    while (n >=c) {
        n -= c;
        ans.push_back(c);
        c++;
    }
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) cout<<ans[i]+n<<" ";
        else cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
