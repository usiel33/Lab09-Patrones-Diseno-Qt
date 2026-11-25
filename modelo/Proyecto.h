#ifndef PROYECTO_H
#define PROYECTO_H

#include "Actividad.h"

class Proyecto : public Actividad
{
public:
    Proyecto(QString titulo, QDate fecha)
        : Actividad(std::move(titulo), fecha)
    {}

    QString tipo() const override {
        return "proyecto";
    }
};

#endif