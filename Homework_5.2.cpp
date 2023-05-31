#include <iostream>
#include <locale.h>
#include <string>

class Figure {
protected:
    int sides_count;
    std::string name;
public:
    Figure() {
        sides_count = 0;
        name = "Фигура";
    }
    int get_sides_count() { return sides_count; }
    std::string get_name() { return name; }
};

//*****************************************ТРЕУГОЛЬНИКИ******************************************************

class Triangle : public Figure {
protected:
    int a, b, c, A, B, C;
public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B; this->C = C;
        name = "Треугольник";
        sides_count = 3;
    }
    Triangle() {
        name = "Треугольник";
        sides_count = 3;
        a = 10, b = 20, c = 30, A = 50, B = 60, C = 70;
    }
    int get_side_a() { return a; }
    int get_side_b() { return b; }
    int get_side_c() { return c; }
    int get_angle_A() { return A; }
    int get_angle_B() { return B; }
    int get_angle_C() { return C; }
};

class Right_Triangle : public Triangle {
public:
    Right_Triangle() {
        name = "Прямоугольный треугольник";
        C = 90;
    }
};

class Isosceles_Triangle : public Triangle {
public:
    Isosceles_Triangle() {
        name = "Равнобедренный треугольник";
        c = a;
        C = A;
    }
};

class Equilateral_Triangle : public Triangle {
public:
    Equilateral_Triangle() {
        name = "Равносторонний треугольник";
        a = c; b = c;
        A = B; C = B;
    }
};

//*****************************************ЧЕТЫРЕХУГОЛЬНИКИ**************************************************

class Quadrangle : public Figure {
protected:
    int a, b, c, d, A, B, C, D;
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->a = a; this->b = b; this->c = c; this->d = d;
        this->A = A; this->B = B; this->C = C; this->D = D;
        name = "Четырёхугольник";
        sides_count = 4;
    }
    Quadrangle() {
        name = "Четырёхугольник";
        sides_count = 4;
        a = 10, b = 20, c = 30, d = 40, A = 50, B = 60, C = 70, D = 80;
    }
    int get_side_a() { return a; }
    int get_side_b() { return b; }
    int get_side_c() { return c; }
    int get_side_d() { return d; }
    int get_angle_A() { return A; }
    int get_angle_B() { return B; }
    int get_angle_C() { return C; }
    int get_angle_D() { return D; }
};

class Rectangle : public Quadrangle {
public:
    Rectangle() {
        name = "Прямоугольник";
        c = a; d = b;
        A = 90; B = 90; C = 90; D = 90;
    }
};

class Square : public Rectangle {
public:
    Square() {
        name = "Квадрат";
        c = b; a = b;
    }
};

class Parallelogram : public Rectangle {
public:
    Parallelogram() {
        name = "Параллелограмм";
        A = 30; C = A;
        B = 40; D = B;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus() {
        name = "Ромб";
        a = 30; b = a; c = a; d = a;
    }
};

//************************************************ПРИНТ******************************************************

void print_info_angle_3(Triangle x) {
    std::cout << x.get_name() << ":" << std::endl;
    std::cout << "Стороны: a=" << x.get_side_a() << " b=" << x.get_side_b() <<
        " c=" << x.get_side_c() << std::endl;
    std::cout << "Углы: A=" << x.get_angle_A() << " B=" << x.get_angle_B() <<
        " C=" << x.get_angle_C() << std::endl << std::endl;
}

void print_info_angle_4(Quadrangle y) {
    std::cout << y.get_name() << ":" << std::endl;
    std::cout << "Стороны: a=" << y.get_side_a() << " b=" << y.get_side_b() <<
        " c=" << y.get_side_c() << " d=" << y.get_side_d() << std::endl;
    std::cout << "Углы: A=" << y.get_angle_A() << " B=" << y.get_angle_B() <<
        " C=" << y.get_angle_C() << " D=" << y.get_angle_D() << std::endl << std::endl;
}

//************************************************МЕЙН*******************************************************

int main() {
    setlocale(LC_ALL, "Russian");

    Triangle triangle;
    Right_Triangle right_triangle;
    Isosceles_Triangle isosceles_triangle;
    Equilateral_Triangle equilateral_triangle;

    Quadrangle quadrangle;
    Rectangle rectangle;
    Square square;
    Parallelogram parallelogram;
    Rhombus rhombus;

    print_info_angle_3(triangle);
    print_info_angle_3(right_triangle);
    print_info_angle_3(isosceles_triangle);
    print_info_angle_3(equilateral_triangle);

    print_info_angle_4(quadrangle);
    print_info_angle_4(rectangle);
    print_info_angle_4(square);
    print_info_angle_4(parallelogram);
    print_info_angle_4(rhombus);
    
    return 0;
}