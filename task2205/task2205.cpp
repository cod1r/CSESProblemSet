#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<string> gc{"0", "1"};

    if (n == 1){
        for (string s : gc)
            printf("%s\n", s.c_str());
    }
    else{
        for (int i = 1; i < n; i++){
            vector<string> temp = gc;

            reverse(temp.begin(), temp.end());

            for (string& s : gc)
                s = "0" + s;
            for (string& s : temp)
                s = "1" + s;
            
            for (string s : temp)
                gc.push_back(s);
        }
        for (string s : gc)
            printf("%s\n", s.c_str());
    }
    return 0;
}