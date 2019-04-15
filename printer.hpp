#ifndef PRINTER_HPP 
#define PRINTER_HPP
// Replace this with proper headers
#include <bits/stdc++.h>

typedef unsigned int uint;
typedef unsigned long long ulong_uint;

#define repeat(i, n) for (long_uint i = 0; i < n; ++i)

using namespace std;

struct printer { 
    string separator = " ";
    
    printer() {}
    printer(string separator): separator(separator) 
    {}

    template<class... T>
    void operator()(T... args) {
        ((cout << args << separator), ...);
    }

} print;
template<class... T>
void println(const T&... args) {
    print(args...);
    cout << '\n';
}
#endif