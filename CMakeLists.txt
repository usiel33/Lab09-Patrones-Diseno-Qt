cmake_minimum_required(VERSION 3.16)

project(Lab09 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Test)

# Aplicacion principal
add_executable(Lab09

    main.cpp

    vista/MainWindow.h
    vista/MainWindow.cpp

    controlador/ActividadController.h
    controlador/ActividadController.cpp

    modelo/Actividad.h
    modelo/Tarea.h
    modelo/Examen.h
    modelo/Proyecto.h
    modelo/FabricaActividades.h
    modelo/IRepositorio.h
    modelo/RepositorioActividades.h

    adaptador/LectorCsvHeredado.h
    adaptador/AdaptadorCsv.h
)

target_link_libraries(Lab09
    PRIVATE Qt6::Widgets
)

# Pruebas sin interfaz grafica
enable_testing()

add_executable(tst_modelo

    tests/tst_modelo.cpp

    controlador/ActividadController.h
    controlador/ActividadController.cpp

    modelo/Actividad.h
    modelo/Tarea.h
    modelo/Examen.h
    modelo/Proyecto.h
    modelo/FabricaActividades.h
    modelo/IRepositorio.h
    modelo/RepositorioActividades.h
)

target_link_libraries(tst_modelo
    PRIVATE
    Qt6::Core
    Qt6::Test
)

add_test(
    NAME PruebasModelo
    COMMAND tst_modelo
)