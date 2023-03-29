#include <iostream>
#include <cmath>
using namespace std;

double nthRoot(double x, int n) {
    double left = 0, right = x;
    double mid = (left + right) / 2;
    while(abs(pow(mid, n) - x) > 1e-7) {
        if(pow(mid, n) < x){
            left = mid;
        }
        else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    return mid;
}

int main() {
    double x = 125;
    int n = 3;
    double root = nthRoot(x, n);
    cout << "The " << n << "th root of " << x << " is " << root << endl;
    return 0;
}
