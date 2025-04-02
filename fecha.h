#ifndef FECHA_FECHA_H
#define FECHA_FECHA_H

#include <stdbool.h>

#define ANIO_BASE 1601
#define esBisiesto(anio) (((anio) % 4 == 0 && (anio) % 100 != 0) || (anio) % 400 == 0)

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

Fecha ingresarFecha();
bool esFechaValida(const Fecha* fecha);
int cantDiasMes(int mes, int anio);
Fecha sumarDiasAfecha(const Fecha* fecha, int dias);
int ingresarEnteroPositivo(const char* mensaje);
int _mayorFecha(const Fecha* f1, const Fecha* f2);
int difFechas(const Fecha* f1, const Fecha* f2);

#endif //FECHA_FECHA_H
