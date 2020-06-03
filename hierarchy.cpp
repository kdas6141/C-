#include <iostream>
#include <vector>

using namespace std;

struct Point{
	int x;
	int y;
 	Point(int ix, int iy) : x(ix), y(iy) {}
};

class Shape {
public:
	virtual Point center() const = 0;	//pure virtual
	virtual void move(Point to) = 0;
	virtual void draw() const = 0;
	virtual void rotate(int angle) = 0;
	virtual ~Shape() {}	
};

void rotate_all(vector<Shape>& v, int angle){
	for (auto p: v)
		p->rotate(angle);
}

class Circle: Public Shape {
public:
	Circle(Point p, int rad);	//constructor
	Point center() const override {
		return x;
	}
	void move(Point to) override {
		x = to;
	}

	void draw() const override;
	void rotate(int) override{}
private:
	Point x;	//center
	int r;		//radius 
}

class Smiley: public Circle {
public: 
	Smiley(Point p, int rad) : Circle{p, rad}, mouth{nullptr}{}
	~Smiley() {
		delete mouth;
		for (auto p: eyes)
			delete p;
	}

	void move(Point to) override;

	void draw() const override;

	void rotate(int) override;

	void add_eye(Shape *s) {
		eyes.push_back(s);
	} 

	virtual set_mouth(Shape *s);
	virtual void wink(int i);

private:
	vector<Shape*> eyes;
	Shape *mouth;
}

void Smiley::draw() const {
	Circle::draw();
	for (auto p: eyes)
		p->draw();
	mouth->draw();
}