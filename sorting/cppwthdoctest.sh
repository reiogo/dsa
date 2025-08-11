#! /usr/bin/env bash

# Create new file with name
if [ $# -eq 1 ]
then
    filename="$1"
else 
    filename="$(date +%Y%m%d)_"
fi

touch $filename.cc

cat <<EOF >>$filename.cc
#include <iostream>
using namespace std;

void solve(){
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

int main(){
    doctest::Context context;
    int test_result = context.run();
    if(context.shouldExit()) return test_result;
    return 0;
}

#else
// ==================================================

int main() {
    solve();
    return 0;
}

#endif
EOF


