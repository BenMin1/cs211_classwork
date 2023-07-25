#include <iostream>
using namespace std;

const int N = 3;
// Men's Preferences
const int MP[N][N] = {{0,2,1}, //man 0 likes woman 0 the most and woman 1 the least.
                      {0,2,1},
                      {1,2,0}};
// Women's Preferences
const int WP[N][N] = {{2,1,0},
                      {0,1,2},
                      {2,0,1}};

void printMatching(int q[]) {
    for (int i = 0; i < N; i++)
        cout << "m" << i << " w" << q[i] << endl;
}
  
bool ok(int q[], int col) {
    //cm = a currently assigned man
    //cw = a currently assigned woman
    //nm = new man
    //nw = new woman
    //nm and nw are the proposed pair to add to the match
    int cm, cw, nm, nw;

    nm = col;
    nw = q[col];

    // Thre aren't repeating assignments (Row Test)
    for (int i = 0; i < col; i++)
        if (q[i] == q[col])
            return false;

    /* Check the new pair (new man, new woman) against each existing pair consisting of
       (current man, current woman) to see if the new pair would make the match unstable. */
    for (cm = 0; cm < N; cm++) {
        cw = q[cm];
        //Lower value implies a higher preference

        // Reject if
        if(// a. the current man prefers the new woman to his partner
           MP[cm][nw] < MP[cm][cw]
           // b. the new woman prefers the current man to her partner
        && WP[nw][cm] < WP[nw][nm]) return false;
        // OR
        if(// c. if the new man prefers the current woman to his partner
           MP[nm][cw] < MP[nm][nw]
           // d. if the current woman prefers the new man to her partner
        && WP[cw][nw] < WP[cw][cm]) return false;
    }

    return true; //since the pair nm & nw do not introduce an instability
}

int main() {
    //Start with the first male (col)
    int new_man = 0;
    int matching[3] = {0};
    int solution = 0;

    // While we have not backtracked beyond the first male:
    while (new_man != -1) {
        // If all the people have been matched
        if (new_man >= N) {
            cout << "Solution " << ++solution << endl;
            printMatching(matching);
            // backtrack
            new_man--;
            matching[new_man]++;
        }
        // If all the available women are matched already
        else if (matching[new_man] >= N) {
            matching[new_man] = 0; // reset new woman to starting value
            //backtrack
            new_man--;
            if (new_man != -1)
                matching[new_man]++;
        }
        // Check if the q is stable
        else if (ok(matching, new_man))
            new_man++; // Next Man (col)
        else
            // pair the man with the next available woman (row)
            matching[new_man]++;
    }
    return 0;
}
