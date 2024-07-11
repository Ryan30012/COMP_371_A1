#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//Part 1: Creating dynamic array
int* createArray(int size) {
	int* arr;
	arr = new int[size] ;
	return arr;
}

//Part 1: initializing the array with 0
void initializeArray(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

//Part 1: Print the array
void printArray(int* arr, int size){
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

//Part 1: Delete the array
void deleteArray(int* arr) {
	free(arr);
}

//Part 2: Point Class
class Point
{
public:
	int x,y,z;
	Point(int, int, int);
	void translate(int, char);
};

//Class constructor takes 3 integer numbers
Point::Point(int input_x, int input_y, int input_z)
{
	this->x = input_x;
	this->y = input_y;
	this->z = input_z;
}

//Class function translate: move point by d distance in 'axis' axe
void Point::translate(int d, char axis) {
	//if distance is invalid input
	
	//if axis is invalid input
	
	//if inputs are correct
	switch (axis)
	{
		case 'x':
			x = x + d;
		case 'y':
			y = y + d;
		case 'z':
			z = z + d;
		default:
			break;
	}
}
//Triangle Class
class Triangle
{
public:
	Point* vertex_x;
	Point* vertex_y;
	Point* vertex_z;
	Triangle(Point*, Point*, Point*);
	void translate(int d, char axis);
};

//Class constructor takes 3 Point objects
Triangle::Triangle(Point* p1, Point* p2, Point* p3)
{
	this->vertex_x = p1;
	this->vertex_y = p2;
	this->vertex_z = p3;
}


//Class function translate: move 3 points by d distance in 'axis' axe
void Triangle::translate(int d, char axis) {
	vertex_x->translate(d, axis);
	vertex_y->translate(d, axis);
	vertex_z->translate(d, axis);
}


int main() {

	//Part 1: main function
	int* rep;
	int size;
	cout << "Please enter the size of the dynamic array:";
	cin >> size;
	rep = createArray(size);
	initializeArray(rep, size);
	cout << "Dynamic Array:" << endl;
	printArray(rep, size);
	deleteArray(rep);


	//Part 2: 
	
	

	return 0;
}