#include "ActividadController.h"

#include <exception>

ActividadController::ActividadController(
    IRepositorio* repositorio,
    QObject* parent
    )
    : QObject(parent),
    repositorio_(repositorio)
{}

void ActividadController::crear(
    const DatosActividad& datos
    )
{
    try {

        auto actividad = FabricaActividades::crear(datos);

        repositorio_->agregar(std::move(actividad));

        listar();

    }
    catch (const std::exception& e) {

        emit errorOcurrido(
            QString::fromUtf8(e.what())
            );
    }
}

void ActividadController::cargar()
{
    try {

        repositorio_->cargar();

        listar();

    }
    catch (const std::exception& e) {

        emit errorOcurrido(
            QString::fromUtf8(e.what())
            );
    }
}

void ActividadController::listar()
{
    emit listaActualizada(repositorio_->listar());
}