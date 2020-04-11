
#include <iostream>
#include <string>

/*
 * Juego del Ahorcado
 *
 * https://es.wikipedia.org/wiki/Ahorcado_(juego)
 */
int main() {

	std::cout << " A H O R C A D O " << std::endl;

	int vidasRestantes = 7;
	const std::string palabraSecreta = "algoritmo";
	std::string palabraDescubierta = "---------";

	std::cout << "Te quedan "
			  << vidasRestantes
			  << " vidas para adivinar una palabra con "
			  << palabraSecreta.length()
			  << " letras"
			  << std::endl;

	char letraArriesgada;
	std::cout << "Arriesgá una letra: ";
	std::cin >> letraArriesgada;

	vidasRestantes--;

	return 0;
}
