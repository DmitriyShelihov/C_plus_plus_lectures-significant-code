#include <iostream>
#include <vector>
#include <cmath>

class ISquare {
public:
	virtual double square() const = 0;
};

class Rectangle : public ISquare {
	int x_, y_;
public:
	explicit Rectangle(int x = 0, int y = 0) : x_(x), y_(y) { std::cout << "Rectangle ctor\n"; }
	double square() const override { return x_*y_; }
};

class Circle : public ISquare {
	int r_;
public:
	explicit Circle(int r = 0) : r_(r) { std::cout << "Circle ctor\n"; }
	double square() const override { return r_*r_*M_PI; }
};

int main() {
	Circle c1(1), c2(2), c3(3);
	Rectangle r1(1, 2), r2(2, 3), r3(3, 4);
	std::vector<ISquare*> mas{&c1, &c2, &c3, &r1, &r2, &r3};
	for (int i = 0, i_end = mas.size(); i < i_end; ++i) {
		std::cout << mas[i]->square() << std::endl;
	}
}
