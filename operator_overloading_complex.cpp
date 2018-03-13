#include <iostream>
using namespace std;

class Complex
{
    private:
      float real;
      float imag;
    public:
       Complex(): real(0), imag(0){ }
       void input()
       {
           cout << "Enter real and imaginary parts respectively: ";
           cin >> real;
           cin >> imag;
       }
       Complex operator - (Complex c2)
       {
           Complex temp;
           temp.real = real - c2.real;
           temp.imag = imag - c2.imag;
           return temp;
       }
       Complex operator + (Complex c2)
       {
           Complex temp;
           temp.real=real+c2.real;
           temp.imag=imag+c2.imag;
           return temp;
       }
       void output()
       {
           if(imag < 0)
               cout << real << imag << "i";
           else
               cout << real << "+" << imag << "i";
               cout<<endl;
       }
};

int main()
{
    Complex c1, c2, result;
    cout<<"               :OPERATOR OVERLOADING:\n\n";
    cout<<"Enter first complex number:\n";
    c1.input();
    cout<<"Enter second complex number:\n";
    c2.input();
    result = c1-c2;
    cout<<"\nDIFFERENCE:"<<endl;
    result.output();
    result=c1+c2;
    cout<<"\nSUM:"<<endl;
    result.output();
    return 0;
}
