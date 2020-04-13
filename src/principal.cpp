/*
 * Juego del Ahorcado
 *
 * https://es.wikipedia.org/wiki/Ahorcado_(juego)
 */

#include <string>
#include "interacciones.h"

#define VIDAS 7

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
 * Devuelve si el ahorcado aún no terminó.
 */
bool sigueJugando(int vidasRestantes, std::string palabraDescubierta,
				  std::string palabraSecreta);

/*
 * Devuelve una versión oculta de 'palabra'.
 */
std::string ocultar(std::string palabra);

int main() {

	mostrarBienvenida();

	int vidasRestantes = VIDAS;
	const std::string palabraSecreta = "algoritmo";
	std::string palabraDescubierta = ocultar(palabraSecreta);

	while (sigueJugando(vidasRestantes, palabraDescubierta, palabraSecreta)) {

		mostrarAhorcado(palabraDescubierta, vidasRestantes);

		char letraArriesgada = arriesgarLetra();

		int ocurrencias = descubrir(letraArriesgada, palabraDescubierta,
									palabraSecreta);

		actualizar(vidasRestantes, ocurrencias, letraArriesgada);
	}

	mostrarResultado(vidasRestantes);

	return 0;
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

void actualizar(int& vidasRestantes, int ocurrencias, char letraArriesgada) {

	if (ocurrencias == 0) {

		vidasRestantes--;

		mostrarQueNoContiene(letraArriesgada);
	}
}

bool sigueJugando(int vidasRestantes, std::string palabraDescubierta,
				  std::string palabraSecreta) {

	return (vidasRestantes > 0) && (palabraDescubierta != palabraSecreta);
}

std::string ocultar(std::string palabra) {

	std::string oculta = "";

	for (unsigned int i = 0; i < palabra.length(); i++) {

		oculta = oculta + "-";
	}

	return oculta;
}
