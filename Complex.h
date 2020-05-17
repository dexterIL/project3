#include <string>
#include <iostream>

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

	explicit Complex()
	{
		real = 0.0;
		imaginary = 0.0;
	}
	

	Complex(double realPart, double imaginaryPart)
	{
		real = realPart;
		imaginary = imaginaryPart;
	}
	Complex(double realPart)
	{
		real = realPart;
		imaginary = 0.0;
	}

	

	
	void setImaginary(double imginaryPart)
	{
		imaginary = imginaryPart;
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

	//Division

	friend ostream &operator<<( ostream& output, const Complex &c)
	{
		if (c.imaginary > 0)
		{
			output << c.real << "+" << c.imaginary << "i";
		}
		else
		 output << c.real  << c.imaginary << "i";
		 
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
	Complex a(0,1),
			b,
			c(-4,5), 
			d(4),
			e(2.6,3.33);

	cout << "Enter the complex number: ";
	cin >> b; // 2 + 3i 
	cout << "The complex number a is: " << a << endl;
	cout << "The complex number b is: " << b << endl;
	cout << "a + b: " << a + b << endl;
	cout << "a - b: " << a - b << endl;
	cout << "a * b: " << a * b << endl;
	
	system("pause");
	return 0;
}