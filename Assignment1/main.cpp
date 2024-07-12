#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Part 1: Creating dynamic array
int* createArray(int size) {
    int* arr = new int[size];
    return arr;
}

// Part 1: Initializing the array with 0
void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

// Part 1: Print the array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

// Part 1: Delete the array
void deleteArray(int* arr) {
    delete[] arr;
}

// Part 2: Point Class
class Point {
public:
    int x, y, z;
    Point(int, int, int);
    int translate(int, char);
    void display();
};

// Class constructor takes 3 integer numbers
Point::Point(int input_x, int input_y, int input_z) {
    this->x = input_x;
    this->y = input_y;
    this->z = input_z;
}

// Class function translate: move point by d distance in 'axis' axis
int Point::translate(int d, char axis) {
    switch (axis) {
        case 'x':
            x += d;
            break;
        case 'y':
            y += d;
            break;
        case 'z':
            z += d;
            break;
        default:
            return -1; // Invalid axis input
    }
    return 0; // Successful translation
}

// Display the coordinates of the point
void Point::display() {
    cout << "Point(" << x << ", " << y << ", " << z << ")\n";
}

// Triangle Class
class Triangle {
public:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;
    Triangle(Point*, Point*, Point*);
    int translate(int d, char axis);
    void display();
    ~Triangle(); // Destructor to clean up
};

// Class constructor takes 3 Point objects
Triangle::Triangle(Point* p1, Point* p2, Point* p3) {
    this->vertex_1 = p1;
    this->vertex_2 = p2;
    this->vertex_3 = p3;
}

// Class function translate: move 3 points by d distance in 'axis' axis
int Triangle::translate(int d, char axis) {
    int res1 = vertex_1->translate(d, axis);
    int res2 = vertex_2->translate(d, axis);
    int res3 = vertex_3->translate(d, axis);

    // Check for errors in translation
    if (res1 == -1 || res2 == -1 || res3 == -1) {
        return -1; // Invalid axis input
    }
    if (res1 == -2 || res2 == -2 || res3 == -2) {
        return -2; // Invalid distance input
    }
    return 0; // Successful translation
}

// Display the coordinates of the triangle vertices
void Triangle::display() {
    cout << "Triangle vertices:\n";
    vertex_1->display();
    vertex_2->display();
    vertex_3->display();
}

// Destructor to clean up dynamically allocated points
Triangle::~Triangle() {
    delete vertex_1;
    delete vertex_2;
    delete vertex_3;
}

int main() {
    // Part 1: Main function for dynamic array
    int* rep;
    int size;
    cout << "Please enter the size of the dynamic array: ";
    cin >> size;
    rep = createArray(size);
    initializeArray(rep, size);
    cout << "Dynamic Array:\n";
    printArray(rep, size);
    deleteArray(rep);

    // Part 2: Main function for Point and Triangle classes
    int x1, y1, z1, x2, y2, z2, x3, y3, z3;
    cout << "Enter coordinates for point 1 (x y z): ";
    cin >> x1 >> y1 >> z1;
    Point* p1 = new Point(x1, y1, z1);

    cout << "Enter coordinates for point 2 (x y z): ";
    cin >> x2 >> y2 >> z2;
    Point* p2 = new Point(x2, y2, z2);

    cout << "Enter coordinates for point 3 (x y z): ";
    cin >> x3 >> y3 >> z3;
    Point* p3 = new Point(x3, y3, z3);

    Triangle* triangle = new Triangle(p1, p2, p3);

    cout << "Triangle created:\n";
    triangle->display();

    int d;
    char axis;
    cout << "Enter translation distance and axis (d axis): ";
    cin >> d >> axis;
    int result = triangle->translate(d, axis);
    if (result == -1) {
        cout << "Invalid axis!\n";
    } else if (result == -2) {
        cout << "Invalid distance!\n";
    } else {
        cout << "Triangle after translation:\n";
        triangle->display();
    }

    // Clean up dynamically allocated memory
    delete triangle;

    return 0;
}
