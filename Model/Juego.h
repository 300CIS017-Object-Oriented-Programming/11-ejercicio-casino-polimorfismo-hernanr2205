#ifndef CASINO_JUEGO_H
#define CASINO_JUEGO_H

#include "Jugador.h"

class Juego {
protected:
    int numeroCasino;
    int numeroJugador;

    virtual float calcularResultado(float gonzosApostar) = 0;

public:
    Juego() = default;

    virtual ~Juego() = default;

    virtual float jugar(float gonzosApostar) = 0;

    // Método virtual que será implementado por las clases derivadas
    virtual void mostrarReglas() const = 0; // Método puramente virtual

};

#endif //CASINO_JUEGO_H
