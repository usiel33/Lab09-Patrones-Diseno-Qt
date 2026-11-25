#ifndef TAREA_H
#define TAREA_H

#include "Actividad.h"

class Tarea : public Actividad
{
public:
    Tarea(QString titulo, QDate fecha)
        : Actividad(std::move(titulo), fecha)
    {}

    QString tipo() const override {
        return "tarea";
    }
};

#endif