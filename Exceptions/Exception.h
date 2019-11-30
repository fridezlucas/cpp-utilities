/*
 * @author Lucas Fridez <fridez.lucas@gmail.com>
 * @version 1.0
 * @date 13.05.2019.
 */

#ifndef CPP_UTILITIES_EXCEPTION_H
#define CPP_UTILITIES_EXCEPTION_H

#include <iostream>
#include <exception>

/**
 *  virtual Exception class
 *  @author Lucas Fridez <fridez.lucas@gmail.com>
 *  @version 1.0
 */
class Exception : virtual public std::exception {
protected:
    int number;
    std::string message;
    std::string* completeMessage;

public:
    /**
     * Exception Constructor
     *
     * @param number  - error number
     * @param message - error message
     *
     * @author Lucas Fridez <fridez.lucas@gmail.com>
     * @version 1.0
     */
    Exception(int number, std::string message) {
        this->number = number;
        this->message = message;
        completeMessage = new std::string("Exception #" + std::to_string(number) + " : " + message);
    };

    /**
     * Exception Destructor
     *
     * @author Lucas Fridez <fridez.lucas@gmail.com>
     * @version 1.0
     */
    ~Exception() noexcept override {
        delete completeMessage;
    };

    /**
     * @author Lucas Fridez <fridez.lucas@gmail.com>
     * @version 1.0
     * @return complete Exception message
     */
    const char *what() const noexcept override {
        return completeMessage->c_str();
    };

    /**
     * @author Lucas Fridez <fridez.lucas@gmail.com>
     * @version 1.0
     * @return Exception number
     */
    virtual int getErrorNumber() const {
        return number;
    };
};


#endif //CPP_UTILITIES_EXCEPTION_H
