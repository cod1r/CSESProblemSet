#include <bits/stdc++.h>
using namespace std;


// brute force solution works but is too slow!
// void rec(
//         vector<unsigned long long> weights, 
//         unsigned long long sum1, 
//         unsigned long long sum2, 
//         unsigned long long half, 
//         unsigned long long sum, 
//         unsigned long long& diff
//     ){
//     if (weights.size() == 0 || sum1 >= half) {
//         diff = min((sum1-sum2) < 0 ? -1*(sum1-sum2):(sum1-sum2), diff);
//         return;
//     }
//     for (int i = 0; i < weights.size(); i++){
//         vector<unsigned long long> copy = weights;
//         copy.erase(copy.begin()+i);
//         rec(copy, sum1+weights[i], sum-(sum1+weights[i]), half, sum, diff);
//     }
// }

long long _min = INT_MAX;
unordered_set<long long> s;
void rec(vector<long long> apples, int i, long long sum, long long half){
    if (i >= apples.size()){
        if (sum > 2400 && sum < 2500)
            s.insert(sum);
        _min = min(abs(half-sum), _min);
        return;
    }
    rec(apples, i+1, sum+apples[i], half);
    rec(apples, i+1, sum-apples[i], half);
}

int main(){
    int apples; cin >> apples;
    if (apples == 1) {
        printf("%i\n", 0);
    }
    if (apples == 1){
        printf("%d", 1);
        return 0;
    }
    long long sum = 0;
    vector<long long> weights(apples);
    for (long long& i : weights){
        cin >> i;
        sum += i;
    }
    rec(weights, 0, 0, sum/2);
    for (long long i : s)
        printf("%lli\n", i);
    return 0;
}
