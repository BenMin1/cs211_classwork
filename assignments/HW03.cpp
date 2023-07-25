/*
instructions can be found at: https://venus.cs.qc.cuny.edu/~waxman/211/Score%20the%20race.pdf
*/

#include <iostream>
using namespace std;

int winner(double arr[], int size){  //returns location of winning team in race
  int lowest = 100;
  int winTeam = 0;
  for(int i = 0; i < size; i++){
    if(arr[i] < lowest){
      lowest = arr[i];
      winTeam = i+1;
    }
  }
  return winTeam;
}

double lowestScore(double arr[], int size){  //returns winning score
  double lowest = 100;
  int winTeam = 0;
  for(int i = 0; i < size; i++){
    if(arr[i] < lowest){
      lowest = arr[i];
      winTeam = i+1;
    }
  }
  return lowest;
}

int alphabet(string x){    //returns location of first team in Alphabetical order
  char firstA = 100;
  int aOrder;
  for(int i = 0; i < x.length(); i++){
    if(x[i] < firstA){
      firstA = x[i];
      aOrder = i;
    }
  }
  return aOrder;
}

int numOfRunners(string s) {
  int count = 0;
  int count2 = 0;
  char c = ' '; // team fct
  for (int i = 0; i < s.length(); i++) {
    count = 0;
    for (int x = 0; x < s.length(); x++) {
      if (s[i] == s[x]) {
        count++;
        c = s[i]; // team fct
      }
    }
    if(i==0) count2 = count;
    if(count != count2) return 0;  //if one team has more runners return 0 (ERROR)
  }
  return count;
}

int main() {
  string race = "";
  string input;
  string error;

  while(error != "valid"){
    while(input != "done"){
      cout << endl << "Enter data or 'done' when finished ";
      cin >> input;
      if(input != "done") race = race + input;
    }
    if(numOfRunners(race) != 0) error = "valid";  //If each team has same # of runners proceed
    else{
      cout << "ERROR each team needs same # of runners ";
      race = "";
      input = "";
      }  
  }

  cout << endl << "INPUT: " << race << endl << endl;
  
  double scoresArr[race.length() / numOfRunners(race)];
  string teamsOrder[race.length() / numOfRunners(race)];
  int counter = 1;
  double totalScore = 0;
  string raceCopy = race;

  cout << "There are " << race.length() / numOfRunners(race) << " teams." <<  endl << "Each team has " << numOfRunners(race) << " runners." << endl << endl;
  cout << "\t" << "Team"<< "\t" << "Score" << endl;

  for(int i = 1; i <= race.length() / numOfRunners(race); i++){  //finds all teams in order 
    teamsOrder[i-1] = race[alphabet(raceCopy)];
    for(int x = 0; x < numOfRunners(race); x++){    //deletes all runners in the team
      totalScore += alphabet(raceCopy) +1;
      raceCopy.replace(alphabet(raceCopy), 1, "a");  //replaces with lowercase a so it is no longer the lowest ASCII value
    }
    cout << "\t" << teamsOrder[i-1] << "\t \t" << totalScore/numOfRunners(race) << endl;
    scoresArr[i-1] = totalScore/numOfRunners(race);
    totalScore = 0;
  }  
  cout << endl << "The winner is team " << teamsOrder[winner(scoresArr, race.length() / numOfRunners(race))-1] << " with " << lowestScore(scoresArr, race.length() /       numOfRunners(race)) << " points!";
  return 0;
}
