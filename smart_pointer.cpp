#include <iostream>
#include <string>
using namespace std;
#include <memory>

class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b) {
		length = l;
		breadth = b;
	}

	int area() {
		return length * breadth;
	}
};

int main() {
	unique_ptr<Rectangle> p1(new Rectangle(10, 5));
	cout << "p1 area: " << p1->area() << endl;
	unique_ptr<Rectangle> p2;
	p2 = move(p1);
	cout << "p2 area: "  << p2->area() << endl;

	shared_ptr<Rectangle> p3(new Rectangle(10, 5));
	cout << "p3 area: " << p3->area() << endl;

	shared_ptr<Rectangle> p4;
	p4 = p3;
	cout << "p4 area: " << p4->area() << endl;
	cout << "p3 area: "  << p3->area() << endl;
	cout << "p3 use count: " << p3.use_count() << endl;

	return 0;
}