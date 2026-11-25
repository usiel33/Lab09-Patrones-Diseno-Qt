#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H

#include <QString>
#include <QDate>
#include <utility>

class Actividad
{
public:
    virtual ~Actividad() = default;

    QString titulo() const {
        return titulo_;
    }

    QDate fecha() const {
        return fecha_;
    }

    virtual QString tipo() const = 0;

protected:
    Actividad(QString titulo, QDate fecha)
        : titulo_(std::move(titulo)),
        fecha_(fecha)
    {}

    QString titulo_;
    QDate fecha_;
};

struct DatosActividad {
    QString tipo;
    QString titulo;
    QDate fecha;
};

#endif