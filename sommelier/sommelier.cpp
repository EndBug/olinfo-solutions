#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Returns the number of samples you can taste AFTER the given index
int searchTree(vector<int> arr, int index, int last) {
  // If I'm skipping the last or over return 0.
  if (index >= arr.size()) return 0;

  int max = 0;
  for (int i = index; i < arr.size(); i++) {
    if (arr[i] >= last) {
      int res = searchTree(arr, i + 2, arr[i]) + 1;
      if (max < res) max = res;
    }
  }
  return max;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  int N;
  vector<int> arr;

  in >> N;
  for (int i = 0; i < N; i++) {
    int curr;
    in >> curr;
    arr.push_back(curr);
  }

  out << searchTree(arr, 0, 0);

  return 0;
}