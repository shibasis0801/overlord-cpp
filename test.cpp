#include "print.hpp"
#include "stream.hpp"
#include "range.hpp"
#include <iostream>

using namespace std;
using namespace ovd;

int main() {
            
    vector<int> x = { 0, 1, 2, 3, 4, 5, 6 };    
    
    stream<int>(x)
        .map([=](int i) -> int { return i * i;})
        .forEach([=](int i) -> void { println(i); });

}