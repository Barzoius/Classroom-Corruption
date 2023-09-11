#pragma once

#include <iostream>

class Vector2D
{
public:
    float x, y;

    Vector2D();
    Vector2D(float x, float y);

    Vector2D& Add(const Vector2D& vec);
    Vector2D& Sub(const Vector2D& vec);
    Vector2D& Mult(const Vector2D& vec);
    Vector2D& Div(const Vector2D& vec);

    friend Vector2D& operator + (Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D& operator - (Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D& operator * (Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D& operator / (Vector2D& vec1, const Vector2D& vec2);

    Vector2D& operator += (const Vector2D& vec);
    Vector2D& operator -= (const Vector2D& vec);
    Vector2D& operator *= (const Vector2D& vec);
    Vector2D& operator /= (const Vector2D& vec);

    Vector2D& operator *(const int& i /*scale*/);
    Vector2D& Zero();

    friend std::ostream& operator <<(std::ostream& out, const Vector2D& vec);

};
