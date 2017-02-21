//
//  main.cpp
//  vector_geom
//
//  Created by Alexey Karpov on 17.02.17.
//  Copyright © 2017 Alexey Karpov. All rights reserved.
//

#include <iostream>
#include "vec_geom.hpp"

using namespace std;
using namespace geom_vector;

int main() {
    int n;
    cin >> n;
    vector a(n);
    vector b(n);
    for (int i = 0; i < n; i++)
    {
        a.set(i, i + 3);
        b.set(i, 6 - i);
    }
    cout << a[0] << endl;
    -a;
    -b;
    -(a + b);
    -(a - b);
    cout << a * b << endl;
    cout << abs(a) << endl;
    -(a ^ b);
    -(a * 3);
    return 0;
}
