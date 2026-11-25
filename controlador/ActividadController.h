#ifndef ACTIVIDADCONTROLLER_H
#define ACTIVIDADCONTROLLER_H

#include "../modelo/IRepositorio.h"
#include "../modelo/FabricaActividades.h"

#include <QObject>
#include <QString>
#include <vector>

class ActividadController : public QObject
{
    Q_OBJECT

public:

    explicit ActividadController(
        IRepositorio* repositorio,
        QObject* parent = nullptr
        );

public slots:

    void crear(const DatosActividad& datos);

    void cargar();

    void listar();

signals:

    void listaActualizada(
        const std::vector<const Actividad*>& actividades
        );

    void errorOcurrido(const QString& mensaje);

private:

    IRepositorio* repositorio_;
};

#endif