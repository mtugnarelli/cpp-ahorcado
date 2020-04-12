
#include <iostream>
#include <string>

/*
 * Juego del Ahorcado
 *
 * https://es.wikipedia.org/wiki/Ahorcado_(juego)
 */

void mostrarBienvenida();

int main() {

	mostrarBienvenida();

	int vidasRestantes = 7;
	const std::string palabraSecreta = "algoritmo";
	std::string palabraDescubierta = "---------";

	while ((vidasRestantes > 0) && (palabraDescubierta != palabraSecreta)) {

		std::cout << "Te quedan "
				  << vidasRestantes
				  << " vidas para adivinar una palabra con "
				  << palabraSecreta.length()
				  << " letras"
				  << std::endl;

		char letraArriesgada;
		std::cout << "Arriesgá una letra: ";
		std::cin >> letraArriesgada;

		int ocurrencias = 0;
		for (unsigned int i = 0; i < palabraSecreta.length(); i++) {

			if (letraArriesgada == palabraSecreta[i]) {

				palabraDescubierta[i] = letraArriesgada;
				ocurrencias++;
			}
		}

		std::cout << palabraDescubierta << std::endl;

		if (ocurrencias == 0) {

			vidasRestantes--;
			std::cout << "La letra "
					  << letraArriesgada
					  << " no está en la palabra, consumiste una vida"
					  << std::endl;
		}
	}

	if (vidasRestantes <= 0) {

		std::cout << "PERDISTE" << std::endl;

	} else {

		std::cout << "GANASTE" << std::endl;
	}

	return 0;
}
