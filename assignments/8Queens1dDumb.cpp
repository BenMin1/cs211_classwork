#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[]) {
  for(int i = 0; i < 8; i++){     //checks all 8 queen positions
    for(int c = 0; c < i; c++){   //compares to queens to the left
      if(q[i] == q[c]) return false; //horizontal check
      int x = c+1;
      if(q[i] - x == q[i-x]) return false; //uppper diagonal check
      if(q[i] + x == q[i-x]) return false;  //lower diagonal check
    }
  }
  return true;
}

void print(int q[], int count) {
  cout << "Solution # " << count << ": " << endl;
  // Prints the array with a column on each line (an = solution flipped)
  for(int i = 0; i < 8; i++){
    for(int x = 0; x < 8; x++){
      cout << " ";
      if(q[i] != x) cout << "0";
      else if (q[i] == x) cout << "1";
    }
    cout << endl;
    //cout << q[i] << " ";
  }
  cout << endl;
}

int main() {
  int q[8] = {};
  int count = 0;
  for(int a = 0; a < 8; a++){
    q[0] = a;
    for(int b = 0; b < 8; b++){
      q[1] = b;
      for(int c = 0; c < 8; c++){
        q[2] = c;
        for(int d = 0; d < 8; d++){
          q[3] = d;
          for(int e = 0; e < 8; e++){
            q[4] = e;
            for(int f = 0; f < 8; f++){
              q[5] = f;
              for(int g = 0; g < 8; g++){
                q[6] = g;
                for(int h = 0; h < 8; h++){
                  q[7] = h;
                  if(ok(q)){
                    count ++;
                    print(q, count);
                  }
                }
              }
            }  
          }
        }
      }
    }
  }
  return 0;
}
