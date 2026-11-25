#ifndef IREPOSITORIO_H
#define IREPOSITORIO_H

#include "Actividad.h"

#include <memory>
#include <vector>

class IRepositorio
{
public:
    virtual ~IRepositorio() = default;

    virtual void agregar(std::unique_ptr<Actividad> actividad) = 0;

    virtual std::vector<const Actividad*> listar() const = 0;

    virtual void cargar() = 0;
};

#endif