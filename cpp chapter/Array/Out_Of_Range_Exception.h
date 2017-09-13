//
// Created by Yair on 11-Sep-17.
//

#ifndef ARRAY_OUT_OF_RANGE_EXCEPTION_H
#define ARRAY_OUT_OF_RANGE_EXCEPTION_H

#include <exception>
class Out_Of_Range_Exception : public std::exception {
public:
    virtual const char* what() const throw()
    {
        return ("Index out of the array range");
    }
};


#endif //ARRAY_OUT_OF_RANGE_EXCEPTION_H
