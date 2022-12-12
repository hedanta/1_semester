#define _USE_MATH_DEFINES
#include "geometry.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

const double EPS = std::numeric_limits<double>::epsilon();

int main() {
	// положение виновников задачи
	Rdec2D r_mouse = { 0.0, -30.0 };
	Rdec2D r_cat = { 30.0, 0.0 };

	// зона поржения
	double kill_dist = 0.5;

	// коэффициент для ускорения мышки
	double k = 0.001;

	double dt = 0.05;

	// начальные скорости
	Rdec2D v0_mouse = { 0.0, 2.5 };
	Rdec2D v0_cat = { 2.5, 0.05 };
	Rdec2D u_mouse = v0_mouse;
	Rdec2D u_cat = v0_cat;

	// предыдущее расстояние между героями событий
	double prev = Norm(r_mouse - r_cat);

	std::ofstream out("C://work//mouse_cat//result.txt");

	int i = 1;

	// реализация
	while (true) {
		if (out.is_open()) {
			out << std::fixed << std::setprecision(3) << i << " " << r_cat.x << " " << r_cat.y << " " << r_mouse.x << " " << r_mouse.y << " " << Norm(r_mouse - r_cat) << '\n';
		}

		// обновление положения кошки
		r_cat = r_cat - u_cat * dt;

		// обновление положения мышки
		r_mouse = r_mouse + u_mouse * dt;

		// мыш дырыш
		// мышка "выше" точки (0, 0) - убежала в норку

		if (r_mouse.y == 0 && r_cat.x == 0) {
			std::cout << "hooray\n";
			break;
		}

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
		if (r_cat.x < 0 || Norm(r_mouse - r_cat) > prev) {
			std::cout << "mouse will be in hole";
			break;
		}

		prev = Norm(r_mouse - r_cat);
		i += 1;
	}
	out.close();
}
