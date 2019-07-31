#ifndef VECTOR_STREAM_HPP
#define VECTOR_STREAM_HPP

#include "macro.hpp"
#include <vector>
#include <algorithm>

using std::vector;
using std::transform;

namespace ovd {


    template <class T>
    struct stream {
        vector<T> data;
        stream(vector<T> input) : data(input) {}

        stream copy() {
            return stream(data);
        }
        

        /**
         * Learn how to declare function type whose result is unknown.
         */
        template <class Functor>
        stream map(Functor lambda) {
            transform(all(data), data.begin(), lambda);
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
