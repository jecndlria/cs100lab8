#ifndef __OP_HPP__
#define __OP_HPP__
#include "base.hpp"
#include "op.hpp"
#include <string>
using std::string;

class SevenOpMock: public Base {
    public:
        SevenOpMock() { }

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
};

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { }

        virtual double evaluate() { return 0; }
        virtual string stringify() { return "0"; }
};

class NegativeHundredOpMock: public Base {
    public:
        NegativeHundredOpMock() { }

        virtual double evaluate() { return -100; }
        virtual string stringify() { return "-100"; }
};

class PositiveHundredOpMock: public Base {
    public:
        PositiveHundredOpMock() { }

        virtual double evaluate() { return 100; }
        virtual string stringify() { return "100"; }
};

class OneOpMock: public Base {
    public:
        OneOpMock() { }

        virtual double evaluate() { return 1; }
        virtual string stringify() { return "1"; }
};

class LargeOpMock: public Base {
    public:
        LargeOpMock() { }

        virtual double evaluate() { return 23434234123.5; }
        virtual string stringify() { return "23434234123.5"; }
};

class SmallOpMock: public Base {
    public:
        SmallOpMock() { }

        virtual double evaluate() { return -23434234123.5; }
        virtual string stringify() { return "-23434234123.5"; }
};

#endif