#include "Fraction.hpp"
using namespace std;
namespace ariel
{
    Fraction::Fraction(int _numerator_, int _denominator_) : numerator(_numerator_), denominator(_denominator_)
    {
        if (_denominator_ == 0)
        {
            throw std ::invalid_argument(" can't divide by zero");
        }

        if (_denominator_ < 0)
        {
            _denominator_ *= -1;
            _numerator_ *= -1;
        }

        reduce();
    }

    Fraction::Fraction(float number) : numerator(number * PRECISION), denominator(PRECISION)
    {
        reduce();
    }

    // operator +
    Fraction Fraction ::operator+(const float &num) const
    {
        Fraction helper(num);
        helper = *this + helper;
        helper.reduce();
        return helper;
    }
    Fraction Fraction ::operator+(const Fraction &other) const
    {
        int _numerator = (numerator * other.denominator) + (other.numerator * denominator);
        int _denominator = (denominator * other.denominator);
        reduce(_numerator, _denominator);
        return Fraction(_numerator, _denominator);
    }
    Fraction& operator+=(Fraction& fraction,const Fraction& other)
    {
        fraction.numerator=(fraction.numerator * other.denominator)+(other.numerator * fraction.denominator);
        fraction.denominator*=other.denominator;
        fraction.reduce();
        return fraction; 
    }
    Fraction operator+(const float &num, const Fraction &other)
    {
        return Fraction(num) + other;
    }
    Fraction &Fraction ::operator++()
    {
        numerator += denominator;
        reduce();
        return *this;
    }
    Fraction Fraction ::operator++(int)
    {
        Fraction helper = *this;
        ++(*this);
        return helper;
    }

    // operator -
    Fraction Fraction ::operator-(const float &num) const
    {
        Fraction helper(num);
        helper = *this - helper;
        helper.reduce();
        return helper;
    }
    Fraction Fraction ::operator-(const Fraction &other) const
    {
        int _numerator = (numerator * other.denominator) - (other.numerator * denominator);
        int _denominator = (denominator * other.denominator);
        reduce(_numerator, _denominator);
        return Fraction(_numerator, _denominator);
    }
    Fraction operator-(const float &num, const Fraction &other)
    {
        Fraction helper(num);
        helper = helper - other;
        // helper.reduce();
        return helper;
    }
    Fraction &Fraction ::operator--()
    {
        numerator -= denominator;
        reduce();
        return *this;
    }
    Fraction Fraction ::operator--(int)
    {
        Fraction helper = *this;
        --(*this);
        return helper;
    }
    Fraction& operator-=(Fraction& fraction,const Fraction& other)
    {
        fraction.numerator=(fraction.numerator * other.denominator)-(other.numerator * fraction.denominator);
        fraction.denominator*=other.denominator;
        fraction.reduce();
        return fraction; 
    }

    // operator *
    Fraction Fraction ::operator*(const float &num) const
    {
        Fraction helper(num);
        helper = *this * helper;
        helper.reduce();
        return helper;
    }
    Fraction Fraction ::operator*(const Fraction &other) const
    {
        int _numerator = (numerator * other.numerator);
        int _denominator = (denominator * other.denominator);
        reduce(_numerator, _denominator);
        return Fraction(_numerator, _denominator);
    }
    Fraction operator*(const float &num, const Fraction &other)
    {
        Fraction helper(num);
        helper = helper * other;
        helper.reduce();
        return helper;
    }
    Fraction& operator*=(Fraction& fraction,const Fraction& other)
    {
        fraction.numerator*=other.numerator;
        fraction.denominator*=other.denominator;
        fraction.reduce();
        return fraction; 
    }

    // operator /
    Fraction Fraction ::operator/(const float &num) const
    {
        if (num == 0)
        {
            throw runtime_error("can't divide by zero");
        }
        Fraction helper(num);
        helper = *this / helper;
        helper.reduce();
        return helper;
    }
    Fraction Fraction ::operator/(const Fraction &other) const
    {
        if (other.numerator == 0)
        {
            throw invalid_argument("can't divide by zero");
        }
        int _numerator = (numerator * other.denominator);
        int _denominator = (denominator * other.numerator);
        reduce(_numerator, _denominator);
        return Fraction(_numerator, _denominator);
    }
    Fraction operator/(const float &num, const Fraction &other)
    {
        if (other.numerator == 0)
        {
            throw invalid_argument("can't divide by zero");
        }
        Fraction helper(num);
        helper = helper / other;
        helper.reduce();
        return helper;
    }
    Fraction& operator/=(Fraction& fraction,const Fraction& other)
    {
        if (other.numerator == 0)
        {
            throw invalid_argument("can't divide by zero");
        }
        fraction.numerator*=other.numerator;
        fraction.denominator*=other.denominator;
        fraction.reduce();
        return fraction; 
    }
    // operator =
    Fraction &Fraction ::operator=(const Fraction &other)
    {
        if (this != &other)
        {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }
    Fraction &Fraction ::operator=(Fraction &&other) noexcept
    {
        if (this != &other)
        {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    // compare ==
    bool Fraction ::operator==(const float &num) const
    {
        Fraction helper(num);
        return *this == helper;
    }
    bool Fraction ::operator==(const Fraction &other) const
    {
        return (this->numerator == other.numerator && this->denominator == other.denominator);
    }
    bool operator==(const float &num, const Fraction &other)
    {
        return Fraction(num) == other;
    }

    // compare !=
    bool Fraction ::operator!=(const float &num) const
    {
        return !(*this == Fraction(num));
    }
    bool Fraction ::operator!=(const Fraction &other) const
    {
        return !(*this == other);
    }
    bool operator!=(const float &num, const Fraction &other)
    {
        return !(Fraction(num) == other);
    }

    // compare >
    bool Fraction ::operator>(const float &num) const
    {
        return *this > Fraction(num);
    }
    bool Fraction ::operator>(const Fraction &other) const
    {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }
    bool operator>(const float &num, const Fraction &other)
    {
        return Fraction(num) > other;
    }

    // compare <
    bool Fraction ::operator<(const float &num) const
    {
        return *this < Fraction(num);
    }
    bool Fraction ::operator<(const Fraction &other) const
    {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }
    bool operator<(const float &num, const Fraction &other)
    {
        return Fraction(num) < other;
    }

    bool Fraction ::operator>=(const float &num) const
    {
        return !(*this < Fraction(num));
    }

    bool Fraction ::operator>=(const Fraction &other) const
    {
        return !(*this < other);
    }
    bool operator>=(const float &num, const Fraction &other)
    {
        return !(Fraction(num) < other);
    }

    bool Fraction ::operator<=(const float &num) const
    {
        return !(*this > Fraction(num));
    }

    bool Fraction ::operator<=(const Fraction &other) const
    {
        return !(*this > other);
    }

    bool operator<=(const float &num, const Fraction &other)
    {
        return !(Fraction(num) > other);
    }

    std::istream &operator>>(std::istream &input, Fraction &fraction)
    {
        int numerator, denominator;
        input >> numerator >> denominator;

        if (!input)
        {
            throw std::runtime_error("invalid input");
        }

        if (denominator == 0)
        {
            throw std::runtime_error("denominator can't be 0");
        }

        if (denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }

        fraction.numerator = numerator;
        fraction.denominator = denominator;

        return input;
    }
}