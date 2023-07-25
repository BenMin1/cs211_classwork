#include <iostream>
#include <fstream>
using namespace std;

int lowestHW(double x[], int y){  //returns location of lowest score
  double lowest = 100;
  int ans;
  for(int i = 0; i < y; i++){
    if(x[i] < lowest){
      lowest = x[i];
      ans = i;    
    }
  }
  return ans;
}

double sum(double x[], int y){  //returns total of an (array, size)
  double total = 0;
  for(int i =0; i <y; i++){
    total = total + x[i];
  }
  return total;
}

int main () {
  ifstream myFile; 
  string storage;
  double scores [250] = {0.0};  //master list of all scores
  double HWGrades [13] = {0.0};  
  double testGrades [12] = {0.0};
  double finals [10] = {0.0};  //final scores
  int counter = 0;
  int students = 10;   
  int stringLen = storage.length();
  
  myFile.open ("StudentData.txt");
  for (int i = 1; i <= students; i++) {  //gets correct amount of lines
    getline (myFile, storage);
    storage.erase(0, 9);  // Deletes Student# Header
    int stringLen = storage.length();  // Length of string for the for loop
    double temp = 0;
    
    for (int q = 1; q < stringLen; q++) {  //cycles through string to find values
      storage.erase(0, 1);  //deletes scanned space
      double m = stod(storage.c_str());  //sets first value to a double
      
      if ((m == temp) || (m > 2) || (m == temp*10) || (m+1 == temp && m!=1)){  //exceptions
        if (temp==0 || temp==1 || temp==2){  //exceptions to exceptions bc value is one digit
          scores[counter] = m; //adds all exception values to single array
          counter ++;
          storage.erase(0,1);
          q++; 
        }
      } 
      else {
        scores[counter] = m;  //adds all values to single array
        counter ++;
        if(m == 0 || m==1 || m==2){
          storage.erase(0,1);
          q++;
        }
      } 
      temp = m;
    }
  } 
  myFile.close();

  for(int x = 0; x < students; x++){  //repeats for each student
    for(int i = 0; i < 25; i++){  //cycles through 25 grades in the large array
      if(i>=12){  //if its a HW score
        HWGrades[i-12] = scores[(25 * x) + i];  
      }
      if(i<12){    //if its a quiz score
        testGrades[i] = scores[(25 * x) + i];
      }
    }
    for(int a = 0; a < 2; a++)  //sets lowest two values to 100
      testGrades[lowestHW(testGrades, 12)] = 100;
    
    for(int q = 0; q < 3; q++)
    HWGrades[lowestHW(HWGrades, 13)] = 100;
                
    if((sum(HWGrades, 13) - 300 + sum(testGrades, 12) - 200) < 30) 
      finals[x] = sum(HWGrades, 13) - 300 + sum(testGrades, 12) - 200;
    else finals[x] = 30;  //sets max value of grade to 30
  }
  ofstream Data("labScore.txt");

  
  Data << "\t" << "Name" << "\t" << "Score" << endl;
  for(int i = 0; i < 10; i++){
    Data << "Student" << i+1 << "\t" << finals[i] << endl;
  }
  return 0;
}
