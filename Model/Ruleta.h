#ifndef CASINO_RUEDA_H
#define CASINO_RUEDA_H

#include "Juego.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Ruleta : public Juego {

protected:
    int numeroJugador;
    int numeroCasino;
    std::string colorJugador;
    std::string colorCasino;

    float calcularResultado(float gonzosApostar) override;

public:
    float jugar(float gonzosApostar) override;

    void mostrarReglas() const override;

    ~Ruleta() override = default;
};

#endif //CASINO_RUEDA_H
