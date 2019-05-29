#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    int32_t x;
    int32_t y;
}
Point;

bool Point_Equal(const Point a, const Point b);

void Point_Print(const Point a);

Point Point_Add(const Point a, const Point b);

Point Point_Sub(const Point a, const Point b);

Point Point_Div(const Point a, const int32_t n);

Point Point_ToIso(const Point);

Point Point_ToCart(const Point);

bool Point_IsZero(const Point);

int32_t Point_Mag(const Point);
