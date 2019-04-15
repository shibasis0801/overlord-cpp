#include <bits/stdc++.h>

using namespace std;

template <class T>
struct functional_vector {
    
    // Create something that will be efficient, fills gaps in STL and makes programming easier.
    // Use macros and as much as C++ infrastructure as required. 
    // End result must be simple, fast and configurable.
        
    // This will not work
    template <class R>
    functional_vector<R> map(const function<T(R)> &apply) {
        functional_vector<R> result;
        // Use STL Transform here.
        return result;
    }

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


};

int main() {
    functional_vector<int> test;
    test.map([=](int i) -> double { return 1.0 * i; });
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