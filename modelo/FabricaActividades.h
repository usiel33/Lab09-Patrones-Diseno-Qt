#ifndef FABRICAACTIVIDADES_H
#define FABRICAACTIVIDADES_H

#include "Actividad.h"
#include "Tarea.h"
#include "Examen.h"
#include "Proyecto.h"

#include <memory>
#include <stdexcept>

class FabricaActividades
{
public:

    static std::unique_ptr<Actividad> crear(
        const DatosActividad& datos)
    {
        if (datos.titulo.trimmed().isEmpty() ||
            !datos.fecha.isValid()) {

            throw std::invalid_argument(
                "Datos invalidos");
        }

        const QString tipo = datos.tipo.trimmed().toLower();

        if (tipo == "tarea") {
            return std::make_unique<Tarea>(
                datos.titulo, datos.fecha);
        }

        if (tipo == "examen") {
            return std::make_unique<Examen>(
                datos.titulo, datos.fecha);
        }

        if (tipo == "proyecto") {
            return std::make_unique<Proyecto>(
                datos.titulo, datos.fecha);
        }

        throw std::invalid_argument(
            "Tipo de actividad desconocido");
    }
};

#endif