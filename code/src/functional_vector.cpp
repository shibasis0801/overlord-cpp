
// Where Possible, do manipulations in place.
// sort USING STL, allow functor 
//  In a more elaborate implementation, create gaps in custom sort function where you can put code
//  Like a SorterBuilder object.
//  Example : vector.copy().sort(ascending)
            //   SortBuilder()
            //     .strategy(quicksortBuilder()
            //         .duringSwaps(countSwaps))
            //     .smallstrategy(insertionsortBuilder()
            //         .duringSwitches(counter))
            //     .threshold(10);
// copy (start with this method when you want functional data)
// reduce using STL accumulate
// filter using STL 

// Create something that will be efficient, fills gaps in STL and makes programming easier.
// Use macros and as much as C++ infrastructure as required. 
// End result must be simple, fast and configurable.

#include <vector>
#include <iostream>
#include <functional>
#include <type_traits>
#include <initializer_list>

#include "../include/print.hpp"
#include "../include/macro.hpp"

using namespace std;

template <class T>
struct functional_vector {

    typedef T value_type;

    vector<value_type> data;

    functional_vector() {}

    functional_vector(vector<value_type> data) : data(data) 
    {}

    functional_vector(initializer_list<value_type> input) {
        data = std::move(vector<value_type>(input));
    }

    functional_vector<value_type> copy() {
        return functional_vector<value_type>(data);
    }
        
    template<
        typename unary_function, 
        typename result_type = typename result_of<unary_function&(value_type)>::type
        >
    functional_vector<result_type> 
    map(const unary_function &apply) {
        // Inefficient when T == result_type
        // Will have to do template specialization for that.
        functional_vector<result_type> result;
        
        for ( value_type item : data ) {
            result.data.emplace_back(apply(item));
        }

        return result;
    }


    functional_vector<value_type>
    mapInPlace(const function<value_type(value_type)> &apply) {
        transform(all(data), data.begin(), apply);
        return *this;
    }

    template<
        typename unary_function, 
        typename result_type = typename std::result_of<unary_function&(int, value_type)>::type
        >
    functional_vector<result_type> 
    mapIndexed(const unary_function &apply) {

        functional_vector<result_type> result;
        
        repeat( idx, data.size() ) {
            value_type item = data[idx];
            result.data.emplace_back(apply(idx, item));
        }

        return result;
    }
    
    functional_vector<value_type> filter(const function<bool(value_type)> &test) {
        
        functional_vector<value_type> result;

        for ( value_type item : data )
            if (test(item)) 
                result.push_back(item);

        return result;

    }
    
    void forEach(const function<void(value_type)> &perform) {
        for_each(all(data), perform);
    }
};

int main() {
    
    functional_vector<int> test = { 1, 2, 3, 4, 5 };

    test.map([](int i) {return i;})
        .mapInPlace([](int i) {return i*i;})
        .mapInPlace([](int i) {return i*2;})
        .mapIndexed([=](int idx, int item) -> pair<int, int> { return pair(idx, item); })
        .forEach([=](pair<int, int> p) {
            auto [idx, item] = p;
            ovd::println("Idx :", idx, "has Value :", item);
        });
}

/*
Also create other files
Graph library
Stacks
Queues
Maps
Priority Queues
Trees
Etc

Create this modularly and also create a small build system(learn CMake) 
which will package all of these into one header file.
Use python along with CMake to do that.

If you find yourself too enthusiastic, create connectors to python, nodejs and kotlin.

*/