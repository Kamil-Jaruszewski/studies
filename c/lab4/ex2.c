#include <stdio.h>
#include <stdbool.h>

bool isSorted(int *arr) {
  for (int i = 1; i < 20; i++) {
    if (!(arr[i] >= arr[i - 1])) {
      return false;
    }
  }

  return true;
}

void boubleSort(int *arr) {
  int i, temp;

  while(!isSorted(arr)) {
    for (i = 1; i < 20; i++ ) {
      if (arr[i - 1] > arr[i]) {
        temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

void disarr(int *arr) {
  for (int i = 0; i < 20; i++) {
    printf(" %d|", arr[i]);
  }
  printf("\n");
}

int main() {
  int nn[20] = {32453, 10, 9, 8, 7, 6, 5, 3, 1, 8, 9, 18, 19, 20, 1232, 542, 0, -13, 8, 13};
  int *n = nn;

  disarr(n);

  boubleSort(n);

  disarr(n);

  printf("\n\n");
  return 0;
}
