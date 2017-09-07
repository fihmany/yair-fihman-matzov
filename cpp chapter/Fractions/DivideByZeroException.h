//
// Created by Yair on 07-Sep-17.
//

#ifndef CPP_CHAPTER_DivideByZeroException_H
#define CPP_CHAPTER_DivideByZeroException_H

#include <exception>
class DivideByZeroException: public std::exception{
public:
    const char * what () const throw () {
        return "Divide By Zero";
    }
};

#endif //CPP_CHAPTER_DivideByZeroException_H
