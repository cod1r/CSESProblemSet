#include <bits/stdc++.h>
using namespace std;

void rec(string in, string gen, vector<string>& con, int more, int max){
    if (gen.length() == max){
        con.push_back(gen);
    }
    for (int i = 0; i < in.length() && (more + 1) <= max; i++){
        string copy = in;
        copy.erase(copy.begin()+i);
        rec(copy, gen+in[i], con, more+1, max);
    }
}

int main(){
    vector<string> con;
    string gen = "";
    string in; cin >> in;
    string srtd = in;
    sort(srtd.begin(), srtd.end());
    rec(in, gen, con, 0, in.length());
    unordered_set<string> ss;
    for (string s : con)
        ss.insert(s);
    vector<string> ans;
    for (string s : ss){
        string t = s;
        sort(t.begin(), t.end());
        if (t == srtd)
            ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (string s: ans)
        printf("%s\n", s.c_str());
    return 0;
}