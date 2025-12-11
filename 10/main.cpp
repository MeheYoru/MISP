#include <bits/stdc++.h>
using namespace std;

vector<double> solveQuadratic(double a, double b, double c) {
    vector<double> roots;
    if (a == 0) {
        if (b != 0) roots.push_back(-c / b);
        return roots;
    }
    double D = b*b - 4*a*c;
    if (D < 0) return roots;
    if (D == 0) {
        roots.push_back(-b / (2*a));
    } else {
        double sqrtD = sqrt(D);
        roots.push_back((-b + sqrtD) / (2*a));
        roots.push_back((-b - sqrtD) / (2*a));
    }
    return roots;
}

int sumNumericArgs(int argc, char* argv[]) {
    int sum = 0;
    for (int i = 1; i < argc; ++i) {
        try {
            sum += stoi(argv[i]);
        } catch (...) {}
    }
    return sum;
}

int main(int argc, char* argv[]) {
    double a, b, c;
    cin >> a >> b >> c;

    vector<double> roots = solveQuadratic(a, b, c);
    if (roots.empty()) {
        cout << "No roots\n";
    } else if (roots.size() == 1) {
        cout << "One root: " << roots[0] << "\n";
    } else {
        cout << "Two roots: " << roots[0] << " and " << roots[1] << "\n";
    }

    int sum = sumNumericArgs(argc, argv);
    if (sum != 0) cout << "Sum of numeric command line arguments: " << sum << "\n";
    else cout << "No numeric command line arguments\n";
}
