#include "fecha.h"

#include <stdio.h>

Fecha ingresarFecha()
{
    Fecha fecha;
    puts("Ingrese la fecha con el formato dd/mm/aaaa\n");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    while(!esFechaValida(&fecha))
    {
        puts("No es fecha valida. Ingrese la fecha con el formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    }
    return fecha;
}

bool esFechaValida(const Fecha* fecha)
{
    if(fecha->anio >= ANIO_BASE)
        if(fecha->mes >= 1 && fecha->mes <= 12)
            if(fecha->dia >=1 && fecha->dia <= cantDiasMes(fecha->mes, fecha->anio))
                return true;

    return false;
}

int cantDiasMes(int mes, int anio)
{
    int cdm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(mes == 2 && esBisiesto(anio))
        return 29;
    else
        return cdm[mes];
}

Fecha sumarDiasAfecha(const Fecha* fecha, int dias)
{
    Fecha fechaSumada;
    fechaSumada.anio = fecha->anio;
    fechaSumada.mes = fecha->mes;
    fechaSumada.dia = fecha->dia + dias;

    while(fechaSumada.dia > cantDiasMes(fechaSumada.mes, fechaSumada.anio))
    {
        fechaSumada.dia -= cantDiasMes(fechaSumada.mes, fechaSumada.anio);
        fechaSumada.mes++;
        if(fechaSumada.mes == 13)
        {
            fechaSumada.mes = 1;
            fechaSumada.anio++;
        }
    }
    return fechaSumada;
}

int ingresarEnteroPositivo(const char* mensaje)
{
    int n;
    puts(mensaje);
    scanf("%d", &n);

    if(n <= 0)
    {
        puts("Ingreso no valid\n");
        puts(mensaje);
        scanf("%d", &n);
    }
    return n;
}


int _mayorFecha(const Fecha* f1, const Fecha* f2)
{
    if(f1->anio > f2->anio)
        return 1;
    if((f1->anio == f2->anio) && (f1->mes > f2->mes))
        return 1;
    if((f1->anio == f2->anio) && (f1->mes == f2->mes) && (f1->dia > f2->dia))
        return 1;
    if((f1->anio == f2->anio) && (f1->mes == f2->mes) && (f1->dia == f2->dia))
        return 0;

    return 2;
}


int difFechas(const Fecha* f1, const Fecha* f2)
{
    int mayor = _mayorFecha(f1, f2);
    Fecha fParametro;
    int contador = 0;

    if(mayor == 1)
    {
        fParametro = *f2;
        while((fParametro.anio != f1->anio) || (fParametro.mes != f1->mes) || (fParametro.dia != f1->dia))
        {
            fParametro = sumarDiasAfecha(&fParametro,1);
            contador++;
        }
    }

    if(mayor == 2)
    {
        fParametro = *f1;

        while((fParametro.anio != f2->anio) || (fParametro.mes != f2->mes) || (fParametro.dia != f2->dia))
        {
            fParametro = sumarDiasAfecha(&fParametro,1);
            contador++;
        }
        contador *= -1;
    }

    return contador;
}

void mostrarDiaDeLaSemana(int diaDeLaSemana)
{
    char diasSemana[7][10] =
            {
            "Domingo",
            "Lunes",
            "Martes",
            "Miercoles",
            "Jueves",
            "Viernes",
            "Sabado",
            };

    printf("%s", diasSemana[diaDeLaSemana]);
}