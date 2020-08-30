#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<int> c(m);
    for(int i=0;i<m;i++) {
        cin>>c[i];
    }
    vector<int> b;
    int s;
    for(auto i=a.begin();i!=a.end();++i) {
        s = 0;
        for(auto j=c.begin();j!=c.end();++j) {
            s = *j - *i;
            if((!(find(b.begin(), b.end(), s) != b.end())) && s>0)
            b.push_back(s);
        }
    }

    int add;
    for(auto i=a.begin();i!=a.end();++i) {
        add = 0;
        for(auto j=b.begin();j!=b.end();++j) {
            add = *i + *j; 
            if(!(find(c.begin(), c.end(), add) != c.end())) {
               b.erase(j);
               j--;
            }
        }
    }

    for(int i=0;i<b.size();i++) {
        cout<<b[i]<<" "; 
    }
}