#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "Complex.hpp"

template<typename T>
void compute(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len+1), diffs(len+1);

    // fill and randomize v
    T current = initial;
    std::generate(v.begin(), v.end(), [&current, step]() { T val = current; current += step; return val; });
    std::shuffle(v.begin(), v.end(), std::default_random_engine{});

    // compute differences
    std::adjacent_difference(v.begin(), v.end(), diffs.begin());

    // compute standard deviation of all differences
    const T sum = std::reduce(diffs.begin(), diffs.end());
    const T sumsq = std::accumulate(diffs.begin(), diffs.end(), T{}, [](const T& acc, const T& x) { return acc + x * x; });
    const T mean = sum/len;
    const T variance = sumsq/len - mean*mean;

    std::cout << "Range = [" << initial << ", " << step*len << "]\n"
              << "Mean = " << mean << '\n'
              << "Variance = " << variance << '\n';
}

int main() {
    std::cout << "Double:\n";
    compute(1000, 0.0, 7.0);
    // call compute here with Complex
    std::cout << "\nComplex:\n";
    compute(1000, Complex(0.0f, 0.0f), Complex(7.0f, 7.0f));
}
