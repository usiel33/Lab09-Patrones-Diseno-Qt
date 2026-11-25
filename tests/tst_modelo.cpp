#include <QtTest>
#include <stdexcept>

#include "../modelo/FabricaActividades.h"
#include "../modelo/RepositorioActividades.h"
#include "../controlador/ActividadController.h"

class TestModelo : public QObject
{
    Q_OBJECT

private slots:

    void fabricaCreaTipoCorrecto()
    {
        auto actividad = FabricaActividades::crear({
            "examen",
            "Parcial",
            QDate(2026, 12, 1)
        });

        QCOMPARE(
            actividad->tipo(),
            QString("examen")
            );
    }

    void fabricaRechazaTituloVacio()
    {
        QVERIFY_EXCEPTION_THROWN(
            FabricaActividades::crear({
                "tarea",
                "",
                QDate(2026, 12, 1)
            }),
            std::invalid_argument
            );
    }

    void crearAgregaAlRepositorio()
    {
        RepositorioActividades repositorio;

        ActividadController controlador(&repositorio);

        controlador.crear({
            "proyecto",
            "Lab 9",
            QDate(2026, 12, 5)
        });

        QCOMPARE(
            repositorio.listar().size(),
            size_t(1)
            );
    }
};

QTEST_APPLESS_MAIN(TestModelo)

#include "tst_modelo.moc"