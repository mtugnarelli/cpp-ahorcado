
#include <iostream>
#include <string>

/*
 * Juego del Ahorcado
 *
 * https://es.wikipedia.org/wiki/Ahorcado_(juego)
 */

/*
 * Indica el inicio del programa.
 */
void mostrarBienvenida();

/*
 * Describe el estado del juego.
 */
void mostrarAhorcado(std::string descubierta, int vidasRestantes);

int main() {

	mostrarBienvenida();

	int vidasRestantes = 7;
	const std::string palabraSecreta = "algoritmo";
	std::string palabraDescubierta = "---------";

	while ((vidasRestantes > 0) && (palabraDescubierta != palabraSecreta)) {

		mostrarAhorcado(palabraDescubierta, vidasRestantes);

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

void mostrarBienvenida() {

	std::cout << " A H O R C A D O " << std::endl;
}

void mostrarAhorcado(std::string descubierta, int vidasRestantes) {

	std::cout << descubierta
			  << std::endl
			  << "Te quedan "
			  << vidasRestantes
			  << " vidas para adivinar una palabra con "
			  << descubierta.length()
			  << " letras"
			  << std::endl;
}
