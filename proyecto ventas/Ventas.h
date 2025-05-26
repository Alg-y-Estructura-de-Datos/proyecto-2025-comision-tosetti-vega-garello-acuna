#include <iostream>
#include <vector>
#include "Lista.h"
#include "ArbolBinario.h"
#include "HashMap.h"
#include <algorithm>

using namespace std;

struct Venta
{

    int id_venta;
    string fecha;
    string pais;
    string ciudad;
    string cliente;
    string producto;
    string categoria;
    int cantidad;
    double precio_unitario;
    double monto_total;
    string medio_envio;
    string estado_envio;
};

void funcion1(const vector<Venta> &ventas, string paiselegido, string ciudad1, string ciudad2, string ciudad3) // usar arboles binarios
{

    Lista<string> listaC1;
    Lista<string> listaC2;
    Lista<string> listaC3;
    Lista<string> listaTop;

    for (int i = 0; i < ventas.size(); i++)
    {

        /*  Lector de ciudades
        while (ventas[i].pais == "Argentina")
        {
            cout << "CIUDAD: [" << ventas[i].ciudad << "]" << endl;
            break;
        } */

        while (ventas[i].pais == paiselegido)
        {
            string ciudad = ventas[i].ciudad;

            while (ciudad == ciudad1)
            {
                listaC1.insertarUltimo(ciudad);
                break;
            }
            while (ciudad == ciudad2)
            {
                listaC2.insertarUltimo(ciudad);
                break;
            }
            while (ciudad == ciudad3)
            {
                listaC3.insertarUltimo(ciudad);
                break;
            }

            break;
        }
    }

    cout << "Cantidad de ventas por ciudad: " << endl;
    cout << "Ventas de " << ciudad1 << ": " << listaC1.getTamanio() << endl;
    cout << "Ventas de " << ciudad2 << ": " << listaC2.getTamanio() << endl;
    cout << "Ventas de " << ciudad3 << ": " << listaC3.getTamanio() << endl;

    // Primer puesto
    while ((listaC1.getTamanio() > listaC2.getTamanio()) && (listaC1.getTamanio() > listaC3.getTamanio()))
    {
        listaTop.insertarUltimo(ciudad1);
        break;
    }
    while ((listaC2.getTamanio() > listaC1.getTamanio()) && (listaC2.getTamanio() > listaC3.getTamanio()))
    {
        listaTop.insertarUltimo(ciudad2);
        break;
    }
    while ((listaC3.getTamanio() > listaC1.getTamanio()) && (listaC3.getTamanio() > listaC2.getTamanio()))
    {
        listaTop.insertarUltimo(ciudad3);
        break;
    }

    // Segundo puesto
    while (((listaC1.getTamanio() > listaC2.getTamanio()) && (listaC1.getTamanio() < listaC3.getTamanio())) || ((listaC1.getTamanio() < listaC2.getTamanio()) && (listaC1.getTamanio() > listaC3.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad1);
        break;
    }

    while (((listaC2.getTamanio() > listaC1.getTamanio()) && (listaC2.getTamanio() < listaC3.getTamanio())) || ((listaC2.getTamanio() < listaC1.getTamanio()) && (listaC2.getTamanio() > listaC3.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad2);
        break;
    }

    while (((listaC3.getTamanio() > listaC1.getTamanio()) && (listaC3.getTamanio() < listaC2.getTamanio())) || ((listaC3.getTamanio() < listaC1.getTamanio()) && (listaC3.getTamanio() > listaC2.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad3);
        break;
    }

    // Tercer puesto
    while (((listaC1.getTamanio() < listaC2.getTamanio()) && (listaC1.getTamanio() < listaC3.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad1);
        break;
    }
    while (((listaC2.getTamanio() < listaC1.getTamanio()) && (listaC2.getTamanio() < listaC3.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad2);
        break;
    }
    while (((listaC3.getTamanio() < listaC1.getTamanio()) && (listaC3.getTamanio() < listaC2.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad3);
        break;
    }

    cout << endl
         << "El top 5 de ciudades con mayor monto de ventas en " << paiselegido << " :" << endl;
    listaTop.print();
    cout << endl;
}

void funcion2(const vector<Venta> &ventas, string productoElegido)
{
    Lista<string> paises;
    Lista<double> montos;

    for (int i = 0; i < ventas.size(); ++i)
    {

        if (ventas[i].producto == productoElegido)
        {
            int pos = -1;

            for (int j = 0; j < paises.getTamanio(); ++j)
            {
                if (paises.getDato(j) == ventas[i].pais)
                {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
            {
                paises.insertarUltimo(ventas[i].pais);
                montos.insertarUltimo(ventas[i].monto_total);
            }
            else
            {
                double acumulado = montos.getDato(pos);
                montos.reemplazar(pos, acumulado + ventas[i].monto_total);
            }
        }
    }

    cout << "Ventas del producto '" << productoElegido << "' discriminadas por país:" << endl;
    for (int i = 0; i < paises.getTamanio(); ++i)
    {
        cout << paises.getDato(i) << ": $" << montos.getDato(i) << endl;
    }
}

void funcion4(const vector<Venta> &ventas, string paiselegido)
{
    Lista<string> listaM1;
    Lista<string> listaM2;
    Lista<string> listaM3;
    Lista<string> listaTop;

    string envio1 = "Mar�timo";
    string envio2 = "A�reo";
    string envio3 = "Terrestre";

    for (int i = 0; i < ventas.size(); i++)
    {

        while (ventas[i].pais == paiselegido)
        {

            string envio = ventas[i].medio_envio;

            while (envio == envio1)
            {
                listaM1.insertarUltimo(envio);
                break;
            }
            while (envio == envio2)
            {
                listaM2.insertarUltimo(envio);
                break;
            }
            while (envio == envio3)
            {
                listaM3.insertarUltimo(envio);
                break;
            }

            break;
        }
    }

    // Primer puesto
    while ((listaM1.getTamanio() > listaM2.getTamanio()) && (listaM1.getTamanio() > listaM3.getTamanio()))
    {
        listaTop.insertarUltimo(envio1);
        break;
    }
    while ((listaM2.getTamanio() > listaM1.getTamanio()) && (listaM2.getTamanio() > listaM3.getTamanio()))
    {
        listaTop.insertarUltimo(envio2);
        break;
    }
    while ((listaM3.getTamanio() > listaM1.getTamanio()) && (listaM3.getTamanio() > listaM2.getTamanio()))
    {
        listaTop.insertarUltimo(envio3);
        break;
    }

    cout << "El medio de envio mas utilizado en " << paiselegido << " es: " << endl;
    listaTop.print();
    cout << endl;
}

void funcion5(const vector<Venta> &ventas, string categoriaelegida)
{
    Lista<string> listaM1;
    Lista<string> listaM2;
    Lista<string> listaM3;
    Lista<string> listaTop;

    string envio1 = "Mar�timo";
    string envio2 = "A�reo";
    string envio3 = "Terrestre";

    for (int i = 0; i < ventas.size(); i++)
    {

        while (ventas[i].categoria == categoriaelegida)
        {

            string envio = ventas[i].medio_envio;

            while (envio == envio1)
            {
                listaM1.insertarUltimo(envio);
                break;
            }
            while (envio == envio2)
            {
                listaM2.insertarUltimo(envio);
                break;
            }
            while (envio == envio3)
            {
                listaM3.insertarUltimo(envio);
                break;
            }

            break;
        }
    }

    // Primer puesto
    while ((listaM1.getTamanio() > listaM2.getTamanio()) && (listaM1.getTamanio() > listaM3.getTamanio()))
    {
        listaTop.insertarUltimo(envio1);
        break;
    }
    while ((listaM2.getTamanio() > listaM1.getTamanio()) && (listaM2.getTamanio() > listaM3.getTamanio()))
    {
        listaTop.insertarUltimo(envio2);
        break;
    }
    while ((listaM3.getTamanio() > listaM1.getTamanio()) && (listaM3.getTamanio() > listaM2.getTamanio()))
    {
        listaTop.insertarUltimo(envio3);
        break;
    }

    cout << "El medio de envio mas utilizado en la categoria " << categoriaelegida << " es: " << endl;
    listaTop.print();

    cout << endl;
}

void funcion7(const vector<Venta> &ventas, string paiselegido)
{
    Lista<string> listaE1;
    Lista<string> listaE2;
    Lista<string> listaE3;
    Lista<string> listaE4;
    Lista<string> listaTop;

    string estadoenvio1 = "Cancelado";
    string estadoenvio2 = "Entregado";
    string estadoenvio3 = "En tr�nsito";
    string estadoenvio4 = "Pendiente";

    for (int i = 0; i < ventas.size(); i++)
    {

        while (ventas[i].pais == paiselegido)
        {

            string estadoenvio = ventas[i].estado_envio;

            while (estadoenvio == estadoenvio1)
            {
                listaE1.insertarUltimo(estadoenvio);
                break;
            }
            while (estadoenvio == estadoenvio2)
            {
                listaE2.insertarUltimo(estadoenvio);
                break;
            }
            while (estadoenvio == estadoenvio3)
            {
                listaE3.insertarUltimo(estadoenvio);
                break;
            }
            while (estadoenvio == estadoenvio4)
            {
                listaE4.insertarUltimo(estadoenvio);
                break;
            }

            break;
        }
    }

    // Primer puesto
    while ((listaE1.getTamanio() > listaE2.getTamanio()) && (listaE1.getTamanio() > listaE3.getTamanio()))
    {
        listaTop.insertarUltimo(estadoenvio1);
        break;
    }
    while ((listaE2.getTamanio() > listaE1.getTamanio()) && (listaE2.getTamanio() > listaE3.getTamanio()))
    {
        listaTop.insertarUltimo(estadoenvio2);
        break;
    }
    while ((listaE3.getTamanio() > listaE1.getTamanio()) && (listaE3.getTamanio() > listaE2.getTamanio()))
    {
        listaTop.insertarUltimo(estadoenvio3);
        break;
    }

    cout << "El estado de envio mas frecuente en " << paiselegido << " es: " << endl;
    listaTop.print();
    cout << endl;
}

void funcion8(const vector<Venta> &ventas)
{

    int cantidadtotal1 = 0;
    int cantidadtotal2 = 0;
    int cantidadtotal3 = 0;
    int cantidadtotal4 = 0;
    int cantidadtotal5 = 0;
    int cantidadtotal6 = 0;
    int cantidadtotal7 = 0;
    int cantidadtotal8 = 0;
    int cantidadtotal9 = 0;
    int cantidadtotal10 = 0;

    for (int i = 0; i < ventas.size(); i++)
    {
        while (ventas[i].producto == "Auriculares")
        {

            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal1 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Celular")
        {

            cantidadtotal2 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Camara")
        {

            cantidadtotal3 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Escritorio")
        {

            cantidadtotal4 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Impresora")
        {

            cantidadtotal5 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Laptop")
        {

            cantidadtotal6 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Monitor")
        {

            cantidadtotal7 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Silla ergonomica")
        {

            cantidadtotal8 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Tablet")
        {

            cantidadtotal9 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Teclado")
        {

            cantidadtotal10 += ventas[i].cantidad;
            break;
        }
    }

    // No usar HashMap con cantidad total como clave para evitar errores
    // Hacemos un arreglo paralelo para producto y cantidad para buscar el máximo

    string productos[10] = {
        "Auriculares", "Celular", "Camara", "Escritorio", "Impresora",
        "Laptop", "Monitor", "Silla ergonomica", "Tablet", "Teclado"};

    int cantidades[10] = {
        cantidadtotal1, cantidadtotal2, cantidadtotal3, cantidadtotal4, cantidadtotal5,
        cantidadtotal6, cantidadtotal7, cantidadtotal8, cantidadtotal9, cantidadtotal10};

    int maxCantidad = cantidades[0];
    int indiceMax = 0;

    for (int i = 1; i < 10; i++)
    {
        if (cantidades[i] > maxCantidad)
        {
            maxCantidad = cantidades[i];
            indiceMax = i;
        }
    }

    cout << "El producto mas vendido es " << productos[indiceMax] << " con una cantidad de " << maxCantidad << " unidades." << endl;
}

void funcion6(const vector<Venta> &ventas)
{
    double maxMonto = 0;
    string fechamax = "";

    int i = 0;
    while (i < ventas.size())
    {
        while (ventas[i].monto_total > maxMonto)
        {
            maxMonto = ventas[i].monto_total;
            fechamax = ventas[i].fecha;
            break;
        }
        i++;
    }

    cout << "El monto maximo es " << maxMonto << " del dia " << fechamax << endl;
}

void funcion9(const vector<Venta> &ventas)
{

    int cantidadtotal1 = 0;
    int cantidadtotal2 = 0;
    int cantidadtotal3 = 0;
    int cantidadtotal4 = 0;
    int cantidadtotal5 = 0;
    int cantidadtotal6 = 0;
    int cantidadtotal7 = 0;
    int cantidadtotal8 = 0;
    int cantidadtotal9 = 0;
    int cantidadtotal10 = 0;

    for (int i = 0; i < ventas.size(); i++)
    {
        while (ventas[i].producto == "Auriculares")
        {

            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal1 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Celular")
        {

            cantidadtotal2 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "C�mara")
        {

            cantidadtotal3 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Escritorio")
        {

            cantidadtotal4 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Impresora")
        {

            cantidadtotal5 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Laptop")
        {

            cantidadtotal6 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Monitor")
        {

            cantidadtotal7 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Silla ergon�mica")
        {

            cantidadtotal8 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Tablet")
        {

            cantidadtotal9 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Teclado")
        {

            cantidadtotal10 += ventas[i].cantidad;
            break;
        }
    }

    // No usar HashMap con cantidad total como clave para evitar errores
    // Hacemos un arreglo paralelo para producto y cantidad para buscar el máximo

    string productos[10] = {
        "Auriculares", "Celular", "C�mara", "Escritorio", "Impresora",
        "Laptop", "Monitor", "Silla ergon�mica", "Tablet", "Teclado"};

    int cantidades[10] = {
        cantidadtotal1, cantidadtotal2, cantidadtotal3, cantidadtotal4, cantidadtotal5,
        cantidadtotal6, cantidadtotal7, cantidadtotal8, cantidadtotal9, cantidadtotal10};

    int minCantidad = cantidades[0];
    int indiceMin = 100;

    for (int i = 1; i < 10; i++)
    {
        if (cantidades[i] < minCantidad)
        {
            minCantidad = cantidades[i];
            indiceMin = i;
        }
    }

    cout << "El producto menos vendido es " << productos[indiceMin] << " con una cantidad de " << minCantidad << " unidades." << endl;
}
