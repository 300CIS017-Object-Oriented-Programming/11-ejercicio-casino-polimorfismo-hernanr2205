#include "Ruleta.h"
#include <iostream>
#include <cstdlib>s
#include <ctime>

float Ruleta::jugar(float gonzosApostar) {
    int numeroApostado;
    std::string colorApostado;


    srand(time(nullptr));

    std::cout << "Ingrese el número que desea apostar (0-36): ";
    std::cin >> numeroApostado;
    std::cout << "Ingrese el color que desea apostar (rojo/negro): ";
    std::cin >> colorApostado;


    if (numeroApostado < 0 || numeroApostado > 36) {
        std::cout << "Número no válido. Debe estar entre 0 y 36." << std::endl;
        return 0;
    }


    numeroCasino = rand() % 37;
    int colorCasinoNumero = rand() % 2;

    colorCasino = (colorCasinoNumero == 0) ? "rojo" : "negro";
    std::cout << "El número del casino es: " << numeroCasino << " y el color es: " << colorCasino << std::endl;

    float gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}

float Ruleta::calcularResultado(float gonzosApostar) {
    if (numeroJugador == numeroCasino && colorJugador == colorCasino) {
        std::cout << "¡Felicidades! Has acertado el número y el color. Ganas 35 veces lo apostado." << std::endl;
        return 35 * gonzosApostar;
    }
    else if (numeroJugador == numeroCasino) {
        std::cout << "Has acertado el número. Ganas 10 veces lo apostado." << std::endl;
        return 10 * gonzosApostar;
    }
    else if (colorJugador == colorCasino) {
        std::cout << "Has acertado el color. Ganas 2 veces lo apostado." << std::endl;
        return 2 * gonzosApostar;
    }
    // Si no acierta ni el número ni el color, pierde todo lo apostado
    else {
        std::cout << "No has acertado ni el número ni el color. Pierdes lo apostado." << std::endl;
        return 0;
    }
}

void Ruleta::mostrarReglas() const {
    std::cout << "================ Reglas del Juego Ruleta ================" << std::endl;
    std::cout << "- El jugador apuesta a un número entre 0 y 36 y un color (rojo o negro)." << std::endl;
    std::cout << "- El sistema genera un número y un color aleatorio para el casino." << std::endl;
    std::cout << "- Si el jugador acierta tanto el número como el color, ganará 35 veces lo apostado." << std::endl;
    std::cout << "- Si el jugador acierta solo el número, ganará 10 veces lo apostado." << std::endl;
    std::cout << "- Si el jugador acierta solo el color, ganará 2 veces lo apostado." << std::endl;
    std::cout << "- Si no acierta ni el número ni el color, pierde todo lo apostado." << std::endl;
    std::cout << "=========================================================" << std::endl;
}
