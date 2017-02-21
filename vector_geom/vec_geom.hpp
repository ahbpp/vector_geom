//
//  vec_geom.hpp
//  vector_geom
//
//  Created by Alexey Karpov on 17.02.17.
//  Copyright © 2017 Alexey Karpov. All rights reserved.
//

#ifndef vec_geom_hpp
#define vec_geom_hpp

#include <stdio.h>

namespace geom_vector {
    class vector {
    private:
        float *coor;
        int n;
    public:
        vector (int n);
        vector (const vector &that);
        ~vector();
        friend float abs (vector &a);
        void set (int i, float x);
        float operator [] (int i);
        float operator * (const vector &that);
        vector operator * (float c);
        vector operator + (const vector &that);
        vector operator - (const vector &that);
        vector operator ^ (const vector &that);
        void operator - ();
    };
}

#endif /* vec_geom_hpp */
