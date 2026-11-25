#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../modelo/Actividad.h"

#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>

#include <vector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget* parent = nullptr);

signals:

    void crearSolicitado(const DatosActividad& datos);

    void cargarSolicitado();

public slots:

    void mostrar(
        const std::vector<const Actividad*>& actividades
        );

    void mostrarError(const QString& mensaje);

private:

    QLineEdit* tituloInput;

    QComboBox* tipoCombo;

    QDateEdit* fechaInput;

    QPushButton* agregarButton;

    QPushButton* cargarButton;

    QListWidget* listaActividades;

    QLabel* estadoLabel;

    void configurarInterfaz();

private slots:

    void solicitarCrear();

};

#endif