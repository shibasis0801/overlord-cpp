#ifndef STREAM_HPP
#define STREAM_HPP

#include "macro.hpp"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
/*
x = stream(all(vector))
    .map(square)
    .filter(isEven)
    .reduce(summer)

*/
namespace ovd {


    // In-place for now.
    template <class Iterator>
    struct stream {
        
        Iterator start, end;
        stream(Iterator start, Iterator end) : start(start), end(end) {}
        
        template <class Functor>
        stream map(Functor lambda) {
            transform(start, end, start, lambda);
            for (T item : data)
                println(item);
            return *this;
        }
        
        template <class Functor>
        void forEach(Functor lambda) {
            for (T item : data) 
                lambda(item);
        }
    };

}

#endif
