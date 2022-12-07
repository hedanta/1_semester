#define _USE_MATH_DEFINES

#include "geometry.h"
#include <iostream>
#include <iomanip>
#include <cmath>

const double EPS = std::numeric_limits<double>::epsilon() * 2;

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D v) {
  return ostrm << std::fixed << std::setprecision(3) << "(" << v.x << "; " << v.y << ")";
}

bool operator==(const Rdec2D& lhs, const Rdec2D& rhs) {
  if (std::abs(rhs.x - lhs.x) < EPS) {
    if (std::abs(rhs.y - lhs.y) < EPS) {
      return true;
    }
  }
  return false;
}

bool operator!=(const Rdec2D& lhs, const Rdec2D& rhs) {
  if (std::abs(rhs.x - lhs.x) < EPS) {
    if (std::abs(rhs.y - lhs.y) < EPS) {
      return false;
    }
  }
  return true;
}

Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs) {
  Rdec2D res = { 0.0, 0.0 };
  res.x = lhs.x + rhs.x;
  res.y = lhs.y + rhs.y;
  return res;
}

Rdec2D operator-(const Rdec2D& r) {
  Rdec2D res = { 0.0, 0.0 };
  res.x = -r.x;
  res.y = -r.y;
  return res;
}

Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs) {
  Rdec2D res = { 0.0, 0.0 };
  res.x = lhs.x - rhs.x;
  res.y = lhs.y - rhs.y;
  return res;
}

Rdec2D operator*(const Rdec2D& v, const double& n) {
  Rdec2D res = { 0.0, 0.0 };
  res.x = n * v.x;
  res.y = n * v.y;
  return res;
}

Rdec2D operator/(const Rdec2D& v, const double& n) {
  Rdec2D res = { 0.0, 0.0 };
  res.x = v.x / n;
  res.y = v.y / n;
  return res;
}

double Norm(const Rdec2D& v) {
  return std::sqrt(v.x * v.x + v.y * v.y);
}

double Dot(const Rdec2D& lhs, const Rdec2D& rhs) {
  return lhs.x * rhs.x + lhs.y + rhs.y;
}

Rdec2D ToDec(const Rpol2D& v) {
  Rdec2D res = { 0.0, 0.0 };
  res.x = v.r * std::cos(v.phi);
  res.y = v.r * std::sin(v.phi);
  return res;
}

Rpol2D ToPol(const Rdec2D& v) {
  Rpol2D res = { 0.0, 0.0 };
  res.r = Norm(v);
  res.phi = std::acos(v.x / res.r);
  return res;
}

std::ostream& operator<<(std::ostream& ostrm, const Rpol2D v) {
  return ostrm << std::fixed << std::setprecision(3) << "(" << v.r << "; " << v.phi << ")";
}

bool operator==(const Rpol2D& lhs, const Rpol2D& rhs) {
  if (std::abs(rhs.r - lhs.r) < EPS) {
    if (std::abs(rhs.phi - lhs.phi) < EPS) {
      return true;
    }
  }
  return false;
}

bool operator!=(const Rpol2D& lhs, const Rpol2D& rhs) {
  if (std::abs(rhs.r - lhs.r) < EPS) {
    if (std::abs(rhs.phi - lhs.phi) < EPS) {
      return false;
    }
  }
  return true;
}

Rpol2D operator+(const Rpol2D& lhs, const Rpol2D& rhs) {
  Rdec2D l = ToDec(lhs);
  Rdec2D r = ToDec(rhs);
  Rdec2D res = { 0.0, 0.0 };
  res.x = l.x + r.x;
  res.y = l.y + r.y;
  return ToPol(res);
}

Rpol2D operator-(const Rpol2D& r) {
  Rpol2D res = { 0.0, 0.0 };
  res.r = r.r;
  res.phi = r.phi + M_PI;
  return res;
}

Rpol2D operator-(const Rpol2D& lhs, const Rpol2D& rhs) {
  Rdec2D l = ToDec(lhs);
  Rdec2D r = ToDec(rhs);
  Rdec2D res = { 0.0, 0.0 };
  res.x = l.x - r.x;
  res.y = l.y - r.y;
  return ToPol(res);
}

Rpol2D operator*(const Rpol2D& v, const double& n) {
  Rdec2D res = { 0.0, 0.0 };
  Rdec2D dec = ToDec(v);
  res.x = n * dec.x;
  res.y = n * dec.y;
  return ToPol(res);
}

Rpol2D operator/(const Rpol2D& v, const double& n) {
  Rdec2D res = { 0.0, 0.0 };
  Rdec2D dec = ToDec(v);
  res.x = dec.x / n;
  res.y = dec.y / n;
  return ToPol(res);
}

double Norm(const Rpol2D& v) {
  return v.r;
}

double Dot(const Rpol2D& lhs, const Rpol2D& rhs) {
  Rdec2D l = ToDec(lhs);
  Rdec2D r = ToDec(rhs);
  return l.x * r.x + l.y + r.y;
}
