#include <iostream>
using namespace std;

void print(int a) {
    cout << a << " int" << endl;
}
void print(double b) {
    cout << b << endl;
}

int main() {
    double a = 1.1;
    print(a);
}