#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ", ";
    }
    os << "}";
    return os;
}

// array -> array
// remove the first value of a array

vector<int> sub(vector<int> a){
    if (a.empty()){
        return a;
    } else {
        return vector<int>(a.begin()+1, a.end());
    }
}

// int array -> array
// insert i into the correct location in a according to ascending order
vector<int> myinsert (int i, const vector<int> & a){
    vector<int> res;
    if(a.empty()){
        res.push_back(i);
    } else {
        if(a[0] > i){
            res.push_back(i);
            res.insert(res.end(), a.begin(), a.end());
        } else {
            vector<int> output = myinsert(i, sub(a));
            output.insert(output.begin(), a[0]);
            res = output;
        }
    }
    return res;
}

// array array -> array
// merge the two arrays and produce a sorted array
vector<int> merge(const vector<int> &s1, const vector<int> &s2){
    if(s1.empty()) {
        return s2;
    } else {
        return myinsert(s1[0], merge(sub(s1), s2));
    }
}

//array -> array
//get the front half of a
vector<int> fronthalf(const vector<int> & a){
    size_t half = a.size()/2;
    return vector<int>(a.begin(), a.begin()+half);
}


//array -> array
//get the back half of a
vector<int> backhalf(const vector<int> & a){
    size_t half = a.size()/2;
    return vector<int>(a.begin()+half, a.end());
}

// array -> array
// sort a
vector<int> mergesort(const vector<int> &a){
    if (a.size() <= 1){
        return a;
    }

    return merge(mergesort(fronthalf(a)), mergesort(backhalf(a)));
}

// ==================================================

#ifdef LOCAL_TESTING

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#define tc TEST_CASE
#define check CHECK

tc("stub test"){
    check(true);
}

tc("mergesort"){
    check(mergesort(vector<int> {9, -2,1,18,4}) == vector<int>{-2,1,4,9,18});
    check(mergesort(vector<int> {0,1,3,4}) == vector<int>{0,1,3,4});
    check(mergesort(vector<int> {1}) == vector<int>{1});
    check(mergesort(vector<int> {}) == vector<int>{});
}

tc("sub"){
    check(sub(vector<int> {9, -2,1,18,4}) == vector<int>{ -2,1,18,4});
    check(sub(vector<int> {0,1,3,4}) == vector<int>{1,3,4});
    check(sub(vector<int> {1}) == vector<int>{});
    check(sub(vector<int> {}) == vector<int>{});
}

tc("myinsert"){
    check(myinsert(4, vector<int> {-2, 3, 5, 6}) == vector<int>{-2,3,4,5,6});
    check(myinsert(4, vector<int> {3, 5}) == vector<int>{3,4,5});
    check(myinsert(4, vector<int> {5}) == vector<int>{4,5});
    check(myinsert(4, vector<int> {}) == vector<int>{4});
}

tc("fronthalf"){
    check(fronthalf(vector<int> {-2, 3, 5, 6}) == vector<int>{-2,3});
    check(fronthalf(vector<int> {-2, 3, 5}) == vector<int>{-2});
    check(fronthalf(vector<int> {3, 5}) == vector<int>{3});
    check(fronthalf(vector<int> {5}) == vector<int>{});
    check(fronthalf(vector<int> {}) == vector<int>{});
}

tc("backhalf"){
    check(backhalf(vector<int> {-2, 3, 5, 6}) == vector<int>{5,6});
    check(backhalf(vector<int> {-2, 3, 5}) == vector<int>{3,5});
    check(backhalf(vector<int> {3, 5}) == vector<int>{5});
    check(backhalf(vector<int> {5}) == vector<int>{5});
    check(backhalf(vector<int> {}) == vector<int>{});
}

int main(){
    doctest::Context context;
    int test_result = context.run();
    if(context.shouldExit()) return test_result;
    return 0;
}

#else
// ==================================================

int main() {
    return 0;
}

#endif
