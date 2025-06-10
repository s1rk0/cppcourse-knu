#include "OrderedVector.hpp"
#include "Complex.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <ranges>

struct ReverseStringLess {
    bool operator() (const std::string &s, const std::string &t) const {
        // TODO: compare reversed strings
        // hint: you can use:
        // - std::views::reverse
        // - std::ranges::lexicographical_compare
        // or, if your compiler does not support those yet,
        // take copies of the strings and reverse them using std::reverse
        return std::ranges::lexicographical_compare(
            std::views::reverse(s), std::views::reverse(t));
    }
};

struct ManhattanLess {
    bool operator()(const Complex &a, const Complex &b) const {
        return (std::abs(a.real()) + std::abs(a.imaginary())) <
               (std::abs(b.real()) + std::abs(b.imaginary()));
    }
};

int main() {
    std::cout << "Integer\n";
    OrderedVector<int> v(10);
    for (int i = 10; i > 0; i--)
        v.add(i);
    for (int i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    std::cout << "\n\n";

    std::cout << "String\n";
    OrderedVector<std::string> vs(5);
    vs.add(std::string("one"));
    vs.add(std::string("two"));
    vs.add(std::string("three"));
    vs.add(std::string("four"));
    vs.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vs[i] << " ";
    std::cout << "\n\n";

    // TODO: Demonstrate OrderedVector with Complex as element type similar to above
    std::cout << "Complex\n";
    OrderedVector<Complex> vc(5);
    vc.add(Complex(1.0f, 1.0f)); // |z| = sqrt(2) ≈ 1.414
    vc.add(Complex(2.0f, 2.0f)); // |z| = sqrt(8) ≈ 2.828
    vc.add(Complex(0.0f, 1.0f)); // |z| = 1
    vc.add(Complex(3.0f, 0.0f)); // |z| = 3
    vc.add(Complex(1.0f, 0.0f)); // |z| = 1
    for (int i = 0; i < 5; i++)
        std::cout << vc[i] << " ";
    std::cout << "\n\n";


    // TODO: Extend OrderedVector to allow to customize the ordering via an additional template paramter.
    //       Then, demonstrate the new functionality by ordering an OrderedVector<std::string>,
    //       where the strings are compared starting at their last letters.
    // String vector with reverse ordering
    std::cout << "String (Reverse Order)\n";
    OrderedVector<std::string, ReverseStringLess> vs_reverse(5);
    vs_reverse.add(std::string("one"));   // eno
    vs_reverse.add(std::string("two"));   // owt
    vs_reverse.add(std::string("three")); // eerht
    vs_reverse.add(std::string("four"));  // ruof
    vs_reverse.add(std::string("five"));  // evif
    for (int i = 0; i < 5; i++)
        std::cout << vs_reverse[i] << " ";
    std::cout << "\n\n";

    // TODO: Order an OrderedVector of Complex based on the Manhattan distance
    // Complex vector with Manhattan distance
    std::cout << "Complex (Manhattan Distance)\n";
    OrderedVector<Complex, ManhattanLess> vc_manhattan(5);
    vc_manhattan.add(Complex(1.0f, 1.0f)); // |r| + |i| = 2
    vc_manhattan.add(Complex(2.0f, 2.0f)); // |r| + |i| = 4
    vc_manhattan.add(Complex(0.0f, 1.0f)); // |r| + |i| = 1
    vc_manhattan.add(Complex(3.0f, 0.0f)); // |r| + |i| = 3
    vc_manhattan.add(Complex(1.0f, 0.0f)); // |r| + |i| = 1
    for (int i = 0; i < 5; i++)
        std::cout << vc_manhattan[i] << " ";
    std::cout << "\n\n";

    return 0;
}
