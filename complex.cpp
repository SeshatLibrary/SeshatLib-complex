#include "complex.hpp"
#include <cmath>

namespace Seshat {
  namespace Math {
    namespace Complex {
      
      Complex::Complex(float re,float im):re(re),im(im)
      {
        this->im = im;
        this->re = re;
      }

      float Complex::getNorm() const{
        return std::sqrt(this->re*this->re+this->im*this->im);
      }

      Complex Complex::conjugate()
      {
        return Complex(this->re,-this->im);
      }

      std::string Complex::ToString(){
        std::ostringstream str_re,str_im;
        str_re << re;
        str_im << im;
        return str_re.str() + " + " + str_im.str() + "j";
      }

      bool Complex::operator==(const Complex &a)
      {
        return this->re == a.re && this->im == a.im;
      }

      Complex Complex::operator+(const Complex &a)
      {
        return Complex(this->re+a.re,this->im+a.im);
      }

      Complex Complex::operator+(const float &a)
      {
        return Complex(this->re+a,this->im);
      }

      Complex Complex::operator-(const Complex &a)
      {
        return Complex(this->re-a.re,this->im-a.im);
      }
      Complex Complex::operator-(const float &a)
      {
        return Complex(this->re-a,this->im);
      }

      Complex Complex::operator*(const Complex &a)
      {
        return Complex(this->re*a.re-this->im*a.im,this->im*a.re+this->re*a.im);
      }
      Complex Complex::operator*(const float &a)
      {
        return Complex(a*this->re,a*this->im);
      }

      Complex Csqrt(float x)
      {
        if (x>=0.0) 
        {
          return Complex(std::sqrt(x),0.0);
        }
        else
        {
          return Complex(0.0,std::sqrt(x));
        }
      }

      Complex Csqrt(Complex x)
      {
        float a = x.re, b = x.im;
        float R = std::sqrt((a+std::sqrt(a*a+b*b))/2);
        float I = std::sqrt((-a+std::sqrt(a*a+b*b))/2);
        if (x.im >= 0.0)
        {
          return Complex(R,I);
        }
        else
        {
          return Complex(R, -I);
        }
      }
    }
  }
}
