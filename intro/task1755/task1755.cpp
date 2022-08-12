#include <bits/stdc++.h>
using namespace std;

int main(){
    string t; cin >> t;
    unordered_map<char, int> m;
    for (int i = 0; i < t.length(); i ++){
        m[t[i]] ++;
    }
    string r = "";
    char mid = '_';
    int chances = 1;
    for (auto& p : m){
        if (p.second % 2 != 0){
            chances--;
            mid = p.first;
            p.second--;
        }
        if (chances < 0) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        for (int i = 0; i < p.second/2; i++){
            r += p.first;
        }
    }
    string tmp = r;
    reverse(tmp.begin(), tmp.end());
    if (mid != '_')
        r += mid;
    r += tmp;
    cout << r << endl;
    return 0;
}
