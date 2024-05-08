#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
  int32_t q;
  cin >> q;
  while (q--) {
    uint64_t k;
    cin >> k;
    uint64_t digits = 0;
    for (int i = 0; i < 18; ++i) {
      uint64_t num_digits_total = 9 * pow<uint64_t>(10, i) * (i + 1);
      if (digits + num_digits_total > k) {
        uint64_t number_digits = i + 1;
        uint64_t mod = (k - digits) % number_digits;
        uint64_t number =
          (uint64_t)pow<uint64_t>(10, i) - 1 + ((k - digits) / number_digits) + ((mod + number_digits - 1) / number_digits);
        string s = to_string(number);
        if (mod > 0) {
          cout << s[mod - 1] << endl;
        } else if (mod == 0) {
          cout << s.back() << endl;
        } else {
          throw;
        }
        break;
      }
      digits += num_digits_total;
    }
  }
}
