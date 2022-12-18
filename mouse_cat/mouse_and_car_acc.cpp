#define _USE_MATH_DEFINES
#include "geometry.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

const double EPS = std::numeric_limits<double>::epsilon();

int main() {
  // положение виновников задачи
  Rdec2D r_mouse = { 0.0, -10.0 };
  Rdec2D r_cat = { 15.0, 0.0 };

  // зона поржения
  double kill_dist = 0.05;

  // коэффициент для ускорения мышки
  double k1 = 2;
  double k2 = 0.05;

  double dt = 0.05;

  // начальные скорости
  double mod_v0_cat = 8.0;
  double mod_v0_mouse = 1.0;

  // ускорение мышки
  Rdec2D dist = (r_mouse - r_cat) / (Norm(r_mouse - r_cat) + k2) * k1;
  Rdec2D a_mouse = dist;

  // скорости
  Rdec2D u_cat = (r_mouse - r_cat) / Norm(r_mouse - r_cat) * mod_v0_cat;
  // v_m = v_0 + at
  Rdec2D u_mouse = -r_mouse / Norm(r_mouse) * mod_v0_mouse + a_mouse * dt;

  // предыдущее расстояние между героями событий
  double prev = Norm(r_mouse - r_cat);

  std::ofstream out("C://work//mouse_cat//result.txt");

  int i = 0;

  if (out.is_open()) {
    out << std::fixed << std::setprecision(3) << i << " " << r_cat.x << " " << r_cat.y << " " << r_mouse.x << " " << r_mouse.y << " " << Norm(u_mouse)
      << " " << Norm(a_mouse) << " " << Norm(r_mouse - r_cat) << '\n';
  }
  i += 1;

  // реализация
  while (true) {
    // обновление скоростей 
    u_cat = (r_mouse - r_cat) / Norm(r_mouse - r_cat) * mod_v0_cat;
    dist = (r_mouse - r_cat) / (Norm(r_mouse - r_cat) + k2) * k1;
    a_mouse = dist;
    u_mouse = -r_mouse / Norm(r_mouse) * Norm(u_mouse) + a_mouse * dt;

    // обновление положений
    r_cat = r_cat + u_cat * dt;
    r_mouse = r_mouse + u_mouse;

    if (out.is_open()) {
      out << std::fixed << std::setprecision(3) << i << " " << r_cat.x << " " << r_cat.y << " " << r_mouse.x << " " << r_mouse.y << " " << Norm(u_mouse)
        << " " << Norm(a_mouse) << " " << Norm(r_mouse - r_cat) << '\n';
    }

    // мыш дырыш
    // мышка "выше" точки (0, 0) - убежала в норку
    if (r_mouse.y >= 0) {
      std::cout << "mouse is in hole";
      break;
    }

    // мыш кирдыш
    // кошка поймала мышку
    if (Norm(r_mouse - r_cat) <= kill_dist) {
      std::cout << "rip mouse";
      break;
    }

    // мыш победыш
    // расстояние между кошкой и мышкой увеличивается 
    // или кошка "перебежала" норку
    /*if (r_cat.x < 0 || Norm(r_mouse - r_cat) > prev) {
      std::cout << "mouse will be in hole";
      break;
    }*/

    prev = Norm(r_mouse - r_cat);
    i += 1;
  }
  out.close();
}
