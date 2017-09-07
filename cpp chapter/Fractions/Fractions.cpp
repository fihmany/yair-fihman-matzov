//
// Created by Yair on 06-Sep-17.
//

#include "Fractions.h"
#include "DivideByZeroException.h"

Fractions::Fractions(int numerator, int denominator):m_numerator(numerator){
    if (denominator != 0)
    {
        m_denominator = denominator;
    }
    else
    {
        throw (DivideByZeroException());
    }
}

void Fractions::print() const {
    std::cout << this->m_numerator << "/" << this->m_denominator << std::endl;
}

Fractions::Fractions() {
    m_numerator = 1;
    m_denominator = 1;
}

std::string Fractions::to_string() const {
    return (std::to_string(this->m_numerator) + std::string("/") + std::to_string(this->m_denominator));
}

Fractions::Fractions(int num) {
    m_numerator = num;
    m_denominator = 1;
}

Fractions operator*(const Fractions &a, const Fractions &b) {
    return Fractions(a.get_numerator() * b.get_numerator(), a.get_denominator()* b.get_denominator());
}

Fractions operator/(const Fractions &a, const Fractions &b) {
    return (a * Fractions(b.m_denominator, b.m_numerator));
}

Fractions operator+(const Fractions &a, const Fractions &b) {
    if (a.get_denominator() != b.get_denominator())
    {
        return (Fractions((a.get_numerator() * b.get_denominator()) + (b.get_numerator()*a.get_denominator()),
                                                                     b.get_denominator() * a.get_denominator()));
    }
    else
    {
        return (Fractions(a.get_numerator() + b.get_numerator(), a.get_denominator()));
    }
}

Fractions operator-(const Fractions &a, const Fractions &b) {
    if (a.get_denominator() != b.get_denominator())
    {
        return (Fractions((a.get_numerator() * b.get_denominator()) - (b.get_numerator()*a.get_denominator()),
                          b.get_denominator() * a.get_denominator()));
    }
    else
    {
        return (Fractions(a.get_numerator() - b.get_numerator(), a.get_denominator()));
    }
}

float Fractions::getAsFloat() const
{
    return ((float) this->get_numerator() / (float) this->get_denominator());
}
