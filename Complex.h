#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
	Complex operator+(const Complex&) const; // addition
	Complex operator-(const Complex&) const; // subtraction
	Complex operator*(const Complex&) const; // multiplication
	Complex operator/(const Complex&) const; // division
	
	explicit Complex(double realPart = 0.0 , double imaginaryPart = 0.0 )
	{
		real = realPart;
		imaginary = imaginaryPart;
	}
	
	Complex conjugate(const Complex& c)
	{
		Complex result(c.real, -1 * c.imaginary);
		return result;
	}
	
	Complex operator+(const Complex& c)
	{
		return  Complex{ real + c.real, imaginary + c.imaginary };
	}
	Complex operator-(const Complex& c)
	{
		return  Complex{ real - c.real, imaginary - c.imaginary };
	}
	Complex operator*(const Complex& c)
	{
		return  Complex{ (real * c.real) - (imaginary * c.imaginary)
						,(real * c.imaginary) + (imaginary * c.real) };
	}
	
	Complex operator/(const Complex& c)
	{
		Complex denominator = conjugate(c);
		double deno = pow(c.real, 2) + pow(c.imaginary, 2);

		return Complex((real * c.real + imaginary * c.imaginary) / deno,
			(imaginary * c.real - real * c.imaginary) / deno);
	}

	friend ostream &operator<<( ostream& output, const Complex &c)
	{
		if (c.imaginary > 0)
			output << setprecision(2) <<c.real << " + " << c.imaginary << "i";
		else if (c.real != 0.0 && c.imaginary != 0.0)
		{
			string a = to_string(c.imaginary);
			for (int i = 0 ; i < a.length(); i++)
			{
				if (a[i] == '.')
				{
					a = (a[i + 1] != '0') ? a.substr(1, i + 2) : a.substr(1, i - 1);
					break;
				}
					
			}
			output << setprecision(2) << c.real << " - " << a <<"i";
		}
		else
			output << 0;
		
		 return output;
	}
	 friend istream &operator>>(istream& input, Complex &c)
	{
		input >> c.real >> c.imaginary;
		return input;
	}

	bool operator==(const Complex& c)
	{
		if (real == c.real && imaginary == c.imaginary)
			return true;
		else
			return false;
	}
	bool operator!=(const Complex& c)
	{
		if (real == c.real && imaginary == c.imaginary)
			return false;
		else
			return true;
	}
private:
	double real;
	double imaginary;
};

#endif // !COMPLEX_H

int main()
{
	Complex 	a(0,1),
			b(2,3),
			c(-4,5), 
			d(4),
			e(2.6,3.33);

	//cout << "Enter the complex number (real before imaginary): ";
	//cin >> b; // 2 + 3i 
	cout << "The complex number a is: " << a << endl;
	cout << "The complex number b is: " << b << endl;
	cout << "The complex number c is: " << c << endl;
	
	cout << "a + b: " << a + b << endl;
	cout << "a * b: " << a * b << endl;

	cout << "b - c: " << b - c << endl;
	cout << "b / c: " << b / c << endl;

	if (a != b)
	{
		cout << "a is different from b" << endl;
	}
	else if ( a == b)
	{
		cout << "a is the same with b" << endl;
	}
	
	system("pause");
	return 0;
}
