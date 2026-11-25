#ifndef ADAPTADORCSV_H
#define ADAPTADORCSV_H

#include "../modelo/IRepositorio.h"
#include "../modelo/FabricaActividades.h"
#include "LectorCsvHeredado.h"

#include <memory>
#include <vector>

class AdaptadorCsv : public IRepositorio
{
public:

    explicit AdaptadorCsv(QString ruta)
        : ruta_(std::move(ruta))
    {}

    void agregar(std::unique_ptr<Actividad> actividad) override
    {
        if (actividad) {
            datos_.push_back(std::move(actividad));
        }
    }

    std::vector<const Actividad*> listar() const override
    {
        std::vector<const Actividad*> resultado;

        for (const auto& actividad : datos_) {
            resultado.push_back(actividad.get());
        }

        return resultado;
    }

    void cargar() override
    {
        datos_.clear();

        QStringList lineas = lector_.leerLineas(ruta_);

        for (const QString& linea : lineas) {

            QStringList columnas = linea.split(';');

            if (columnas.size() != 3) {
                continue;
            }

            DatosActividad datos {
                columnas[2].trimmed(),
                columnas[0].trimmed(),
                QDate::fromString(
                    columnas[1].trimmed(),
                    "dd/MM/yyyy"
                    )
            };

            try {
                agregar(FabricaActividades::crear(datos));
            }
            catch (const std::exception&) {
                continue;
            }
        }
    }

private:

    LectorCsvHeredado lector_;
    QString ruta_;

    std::vector<std::unique_ptr<Actividad>> datos_;
};

#endif