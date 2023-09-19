#include "Vector2D.h"

Vector2D::Vector2D() : x(0.0f), y(0.0f) {}

Vector2D::Vector2D(float x, float y)
{
    this -> x = x;
    this -> y = y;
}

Vector2D& Vector2D::Add(const Vector2D& vec)
{
    this -> x += vec.x;
    this -> y += vec.y;

    return *this;
}

Vector2D& Vector2D::Sub(const Vector2D& vec)
{
    this -> x -= vec.x;
    this -> y -= vec.y;

    return *this;
}

Vector2D& Vector2D::Mult(const Vector2D& vec)
{
    this -> x *= vec.x;
    this -> y *= vec.y;

    return *this;
}

Vector2D& Vector2D::Div(const Vector2D& vec)
{
    this -> x /= vec.x;
    this -> y /= vec.y;

    return *this;
}

Vector2D& operator + (Vector2D& vec1, const Vector2D& vec2)
{
    return vec1.Add(vec2);
}

Vector2D& operator - (Vector2D& vec1, const Vector2D& vec2)
{
    return vec1.Sub(vec2);
}

Vector2D& operator * (Vector2D& vec1, const Vector2D& vec2)
{
    return vec1.Mult(vec2);
}

Vector2D& operator / (Vector2D& vec1, const Vector2D& vec2)
{
    return vec1.Div(vec2);
}

Vector2D& Vector2D::operator += (const Vector2D& vec)
{
    return this -> Add(vec);
}

Vector2D& Vector2D::operator -= (const Vector2D& vec)
{
    return this -> Sub(vec);
}

Vector2D& Vector2D::operator *= (const Vector2D& vec)
{
    return this -> Mult(vec);
}

Vector2D& Vector2D::operator /= (const Vector2D& vec)
{
    return this -> Div(vec);
}

std::ostream& operator <<(std::ostream& out, const Vector2D& vec)
{
    out <<"("<< vec.x << ")"<< vec.y <<"("<<")";
    return out;
}

Vector2D& Vector2D::operator*(const int &i)
{
    this -> x *= i;
    this -> y *= i;

    return *this;

}

Vector2D &Vector2D::Zero()
{
    this -> x = 0;
    this -> y = 0;

    return  *this;
}
