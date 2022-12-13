#define _USE_MATH_DEFINES
#include "geometry.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

const double EPS = std::numeric_limits<double>::epsilon();

int main() {
  // положение виновников задачи
  Rdec2D r_mouse = { 0.0, -3.0 };
  Rdec2D r_cat = { 3.0, 0.0 };

  // зона поржения
  double kill_dist = 0.5;

  // коэффициент для ускорения мышки
  double k = 0.001;

  double dt = 0.1;

  // начальные скорости
  double mod_v0_cat = 1.0;
  double mod_v0_mouse = 1.0;
  Rdec2D u_cat = (r_mouse - r_cat) / Norm(r_mouse - r_cat) * mod_v0_cat;
  Rdec2D u_mouse = r_mouse / Norm(r_mouse) * mod_v0_mouse;

  // предыдущее расстояние между героями событий
  double prev = Norm(r_mouse - r_cat);

  std::ofstream out("C://work//mouse_cat//result.txt");

  int i = 1;

  // реализация
  while (true) {
    if (out.is_open()) {
      out << std::fixed << std::setprecision(3) << i << " " << r_cat.x << " " << r_cat.y << " " << r_mouse.x << " " << r_mouse.y << " " << Norm(r_mouse - r_cat) << '\n';
    }

    // обновление скоростей 
    u_cat = (r_mouse - r_cat) / Norm(r_mouse - r_cat) * mod_v0_cat;
    u_mouse = r_mouse / Norm(r_mouse) * mod_v0_mouse;

    // обновление положений
    r_cat = r_cat + u_cat * dt;
    r_mouse = r_mouse - u_mouse * dt;

    // мыш дырыш
    // мышка "выше" точки (0, 0) - убежала в норку
    if (r_mouse.y >= 0) {
      i += 1;
      out << std::fixed << std::setprecision(3) << i << " " << r_cat.x << " " << r_cat.y << " " << r_mouse.x << " " << r_mouse.y << " " << Norm(r_mouse - r_cat) << '\n';
      std::cout << "mouse is in hole";
      break;
    }

    // мыш кирдыш
    // кошка поймала мышку
    if (Norm(r_mouse - r_cat) <= kill_dist) {
      i += 1;
      out << std::fixed << std::setprecision(3) << i << " " << r_cat.x << " " << r_cat.y << " " << r_mouse.x << " " << r_mouse.y << " " << Norm(r_mouse - r_cat) << '\n';
      std::cout << "rip mouse";
      break;
    }

    // мыш победыш
    // расстояние между кошкой и мышкой увеличивается 
    // или кошка "перебежала" норку
    if (r_cat.x < 0 || Norm(r_mouse - r_cat) > prev) {
      i += 1;
      out << std::fixed << std::setprecision(3) << i << " " << r_cat.x << " " << r_cat.y << " " << r_mouse.x << " " << r_mouse.y << " " << Norm(r_mouse - r_cat) << '\n';
      std::cout << "mouse will be in hole";
      break;
    }

    prev = Norm(r_mouse - r_cat);
    i += 1;
  }
  out.close();
}
