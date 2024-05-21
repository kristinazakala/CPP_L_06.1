#include "file.h"
using namespace std;

Point::Point(double x, double y, string color)
    : x(x), y(y), color(color) {}

// переміщення точки
void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}

// зміна кольору точки
void Point::changeColor(const string& newColor) {
    color = newColor;
}

// виведення інформації про точку
void Point::display() const {
    cout << "Point(" << x << ", " << y << "), Color: " << color << endl;
}


Vector::Vector(double x, double y, double length, double angle, string color)
    : Point(x, y, color), length(length), angle(angle) {}

// зміна розміру вектора
void Vector::resize(double factor) {
    length *= factor;
}

// обертання вектора на заданий кут
void Vector::rotate(double deltaAngle) {
    angle += deltaAngle;
    if (angle >= 360.0) angle -= 360.0;
    if (angle < 0.0) angle += 360.0;
}

// виведення інформації про вектор
void Vector::display() const {
    cout << "Vector(" << x << ", " << y << "), Length: " << length
        << ", Angle: " << angle << " degrees, Color: " << color << endl;
}



void displayMenu() {
    cout << "1. Створити точку\n";
    cout << "2. Створити вектор\n";
    cout << "3. Перемістити\n";
    cout << "4. Змінити колір\n";
    cout << "5. Змінити розмір вектора\n";
    cout << "6. Повернути вектор\n";
    cout << "7. Відобразити\n";
    cout << "8. Вийти\n";
    cout << "Виберіть номер: ";
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    Point* shape = nullptr;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            double x, y;
            string color;
            cout << "Введіть x, y, колір: ";
            cin >> x >> y >> color;
            delete shape;
            shape = new Point(x, y, color);
        }
        else if (choice == 2) {
            double x, y, length, angle;
            string color;
            cout << "Введіть x, y, довжину, кут, колір: ";
            cin >> x >> y >> length >> angle >> color;
            delete shape;
            shape = new Vector(x, y, length, angle, color);
        }
        else if (choice == 3) {
            double dx, dy;
            cout << "Введіть зміщення dx, dy: ";
            cin >> dx >> dy;
            if (shape) {
                shape->move(dx, dy);
            }
            else {
                cout << "Спочатку створіть точку або вектор.\n";
            }
        }
        else if (choice == 4) {
            string newColor;
            cout << "Введіть новий колір: ";
            cin >> newColor;
            if (shape) {
                shape->changeColor(newColor);
            }
            else {
                cout << "Спочатку створіть точку або вектор.\n";
            }
        }
        else if (choice == 5) {
            double factor;
            cout << "Введіть коефіцієнт зміни розміру: ";
            cin >> factor;
            Vector* vec = dynamic_cast<Vector*>(shape);
            if (vec) {
                vec->resize(factor);
            }
            else {
                cout << "Для зміни розміру спочатку створіть вектор.\n";
            }
        }
        else if (choice == 6) {
            double deltaAngle;
            cout << "Введіть кут повороту: ";
            cin >> deltaAngle;
            Vector* vec = dynamic_cast<Vector*>(shape);
            if (vec) {
                vec->rotate(deltaAngle);
            }
            else {
                cout << "Для повороту спочатку створіть вектор.\n";
            }
        }
        else if (choice == 7) {
            if (shape) {
                shape->display();
            }
            else {
                cout << "Спочатку створіть точку або вектор.\n";
            }
        }
        else if (choice == 8) {
            delete shape;
            break;
        }
        else {
            cout << "Error. Спробуйте ще раз.\n";
        }
    }

    return 0;
}
