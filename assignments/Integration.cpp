#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

double integrate(FUNC f, double a, double b) {
  const int n = 1000000; // The number of rectangles we use (Higher the number the more accurate)       
  const double width = (b - a) / n; // Gets the width of each rectangle
  double count = 0;                 // Counter for the sum of the rectangles

  for (int i = 0; i < n; i++) {
    double x = a + (i + 0.0001) * width;     // Making sure we are in the correct rectangle
    double height = f(x);         // Getting the height of the current rectangle
    double area = width * height; // Area of the current rectangle
    count += area;                // Adds the sum
  }
  return count; // Returns the total sum of the rectangles between x = a and x = b
}

double line(double x) { return x; }
double square(double x) { return x * x; }
double cube(double x) { return x * x * x; }

int main() {
  cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl; // 12
  cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
  cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl; // 156
  return 0;
}
