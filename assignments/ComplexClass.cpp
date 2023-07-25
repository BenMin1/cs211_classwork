#include <iostream>
using namespace std;

class Complex {
  private:
    double r;
    double i;

  public:
    Complex(){
      r=0;
      i=0;
    }

    Complex(double real, double imag){
      r = real;
      i = imag;
    }

    Complex(double real){
      r = real;
      i = 0;
    }

    double get_r(){return r;}
    double get_i(){return i;}
    void set_r(double real){r = real;}
    void set_i(double imag){i = imag;}

    Complex operator+(Complex a) {
      Complex ret; 
      ret.r = a.r + r;
      ret.i = a.i + i;
      return ret;
    }

    Complex operator-(Complex a) {
      Complex ret; 
      ret.r = r - a.r;
      ret.i = i - a.i;
      return ret;
    }

    Complex operator*(Complex a) {
      Complex ret; 
      ret.r = a.r * r + i * a.i;
      ret.i = a.r * i + r * a.i;
      return ret;
    }

    Complex operator/(Complex a) {
      Complex ret;
      double temp = a.r * a.r + a.i *a.i; 
      ret.r = (a.r * r + i * a.i) / temp;
      ret.i = (a.r * i + r * a.i) / temp;
      return ret;
    }

  friend ostream& operator<<(ostream& os, Complex r){
    os<<r.r << " + " << r.i << " i";
    return os;
  }

};

int main() {
	Complex c1;
	c1.set_r(5);
	c1.set_i(6);
	//c1 = 5 +  6i
	
	Complex c2;
	c2.set_r(12);
	c2.set_i(4);
	//c2 = 12 + 4i
	
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << "c1 + c2: " << c1 + c2 << endl;
	cout << "c1 - c2: " << c1 - c2 << endl;
	cout << "c1 * c2: " << c1 * c2 << endl;
	cout << "c1 / c2: " << c1 / c2 << endl;
	
	return 0;
}
