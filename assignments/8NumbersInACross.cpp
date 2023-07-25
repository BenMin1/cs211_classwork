/*
Question:
    https://venus.cs.qc.cuny.edu/~waxman/211/eight%20numbers%20in%20a%20cross%20problem.pdf
*/

#include <iostream>
using namespace std;

void printCross(int c[]){
  cout << "  " << c[0] << " " << c[1] << endl
  << c[2] << " " << c[3] << " " << c[4] << " " << c[5] << endl
  << "  " << c[6] << " " << c[7] << endl;
}

bool alreadyPlaced(int q[], int c){
  // Row Test
  for(int i = 0; i < c; i++)
    if(q[c] == q[i])
      return false;
  return true;
}

bool okAdjacent(int q[], int c){
  static int checkArray[8][5] = {
    {-1},
    {0, -1},
    {0, -1},
    {0,1,2,-1},
    {0,1,3,-1},
    {1,4,-1},
    {2,3,4,-1},
    {3,4,5,6,-1}
  };

  for (int i = 0; checkArray[c][i] != -1; ++i){
    if(abs(q[c] - q[checkArray[c][i]]) == 1)
      return false;
    }
    return true;
}

int main() {
  int q[8] = {1,1,1,1,1,1,1,1}, col = 0, solutions = 0;
  // while we have not backtracked beyond the first index
  while (col != -1){
  // cout << "Start col " << col << " ..." << endl;
  // If we have exceed our last index
  if (col >= 8){
    cout << "Solution " << ++solutions << endl;
    printCross(q);
    // backtrack
    col--;
    q[col]++;
  }
      // If we have run out of numbers to try
  if(q[col] >= 9) {
    q[col] = 1; // reset 
    // backtrack
    col--;
    if (col != -1)
      q[col]++;
    }
    // if the number we place is okay
    else if (alreadyPlaced(q, col) && okAdjacent(q, col))
      // NextCol
      col++;  
    else {
      // NextRow
      q[col]++;
      // cout << "row " << q[col] << endl;
    }
  }
    return 0;
}
