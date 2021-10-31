#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

namespace Seshat {
  namespace Math{
    namespace Complex{

      class Complex {
        public:
          float re; // 実部
          float im; // 虚部
          //float norm = getNorm();
          
          Complex(float re=0.0,float im=0.0);
          float getNorm() const;
          Complex conjugate();
          std::string ToString();
          
          bool operator==(const Complex &a);
          Complex operator+(const Complex &a);
          Complex operator+(const float &a);
          Complex operator-(const Complex &a);
          Complex operator-(const float &a);
          Complex operator*(const Complex &a);
          Complex operator*(const float &a);
      };
      Complex Csqrt(float x);
      Complex Csqrt(Complex x);
    }
  }
}
#endif
