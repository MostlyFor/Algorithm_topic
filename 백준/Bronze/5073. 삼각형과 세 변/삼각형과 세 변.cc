#include <iostream>
#include <vector>
using namespace std;


int main() { 
    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b && b == c & c == 0) return 0;

        int longest = 0;
        longest = max(a, longest);
        longest = max(b, longest);
        longest = max(c, longest);

        if (a + b + c - longest <= longest) cout << "Invalid" << "\n";

        else if (a == b  && a == c) cout << "Equilateral" << '\n';
        else if (a == b || b == c || a == c) cout << "Isosceles" << '\n';
        else cout << "Scalene" << '\n';
    }

    return 0;
}