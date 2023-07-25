/*
Part A:
Declare a c-string of size 50.
Ask the user for a line of text of length 10 or more. Recall to maintain the proper length in order to not destroy the c-str.
Insert it into the c-str created in step 1. Print out the c-str and its length.
Extract the middle 5 or 6 characters of the c-str. 5 if the c-string is of an odd length, 6 if it’s of even length. Ex: “Hello New York” -> “o New ”, “Goodbye Bob” -> “dbye “
Insert these characters into another c-str. Print the c-str substituting spaces with asterisks (*).
Part B:
Do all the above using strings and the methods available in the string class. (Hint: substrings)
*/

#include <iostream>
#include <cstring>
using namespace std;

int main () {
  //Part A
  char str[50] = {}; // 1
  char temp[50];
  char ans[50];

  cout << endl << "Enter a line of text of length 10 or more" << endl; // 2
  
  cin >> temp;
  strcat(str,temp);
  
  while(strlen(str) < 10) {
    str[strlen(str)] = ' ';
    cin >> temp;
    strcat(str,temp);  // 3
  }

  cout << str << endl << strlen(str);
  
  if(strlen(str) % 2 == 1){  //If odd extract middle 5 
    for(int i =0; i <= 4; i++){
//      cout  << str[(strlen(str)/2)-2+i];
      ans[i] = str[(strlen(str)/2)-2+i];
    }
  }

  if(strlen(str) % 2 == 0){  //If even extract middle 6
    for(int i =0; i <= 5; i++){
//      cout << str[(strlen(str)/2)-3+i];
      ans[i] = str[(strlen(str)/2)-3+i];
    }
  }

  for(int i = 0; i < strlen(ans); i++){  //change ' ' to '*'
    if(ans[i] == ' ') ans[i] = '*';    
  }
  
  cout << endl << ans;

  //Part B
  string text;  //1
  string input;
  string finalString;

  cout << endl << "Enter a line of text of length 10 or more" << endl;  //2
  cin >> input;
  text = input;  //3
  
  while(text.length() < 11){
    cin >> input;
    text = text + " " + input;
  }

  cout << text << endl << text.length() << endl;
  
  if(text.length() % 2 == 0){
    finalString = text.substr((text.length()/2)-3, 6); //4
  }
  
  if(text.length() % 2 == 1){
    finalString = text.substr((text.length()/2)-2, 5);  //4
  }
  
  for(int i = 0; i < finalString.length(); i++){
    if(finalString.substr(i, 1) == " ") finalString.replace(i, 1, "*");  //5
  }
  
  cout << finalString;
}
