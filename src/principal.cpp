
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

/*
 * Solicita al usuario arriesgar una letra y devuelve la letra que arriesgada.
 */
char arriesgarLetra();

/*
 * Descubre las ocurrencias de la letra en la palabra 'secreta', actualizando
 * la palabra 'descubierta' y devuelve la cantidad de apariciones.
 */
int descubrir(char letra, std::string& descubierta, std::string secreta);

/*
 * Según la cantidad de ocurrencias de la letraArriesgada en la
 * palabra secreta consume o no una vida.
 */
void actualizar(int& vidasRestantes, int ocurrencias, char letraArriesgada);

/*
 * Indica al usuario que 'letra' no está en la palabra secreta.
 */
void mostrarQueNoContiene(char letra);

/*
 * Indica al usuario cómo finalizó el juego.
 */
void mostrarResultado(int vidasRestante);

int main() {

	mostrarBienvenida();

	int vidasRestantes = 7;
	const std::string palabraSecreta = "algoritmo";
	std::string palabraDescubierta = "---------";

	while ((vidasRestantes > 0) && (palabraDescubierta != palabraSecreta)) {

		mostrarAhorcado(palabraDescubierta, vidasRestantes);

		char letraArriesgada = arriesgarLetra();

		int ocurrencias = descubrir(letraArriesgada, palabraDescubierta,
									palabraSecreta);

		actualizar(vidasRestantes, ocurrencias, letraArriesgada);
	}

	mostrarResultado(vidasRestantes);

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

char arriesgarLetra() {

	char letra;

	std::cout << "Arriesgá una letra: ";
	std::cin >> letra;

	return letra;
}

int descubrir(char letra, std::string& descubierta, std::string secreta) {

	int ocurrencias = 0;
	for (unsigned int i = 0; i < secreta.length(); i++) {

		if (letra == secreta[i]) {

			descubierta[i] = letra;
			ocurrencias++;
		}
	}

	return ocurrencias;
}

void mostrarQueNoContiene(char letra) {

	std::cout << "La letra "
			  << letra
			  << " no está en la palabra, consumiste una vida"
			  << std::endl;
}

void actualizar(int& vidasRestantes, int ocurrencias, char letraArriesgada) {

	if (ocurrencias == 0) {

		vidasRestantes--;

		mostrarQueNoContiene(letraArriesgada);
	}
}

void mostrarResultado(int vidasRestantes) {

	if (vidasRestantes <= 0) {

		std::cout << "PERDISTE" << std::endl;

	} else {

		std::cout << "GANASTE" << std::endl;
	}
}
