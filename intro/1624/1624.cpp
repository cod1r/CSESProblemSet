#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
bool canPlace(const vector<vector<char>> &matrix, int row, int col) {
  for (int i = 0; i < matrix[row].size(); ++i) {
    if (matrix[row][i] == 'Q')
      return false;
  }
  for (int i = 0; i < matrix.size(); ++i) {
    if (matrix[i][col] == 'Q')
      return false;
  }
  int diag_top_right_row = row - 1;
  int diag_top_right_col = col + 1;
  while (diag_top_right_row >= 0 && diag_top_right_col < 8) {
    if (matrix[diag_top_right_row][diag_top_right_col] == 'Q')
      return false;
    diag_top_right_row--;
    diag_top_right_col++;
  }
  int diag_bottom_right_row = row + 1;
  int diag_bottom_right_col = col + 1;
  while (diag_bottom_right_row < 8 && diag_bottom_right_col < 8) {
    if (matrix[diag_bottom_right_row][diag_bottom_right_col] == 'Q')
      return false;
    diag_bottom_right_row++;
    diag_bottom_right_col++;
  }
  int diag_top_left_row = row - 1;
  int diag_top_left_col = col - 1;
  while (diag_top_left_row >= 0 && diag_top_left_col >= 0) {
    if (matrix[diag_top_left_row][diag_top_left_col] == 'Q')
      return false;
    diag_top_left_row--;
    diag_top_left_col--;
  }
  int diag_bottom_left_row = row + 1;
  int diag_bottom_left_col = col - 1;
  while (diag_bottom_left_row < 8 && diag_bottom_left_col >= 0) {
    if (matrix[diag_bottom_left_row][diag_bottom_left_col] == 'Q')
      return false;
    diag_bottom_left_row++;
    diag_bottom_left_col--;
  }
  return true;
}
void print_matrix(const vector<vector<char>> &matrix) {
  for (const auto &v : matrix) {
    for (const auto &c : v)
      cout << c << " ";
    cout << endl;
  }
}
void column_wise(vector<vector<char>> &matrix, int queens, int col, int &ans) {
  for (int r = 0; r < matrix.size(); ++r) {
    if (canPlace(matrix, r, col) && matrix[r][col] == '.') {
      if (queens + 1 == 8) {
        ans++;
        continue;
      }
      matrix[r][col] = 'Q';
      column_wise(matrix, queens + 1, col + 1, ans);
      matrix[r][col] = '.';
    }
  }
}
int main() {
  vector<vector<char>> matrix(8, vector<char>(8));
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cin >> matrix[i][j];
    }
  }
  int ans = 0;
  column_wise(matrix, 0, 0, ans);
  cout << ans << endl;
  return 0;
}
