#include <cstring>
#include <iostream>
using namespace std;
void bubbleSort(int a[], int length) { // 冒泡、稳定
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
}
void selectionSort(int a[], int length) { // 选择，不稳定
  int minIndex = 0, temp;
  for (int i = 0; i < length - 1; i++) {
    for (int j = i + 1; j < length; j++) {
      if (a[j] < a[minIndex])
        minIndex = j;
    }
    temp = a[i];
    a[i] = a[minIndex];
    a[minIndex] = temp;
  }
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
}
void insertSort(int a[], int length) { // 插入，稳定
  int current, preIndex;
  for (int i = 1; i < length; i++) {
    current = a[i];
    preIndex = i - 1;
    while (preIndex >= 0 && current < a[preIndex]) {
      a[preIndex + 1] = a[preIndex];
      preIndex--;
    }
    a[preIndex + 1] = current;
  }
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
}

int main() {
  int a[10] = {9, 8, 7, 6, 5, 4, 3, 1, 2, 0};
  int length = sizeof(a) / sizeof(a[0]);
  //  cout << a << endl << length << endl;
  //  bubbleSort(a, length);   //冒泡
  //  selectionSort(a,length);  //选择
  //  insertSort(a,length);    //插入
}
