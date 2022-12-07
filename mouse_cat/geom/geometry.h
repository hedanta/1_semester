#include <iosfwd>
#include <iostream>

struct Rdec2D {
  double x = 0.0;
  double y = 0.0;
};

struct Rpol2D {
  double r = 0.0;
  double phi = 0.0;
};

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D v);

Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs);

bool operator==(const Rdec2D& lhs, const Rdec2D& rhs);

bool operator!=(const Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator-(const Rdec2D& r);

Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator*(const Rdec2D& v, const double& n);

Rdec2D operator/(const Rdec2D& v, const double& n);

double Norm(const Rdec2D& v);

double Dot(const Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D ToDec(const Rpol2D& v);

Rpol2D ToPol(const Rdec2D& v);

std::ostream& operator<<(std::ostream& ostrm, const Rpol2D v);

bool operator==(const Rpol2D& lhs, const Rpol2D& rhs);

bool operator!=(const Rpol2D& lhs, Rpol2D& rhs);

Rpol2D operator+(const Rpol2D& lhs, const Rpol2D& rhs);

Rpol2D operator-(const Rpol2D& r);

Rpol2D operator-(const Rpol2D& lhs, const Rpol2D& rhs);

Rpol2D operator*(const Rpol2D& v, const double& n);

Rpol2D operator/(const Rpol2D& v, const double& n);

double Norm(const Rpol2D& v);

double Dot(const Rpol2D& lhs, const Rpol2D& rhs);
