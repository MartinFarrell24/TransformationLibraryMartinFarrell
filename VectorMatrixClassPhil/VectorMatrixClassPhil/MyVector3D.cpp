#include "MyVector3D.h"
#include <math.h>
//@Author Martin Farrell
//--------------------------------------------------
//3D Vectors
//--------------------------------------------------
//Known bugs

MyVector3D::MyVector3D() : //Default constructor
	m_x(0.0),
	m_y(0.0),
	m_z(0.0)
{
}


MyVector3D::~MyVector3D() //default destructor
{
}

std::string MyVector3D::toString() //converts vector(s) to a string
{
	char tmpbuf[256];
	sprintf_s(tmpbuf, "[ %g, %g, %g ]", m_x, m_y, m_z);
	return tmpbuf;
}

double MyVector3D::X()const//returns m_x
{
	return m_x;
}

double MyVector3D::Y()const//returns m_y
{
	return m_y;
}

double MyVector3D::Z()const//return m_z
{
	return m_z;
}

void MyVector3D::reverseX()
{
	m_x = -m_x;
}

void MyVector3D::reverseY()
{
	m_y = -m_y;
}


MyVector3D::MyVector3D(double x, double y, double z) : //passes the constructor 3 variable(x,y,z coordinates)
	m_x(x),
	m_y(y),
	m_z(z)
{
}

MyVector3D::MyVector3D(sf::Vector3f sfVector) : //casts the vectors as a float
	m_x(static_cast<float>(sfVector.x)),
	m_y(static_cast<float>(sfVector.y)),
	m_z(static_cast<float>(sfVector.z))
{
}

MyVector3D::MyVector3D(sf::Vector3i sfVector) : //casts the vectors as an integer
	m_x(static_cast<int>(sfVector.x)),
	m_y(static_cast<int>(sfVector.y)),
	m_z(static_cast<int>(sfVector.z))
{
}

MyVector3D::MyVector3D(sf::Vector2f sfVector) : //casts the vectors as a float(2D)
	m_x(static_cast<float>(sfVector.x)),
	m_y(static_cast<float>(sfVector.y))
{
}

MyVector3D::MyVector3D(sf::Vector2i sfVector) :  //casts the vectors as an integer(2D)
	m_x(static_cast<int>(sfVector.x)),
	m_y(static_cast<int>(sfVector.y))
{
}

MyVector3D::MyVector3D(sf::Vector2u sfVector) :  //casts 2D vectors as an unsigned int
	m_x(static_cast<unsigned int>(sfVector.x)),
	m_y(static_cast<unsigned int>(sfVector.y))
{
}

MyVector3D MyVector3D::operator+(const MyVector3D right) const //adds vectors
{
	//adds the corresponding components of the vectors to each other i.e VectorA(x) + VectorB(x)
	return MyVector3D(m_x + right.m_x, m_y + right.m_y, m_z + right.m_z);
}

MyVector3D MyVector3D::operator-(const MyVector3D right) const //subtracts vectors
{
	//subtracts the corresponding components of the vectors from each other i.e VectorA(x) - VectorB(x)
	return MyVector3D(m_x - right.m_x, m_y - right.m_y, m_z - right.m_z);
}

MyVector3D MyVector3D::operator*(const double scalar) const //multiplies vectors by a scalar
{
	//multiplies each component of a vector(x,y,z) by the scalar
	return MyVector3D(m_x * scalar, m_y * scalar, m_z * scalar);
}

MyVector3D MyVector3D::operator/(const double divisor) const //divides vectors by a divisor
{
	//divides the vector's x, y & z component by a divisor
	return MyVector3D(m_x / divisor, m_y / divisor, m_z / divisor);
}

MyVector3D MyVector3D::operator+=(const MyVector3D right) //adds and assigns to a vector to another
{
	//Adds the  value of the right vector's components to the left vector's corresponding components and assigns the value to left vector i.e. VectorA(x) += VectorB(x)
	m_x += right.m_x;
	m_y += right.m_y;
	m_z += right.m_z;
	return MyVector3D(m_x, m_y, m_z); //returns the new values of the assigned vector's components
}

MyVector3D MyVector3D::operator-=(const MyVector3D right) //subtracts and assigns to a vector to another
{
	//subtracts the  value of the right vector's components from the left vector's corresponding components and assigns the value to left vector i.e. VectorA(x) += VectorB(x)
	m_x -= right.m_x;
	m_y -= right.m_y;
	m_z -= right.m_z;
	return MyVector3D(m_x, m_y, m_z); //returns the new values of the assigned vector's components
}

bool MyVector3D::operator==(const MyVector3D right) const //equality check
{
	//checks if all of the corresponding values of two vectors are equal
	return (m_x == right.m_x && m_y == right.m_x && m_z == right.m_x);
}

bool MyVector3D::operator!=(const MyVector3D right) const //inequality check
{
	//checks if all of the corresponding values of two vectors are not equal
	return (m_x != right.m_x && m_y != right.m_x && m_z != right.m_x);
}

double MyVector3D::length() const //Gets the length of a vector using it's components(x,y,z)
{
	//gets the magnitude of the vector(s) by getting the square root of the sum of the components squared
	const double result = std::sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
	return result;
}

double MyVector3D::lengthSquared() const
{
	//gets the magnitude of the vector(s) squared by multiplying the components by each other.
	//The square root is omitted because squaring cancels out the square root and the result is the length squared.
	const double result = (m_x * m_x) + (m_y * m_y) + (m_z * m_z);
	return result;//returns length squared
}

double MyVector3D::dot(MyVector3D other) const //gets the dot product of 2 vectors
{
	//multiplies the corresponding components of both vectors i.e. VectorA(x) * vectorB(x) and adds the result of the multiplications of the x, y and z values to get the dot product
	const double result = ((m_x * other.m_x) + (m_y * other.m_y) + (m_z * other.m_z));
	return result;
}

MyVector3D MyVector3D::crossProduct(const MyVector3D other) const //cross multiplies two vectors
{
	//multiplies the appropriate corresponding coordinates of both vectors and subtracts them from each other to get the cross product resulting in a vector
	return MyVector3D((m_y * other.m_z) - (m_z * other.m_y), (m_x * other.m_z) - (m_z * other.m_x), (m_x * other.m_y) - (m_y * other.m_x));
}

MyVector3D MyVector3D::unit() const //gets the unit vector 
{
	//local variables
	double vectorlength = length();//calls length function to get magnitude of vector
	double X = 0; //x coordinate
	double Y = 0;//y coordinate
	double Z = 0;//z coordinate

				 //assigns x,y,z the result of the components of the vector passed to this function divided by it's magnitude.
	X = m_x / vectorlength;
	Y = m_y / vectorlength;
	Z = m_z / vectorlength;

	return MyVector3D(X, Y, Z);
}

void MyVector3D::normalise()//normalises vector
{
	double vectorLength = length();//calls length function and assigns magnitude to variable

	if (vectorLength != 0)//prevents division by zero
	{
		//divides x, y and z components by the magnitude of our vector
		m_x = m_x / vectorLength;
		m_y = m_y / vectorLength;
		m_z = m_z / vectorLength;
	}
}

double MyVector3D::angleBetween(MyVector3D other) const //gets the angle between two vectors
{
	const float PI_F = 3.14159265359;
	double top = dot(other);
	double under = length() * other.length();
	double angle;
	if (under != 0) // never divide by zero
	{
		double answer = top / under;
		if (answer > 1) answer = 1;
		if (answer < -1) answer = -1;
		angle = std::acos(answer);
		return (angle * 180 / PI_F);
	}
	return 0.0; //returns the angle
}

MyVector3D MyVector3D::projection(const MyVector3D other) const//projects a vector onto another
{
	double lenghtSq = lengthSquared();
	double dotProduct = dot(other);
	double scale = 1.0; // default for null vector involvement
	if (lenghtSq != 0)
	{
		scale = dotProduct / lenghtSq;
	}

	return this->operator*(scale);
}

MyVector3D MyVector3D::rejection(const MyVector3D other) const
{
	return other - projection(other);
}