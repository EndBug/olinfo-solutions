#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    else if (n <= 3) return true;
    else if (n%2 == 0 || n%3 == 0) return false;
    int i = 5;
    while (i*i <= n) {
        if (n%i == 0 || n%(i+2) == 0) return false;
        i += 6;
    }
    return true;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, f[2];
    in >> n;
    if (isPrime(n)) {
        f[0] = -1;
        f[1] = 0;
    } else {
        int first = -1, second = 0;
        for (int i = 1; i < n/2; i++) {
            double dn = static_cast<double>(n);
            if (isPrime(i) && isPrime(n/i) && n % i == 0) {
                first = i;
                second = n/i;
                break;
            }
        }
        f[0] = first;
        f[1] = second;
    }

    out << f[0];
    if (f[1] != 0) out << " " << f[1];

    return 0;
}
