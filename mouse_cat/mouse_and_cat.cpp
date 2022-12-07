#define _USE_MATH_DEFINES
#include "geometry.h"

#include <iostream>
#include <iomanip>
#include <cmath>


int main() {
	Rdec2D r_mouse = { 0, -3 };
	Rdec2D r_cat = { 3, 0 };
	double kill_dist = 0.001;

	double norm_v_mouse = 1.0;
	double norm_v_cat = 1.0;
	Rdec2D u_mouse = (Rdec2D{0.0, 0.0} - r_mouse) / Norm(Rdec2D{0.0, 0.0} - r_mouse) * norm_v_mouse;
	Rdec2D u_cat = (r_mouse - r_cat) / Norm(r_mouse - r_cat) * norm_v_cat;
	double Norm_v_cat = Norm(u_cat);

	double dt = 0.001;
	double prev = Norm(r_mouse - r_cat);

	// реализация
	while (true) {
		// обновление скорости и радиуса кошки
		u_cat = (r_mouse - r_cat) / Norm(r_mouse - r_cat) * Norm_v_cat;
		r_cat = r_cat + u_cat * dt;

		// обновление скорости и радиуса мышки
		u_mouse = (Rdec2D{ 0.0, 0.0 } - r_mouse) / Norm(Rdec2D{ 0.0, 0.0 } - r_mouse) * norm_v_mouse;
		r_mouse = r_mouse + u_mouse * dt;

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
		if (Norm(r_mouse - r_cat) >= prev) {
			std::cout << u_mouse << " " << u_cat << '\n';
			std::cout << "mouse will be in hole";
			break;
		}
		prev = Norm(r_mouse - r_cat);
	}
}
