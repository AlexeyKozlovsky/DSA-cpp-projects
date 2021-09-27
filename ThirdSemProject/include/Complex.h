#include <ostream>

class Complex {
private:
    double re, im;
public:
    inline double getRe() const {return this->re;};
    inline double getIm() const {return this->im;};

    //inline Complex(int re = 0, int im = 0) {this->re = re; this->im = im;};
    inline Complex(double re = 0, double im = 0) {this->re = re; this->im = im;};

    double getMod();
    double getArg();
    Complex conjugate();

    // Operators
    inline bool operator==(const Complex &c) const {
        return this->re == c.re && this->im == c.im;
    }

    inline Complex operator+(const Complex &c) const {
        Complex result;
        result.im = c.im + this->im;
        result.re = c.re + this->re;
        return result;
    };

    inline Complex operator-(const Complex &c) const {
        Complex result;
        result.im = this->im - c.im;
        result.re = this->re - c.re;
        return result;
    };

    inline Complex operator*(const Complex &c) const {
        Complex result;
        result.re = c.re * this->re - c.im * this->im;
        result.im = c.re * this->im + c.im * this->re;
        return result;
    };

    inline Complex operator/(const Complex &c) const {
        Complex result;
        double under = (c.re * c.re + c.im * c.im);
        result.re = (this->re * c.re + this->im * c.im) / under;
        result.im = (c.re * this->im - this->re * c.im) / under;
        return result;
    };

    friend inline std::ostream& operator << (std::ostream &o, const Complex &c) {
      return o << '(' << c.re << ", " << c.im << ')';
    };

};