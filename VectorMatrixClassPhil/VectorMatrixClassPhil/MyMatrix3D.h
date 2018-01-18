#ifndef MY_MATRIX3
#define MY_MATRIX3

#include "MyVector3D.h"
#include <stdio.h>
#include <math.h>

class MyMatrix3
{
public:
	MyMatrix3();//default constructor
	MyMatrix3(
		double a11, double a12, double a13,
		double a21, double a22, double a23,
		double a31, double a32, double a33);//overloaded constructor that accepts 9 doubles
	MyMatrix3(MyVector3D row1, MyVector3D row2, MyVector3D row3);//overloaded constructor that accepts 3 vectors
	~MyMatrix3();//destructor
	std::string toString();//convert to string function
	MyMatrix3 operator +(const MyMatrix3 other) const; //addition function for adding two matrices
	MyMatrix3 operator -(const MyMatrix3 other) const;//subtraction function for subtracting two matrices
	MyMatrix3 operator *(const MyMatrix3 other) const; //multiplication function for multiplying one matrix by another
	MyVector3D operator *(const MyVector3D vector) const;//multiplication function for multiplying a matrix by a vector
	MyMatrix3 operator *(const double scale) const;//multiplies a matrix by a scalar

	MyMatrix3 transpose()const; //returns the transpose of a matrix
	double determinant()const; //returns the determinant of a matrix
	MyMatrix3 inverse()const; //returns the inverse of a matrix

	MyVector3D row(int row)const;//returns a given row of a matrix based on the argument value
	MyVector3D col(int col)const;//returns a given column of a matrix base on passed integer

	bool operator ==(const MyMatrix3 other)const; //checks if two matrices are equal
	bool operator !=(const MyMatrix3 other)const; //checks if two matrices are not equal
	static MyMatrix3 rotationZ(double angleradians); //returns a matrix that rotates about the Z matrix
	static MyMatrix3 rotationY(double angleradians); //returns a matrix that rotates about the y matrix
	static MyMatrix3 rotationX(double angleradians); //returns a matrix that rotates about the X matrix

	static MyMatrix3 translation(MyVector3D displacement);//creates a matrix that moves an object
	static MyMatrix3 scale(double scalingfactor);//returns a matrix that scales an object based on the number passed


private:
	double m11;
	double m12;
	double m13;
	double m21;
	double m22;
	double m23;
	double m31;
	double m32;
	double m33;
};


#endif // !MY_MATRIX3
