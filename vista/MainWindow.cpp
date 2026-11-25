#include "MainWindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QDate>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    configurarInterfaz();

    connect(
        agregarButton,
        &QPushButton::clicked,
        this,
        &MainWindow::solicitarCrear
        );

    connect(
        cargarButton,
        &QPushButton::clicked,
        this,
        [this]() {
            emit cargarSolicitado();
        }
        );
}

void MainWindow::configurarInterfaz()
{
    setWindowTitle("Sistema de Seguimiento Academico");

    resize(800, 600);

    QWidget* central = new QWidget(this);

    setCentralWidget(central);

    QVBoxLayout* principal = new QVBoxLayout(central);

    QLabel* titulo = new QLabel(
        "SEGUIMIENTO ACADEMICO"
        );

    titulo->setAlignment(Qt::AlignCenter);

    titulo->setStyleSheet(
        "font-size: 24px;"
        "font-weight: bold;"
        "color: #2457A7;"
        "padding: 15px;"
        );

    principal->addWidget(titulo);

    QFormLayout* formulario = new QFormLayout();

    tituloInput = new QLineEdit();

    tituloInput->setPlaceholderText(
        "Ingrese el nombre de la actividad"
        );

    tipoCombo = new QComboBox();

    tipoCombo->addItems({
        "Tarea",
        "Examen",
        "Proyecto"
    });

    fechaInput = new QDateEdit();

    fechaInput->setCalendarPopup(true);

    fechaInput->setDisplayFormat("dd/MM/yyyy");

    fechaInput->setDate(QDate::currentDate());

    formulario->addRow("Nombre:", tituloInput);

    formulario->addRow("Tipo:", tipoCombo);

    formulario->addRow("Fecha:", fechaInput);

    principal->addLayout(formulario);

    QHBoxLayout* botones = new QHBoxLayout();

    agregarButton = new QPushButton(
        "Agregar actividad"
        );

    cargarButton = new QPushButton(
        "Importar CSV"
        );

    agregarButton->setStyleSheet(
        "background-color: #246BCE;"
        "color: white;"
        "padding: 10px;"
        "font-weight: bold;"
        );

    cargarButton->setStyleSheet(
        "background-color: #16865C;"
        "color: white;"
        "padding: 10px;"
        "font-weight: bold;"
        );

    botones->addWidget(agregarButton);

    botones->addWidget(cargarButton);

    principal->addLayout(botones);

    QLabel* subtitulo = new QLabel(
        "LISTA DE ACTIVIDADES"
        );

    subtitulo->setStyleSheet(
        "font-size: 17px;"
        "font-weight: bold;"
        "padding-top: 15px;"
        );

    principal->addWidget(subtitulo);

    listaActividades = new QListWidget();

    principal->addWidget(listaActividades);

    estadoLabel = new QLabel(
        "Sistema preparado."
        );

    principal->addWidget(estadoLabel);
}

void MainWindow::solicitarCrear()
{
    DatosActividad datos;

    datos.titulo = tituloInput->text();

    datos.tipo = tipoCombo->currentText().toLower();

    datos.fecha = fechaInput->date();

    emit crearSolicitado(datos);
}

void MainWindow::mostrar(
    const std::vector<const Actividad*>& actividades
    )
{
    listaActividades->clear();

    for (const Actividad* actividad : actividades) {

        QString texto =
            actividad->tipo()
            + " | "
            + actividad->titulo()
            + " | "
            + actividad->fecha().toString("dd/MM/yyyy");

        listaActividades->addItem(texto);
    }

    estadoLabel->setText(
        QString("Total de actividades: %1")
            .arg(actividades.size())
        );
}

void MainWindow::mostrarError(const QString& mensaje)
{
    QMessageBox::warning(
        this,
        "Error",
        mensaje
        );
}