#include <QApplication>
#include <QDir>
#include <QCoreApplication>

#include "vista/MainWindow.h"
#include "controlador/ActividadController.h"
#include "adaptador/AdaptadorCsv.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString rutaCsv = QDir::cleanPath(
        QCoreApplication::applicationDirPath()
        + "/../../datos/actividades.csv"
        );

    AdaptadorCsv repositorio(rutaCsv);

    ActividadController controlador(&repositorio);

    MainWindow ventana;

    QObject::connect(
        &ventana,
        &MainWindow::crearSolicitado,
        &controlador,
        &ActividadController::crear
        );

    QObject::connect(
        &ventana,
        &MainWindow::cargarSolicitado,
        &controlador,
        &ActividadController::cargar
        );

    QObject::connect(
        &controlador,
        &ActividadController::listaActualizada,
        &ventana,
        &MainWindow::mostrar
        );

    QObject::connect(
        &controlador,
        &ActividadController::errorOcurrido,
        &ventana,
        &MainWindow::mostrarError
        );

    ventana.show();

    return app.exec();
}