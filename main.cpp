#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Line {
    double k;
    double b;
public:
    Line(double x, double z, double gameAngle) {
        double radian = gameAngle >= -90 ? (gameAngle + 90) * M_PI / 180.0 : (gameAngle + 450) * M_PI / 180.0;
        k = std::tan(radian);
        b = z - k * x;
    }
    double getK() const { return k; }
    double getB() const { return b; }
};

int main(int argc, char* argv[]) {
    std::cout << "Enter in the format: x z angle" << std::endl;
    std::cout << "x and z are your game coordinates" << std::endl;
    std::cout << "angle is the direction your eye is flying to, should be between -180 and 180 degrees" << std::endl;
    std::cout << "angle can be found from the first value of \"Facing: xxx (value1/value2)\"" << std::endl;

    double x, z, angle;

    std::cout << "Enter first set of (x z angle): ";
    std::cin >> x >> z >> angle;
    if (!std::cin || angle < -180 || angle > 180) {
        std::cerr << "Invalid input." << std::endl;
        return 1;
    }
    Line line1(x, z, angle);

    std::cout << "Enter second set of (x z angle): ";
    std::cin >> x >> z >> angle;
    if (!std::cin || angle < -180 || angle > 180) {
        std::cerr << "Invalid input." << std::endl;
        return 1;
    }
    Line line2(x, z, angle);

    double intersectX = (line2.getB() - line1.getB()) / (line1.getK() - line2.getK());
    double intersectZ = line1.getK() * intersectX + line1.getB();

    std::cout << "Intersection point: (" << intersectX << ", " << intersectZ << ")" << std::endl;
    return 0;
}