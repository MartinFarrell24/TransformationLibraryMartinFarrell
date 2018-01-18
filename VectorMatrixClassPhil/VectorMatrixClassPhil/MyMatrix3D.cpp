#include "MyMatrix3D.h"
/// <summary>
/// 
/// </summary>


MyMatrix3::MyMatrix3() ://default constructor
	m11{ 0.0 },
	m12{ 0.0 },
	m13{ 0.0 },
	m21{ 0.0 },
	m22{ 0.0 },
	m23{ 0.0 },
	m31{ 0.0 },
	m32{ 0.0 },
	m33{ 0.0 }
{
}

//overloaded constructor that accepts 9 doubles
MyMatrix3::MyMatrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) :
	m11{ a11 },
	m12{ a12 },
	m13{ a13 },
	m21{ a21 },
	m22{ a22 },
	m23{ a23 },
	m31{ a31 },
	m32{ a32 },
	m33{ a33 }
{
}

MyMatrix3::MyMatrix3(MyVector3D row1, MyVector3D row2, MyVector3D row3)//overloaded constructor that accepts 3 vectors
{
	m11 = row1.X();
	m12 = row1.Y();
	m13 = row1.Z();
	m21 = row2.X();
	m22 = row2.Y();
	m23 = row2.Z();
	m31 = row3.X();
	m32 = row3.Y();
	m33 = row3.Z();
}


MyMatrix3::~MyMatrix3()//destructor
{
}

std::string MyMatrix3::toString()//convert to string function
{
	char tmpbuf[512];
	sprintf_s(tmpbuf, "{ [ %g, %g, %g ] [ %g, %g, %g ] [ %g, %g, %g ] }", m11, m12, m13, m21, m22, m23, m31, m32, m33);
	return tmpbuf;


}

MyMatrix3 MyMatrix3::operator+(const MyMatrix3 other) const //addition function for adding two matrices
{
	//return a matrix with corresponding components added to each other
	return{ m11 + other.m11, m12 + other.m12, m13 + other.m13, m21 + other.m21, m22 + other.m22, m23 + other.m23, m31 + other.m31, m32 + other.m32, m33 + other.m33 };;
}

MyMatrix3 MyMatrix3::operator-(const MyMatrix3 other) const//subtraction function for subtracting two matrices
{
	//return a matrix with corresponding components subtracted from each other
	return{ m11 - other.m11, m12 - other.m12, m13 - other.m13, m21 - other.m21, m22 - other.m22, m23 - other.m23, m31 - other.m31, m32 - other.m32, m33 - other.m33 };
}

MyMatrix3 MyMatrix3::operator*(const MyMatrix3 other) const//multiplication function for multiplying one matrix by another
{
	//return a matrix which has multiplied each row of our matrix by each column of the other matrix
	return{ m11*other.m11 + m12*other.m21 + m13*other.m31, m11*other.m12 + m12*other.m22 + m13*other.m32, m11*other.m13 + m12*other.m23 + m13*other.m33,
		m21*other.m11 + m22*other.m21 + m23*other.m31, m21*other.m12 + m22*other.m22 + m23*other.m32, m21*other.m13 + m22*other.m23 + m23*other.m33,
		m31*other.m11 + m32*other.m21 + m33*other.m31, m31*other.m12 + m32*other.m22 + m33*other.m32, m31*other.m13 + m32*other.m23 + m33*other.m33 };

}

MyVector3D MyMatrix3::operator*(const MyVector3D vector) const//multiplication function for multiplying a matrix by a vector
{
	//multiplies the corresponding components 
	double x = (m11 * vector.X()) + (m12 * vector.Y()) + (m13 * vector.Z());
	double y = (m21 * vector.X()) + (m22 * vector.Y()) + (m23 * vector.Z());
	double z = (m31 * vector.X()) + (m32 * vector.Y()) + (m33 * vector.Z());

	//returns the resulting vector
	return{ x, y, z };
}

MyMatrix3 MyMatrix3::operator*(const double scale) const//multiplies a matrix by a scalar
{
	//returns a matrix multiplied by the scalar argument
	return{ m11 * scale, m12 * scale, m13 * scale, m21 * scale, m22 * scale, m23 * scale, m31 * scale, m32 * scale, m33 * scale };
}

MyMatrix3 MyMatrix3::transpose() const//returns the transpose of a matrix
{
	//returns the transpose of our matrix
	return{ m11, m21, m31, m12, m22, m32, m13, m23, m33 };;
}

double MyMatrix3::determinant() const//returns the determinant of a matrix
{
	//determinant of our matrix
	double result = (m11*(m22*m33 - m32*m23)) - (m21*(m33 * m12 - m32 * m13)) + (m31*(m23 * m12 - m22 * m13));
	return result;
}

MyMatrix3 MyMatrix3::inverse() const//returns the inverse of a matrix
{
	if (determinant() != 0)//prevents division by zero
	{
		//matrix of minors
		MyMatrix3 matrixA = { m33*m22 - m32*m23, m32*m13 - m33*m12, m23*m12 - m22*m13, m31*m23 - m33*m21, m33*m11 - m31*m13, m21*m13 - m23*m11, m32*m21 - m31*m22, m31*m12 - m32*m11, m22*m11 - m21*m12 };
		//divide by 1 over the determinant of the matrix
		return matrixA*(1 / matrixA.determinant());
	}
	return MyMatrix3();//if determinant is zero return empty matrix
}

MyVector3D MyMatrix3::row(int row) const//returns a given row of a matrix based on the argument value
{
	if (row == 0)//return 1st row if argument is zero
	{
		return MyVector3D{ m11, m12, m13 };
	}
	else if (row == 1)//return 2nd row if argument is one
	{
		return MyVector3D{ m21, m22, m23 };
	}
	else if (row == 2)//return 3rd row if argument is two
	{
		return MyVector3D{ m31, m32, m33 };
	}
	else //return an empty vector if any other number
	{
		return MyVector3D();
	}
}

MyVector3D MyMatrix3::col(int col) const//returns a given column of a matrix base on passed integer
{
	if (col == 0)//return 1st column if argument is zero
	{
		return MyVector3D{ m11, m21, m31 };
	}
	else if (col == 1)//return 2nd column if argument is one
	{
		return MyVector3D{ m12, m22, m32 };
	}
	else if (col == 2)//return 3rd column if argument is two
	{
		return MyVector3D{ m13, m23, m33 };
	}
	else//return an empty vector if any other number
	{
		return MyVector3D();
	}
}

bool MyMatrix3::operator==(const MyMatrix3 other) const//checks if two matrices are equal
{
	//check each corresponding component against each other
	if (m11 == other.m11 && m12 == other.m12 && m13 == other.m13 && m21 == other.m21 && m22 == other.m22 && m23 == other.m23 && m31 == other.m31 && m32 == other.m32 && m33 == other.m33)
	{
		return true;//if all components are the same return true
	}
	else
	{
		return false;
	}
}

bool MyMatrix3::operator!=(const MyMatrix3 other) const//checks if two matrices are not equal
{
	//check if any of the components are not the same
	if (m11 != other.m11 || m12 != other.m12 || m13 != other.m13 || m21 != other.m21 || m22 != other.m22 || m23 != other.m23 || m31 != other.m31 || m32 != other.m32 || m33 != other.m33)
	{
		//if a single component is not the same it returns true
		return true;
	}
	else
	{
		return false;
	}
}

MyMatrix3 MyMatrix3::rotationZ(double angleradians)//returns a matrix that rotates about the Z matrix
{

	double topLeftCos = cos(angleradians); //first row first column
	double topRightSin = -sin(angleradians);//first row second column
	double bottomLeftSin = sin(angleradians);//second row first column
	double bottomRightCos = cos(angleradians);//second row second column

											  //return the rotation matrix
	return MyMatrix3{ topLeftCos, topRightSin, 0, bottomLeftSin,bottomRightCos, 0, 0, 0, 1 };
}

MyMatrix3 MyMatrix3::rotationY(double angleradians)//returns a matrix that rotates about the y matrix
{
	double topLeftCos = cos(angleradians);//first row first column
	double topRightSin = sin(angleradians);//first row third column
	double bottomLeftSin = -sin(angleradians);//third row first column
	double bottomRightCos = cos(angleradians);//third row third column

											  //return rotation matrix
	return MyMatrix3{ topLeftCos, 0,topRightSin, 0,1, 0, bottomLeftSin, 0, bottomRightCos };
}

MyMatrix3 MyMatrix3::rotationX(double angleradians)//returns a matrix that rotates about the X matrix
{
	double topLeftCos = cos(angleradians);//second row second column
	double topRightSin = sin(angleradians);//second row third column
	double bottomLeftSin = -sin(angleradians);//third row second column
	double bottomRightCos = cos(angleradians);//third row third column

											  //return the rotation matrix
	return MyMatrix3{ 1, 0, 0, 0, topLeftCos, topRightSin, 0, bottomLeftSin, bottomRightCos };
}

MyMatrix3 MyMatrix3::translation(MyVector3D displacement)//creates a matrix that moves an object
{
	//puts x and v of 
	return MyMatrix3{ 1, 0, displacement.X(), 0, 1, displacement.Y(), 0, 0, 1 };
}

MyMatrix3 MyMatrix3::scale(double scalingfactor)//returns a matrix that scales an object based on the number passed
{
	//replaces the "1s" in the identity matrix with the scale
	return MyMatrix3{ scalingfactor, 0, 0, 0, scalingfactor, 0, 0, 0, scalingfactor };
}

