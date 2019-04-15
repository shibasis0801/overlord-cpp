#ifndef PRINTER_HPP 
#define PRINTER_HPP

#include <iostream>
#include <string>

using std::cout;
using std::string;

/**
 *  Exports a print object and a println function.
 */
namespace ovd {
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
}


#endif