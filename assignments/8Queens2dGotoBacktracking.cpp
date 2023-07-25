/*
https://venus.cs.qc.cuny.edu/~jchen/CS211/Projects/2D%20Queens/
*/

#include <iostream>
using namespace std;

int main() {
      int q[8][8] = {};// Initialize the board to 0
      int r = 0, c = 0;// Start in the 1st row, 1st column
      q[0][0] = 1; // Place the first queen on the upper left corner 

nextCol:
      // Move to the next column
      c++;
      // If you passed the last column
            //goto print
      if(c > 7) goto print;
      // Otherwise start at the "TOP" of the column
      r = -1;

nextRow:
      // Move to the next row
      r++;
      // If you have passed the end of the column
            //goto backtrack
      if(r > 7) goto backtrack;
      // If there is a queen in the same row (to the left), goto nextRow
      //for each square to the left of the current square
            //if there is a queen on that square
            //goto nextRow;
      for(int i = 0; i < c; i++){
        if(q[r][i] == 1) goto nextRow;
      }
      // If there is a queen in the upper-left diagonal, goto nextRow
      //for (int i = 1; ...; i++) // End the loop when you are above or left of the chessboard
            //if there is a queen i spots above and left of the current square
            //goto nextRow;
      for(int i = 1; i < c+1; i++){
        if(r-i < 0 || c-i < 0) i = c;
        else if(q[r-i][c-i] == 1){
          goto nextRow;
        }
      }
      // If there is a queen in the lower-left diagonal, goto nextRow
      //for (int i = 1; ...; i++) // End the loop when you are below or left of the chessboard
            //if (there is a queen i spots below and left of the current square)
            //goto nextRow;
      for(int i = 1; i < c+1; i++){
        if(r+i > 7 || c-i < 0) i = c;
        else if(q[r+i][c-i] == 1){
          goto nextRow;
        }
      }
      q[r][c] = 1;
      //goto nextCol;
      goto nextCol;

backtrack:
      // Move to the previous column
      c--;
      //if (you have moved to the left of the chessboard)
            //exit the program
      r = 0;
      if(c < 0) return 0;
      // Find the square in the column with a queen in it and set r to the row number of that square
      for(int i = 0; i < 8; i ++){
        if(q[i][c] == 1) r=i;
      }
      // Remove the queen from the current square
      q[r][c] = 0;
      //goto nextRow;
      goto nextRow;
  
print:
      static int numSolutions = 0;
      cout << "Solution #" << ++numSolutions << ":\n";
      //Use a nested loop to print the chessboard
      for(int i = 0; i < 8; i++){
        for(int x = 0; x < 8; x++ ){
          cout << q[i][x] << " ";
        }
        cout << endl;
      }
      goto backtrack;
}

