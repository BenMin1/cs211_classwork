#include <iostream>
using namespace std;

int main () {
  int win[6] = { }; 
  for(int i0 = 0; i0 <= 9; i0++) { // window 1
    win[0] = i0; 
    for(int i1 = 0; i1 <= 9; i1++) { // window 2
      win[1] = i1; 
      for(int i2 = 0; i2 <= 9; i2++) { // window 3
        win[2] = i2;
        for(int i3 = 0; i3 <= 9; i3++) { // window 4
          win[3] = i3;
          for(int i4 = 0; i4 <= 9; i4++) { // window 5
            win[4] = i4;
            for(int i5 = 0; i5 <= 9; i5++) { // window 6
              win[5] = i5;
              cout << win[0] << win[1] << win[2] << win[3] << win[4] << win[5] << " "; 
              cout << endl;
            }
          }
        }
      }
    }
  }
  return 0;
}
