#include <iostream>
#include <vector>

class ISquare {
public:
	typedef double (ISquare::*Method_ptr)() const;
private:
	ISquare *sqptr_;
	Method_ptr square_;
public:
	double square() const { return (sqptr_->*square_)(); }
	ISquare(ISquare *sqptr, Method_ptr method) : sqptr_(sqptr), square_(method) { std::cout << "ISquare ctor\n"; }
};

class Square : public ISquare {
	int x_;
public:
	explicit Square(int x = 0) : ISquare(this, reinterpret_cast<Method_ptr>(&Square::square)), x_(x) { std::cout << "Square ctor\n"; }
	double square() const { return x_*x_; }
};

class Rectangle : public ISquare {
	int x_, y_;
public:
	explicit Rectangle(int x = 0, int y = 0) : ISquare(this, reinterpret_cast<Method_ptr>(&Rectangle::square)), x_(x), y_(y) { std::cout << "Rectangle ctor\n"; }
	double square() const { return x_*y_; }
};

int main() {
	std::vector<ISquare*> mas(3);
	Square a1(1);
	Square a2(2);
	Rectangle a3(3, 4);
	mas[0] = &a1; mas[1] = &a2; mas[2] = &a3;
	for (int i = 0; i < 3; ++i) {
		std::cout << mas[i]->square() << std::endl;
	}
}
