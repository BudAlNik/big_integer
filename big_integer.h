#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <iosfwd>
#include <vector>

using namespace std;

struct big_integer {
private:
    vector<uint32_t> number;
    void normalize();
    void negate();
    
public:
    big_integer();
    big_integer(int num);
    big_integer(uint32_t num);
    big_integer(vector<uint32_t> const& _number);
    explicit big_integer(string const& s);

    ~big_integer();
    
    big_integer(big_integer const& other);

    void print() const;

    bool get_sign() const;

    size_t size() const;
    
    uint32_t operator[](size_t pos) const;

    big_integer& operator=(big_integer const& other);

    big_integer& operator+=(big_integer const& rhs);
    big_integer& operator-=(big_integer const& rhs);
    big_integer& operator*=(big_integer const& rhs);
    big_integer& operator/=(big_integer const& rhs);
    big_integer& operator%=(big_integer const& rhs);

    big_integer& operator&=(big_integer const& rhs);
    big_integer& operator|=(big_integer const& rhs);
    big_integer& operator^=(big_integer const& rhs);

    big_integer& operator<<=(int rhs);
    big_integer& operator>>=(int rhs);

    big_integer operator+() const;
    big_integer operator-() const;
    big_integer operator~() const;

    big_integer& operator++();
    big_integer operator++(int);
    big_integer& operator--();
    big_integer operator--(int);

    friend bool operator==(big_integer const& a, big_integer const& b);
    friend bool operator!=(big_integer const& a, big_integer const& b);
    friend bool operator<(big_integer const& a, big_integer const& b);
    friend bool operator>(big_integer const& a, big_integer const& b);
    friend bool operator<=(big_integer const& a, big_integer const& b);
    friend bool operator>=(big_integer const& a, big_integer const& b);

    friend std::string to_string(big_integer const& a);
};

bool operator==(big_integer const& num1, big_integer const& num2);
bool operator!=(big_integer const& a, big_integer const& b);
bool operator<(big_integer const& num1, big_integer const& num2);
bool operator>(big_integer const& num1, big_integer const& num2);
bool operator<=(big_integer const& num1, big_integer const& num2);
bool operator>=(big_integer const& num1, big_integer const& num2);

big_integer operator+(big_integer num1, big_integer const& num2);
big_integer operator-(big_integer num1, big_integer const& num2);
big_integer operator*(big_integer a, big_integer const& b);
big_integer operator/(big_integer a, big_integer const& b);
big_integer operator%(big_integer a, big_integer const& b);

big_integer operator&(big_integer num1, big_integer const& num2);
big_integer operator|(big_integer num1, big_integer const& num2);
big_integer operator^(big_integer num1, big_integer const& num2);

big_integer operator<<(big_integer a, int b);
big_integer operator>>(big_integer a, int b);

std::string to_string(big_integer const& a);
std::ostream& operator<<(std::ostream& s, big_integer const& a);

#endif // BIG_INTEGER_H