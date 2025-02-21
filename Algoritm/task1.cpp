#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> flowers(n);

  for (int i = 0; i < n; i++) {
    cin >> flowers[i];
  }

  int max_l = 0;
  int max_r = 0;
  int left = 0;

  unordered_map<int, int> count;

  for (int right = 0; right < n; right++) {
    count[flowers[right]]++;

    if (count[flowers[right]] >= 3) {
      while (count[flowers[right]] >= 3) {
        count[flowers[left]]--;
        left++;
      }
    }

    if (right - left > max_r - max_l) {
      max_l = left;
      max_r = right;
    }
  }

  cout << max_l + 1 << " " << max_r + 1 << "\n";
}