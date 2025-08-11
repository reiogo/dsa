#include <iostream>
#include <vector>
using namespace std;



// array -> array
// go through the array once, swapping those that are not in the correct order

// given {0,3,1,2} expect {0,1,2,3}
// given {5,3,1,2} expect {3,1,2,5}
// given {1} expect {1}
// given {} expect {}
//
vector<int> swaps(const vector<int>& a){
    int n = (int)a.size();
    vector<int> res (a.begin(), a.end());
    for (int i = 0; i < n -1; i++){
        if(res[i] > res[i+1]){
            swap(res[i], res[i+1]);
        }
    }
    return res;
}

// array -> array
// sort an array

// given {0,1,3,2} expect {0,1,2,3}
// given {1} expect {1}
// given {} expect {}

vector<int> bubblesort(const vector<int>& a, int n){
    if ( n == 0){
        return a;
    } else {
        return bubblesort(swaps(a), n - 1);
    }
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

tc("bubblesort") {
    check(bubblesort(vector<int> {9, -2,1,18,4}, 5) == vector<int>{-2,1,4,9,18});
    check(bubblesort(vector<int> {0,1,3,4}, 4) == vector<int>{0,1,3,4});
    check(bubblesort(vector<int> {1}, 1) == vector<int>{1});
    check(bubblesort(vector<int> {}, 0) == vector<int>{});
}

tc("swaps"){
    check(swaps(vector<int> {0,1,3,4}) == vector<int>{0,1,3,4});
    check(swaps(vector<int> {5,3,1,2}) == vector<int>{3,1,2,5});
    check(swaps(vector<int> {1}) == vector<int>{1});
    check(swaps(vector<int> {}) == vector<int>{});
}

tc("merge"){
    check(merge(
            vector<int> {0,1,3,4},
            vector<int> {0,1,2,3}) == vector<int>{0,0,1,1,2,3,3,4});
    /* check(merge( */
    /*         vector<int> {1,2,3,5}, */
    /*         vector<int> {2,5,6,7} */
    /*         ) == vector<int>{1,2,2,3,5,5,6,7}); */
    /* check(merge( */
    /*         vector<int> {1}, */
    /*         vector<int> {3}) == vector<int>{1,3}); */
    /* check(merge( */
    /*         vector<int> {}, */
    /*         vector<int> {}) == vector<int>{}); */
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
