#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    // std::vector<double> x, y;
    // for (double i = 0; i < 2 * M_PI; i += 0.1) {
    //     x.push_back(i);
    //     y.push_back(std::sin(i));
    // }

    // plt::plot(x, y);
    // plt::show();

    // return 0;

    plt::plot({1,2,3,4});
    plt::show();
}
