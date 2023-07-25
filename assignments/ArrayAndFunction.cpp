/*
Write a program for filling 1D-array and printing 1D-array to 3x3 matrix.
You should call fill_Arr method in main method.
Make void method named fill_Arr.
This method will fill the 1D-array with each number digit of string and print the 1D-array of 3x3 matrix format.
Title line: void fill_Arr(int arr[], string input) { //Write a body}
You can add or delete variables if you want.
Variables that you can use in main method. int arr[9] //filling this 1D-array string input

For example, fill_arr(arr, "123456789") will print
1 2 3
4 5 6
7 8 9

fill_arr(arr, "132465798") will print
1 3 2
4 6 5
7 9 8
*/

#include <iostream>
using namespace std;

void fill_Arr(int a[9], string str){
  for(int i=0;i<9;i++){
    a[i]=str[i] - 48;
    if(i % 3 == 0) cout << endl;
    cout << str[i] << " ";
  }
}

int main() {
  int a[9] = {};
  string s;
  cout<<"Enter 9 numbers: ";
  cin>> s;
  cout<<endl;
  while(s.length()!=9){
    cout<<"Insiffiecnt amount of numbers. Enter again: ";
    cin>> s;
  }
  fill_Arr(a,s);

 /* for(int i=0;i<9;i++){
    cout << endl << a[i] << " ";  
 }*/
  
  return 0;
}
