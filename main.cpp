#include <iostream>
#include "generator.h"
#include "recurse.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
   // Generator g(7, 4);
   // g.GenerateAll();

    
    Recurse a(4,3,3);
    vector<int> q;
    a.GenerateAll(q);
    a.Print();
}

