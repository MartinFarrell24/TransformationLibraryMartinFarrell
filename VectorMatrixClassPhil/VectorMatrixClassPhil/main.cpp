//@Author Martin Farrell
//----------------------------------------
//Vector and matrix tests
//----------------------------------------
//No known bugs

#include "MyVector3D.h"
#include "MyMatrix3D.h"
#include <SFML\Graphics.hpp>
#include <string.h>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 




void testConstructors();//default constructor test
void testVectorConstructor();//overloaded constructor that accepts vector test
void testAddition();//test for adding two matrices
void testSubtraction();//test for subtracting two  matrices
void testMultiplication(); //test for multiplying two matrices
void testVectorMultiplication(); //test for multiplying a matrix by a vector
void testScalarMultiplication(); //test for multiplying a matrix by a scalar
void testTranspose(); //test for getting transpose of a matrix
void testDeterminant(); //test for getting the determinant of the matrix
void testInverse(); //test for getting the inverse of a matrix
void testRow(); //test for returning a row after accepting an integer argument
void testCol(); //test for returning a column after accepting an integer argument
void testEquals(); //test for checking if two matrices are equal
void testNotEquals(); //test for checking if two matrices are not equal
void testRotateZ(); //test for getting a matrix for a rotation about the z axis by a certain angle
void testRotateY(); //test for getting a matrix for a rotation about the y axis by a certain angle
void testRotateX(); //test for getting a matrix for a rotation about the x axis by a certain angle
void testTranslation();
void testScaling();

int main()
{
	testConstructors();
	testVectorConstructor();
	testAddition();
	testSubtraction();
	testMultiplication();
	testVectorMultiplication();
	testScalarMultiplication();
	testTranspose();
	testDeterminant();
	testInverse();
	testRow();
	testCol();
	testEquals();
	testNotEquals();
	testRotateZ();//vectors
	testRotateY();
	testRotateX();
	testTranslation();//vectors
	testScaling();
	std::system("pause");
	return EXIT_SUCCESS;
}

void testConstructors()
{
	MyMatrix3 matrixA{};


	std::cout << "-------- default constructor--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 0, 0, 0 ] [ 0, 0, 0 ] [ 0, 0, 0 ] }" << std::endl;
	matrixA = MyMatrix3{ 1.1,2.2,3.3,-4.4,5.5,6.6,7.7,8.8,9.9 };
	std::cout << "-------- 9 doubles constructor--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 1.1, 2.2, 3.3 ] [ -4.4, 5.5, 6.6 ] [ 7.7, 8.8, 9.9 ] }" << std::endl;


	std::cout << "========================================" << std::endl;
}

void testVectorConstructor()
{
	//3 vectors to be passed to the overloaded constructor
	MyVector3D murtVectorA(1, 2, 3);
	MyVector3D murtVectorB(-4, 5.5, 6);
	MyVector3D murtVectorC(7.7, 2, 0);

	std::cout << "-------- Vector constructor--------------" << std::endl;
	std::cout << murtVectorA.toString() + " , " + murtVectorB.toString() + " , " + murtVectorC.toString() << std::endl;
	std::cout << "{ [ 1, 2, 3 ] [ -4, 5.5, 6 ] [ 7.7, 2, 0 ] }" << std::endl;
	MyMatrix3 matrixA{ murtVectorA, murtVectorB, murtVectorC }; //pass vectors to constructor
	std::cout << "-------- accepts 3 vectors--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "{ [ 1, 2, 3 ] [ -4, 5.5, 6 ] [ 7.7, 2, 0 ] }" << std::endl;


	std::cout << "========================================" << std::endl;
}

void testAddition()
{
	//matrices to be added
	MyMatrix3 matrixA = MyMatrix3{ 1,2.2,-3,-4,5.5,6.6,7.7,8.8,9.9 };
	MyMatrix3 matrixB = MyMatrix3{ 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };

	std::cout << "-------- Test Addition--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{ 1, 2.2, -3 ] [ -4, 5.5, 6.6 ] [ 7.7, 8.8, 9.9 }" << std::endl;
	matrixA = matrixA.operator +(MyMatrix3(matrixB));//call the function and pass 2nd matrix
	std::cout << "------------------------------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "AFTER{ [ 2.1, 4.4, 0.3 ] [ 0.4, 11.0, 13.2 ] [ 15.4, 17.6, 19.8 ] }" << std::endl;


	std::cout << "========================================" << std::endl;
}

void testSubtraction()
{
	//matrices to be subtracted
	MyMatrix3 matrixA = MyMatrix3{ 1,2.2,-3,-4,5.5,6.6,7.7,8.8,9.9 };
	MyMatrix3 matrixB = MyMatrix3{ -1.1,2.2,3.3,-4.4,5.5,6.6,7.7,8.8,0 };

	std::cout << "-----------Subtraction--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{ 1, 2.2, -3 ] [ -4, 5.5, 6.6 ] [ 7.7, 8.8, 9.9 }" << std::endl;
	matrixA = matrixA.operator -(MyMatrix3(matrixB));//call the function and pass second matrix
	std::cout << "------------------------------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "AFTER{ [ 2.1, 0, -6.3 ] [ -0.4, 0, 0 ] [ 0, 0, 9.9 ] }" << std::endl;


	std::cout << "========================================" << std::endl;
}

void testMultiplication()
{
	//matrices to be multiplied
	MyMatrix3 matrixA = MyMatrix3{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	MyMatrix3 matrixB = MyMatrix3{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "-----------Multiplication--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{ 1, 2.2, -3 ] [ -4, 5.5, 6.6 ] [ 7.7, 8.8, 9.9 }" << std::endl;
	matrixA = matrixA.operator *(MyMatrix3(matrixB));//call the function and pass 2nd matrix
	std::cout << "------------------------------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "AFTER{ [ 30, 36, 42 ] [ 66, 81, 96 ] [ 102, 126, 150 ] }" << std::endl;


	std::cout << "========================================" << std::endl;
}

void testVectorMultiplication()
{
	//matrix and vector it's to be multiplied by
	MyMatrix3 matrixA = MyMatrix3{ 1,2.2,-3,-4,5.5,6.6,7.7,8.8,9.9 };
	MyVector3D vectorA(2, 3, -2);

	std::cout << "--------vector multiplication--------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{ 1, 2.2, -3 ] [ -4, 5.5, 6.6 ] [ 7.7, 8.8, 9.9 }" << std::endl;
	vectorA = matrixA.operator *(MyVector3D(vectorA));//call function and pass the vector
	std::cout << "------------------------------------" << std::endl;
	std::cout << vectorA.toString() << std::endl;
	std::cout << "AFTER{ [ 0.4 ] [ 24.3 ] [ -52.8 ] }" << std::endl;


	std::cout << "========================================" << std::endl;
}

void testScalarMultiplication()
{
	//matrix to be multiplied by a scalar
	MyMatrix3 matrixA = MyMatrix3{ 1,2.2,-3,-4,5.5,6.6,7.7,8.8,9.9 };

	std::cout << "---------Scalar Multiplication------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{ 1, 2.2, -3 ] [ -4, 5.5, 6.6 ] [ 7.7, 8.8, 9.9 }" << std::endl;
	matrixA = matrixA.operator *(double(10));//call function and pass scalar
	std::cout << "------------------------------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "AFTER{ [ 10, 22, -30 ] [ -40, 55, 66 ] [ 77, 88, 99] }" << std::endl;


	std::cout << "========================================" << std::endl;
}

void testTranspose()
{
	//matrix to get the transpose of
	MyMatrix3 matrixA = MyMatrix3{ 1,2.2,-3,-4,5.5,6.6,7.7,8.8,9.9 };

	std::cout << "-------------Transpose--------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{ 1, 2.2, -3 ] [ -4, 5.5, 6.6 ] [ 7.7, 8.8, 9.9 }" << std::endl;
	matrixA = matrixA.transpose();//call function
	std::cout << "------------------------------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "AFTER{ [ 1, -4, 7.7 ] [ 2.2, 5.5, 8.8 ] [ -3, 6.6, 9.9] }" << std::endl;


	std::cout << "========================================" << std::endl;
}

void testDeterminant()
{
	//matrix to get the determinant of
	MyMatrix3 matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };

	std::cout << "-------------Determinant-----------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{ 1, 2.2, -3 ] [ -4, 5.5, 6.6 ] [ 7.7, 8.8, 9.9 }" << std::endl;
	double result = matrixA.determinant();//call function
	std::cout << "------------------------------------" << std::endl;
	std::cout << result << std::endl;
	std::cout << "AFTER{ [38.87399] }" << std::endl;


	std::cout << "========================================" << std::endl;
}

void testInverse()
{
	//matrix to get the inverse of
	MyMatrix3 matrixA = MyMatrix3{ 2,1,1,3,2,1,2,1,2 };

	std::cout << "----------------Inverse-------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{2,1,1 ] [ 3,2,1 ] [ 2,1,2 }" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << matrixA.inverse().toString() << std::endl;//call function and convert to and display as a string
	std::cout << "AFTER{ [3, -1, -1 ][-4, 2, 1][-1, 0, 1] }" << std::endl;

	std::cout << (matrixA*(matrixA.inverse())).toString() << std::endl;

	std::cout << "========================================" << std::endl;
}

void testRow()
{
	//matrix whose rows shall be returned
	MyMatrix3 matrixA = MyMatrix3{ 2,1,1,3,2,1,2,1,2 };

	std::cout << "----------------Row Test------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{2,1,1 ] [ 3,2,1 ] [ 2,1,2 }" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << matrixA.row(1).toString() << std::endl;//call function and pass integer (0-2)
	std::cout << "AFTER{ [3, 2, 1] }" << std::endl;

	std::cout << "========================================" << std::endl;
}

void testCol()
{
	//matrix whose columns shall be returned
	MyMatrix3 matrixA = MyMatrix3{ 2,1,1,3,2,1,2,1,2 };

	std::cout << "----------------Col Test------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{2,1,1 ] [ 3,2,1 ] [ 2,1,2 }" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << matrixA.col(0).toString() << std::endl;//call function and pass integer (0-2)
	std::cout << "AFTER{ [2, 3, 2] }" << std::endl;

	std::cout << "========================================" << std::endl;
}

void testEquals()
{
	//two matrices to check if they're equal to each other or not
	MyMatrix3 matrixA = MyMatrix3{ 1,2,-3,4,5.5,0,7.7,8.8,9.9 };
	MyMatrix3 matrixB = MyMatrix3{ 1,2,-3,4,5.5,0,7.7,8.8,9.9 };

	std::cout << "--------------Equal Test------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{2,1,1 ] [ 3,2,1 ] [ 2,1,2 }" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	bool checkEquals = matrixA.operator==(matrixB);//call function and pass other matrix
	std::cout << std::to_string(checkEquals) << std::endl;
	std::cout << "AFTER{  [1 = True] }" << std::endl;

	std::cout << "========================================" << std::endl;
}

void testNotEquals()
{
	//two matrices to check if they're not equal to each other
	MyMatrix3 matrixA = MyMatrix3{ 1,2,-3,4,5.5,0,7.7,8.8,9.9 };
	MyMatrix3 matrixB = MyMatrix3{ 2,2,-3,4,5.5,0,7.7,8.8,9.9 };

	std::cout << "---------Inequality Test------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "BEFORE{2,1,1 ] [ 3,2,1 ] [ 2,1,2 }" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	bool checkNotEqual = matrixA.operator!=(matrixB);//call function and pass other matrix
	std::cout << std::to_string(checkNotEqual) << std::endl;
	std::cout << "AFTER{  [1 = True] }" << std::endl;

	std::cout << "========================================" << std::endl;
}

void testRotateZ()
{
	MyVector3D vectorA(1, 1, 1);//vector to be rotated about the z axis
	MyMatrix3 matrixA = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };//matrix to store rotation matrix

	std::cout << "---------RotateZ Test------------" << std::endl;
	std::cout << vectorA.toString() << std::endl;//vector before rotation
	std::cout << "BEFORE{1 , 1, 1] }" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << (matrixA.rotationZ(3.1415926535) * vectorA).toString() << std::endl;//vector rotated
	std::cout << "AFTER{ [-1, -1, 1 }" << std::endl;

	std::cout << "========================================" << std::endl;
}

void testRotateY()
{
	MyVector3D vectorA(1, 2, 3);//vector to be rotated about the Y axis
	MyMatrix3 matrixA = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };//matrix to store rotation matrix

	std::cout << "---------RotateY Test------------" << std::endl;
	std::cout << vectorA.toString() << std::endl;//vector before rotation
	std::cout << "BEFORE{1 , 1, 1] }" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << (matrixA.rotationY(3.1415926535) * vectorA).toString() << std::endl;//vector rotated
	std::cout << "AFTER{ [-1, 2, -3 }" << std::endl;

	std::cout << "========================================" << std::endl;
}

void testRotateX()
{
	MyVector3D vectorA(2, 2, 2);//vector to be rotated about the Y axis
	MyMatrix3 matrixA = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };//matrix to store rotation matrix

	std::cout << "---------RotateX Test------------" << std::endl;
	std::cout << vectorA.toString() << std::endl;//vector before rotation
	std::cout << "BEFORE{1 , 1, 1] }" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << (matrixA.rotationX(3.1415926535) * vectorA).toString() << std::endl;//vector rotated
	std::cout << "AFTER{ [2, -2, -2 }" << std::endl;

	std::cout << "========================================" << std::endl;
}

void testTranslation()
{
	MyVector3D murtVectorA(3, 1, 1);
	MyVector3D murtVectorB(2, 9, 1);
	MyMatrix3 matrixA{};
	MyMatrix3 matrixB = { matrixA.translation(murtVectorB) };

	std::cout << "---------Translation Test------------" << std::endl;
	std::cout << matrixB.toString() << std::endl;//translation matrix
	std::cout << "BEFORE{1 , 1, 1] }" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << murtVectorA.toString() << std::endl;//vector being moved
	std::cout << murtVectorB.toString() << std::endl;//displacement
	std::cout << (matrixB*murtVectorA).toString() << std::endl;//vector translated
	std::cout << "AFTER{ [5, 10, 1]}" << std::endl;

	std::cout << "========================================" << std::endl;
}

void testScaling()
{
	MyMatrix3 matrixA{ 1, 2, 3, -4, 5, 6, 7.7, 8.8, 9.9 };
	MyMatrix3 matrixB = matrixA.scale(10);//scale matrix
	std::cout << "---------Scaling Test------------" << std::endl;
	std::cout << matrixA.toString() << std::endl;//matrix/object before upscale
	std::cout << "BEFORE{ [1, 2, 3] [-4, 5, 6] [7.7, 8.8, 9.9] }" << std::endl;
	std::cout << "------------------------------------" << std::endl;

	std::cout << matrixA.operator*(matrixB).toString() << std::endl;//matrix scaled up by 10
	std::cout << "AFTER{[10, 20, 30] [-40, 50, 60] [77, 88, 99]}" << std::endl;

	std::cout << "========================================" << std::endl;
}

