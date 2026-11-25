#ifndef EXAMEN_H
#define EXAMEN_H

#include "Actividad.h"

class Examen : public Actividad
{
public:
    Examen(QString titulo, QDate fecha)
        : Actividad(std::move(titulo), fecha)
    {}

    QString tipo() const override {
        return "examen";
    }
};

#endif