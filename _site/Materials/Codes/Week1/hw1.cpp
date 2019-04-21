//-ebook|P-2.3
#include <iostream>
using namespace std;

class Complex {
	protected:
		double R;
		double I;
	public:
		Complex(double r = 0, double i = 0) : R(r), I(i) {};

		friend ostream& operator<<(ostream& os, const Complex& obj) {
			os << obj.R << ((obj.I >= 0) ? "+" : "") << obj.I << 'i';
			return os;
		}
		friend Complex operator + (Complex lhs, const Complex& rhs) {
			lhs.R += rhs.R;
			lhs.I += rhs.I;
			return lhs;
		}
		friend Complex operator-(Complex lhs, const Complex& rhs) {
			lhs.R -= rhs.R;
			lhs.I -= rhs.I;
			return lhs;
		}
		friend Complex operator*(Complex lhs, const Complex& rhs) {
			lhs.R = lhs.R*rhs.R - lhs.I*rhs.I;
			lhs.I = lhs.R*rhs.I + lhs.I*rhs.R;
			return lhs;
		}
};

template <typename T>
class Vector{
	protected:
		std::vector<T> buffer;
	public:
		Vector(int len = 0, int init = 0);
		Vector(vector<T> v);
		Vector(Complex c, int len = 1);

		friend ostream& operator<<(ostream& os, const Vector<T>& obj) {
			for (typename vector<T>::const_iterator it = obj.buffer.begin(); it != obj.buffer.end(); ++it) {
				os << *it << ' ';
			}
			return os;
		}

		friend Vector<T> operator+(Vector<T> lhs, const Vector<T>& rhs){
			assert(lhs.buffer.size() == rhs.buffer.size());
			typename std::vector<T>::iterator itL = lhs.buffer.begin();
			typename std::vector<T>::const_iterator itR = rhs.buffer.begin();
			for (; itL != lhs.buffer.end() || itR != rhs.buffer.end(); ++itL, ++itR) {
				*itL += *itR;
			}
			return lhs;
		}
		friend Vector<T> operator-(Vector<T> lhs, const Vector<T>& rhs) {
			assert(lhs.buffer.size() == rhs.buffer.size());
			typename std::vector<T>::iterator itL = lhs.buffer.begin();
			typename std::vector<T>::const_iterator itR = rhs.buffer.begin();
			for (; itL != lhs.buffer.end() || itR != rhs.buffer.end(); ++itL, ++itR) {
				*itL -= *itR;
			}
			return lhs;
		}
		friend Vector<T> operator*(Vector<T> lhs, const Vector<T>& rhs) {
			assert(lhs.buffer.size() == rhs.buffer.size());
			typename std::vector<T>::iterator itL = lhs.buffer.begin();
			typename std::vector<T>::const_iterator itR = rhs.buffer.begin();
			for (; itL != lhs.buffer.end() || itR != rhs.buffer.end(); ++itL, ++itR) {
				*itL *= *itR;
			}
			return lhs;
		}
		friend Vector<T> operator*(Vector<T> lhs, const T& rhs) {
			typename std::vector<T>::iterator itL = lhs.buffer.begin();
			for (; itL != lhs.buffer.end(); ++itL) {
				*itL = *itL * rhs;
			}
			return lhs;
		}
		// unsigned size() {return buffer.size();}

};

template <typename T>
Vector<T>::Vector(int len, int init) {
	assert (init == 0 || init == 1);
	for (int i = 0; i < len; i++) {
		buffer.push_back(T(init));
	}
}
template <typename T>
Vector<T>::Vector(vector<T> v) {
	this->buffer = v;
}
template <typename T>
Vector<T>::Vector(Complex c, int len) {
	for (int i = 0; i < len; i++) {
		buffer.push_back(c);
	}
}

int main () {
	Vector<int> *v1 = new Vector<int>(10, 0);
	Vector<int> *v2 = new Vector<int>(10, 1);
	cout << *v1 << endl;
	cout << *v2 << endl;

	cout << *v1 + *v2 << endl;

	Complex *c = new Complex(2, 3);
	Vector<Complex> *v3 = new Vector<Complex>(*c, 10);
	Complex *d = new Complex (-1, 4);
	cout << *v3 * *d << endl;

	return 0;
}

