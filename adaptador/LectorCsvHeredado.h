#ifndef LECTORCSVHEREDADO_H
#define LECTORCSVHEREDADO_H

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>

class LectorCsvHeredado
{
public:

    QStringList leerLineas(const QString& ruta)
    {
        QFile archivo(ruta);

        if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return {};
        }

        QTextStream entrada(&archivo);

        QStringList lineas;

        while (!entrada.atEnd()) {
            QString linea = entrada.readLine().trimmed();

            if (!linea.isEmpty()) {
                lineas.append(linea);
            }
        }

        return lineas;
    }
};

#endif