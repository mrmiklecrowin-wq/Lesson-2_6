#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <windows.h>

class Shape {
protected:
	int sidesCount;
public:
	Shape(int sides) : sidesCount(sides) {}
	virtual ~Shape() = default;
	int getSidesCount() const { return sidesCount; }
	virtual const char* getName() const = 0;
};

class Triangle : public Shape {
private:
	double a, b, c;
	double A, B, C;
public:
	Triangle(double a_, double b_, double c_,
			 double A_, double B_, double C_)
	: Shape(3), a(a_), b(b_), c(c_), A(A_), B(B_), C(C_) {
		if (a_ <= 0 || b_ <= 0 || c_ <= 0) {
			std::cerr << "Ошибка создания фигуры. Причина: длина стороны должна быть положительной.\n";
			std::exit(1);
		}
		if (A_ + B_ + C_ != 180.0) {
			std::cerr << "Ошибка создания фигуры. Причина: сумма углов треугольника не равна 180.\n";
			std::exit(1);
		}
	}
	const char* getName() const override { return "Треугольник"; }
	double getA() const { return a; }
	double getB() const { return b; }
	double getC() const { return c; }
	double getAngleA() const { return A; }
	double getAngleB() const { return B; }
	double getAngleC() const { return C; }
};

class Quadrilateral : public Shape {
private:
	double a, b, c, d;
	double A, B, C, D;
public:
	Quadrilateral(double a_, double b_, double c_, double d_,
				  double A_, double B_, double C_, double D_)
	: Shape(4), a(a_), b(b_), c(c_), d(d_),
	A(A_), B(B_), C(C_), D(D_) {
		if (a_ <= 0 || b_ <= 0 || c_ <= 0 || d_ <= 0) {
			std::cerr << "Ошибка создания фигуры. Причина: длина стороны должна быть положительной.\n";
			std::exit(1);
		}
		if (A_ + B_ + C_ + D_ != 360.0) {
			std::cerr << "Ошибка создания фигуры. Причина: сумма углов четырёхугольника не равна 360.\n";
			std::exit(1);
		}
	}
	const char* getName() const override { return "Четырёхугольник"; }
	double getA() const { return a; }
	double getB() const { return b; }
	double getC() const { return c; }
	double getD() const { return d; }
	double getAngleA() const { return A; }
	double getAngleB() const { return B; }
	double getAngleC() const { return C; }
	double getAngleD() const { return D; }
};

class RightTriangle : public Triangle {
public:
	RightTriangle(double a, double b, double c, double A, double B)
	: Triangle(a, b, c, A, B, 90.0) {
		if (A + B != 90.0) {
			std::cerr << "Ошибка создания фигуры. Причина: в прямоугольном треугольнике сумма острых углов должна быть 90.\n";
			std::exit(1);
		}
	}
	const char* getName() const override { return "Прямоугольный треугольник"; }
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(double a, double b, double A, double B)
	: Triangle(a, b, a, A, B, A) {}
	const char* getName() const override { return "Равнобедренный треугольник"; }
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(double side)
	: Triangle(side, side, side, 60.0, 60.0, 60.0) {
		if (side <= 0) {
			std::cerr << "Ошибка создания фигуры. Причина: сторона должна быть положительной.\n";
			std::exit(1);
		}
		if (60.0 + 60.0 + 60.0 != 180.0) {
			std::cerr << "Ошибка создания фигуры. Причина: углы равностороннего треугольника должны давать в сумме 180.\n";
			std::exit(1);
		}
	}
	const char* getName() const override { return "Равносторонний треугольник"; }
};

class Rectanglee : public Quadrilateral {
public:
	Rectanglee(double w, double h)
	: Quadrilateral(w, h, w, h, 90.0, 90.0, 90.0, 90.0) {
		if (w <= 0 || h <= 0) {
			std::cerr << "Ошибка создания фигуры. Причина: ширина и высота должны быть положительными.\n";
			std::exit(1);
		}
	}
	const char* getName() const override { return "Прямоугольник"; }
};

class Square : public Rectanglee {
public:
	Square(double side) : Rectanglee(side, side) {
		if (side <= 0) {
			std::cerr << "Ошибка создания фигуры. Причина: сторона квадрата должна быть положительной.\n";
			std::exit(1);
		}
	}
	const char* getName() const override { return "Квадрат"; }
};

class Parallelogram : public Quadrilateral {
public:
	Parallelogram(double a, double b, double A, double B)
	: Quadrilateral(a, b, a, b, A, B, A, B) {
		if (a <= 0 || b <= 0) {
			std::cerr << "Ошибка создания фигуры. Причина: длины сторон должны быть положительными.\n";
			std::exit(1);
		}
		if (A + B + A + B != 360.0) {
			std::cerr << "Ошибка создания фигуры. Причина: сумма углов параллелограмма должна быть 360.\n";
			std::exit(1);
		}
	}
	const char* getName() const override { return "Параллелограмм"; }
};

class Rhombus : public Parallelogram {
public:
	Rhombus(double side, double A, double B)
	: Parallelogram(side, side, A, B) {
		if (side <= 0) {
			std::cerr << "Ошибка создания фигуры. Причина: сторона ромба должна быть положительной.\n";
			std::exit(1);
		}
	}
	const char* getName() const override { return "Ромб"; }
};

void print_info(const Shape* s) {
	if (!s) return;
	std::cout << s->getName() << ":\n";
	const auto* tri = dynamic_cast<const Triangle*>(s);
	if (tri) {
		std::cout << "Стороны: a=" << tri->getA() << " b=" << tri->getB()
		<< " c=" << tri->getC() << "\n";
		std::cout << "Углы: A=" << tri->getAngleA() << " B=" << tri->getAngleB()
		<< " C=" << tri->getAngleC() << "\n\n";
		return;
	}
	const auto* quad = dynamic_cast<const Quadrilateral*>(s);
	if (quad) {
		std::cout << "Стороны: a=" << quad->getA() << " b=" << quad->getB()
		<< " c=" << quad->getC() << " d=" << quad->getD() << "\n";
		std::cout << "Углы: A=" << quad->getAngleA() << " B=" << quad->getAngleB()
		<< " C=" << quad->getAngleC() << " D=" << quad->getAngleD() << "\n\n";
		return;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	try {
		Triangle t(10, 20, 30, 50, 60, 70);
		std::cout << t.getName() << " (стороны " << t.getA() << ", " << t.getB() << ", "
		<< t.getC() << "; углы " << t.getAngleA() << ", " << t.getAngleB() << ", "
		<< t.getAngleC() << ") создан\n\n";
	} catch (...) {
		std::cerr << "Неизвестная ошибка.\n";
	}
	
	RightTriangle rt(3, 4, 5, 30, 60);
	std::cout << rt.getName() << " (стороны 3, 4, 5; углы 30, 60, 90) создан\n\n";
	
	IsoscelesTriangle it(10, 20, 50, 65);
	std::cout << it.getName() << " создан\n\n";
	
	EquilateralTriangle et(30);
	std::cout << et.getName() << " со стороной 30 создан\n\n";
	
	Quadrilateral q(10, 20, 30, 40, 80, 100, 80, 100);
	std::cout << q.getName() << " создан\n\n";
	
	Rectanglee rectt(10, 20);
	std::cout << rectt.getName() << " (10x20) создан\n\n";
	
	Square sq(20);
	std::cout << sq.getName() << " со стороной 20 создан\n\n";
	
	Parallelogram par(20, 30, 30, 40);
	std::cout << par.getName() << " создан\n\n";
	
	Rhombus rh(30, 30, 40);
	std::cout << rh.getName() << " со стороной 30 создан\n\n";
	
	
	return 0;
}

