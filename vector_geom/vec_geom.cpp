//
//  vec_geom.cpp
//  vector_geom
//
//  Created by Alexey Karpov on 17.02.17.
//  Copyright © 2017 Alexey Karpov. All rights reserved.
//

#include "vec_geom.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace geom_vector;

vector::vector (int n)
{
    this->n = n;
    coor = new float [n];
}
vector::vector(const vector &that)
{
    this->n = that.n;
    for (int i = 0; i < this->n; i++)
        this->coor[i] = that.coor[i];
}
vector::~vector()
{
    delete [] coor;
}
void vector::set(int i, float x)
{
    this->coor[i] = x;
}
float vector::operator [] (int i)
{
    return this->coor[i];
}
namespace geom_vector {
    float abs(vector &a)
    {
        float sum = 0;
        for (int  i = 0; i < a.n; i++)
        {
            sum += (a.coor[i] * a.coor[i]);
        }
        sum = sqrt(sum);
        return sum;
    }
}
float vector::operator * (const vector &that)
{
    float res = 0;
    for (int i = 0; i < this->n; i++)
    {
        res += this->coor[i] * that.coor[i];
    }
    return res;
}
vector vector::operator * (float c)
{
    vector res(this->n);
    for (int i = 0; i < this->n; i++)
    {
        res.coor[i] = this->coor[i] * c;
    }
    return res;
}
vector vector::operator + (const vector &that)
{
    vector res(this->n);
    for (int i = 0; i < this->n; i++)
    {
        res.coor[i] = this->coor[i] + that.coor[i];
    }
    return res;

}
vector vector::operator - (const vector &that)
{
    vector res(this->n);
    for (int i = 0; i < this->n; i++)
    {
        res.coor[i] = this->coor[i] - that.coor[i];
    }
    return res;
}
vector vector::operator ^ (const vector &that) //возможно только для трех
{
    if (this->n != 3)
    {
        return 0;
    }else {
        vector res(this->n);
        res.coor[0] = this->coor[1] * that.coor[2] - this->coor[2] * that.coor[1];
        res.coor[1] = this->coor[2] * that.coor[0] - this->coor[0] * that.coor[2];
        res.coor[2] = this->coor[0] * that.coor[1] - this->coor[1] * that.coor[0];
        return res;
    }
}
void vector::operator - ()
{
    for (int i = 0; i < this->n; i++)
    {
        cout << this->coor[i] << " ";
    }
    cout << endl;

}


