
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

	std::cout << "Te quedan " << vidasRestantes << " vidas" << std::endl;

	std::string palabraSecreta = "algoritmo";

	std::cout << "La palabra secreta tiene "
			  << palabraSecreta.length()
			  << " letras"
			  << std::endl;

	return 0;
}
