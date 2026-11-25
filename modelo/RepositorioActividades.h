#ifndef REPOSITORIOACTIVIDADES_H
#define REPOSITORIOACTIVIDADES_H

#include "IRepositorio.h"

#include <memory>
#include <vector>

class RepositorioActividades : public IRepositorio
{
public:

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
        // La importación CSV se realiza mediante AdaptadorCsv.
    }

private:

    std::vector<std::unique_ptr<Actividad>> datos_;
};

#endif