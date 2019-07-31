/**
 * This file needs cleaning.
 * But simple and fast implementation. 
 * :D
 */

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

#define all(v) v.begin(), v.end()
#define r_all(v) v.rbegin(), v.rend()

inline decltype(auto) maxref(auto &x, auto &y) {
    return (x > y) ? x : y; 
}

inline decltype(auto) minref(auto &x, auto &y) {
    return (x < y) ? x : y; 
}

struct var_int {
    vector<int> number;

    var_int(){}
    var_int(vector<int> number) : number(number) {};
    var_int(string number_string) {
        transform(r_all(number_string), 
                  back_inserter(number), 
                  [](char c) { 
                      return c - 48; 
                  }
        );
    }


    inline int& operator[](int idx) {
        if(idx < 0 || idx >= number.size())
            throw runtime_error("Out of Bounds\n");
        return number[idx];
    }

    var_int operator+(const var_int &other) {
        int carry = 0;
        int idx = 0;
        vector<int> result;
        do {
            if(idx < size()) 
                carry += number[idx];
            if(idx < other.size())
                carry += other.number[idx];

            result.push_back(carry % 10);
            carry /= 10;
            ++idx;
        } while(carry != 0 || idx < size() || idx < other.size());
        return result;
    }


    inline decltype(auto) begin() { return number.begin(); }
    inline decltype(auto) rbegin() { return number.rbegin(); }
    inline decltype(auto) end() { return number.end(); }
    inline decltype(auto) rend() { return number.rend(); }
    

    inline size_t size() const {  return number.size();   }

    friend bool operator<(const var_int &a, const var_int &b);
    friend bool operator>(const var_int &a, const var_int &b);
    friend var_int operator+(const var_int &vint, long long num);
    friend var_int operator+(long long num, const var_int &vint);
    friend istream& operator>>(istream& is, var_int &obj); 
    friend ostream& operator>>(ostream& is, const var_int &obj); 
};

 bool operator<(const var_int &a, const var_int &b) {
     return a.number < b.number;
 }

 bool operator>(const var_int &a, const var_int &b) {
     return a.number > b.number;
 }

inline
bool valid(char c) {
    return (c > 47 && c < 58);
}

istream& operator>>(istream& is, var_int &obj) {
    //Little Endian.
    string number;
    is >> number;
    bool valid_ints = accumulate(all(number), true, [=](bool  init, char c) {
        return init && valid(c);
    });
    if(valid_ints)
        obj = number;
    else
        throw runtime_error("Invalid Number, must contain digits only\n");
    
    return is;
}

ostream& operator<<(ostream &os, const var_int &obj) {
    for_each(r_all(obj.number), [&](int c) { os << c; });
    return os;
}

int main() {
    var_int n1, n2;
    cin >> n1 >> n2;
    cout << "Sum of arbitary size ints in C++\n";
    cout << n1 + n2 << endl;
}