#ifndef MYVECTOR3D
#define MYVECTOR3D

#include <iostream>
#include <SFML\Graphics.hpp>

class MyVector3D
{
public:
	MyVector3D(); //Default constructor, draws our vectors
	~MyVector3D(); //default destructor, clears our vectors
	MyVector3D(double x, double y, double z); //This function will pass 3 co-ordinates to the constructor(x,y,z)
	MyVector3D(sf::Vector3f sfVector); //3D conversion to a float
	MyVector3D(sf::Vector3i sfVector);// 3D conversion to an integer
	MyVector3D(sf::Vector2f sfVector); //2D conversion to a float
	MyVector3D(sf::Vector2i sfVector); //2D conversion to an integer
	MyVector3D(sf::Vector2u sfVector); //2D conversion to an unsigned integer

	MyVector3D operator+ (const MyVector3D right) const; //addition operator, will add vectors
	MyVector3D operator- (const MyVector3D right) const; //subtraction operator, will subtract vectors
	MyVector3D operator* (const double scalar) const; //multiplication operator, will multiply vectors
	MyVector3D operator/ (const double divisor) const; //division operator, divides vectors
	MyVector3D operator += (const MyVector3D right); //plus equals operator will add then assign vectors
	MyVector3D operator -= (const MyVector3D right);//plus equals operator willsubtract then assign vectors

	bool operator == (const MyVector3D right) const; //equals boolean, checks if any two vectors are the same
	bool operator != (const MyVector3D right) const;//inequality boolean, checks if two vectors are not the same

	double length() const; //gets the length of a vector
	double lengthSquared() const;// gets the length-squared of any given vector
	double dot(MyVector3D other) const; //Gets the dot product of two vectors
	MyVector3D crossProduct(const MyVector3D other)const; //gets the cross product of two vectors
	MyVector3D unit() const; //returns a unit vector
	void normalise();//normalises a vector
	double angleBetween(MyVector3D other) const; //gets the angle between two vectors
	MyVector3D projection(const MyVector3D other) const; //Gets the projection of a vector onto another
	MyVector3D rejection(const MyVector3D other)const;
	void reverseX();
	void reverseY();


	std::string toString(); //converts to a string
	double X()const;//returns m_x
	double Y()const;//returns m_y
	double Z()const;//returns m_z
	operator sf::Vector3f() { return sf::Vector3f(static_cast<float>(m_x), static_cast<float>(m_y), static_cast<float>(m_z)); }; //converts variables of vector(s) to a float
	operator sf::Vector3i() { return sf::Vector3i(static_cast<int>(m_x), static_cast<int>(m_y), static_cast<int>(m_z)); }; //converts x,y,z of vector(s) to integer data type
	operator sf::Vector2i() { return sf::Vector2i(static_cast<int>(m_x), static_cast<int>(m_y)); }; //casts 2D vectors to an integer value(truncation)
	operator sf::Vector2f() { return sf::Vector2f(static_cast<float>(m_x), static_cast<float>(m_y)); };//casts 2D vectors as a float
	operator sf::Vector2u() { return sf::Vector2u(static_cast<unsigned int>(m_x), static_cast<unsigned int>(m_y)); }; // converts variables to 2D unsigned int

private:
	double m_x;
	double m_y;
	double m_z;
};

#endif // !MYVECTOR3D
#pragma once
