//
// Created by Yair on 06-Sep-17.
//

#ifndef CPP_CHAPTER_FRACTIONS_H
#define CPP_CHAPTER_FRACTIONS_H

#include <iostream>
#include <string>

class Fractions {
public:
    Fractions(int numerator, int denominator);
    Fractions();
    Fractions(int num);

    friend Fractions operator*(const Fractions &a, const Fractions &b);
    friend Fractions operator+(const Fractions &a, const Fractions &b);
    friend Fractions operator-(const Fractions &a, const Fractions &b);
    friend Fractions operator/(const Fractions &a, const Fractions &b);
    float getAsFloat() const;
    void print() const;
    std::string to_string() const;
    int get_numerator() const {return (this->m_numerator);}
    int get_denominator() const {return (this->m_denominator);}

private:
    int m_numerator;
    int m_denominator;
};

//Fractions operator*(int num, const Fractions &other);
Fractions operator/(int num, const Fractions &other);
Fractions operator+(int num, const Fractions &other);
Fractions operator-(int num, const Fractions &other);

#endif //CPP_CHAPTER_FRACTIONS_H
