#include<iostream>
#include<iomanip>
#include<math.h>

/* double pi = acos(-1); */
double pi = M_PI;

double area(int radius) {
    return pow(radius,2) *pi;
}
void solve() {
    int R, A, B;
    std::cin >> R >> A >> B;

    double total_area = area(R);
    while(R > 0) {
        R *= A;
        total_area += area(R);
        R /= B;
        total_area += area(R);
    }

    std::cout << std::setprecision(15) << total_area;
}

int main() {

    int T(0);
    std::cin >> T;

    for(size_t t = 1; t <= T; t++) {
        std::cout << "Case #" << t << ": ";
        solve();
        std::cout << std::endl;
    }

    return 0;
}
