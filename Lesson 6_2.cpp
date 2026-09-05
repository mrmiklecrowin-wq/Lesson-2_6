#include <iostream>
#include <string>
#include <windows.h>

class ShapeError {
private:
	std::string message;
public:
	ShapeError(const char* msg) : message(msg) {}
	const char* what() const {
		return message.c_str();
	}
};

class Shape {
protected:
	int sidesCount;
public:
	Shape(int sides) : sidesCount(sides) {
		if (sides <= 0) {
			throw ShapeError("количество сторон должно быть положительным");
		}
	}
	int getSidesCount() const { return sidesCount; }
};

class Triangle {
private:
	double a, b, c;
	double A, B, C;
public:
	Triangle(double a_, double b_, double c_,
			 double A_, double B_, double C_)
	: a(a_), b(b_), c(c_), A(A_), B(B_), C(C_) {
		if (a_ <= 0 || b_ <= 0 || c_ <= 0) {
			throw ShapeError("длина стороны должна быть положительной");
		}
		if (A_ + B_ + C_ != 180.0) {
			throw ShapeError("сумма углов треугольника не равна 180");
		}
	}
	
	const char* getName() const { return "Треугольник"; }
	void printDetails() const {
		std::cout << getName() << ":\n";
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
	}
	double getA() const { return a; }
	double getB() const { return b; }
	double getC() const { return c; }
	double getAngleA() const { return A; }
	double getAngleB() const { return B; }
	double getAngleC() const { return C; }
};

class Quadrilateral {
private:
	double a, b, c, d;
	double A, B, C, D;
public:
	Quadrilateral(double a_, double b_, double c_, double d_,
				  double A_, double B_, double C_, double D_)
	: a(a_), b(b_), c(c_), d(d_),
	A(A_), B(B_), C(C_), D(D_) {
		if (a_ <= 0 || b_ <= 0 || c_ <= 0 || d_ <= 0) {
			throw ShapeError("длина стороны должна быть положительной");
		}
		if (A_ + B_ + C_ + D_ != 360.0) {
			throw ShapeError("сумма углов четырёхугольника не равна 360");
		}
	}
	
	const char* getName() const { return "Четырёхугольник"; }
	void printDetails() const {
		std::cout << getName() << ":\n";
		std::cout << "Стороны: a=" << a << " b=" << b
		<< " c=" << c << " d=" << d << "\n";
		std::cout << "Углы: A=" << A << " B=" << B
		<< " C=" << C << " D=" << D << "\n\n";
	}
	double getA() const { return a; }
	double getB() const { return b; }
	double getC() const { return c; }
	double getD() const { return d; }
	double getAngleA() const { return A; }
	double getAngleB() const { return B; }
	double getAngleC() const { return C; }
	double getAngleD() const { return D; }
};

class RightTriangle {
private:
	Triangle base;
public:
	RightTriangle(double a, double b, double c, double A, double B)
	: base(a, b, c, A, B, 90.0) {
		if (A + B != 90.0) {
			throw ShapeError("в прямоугольном треугольнике сумма острых углов должна быть 90");
		}
	}
	const char* getName() const { return "Прямоугольный треугольник"; }
	void printDetails() const { base.printDetails(); }
};

class IsoscelesTriangle {
private:
	Triangle base;
public:
	IsoscelesTriangle(double a, double b, double A, double B)
	: base(a, b, a, A, B, A) {}
	const char* getName() const { return "Равнобедренный треугольник"; }
	void printDetails() const { base.printDetails(); }
};

class EquilateralTriangle {
private:
	Triangle base;
public:
	EquilateralTriangle(double side)
	: base(side, side, side, 60.0, 60.0, 60.0) {
		if (side <= 0) {
			throw ShapeError("сторона должна быть положительной");
		}
	}
	const char* getName() const { return "Равносторонний треугольник"; }
	void printDetails() const { base.printDetails(); }
};

class Rectanglee {
private:
	Quadrilateral base;
public:
	Rectanglee(double w, double h)
	: base(w, h, w, h, 90.0, 90.0, 90.0, 90.0) {
		if (w <= 0 || h <= 0) {
			throw ShapeError("ширина и высота должны быть положительными");
		}
	}
	const char* getName() const { return "Прямоугольник"; }
	void printDetails() const { base.printDetails(); }
};

class Square {
private:
	Rectanglee base;
public:
	Square(double side) : base(side, side) {
		if (side <= 0) {
			throw ShapeError("сторона квадрата должна быть положительной");
		}
	}
	const char* getName() const { return "Квадрат"; }
	void printDetails() const { base.printDetails(); }
};

class Parallelogram {
private:
	Quadrilateral base;
public:
	Parallelogram(double a, double b, double A, double B)
	: base(a, b, a, b, A, B, A, B) {
		if (a <= 0 || b <= 0) {
			throw ShapeError("длины сторон должны быть положительными");
		}
		if (A + B + A + B != 360.0) {
			throw ShapeError("сумма углов параллелограмма должна быть 360");
		}
	}
	const char* getName() const { return "Параллелограмм"; }
	void printDetails() const { base.printDetails(); }
};

class Rhombus {
private:
	Parallelogram base;
public:
	Rhombus(double side, double A, double B)
	: base(side, side, A, B) {
		if (side <= 0) {
			throw ShapeError("сторона ромба должна быть положительной");
		}
	}
	const char* getName() const { return "Ромб"; }
	void printDetails() const { base.printDetails(); }
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	try {
		Triangle t(10, 20, 30, 50, 60, 70);
		t.printDetails();
		
		RightTriangle rt(3, 4, 5, 30, 60);
		rt.printDetails();
		
		IsoscelesTriangle it(10, 20, 50, 65);
		it.printDetails();
		
		EquilateralTriangle et(30);
		et.printDetails();
		
		Quadrilateral q(10, 20, 30, 40, 80, 100, 80, 100);
		q.printDetails();
		
		Rectanglee rectt(10, 20);
		rectt.printDetails();
		
		Square sq(20);
		sq.printDetails();
		
		Parallelogram par(20, 30, 30, 40);
		par.printDetails();
		
		Rhombus rh(30, 30, 40);
		rh.printDetails();
	} catch (const ShapeError& e) {
		std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << "\n";
	} catch (...) {
		std::cerr << "Неизвестная ошибка.\n";
	}
	
	return 0;
}
