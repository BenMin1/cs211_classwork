#include <iostream>
#include <vector>
using namespace std;

// check if queens placement is valid
bool isValid(int result[], int c) {
  for (int i = 0; i < c; i++)
    if (result[i] == result[c] || abs(result[i] - result[c]) == c - i)
      return false;
  return true;
}

int nQueens(int n) {
  int *q = new int[n]; //
  int c = 0;
  int answer = 0;
    while (c >= 0) { // End the loop if you backtrack from the first column
    if(c == (n-1)){   // If you have passed the last column,
      c--;
      answer ++;
    }
    else{        // Otherwise, move to one before the first row
      c++;
      q[c] = -1; 
    }
    while (c >= 0) {
      q[c] ++;          // Move to the next row
      if(q[c] > (n-1)) c--;  // If you have passed the end of the column, backtrack
      else if(isValid(q, c)){          // Otherwise, call the ok function.
        break;  //If it returns true, go back to the beginning of the outer loop.
      }
    }  
  }
  return answer;
}

int main() {
  int n = 12;
  
  for (int i = 1; i <= n; i++)
    cout << "There are " << nQueens(i) << " possible answers to the " << i << " queens problem" << endl;
  
  return 0;
}
