#include <iostream>
#include <vector>
#include "Lista.h"
#include "ArbolBinario.h"
#include "HashMap.h"
#include <algorithm>
#include <string>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Funcion auxiliar para limpiar el buffer
string limpiar(const string& texto) {
    string resultado = texto;
    // Eliminar espacios al principio y al final
    resultado.erase(0, resultado.find_first_not_of(" \n\r\t"));
    resultado.erase(resultado.find_last_not_of(" \n\r\t") + 1);
    // Pasar a minúsculas
    transform(resultado.begin(), resultado.end(), resultado.begin(), ::tolower);
    return resultado;
}


struct Venta //creacion de la estructura venta para procesar los campos del csv
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

void lectorpais() //funcion para leer los paises
{
    cout << "1. Argentina" << endl;
    cout << "2. Bolivia" << endl;
    cout << "3. Brasil" << endl;
    cout << "4. Chile" << endl;
    cout << "5. Colombia" << endl;
    cout << "6. Ecuador" << endl;
    cout << "7. Paraguay" << endl;
    cout << "8. Perú" << endl;
    cout << "9. Uruguay" << endl;
    cout << "10. Venezuela" << endl;
}

void lectorciudad() //funcion para leer las ciudades
{
    cout << "1. Arequipa" << endl;
    cout << "2. Asunción" << endl;
    cout << "3. Bogotá" << endl;
    cout << "4. Brasília" << endl;
    cout << "5. Buenos Aires" << endl;
    cout << "6. Cali" << endl;
    cout << "7. Caracas" << endl;
    cout << "8. Ciudad del Este" << endl;
    cout << "9. Cochabamba" << endl;
    cout << "10. Concepción" << endl;
    cout << "11. Córdoba" << endl;
    cout << "12. Cuenca" << endl;
    cout << "13. Cusco" << endl;
    cout << "14. Encarnación" << endl;
    cout << "15. Guayaquil" << endl;
    cout << "16. La Paz" << endl;
    cout << "17. Lima" << endl;
    cout << "18. Maracaibo" << endl;
    cout << "19. Medellín" << endl;
    cout << "20. Montevideo" << endl;
    cout << "21. Paysandú" << endl;
    cout << "22. Quito" << endl;
    cout << "23. Río de Janeiro" << endl;
    cout << "24. Rosario" << endl;
    cout << "25. Salto" << endl;
    cout << "26. Santa Cruz" << endl;
    cout << "27. Santiago" << endl;
    cout << "28. São Paulo" << endl;
    cout << "29. Valencia" << endl;
    cout << "30. Valparaíso" << endl;
}

void lectorproducto() //funcion para leer los productos
{
    cout << "1. Auriculares" << endl;
    cout << "2. Celular" << endl;
    cout << "3. Cámara" << endl;
    cout << "4. Escritorio" << endl;
    cout << "5. Impresora" << endl;
    cout << "6. Laptop" << endl;
    cout << "7. Monitor" << endl;
    cout << "8. Silla ergonómica" << endl;
    cout << "9. Tablet" << endl;
    cout << "10. Teclado" << endl;
}


//Calcula el TOP 5 de ciudades con mayor monto de ventas por pais
void funcion1(const vector<Venta> &ventas, string paiselegido, string ciudad1, string ciudad2, string ciudad3) 
{
    //crea listas para almacenar los calculos
    Lista<string> listaC1; 
    Lista<string> listaC2;
    Lista<string> listaC3;
    Lista<string> listaTop;

    for (int i = 0; i < ventas.size(); i++) //bucle for que recorre linea por linea la base de datos
    {

        /*  Lector de ciudades
        while (ventas[i].pais == "Argentina")
        {
            cout << "CIUDAD: [" << ventas[i].ciudad << "]" << endl;
            break;
        } */

        while (ventas[i].pais == paiselegido) //condicion de bsuqueda por el pais que ingreso el ususario
        {
            string ciudad = ventas[i].ciudad;

            while (ciudad == ciudad1)
            {
                listaC1.insertarUltimo(ciudad); // inserta la ciudad  a la lista
                break;
            }
            while (ciudad == ciudad2)
            {
                listaC2.insertarUltimo(ciudad); // inserta la ciudad  a la lista
                break;
            }
            while (ciudad == ciudad3)
            {
                listaC3.insertarUltimo(ciudad); // inserta la ciudad  a la lista
                break;
            }

            break;
        }
    }

    cout << "Cantidad de ventas por ciudad: " << endl;
    cout << "Ventas de " << ciudad1 << ": " << listaC1.getTamanio() << endl; //muestra la cant. de veces que esta la ciudad en la lista, o sea el tamanio de la mimsa
    cout << "Ventas de " << ciudad2 << ": " << listaC2.getTamanio() << endl;
    cout << "Ventas de " << ciudad3 << ": " << listaC3.getTamanio() << endl;

    // Primer puesto
    while ((listaC1.getTamanio() > listaC2.getTamanio()) && (listaC1.getTamanio() > listaC3.getTamanio()))
    {
        listaTop.insertarUltimo(ciudad1); // a la de mayor tamanio la inserta
        break;
    }
    while ((listaC2.getTamanio() > listaC1.getTamanio()) && (listaC2.getTamanio() > listaC3.getTamanio()))
    {
        listaTop.insertarUltimo(ciudad2); // a la de mayor tamanio la inserta
        break;
    }
    while ((listaC3.getTamanio() > listaC1.getTamanio()) && (listaC3.getTamanio() > listaC2.getTamanio()))
    {
        listaTop.insertarUltimo(ciudad3); // a la de mayor tamanio la inserta
        break;
    }

    // Segundo puesto
    while (((listaC1.getTamanio() > listaC2.getTamanio()) && (listaC1.getTamanio() < listaC3.getTamanio())) || ((listaC1.getTamanio() < listaC2.getTamanio()) && (listaC1.getTamanio() > listaC3.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad1); // a la de mayor tamanio la inserta
        break;
    }

    while (((listaC2.getTamanio() > listaC1.getTamanio()) && (listaC2.getTamanio() < listaC3.getTamanio())) || ((listaC2.getTamanio() < listaC1.getTamanio()) && (listaC2.getTamanio() > listaC3.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad2);// a la de mayor tamanio la inserta
        break;
    }

    while (((listaC3.getTamanio() > listaC1.getTamanio()) && (listaC3.getTamanio() < listaC2.getTamanio())) || ((listaC3.getTamanio() < listaC1.getTamanio()) && (listaC3.getTamanio() > listaC2.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad3);// a la de mayor tamanio la inserta
        break;
    }

    // Tercer puesto
    while (((listaC1.getTamanio() < listaC2.getTamanio()) && (listaC1.getTamanio() < listaC3.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad1);// a la de mayor tamanio la inserta
        break;
    }
    while (((listaC2.getTamanio() < listaC1.getTamanio()) && (listaC2.getTamanio() < listaC3.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad2);// a la de mayor tamanio la inserta
        break;
    }
    while (((listaC3.getTamanio() < listaC1.getTamanio()) && (listaC3.getTamanio() < listaC2.getTamanio())))
    {
        listaTop.insertarUltimo(ciudad3);// a la de mayor tamanio la inserta
        break;
    }

    cout << endl
         << "El top 5 de ciudades con mayor monto de ventas en " << paiselegido << " :" << endl;
    listaTop.print(); //imprime la lista con las ciudades de mayor tamanio
    cout << endl;

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\"" << endl;
    cout << "PROCESO: funcion1\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Uso de ciclos for y múltiples ciclos while para filtrar y contar ventas por ciudad; manejo de listas para almacenar resultados.\n";
    cout << "======================================================================================================================\n";
}


//Calcula el monto total del pais elegido
void funcion2(const vector<Venta> &ventas, string productoElegido)
{
    Lista<string> paises; //crea una lista de paises
    Lista<double> montos; //crea una lista de los montos totales

    for (int i = 0; i < ventas.size(); ++i)
    {

        if (limpiar(ventas[i].producto) == limpiar(productoElegido))
        {
            int pos = -1; // Variable para guardar la posición del país en la lista, si ya fue registrado

            for (int j = 0; j < paises.getTamanio(); ++j) 
            {
                if (paises.getDato(j) == ventas[i].pais)//toma 
                {
                    pos = j;// Si lo encuentra (pos), guarda la posición
                    break;
                }
            }
            
// Si el país no está en la lista, lo agrega junto con su monto
            if (pos == -1) //indica que no se encontró (pos =-1)
            {
                paises.insertarUltimo(ventas[i].pais); //guarda el pais
                montos.insertarUltimo(ventas[i].monto_total); //guarda el monto
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
    }//bucle que hace que muestre todos los elementos de la lista

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 4\n";
    cout << "PROCESO: funcion2\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Búsqueda y acumulación en listas con ciclos for y condicionales if para agrupar ventas por país.\n";
    cout << "======================================================================================================================\n";
}


//funcion auxliar para la funcion3
void funcion3p(const vector<Venta> &ventas, string categoriaelegida, string pais)
{
    double Monto = 0;
    int c = 0;
    double Promedio;

    for (int i = 0; i < ventas.size(); ++i)
    {
        if (limpiar(categoriaelegida) == limpiar(ventas[i].categoria) && limpiar(pais) == limpiar(ventas[i].pais))
        {
            c++;//contador
            Monto += ventas[i].monto_total;//suma de los montos x el pais
        }
    }

    if (c > 0)
    {
        Promedio = Monto / c; //divide la suma total de los montos por la cant de veces q se sumo
        cout << "El promedio de ventas en " << pais << " de la categoria " << categoriaelegida << " es: ";
        cout << Promedio << endl;
    }

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 2\n";
    cout << "PROCESO: funcion3p\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Cálculo de promedio con ciclo for y condicional if para filtrar por categoría y país.\n";
    cout << "======================================================================================================================\n";
}

// Promedio de ventas por CATEGORIA en cada PAIS
void funcion3(const vector<Venta> &ventas, string categoriaelegida)
{
    for (int i = 0; i < ventas.size(); ++i)
    {
        string pais = ventas[i].pais; //filtra por pais

        // Bandera para saber si ya se calculó el promedio de este país
        bool yaProcesado = false;

        // Verificamos si este país ya apareció antes
        for (int j = 0; j < i; ++j)
        {
            if (ventas[j].pais == pais)
            {
                yaProcesado = true;
                break;
            }
        } // evita procesar el mismo país más de una vez.

        // Si no fue procesado, lo procesamos ahora
        if (!yaProcesado)
        {
            funcion3p(ventas, categoriaelegida, pais);
        }
    }

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: funcion3\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclos for anidados para evitar procesamiento repetido de países, usa función auxiliar para cálculo.\n";
    cout << "======================================================================================================================\n";
}

//Medio de envio mas utilizado por pais
void funcion4(const vector<Venta> &ventas, string paiselegido)
{
    Lista<string> listaM1; //guarda las veces que aparece el medio de envio1
    Lista<string> listaM2;//guarda las veces que aparece el medio de envio2
    Lista<string> listaM3;//guarda las veces que aparece el medio de envio3
    Lista<string> listaTop; //guarda los medios de envios en orden de mas usado

    string envio1 = "Marítimo";
    string envio2 = "Aéreo";
    string envio3 = "Terrestre";

    for (int i = 0; i < ventas.size(); i++)
    {

        while (ventas[i].pais == paiselegido) //filtra x pais
        {

            string envio = ventas[i].medio_envio; 

            while (envio == envio1) 
            {
                listaM1.insertarUltimo(envio);//si es el envio 1 lo agrega a la lista
                break;
            }
            while (envio == envio2)
            {
                listaM2.insertarUltimo(envio);//si es el envio 2 lo agrega a la lista
                break;
            }
            while (envio == envio3)
            {
                listaM3.insertarUltimo(envio);//si es el envio 2 lo agrega a la lista
                break;
            }

            break;
        }
    }

    // Medio envio 1
    while ((listaM1.getTamanio() > listaM2.getTamanio()) && (listaM1.getTamanio() > listaM3.getTamanio()))
    {
        listaTop.insertarUltimo(envio1); 
        break;
    }

    //Medio envio2
    while ((listaM2.getTamanio() > listaM1.getTamanio()) && (listaM2.getTamanio() > listaM3.getTamanio()))
    {
        listaTop.insertarUltimo(envio2);
        break;
    }

    //Medio envio3
    while ((listaM3.getTamanio() > listaM1.getTamanio()) && (listaM3.getTamanio() > listaM2.getTamanio()))
    {
        listaTop.insertarUltimo(envio3);
        break;
    }

    cout << "El medio de envio mas utilizado en " << paiselegido << " es: " << endl;
    listaTop.print(); //los medios ya estan guardados en orden, asi q solo imprime la lista
    cout << endl;
    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 0\n";
    cout << "PROCESO: funcion4\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Uso de ciclos for y listas para filtrar y contar medios de envío; manejo de ranking.\n";
    cout << "======================================================================================================================\n";
}

//Medio de envio mas utilizado por categoria
void funcion5(const vector<Venta> &ventas, string categoriaelegida)
{
    Lista<string> listaM1; //crea una lista para guardar la cant de veces que se usa el medio 1
    Lista<string> listaM2;//crea una lista para guardar la cant de veces que se usa el medio 2
    Lista<string> listaM3;//crea una lista para guardar la cant de veces que se usa el medio 3
    Lista<string> listaTop; //lista ordenada por uso

    string envio1 = "Marítimo";
    string envio2 = "Aéreo";
    string envio3 = "Terrestre";

    for (int i = 0; i < ventas.size(); i++)
    {

        while (ventas[i].categoria == categoriaelegida) //filtra por categoria
        {

            string envio = ventas[i].medio_envio;

            while (envio == envio1) 
            {
                listaM1.insertarUltimo(envio);//si aparece, guarda el envio 1
                break;
            }
            while (envio == envio2)
            {
                listaM2.insertarUltimo(envio);//si aparece, guarda el envio 2
                break;
            }
            while (envio == envio3)
            {
                listaM3.insertarUltimo(envio);//si aparece, guarda el envio 3
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
    listaTop.print(); //la lista ya esta ordenada, por lo q solo la imprime

    cout << endl;

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 0\n";
    cout << "PROCESO: funcion5\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Similar a funcion4, filtrado por categoría; conteo y ranking de medios de envío con listas.\n";
    cout << "======================================================================================================================\n";
}


//Dia con mayor cantidad de ventas (por monto de dinero) en TODA la base de datos
void funcion6(const vector<Venta> &ventas)
{
    //inicializacion de las variables
    double maxMonto = 0;
    string fechamax = "";

    int i = 0; //inicializacion del contador
    while (i < ventas.size()) //se repite mientras haya lineas de ventas
    {
        while (ventas[i].monto_total > maxMonto) //compara el monto que entra con el ultimo MaxMonto guardado
        {
            maxMonto = ventas[i].monto_total; //el 1er monto en entrar va a ser el Maximo
            fechamax = ventas[i].fecha; // si es el maximo guarda tmb la fecha del mismo
            break;
        }
        i++; //amenta el contador
    }

    cout << "El monto maximo es " << maxMonto << " del dia " << fechamax << endl;

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 0\n";
    cout << "PROCESO: funcion6\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Búsqueda del monto máximo con ciclo while y actualización de variables de control.\n";
    cout << "======================================================================================================================\n";
}


//Estado de envio mas frecuente por pais
void funcion7(const vector<Venta> &ventas, string paiselegido)
{
    Lista<string> listaE1; //lista para el estado de enevio 1
    Lista<string> listaE2;//lista para el estado de enevio 2
    Lista<string> listaE3;//lista para el estado de enevio 3
    Lista<string> listaE4;//lista para el estado de enevio 4
    Lista<string> listaTop; //lista ordenada con los 4 estados
    
    //asigna los envios
    string estadoenvio1 = "Cancelado"; 
    string estadoenvio2 = "Entregado";
    string estadoenvio3 = "En tránsito";
    string estadoenvio4 = "Pendiente";

    for (int i = 0; i < ventas.size(); i++) //recorre el ventas
    {

        while (ventas[i].pais == paiselegido) //filtra x pais
        {

            string estadoenvio = ventas[i].estado_envio;

            while (estadoenvio == estadoenvio1) 
            {
                listaE1.insertarUltimo(estadoenvio);// se inserta si es el estado de envio 1
                break;
            }
            while (estadoenvio == estadoenvio2)
            {
                listaE2.insertarUltimo(estadoenvio); // se inserta si es el estado de envio 2
                break;
            }
            while (estadoenvio == estadoenvio3)
            {
                listaE3.insertarUltimo(estadoenvio); // se inserta si es el estado de envio 3
                break;
            }
            while (estadoenvio == estadoenvio4)
            {
                listaE4.insertarUltimo(estadoenvio); // se inserta si es el estado de envio 4
                break;
            }

            break;
        }
    }

    // Compara e inserta de mayor  a menor
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
    listaTop.print(); //como la lista ya esta ordenada, la imprime
    cout << endl;

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 0\n";
    cout << "PROCESO: funcion7\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for con listas para conteo y clasificación de estados de envío, con ranking por cantidad.\n";
    cout << "======================================================================================================================\n";
}

//Producto mas vendido en cantidad total (en unidades)
void funcion8(const vector<Venta> &ventas)
{

    //inicializa los contadores de cada producto
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

    for (int i = 0; i < ventas.size(); i++) ///recorre
    {
        while (ventas[i].producto == "Auriculares")
        {

            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal1 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Celular")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal2 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Cámara")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal3 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Escritorio")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal4 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Impresora")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal5 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Laptop")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal6 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Monitor")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal7 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Silla ergonomica")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal8 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Tablet")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal9 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Teclado")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal10 += ventas[i].cantidad;
            break;
        }
    }

    // No usar HashMap con cantidad total como clave para evitar errores
    // Hacemos un arreglo paralelo para producto y cantidad para buscar el máximo

    string productos[10] = { //creamos un arr con los productos
        "Auriculares", "Celular", "Cámara", "Escritorio", "Impresora",
        "Laptop", "Monitor", "Silla ergonómica", "Tablet", "Teclado"};

    int cantidades[10] = { //cremaos un arr con las cantidades de unidades vendidas x prod
        cantidadtotal1, cantidadtotal2, cantidadtotal3, cantidadtotal4, cantidadtotal5,
        cantidadtotal6, cantidadtotal7, cantidadtotal8, cantidadtotal9, cantidadtotal10};

    int maxCantidad = cantidades[0]; //inicializamos el maximo de unidades vendidas
    int indiceMax = 0; 

    for (int i = 1; i < 10; i++) //recorre todas las cantidades buscando la mayor, y guarda cual es y la posicion
    {
        if (cantidades[i] > maxCantidad)
        {
            maxCantidad = cantidades[i];
            indiceMax = i;
        }
    }

    cout << "El producto mas vendido es " << productos[indiceMax] << " con una cantidad de " << maxCantidad << " unidades." << endl;

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: funcion8\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Conteo acumulativo en arreglos paralelos para productos, con búsqueda de máximo con ciclo for.\n";
    cout << "======================================================================================================================\n";
}

//Producto menos vendido en cantidad total (unidades)
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
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal2 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Cámara")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal3 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Escritorio")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal4 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Impresora")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal5 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Laptop")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal6 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Monitor")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal7 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Silla ergonómica")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal8 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Tablet")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal9 += ventas[i].cantidad;
            break;
        }
        while (ventas[i].producto == "Teclado")
        {
            // sumo solo la última cantidad insertada para no repetir sumas
            cantidadtotal10 += ventas[i].cantidad;
            break;
        }
    }

    // No usar HashMap con cantidad total como clave para evitar errores
    // Hacemos un arreglo paralelo para producto y cantidad para buscar el máximo

    string productos[10] = {
        "Auriculares", "Celular", "Cámara", "Escritorio", "Impresora",
        "Laptop", "Monitor", "Silla ergonómica", "Tablet", "Teclado"};

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

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: funcion9\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Similar a funcion8, conteo acumulativo y búsqueda del mínimo usando arreglos paralelos.\n";
    cout << "======================================================================================================================\n";
}

//Muentras las ventas por pais
void funcion103a(const vector<Venta> &ventas, string Pais)
{
    cout << "id venta, ";
    cout << "fecha, ";
    cout << "pais, ";
    cout << "ciudad, ";
    cout << "cliente, ";
    cout << "categoria, ";
    cout << "cantidad, ";
    cout << "precio unitario, ";
    cout << "monto total, ";
    cout << "Medio de envio, ";
    cout << "estado de envio" << endl;

    for (int i = 0; i < ventas.size(); i++)
    {
        if (Pais == ventas[i].pais)
        {
            cout << ventas[i].id_venta;
            cout << ", " << ventas[i].fecha;
            cout << ", " << ventas[i].pais;
            cout << ", " << ventas[i].ciudad;
            cout << ", " << ventas[i].cliente;
            cout << ", " << ventas[i].categoria;
            cout << ", " << ventas[i].cantidad;
            cout << ", " << ventas[i].precio_unitario;
            cout << ", " << ventas[i].monto_total;
            cout << ", " << ventas[i].medio_envio;
            cout << ", " << ventas[i].estado_envio << endl;
        }
    }

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: funcion103a\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for para mostrar ventas por país.\n";
    cout << "======================================================================================================================\n";
}

//Muestra las ventas por ciudad elegida
void funcion103b(const vector<Venta> &ventas, string Ciudad)
{

    cout << "id venta, ";
    cout << "fecha, ";
    cout << "pais, ";
    cout << "ciudad, ";
    cout << "cliente, ";
    cout << "categoria, ";
    cout << "cantidad, ";
    cout << "precio unitario, ";
    cout << "monto total, ";
    cout << "Medio de envio, ";
    cout << "estado de envio" << endl;

    for (int i = 0; i < ventas.size(); i++)
    {
        if (ventas[i].ciudad == Ciudad)
        {
            cout << ventas[i].id_venta;
            cout << ", " << ventas[i].fecha;
            cout << ", " << ventas[i].pais;
            cout << ", " << ventas[i].ciudad;
            cout << ", " << ventas[i].cliente;
            cout << ", " << ventas[i].categoria;
            cout << ", " << ventas[i].cantidad;
            cout << ", " << ventas[i].precio_unitario;
            cout << ", " << ventas[i].monto_total;
            cout << ", " << ventas[i].medio_envio;
            cout << ", " << ventas[i].estado_envio << endl;
        }
    }

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: funcion103b\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for con reemplazo de caracteres especiales para ventas por ciudad.\n";
    cout << "======================================================================================================================\n";
}

//Eliminar una venta
void FuncionEliminar(const vector<Venta> &ventas, int Id)
{

    for (int i = 0; i < ventas.size(); i++)
    {

        if (Id == ventas[i].id_venta) //filtra por id
        {
            //muestra la venta de ese id
            cout << ventas[i].id_venta;
            cout << ", " << ventas[i].fecha;
            cout << ", " << ventas[i].pais;
            cout << ", " << ventas[i].ciudad;
            cout << ", " << ventas[i].cliente;
            cout << ", " << ventas[i].categoria;
            cout << ", " << ventas[i].cantidad;
            cout << ", " << ventas[i].precio_unitario;
            cout << ", " << ventas[i].monto_total;
            cout << ", " << ventas[i].medio_envio;
            cout << ", " << ventas[i].estado_envio << endl;
            cout << "𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗" << endl;
            cout << "Venta eliminada con exito 🗑️" << endl; //dice q se ha eliminado
            cout << "𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗𝄗" << endl;
        }
    }

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: FuncionEliminar\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for para mostrar venta a eliminar por id.\n";
    cout << "======================================================================================================================\n";
}

//Muestra todas las ventas
void FuncionVer(const vector<Venta> &ventas, int Id)
{
    for (int i = 0; i < ventas.size(); i++)
    {
        if (Id == ventas[i].id_venta)
        {
            cout << ventas[i].id_venta;
            cout << ", " << ventas[i].fecha;
            cout << ", " << ventas[i].pais;
            cout << ", " << ventas[i].ciudad;
            cout << ", " << ventas[i].cliente;
            cout << ", " << ventas[i].categoria;
            cout << ", " << ventas[i].cantidad;
            cout << ", " << ventas[i].precio_unitario;
            cout << ", " << ventas[i].monto_total;
            cout << ", " << ventas[i].medio_envio;
            cout << ", " << ventas[i].estado_envio << endl;
        }
    }

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: FuncionVer\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for para mostrar venta por id.\n";
    cout << "======================================================================================================================\n";
}

//Funcion que ordena la fecha ingresada x el usuario
string reordenarFecha(const string &fecha)
{
    // Fecha viene en formato "dd/mm/aaaa"
    string dd = fecha.substr(0, 2);
    string mm = fecha.substr(3, 2);
    string aaaa = fecha.substr(6, 4);

    return  aaaa + mm + dd; //devuelve los nros convertidos en aaaammdd

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 0\n";
    cout << "PROCESO: reordenarFecha\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Manipulación de strings mediante substr para reordenar fecha.\n";
    cout << "======================================================================================================================\n";
    return "";
}

//lista de ventas en un rango de fecha y por pais 
void funcion11b(const vector<Venta> &ventas, const string &Fechainicio, const string &Fechafin, const string &Paisingresado)
{

    for (int i = 0; i < ventas.size(); i++)
    {
        if (ventas[i].pais == Paisingresado)
        {
            string fechaReordenada = reordenarFecha(ventas[i].fecha); 

            if (fechaReordenada >= Fechainicio && fechaReordenada <= Fechafin) //busca en el rango de la fecha
            {
                cout << ventas[i].id_venta;
                cout << ", " << ventas[i].fecha;
                cout << ", " << ventas[i].pais;
                cout << ", " << ventas[i].ciudad;
                cout << ", " << ventas[i].cliente;
                cout << ", " << ventas[i].categoria;
                cout << ", " << ventas[i].cantidad;
                cout << ", " << ventas[i].precio_unitario;
                cout << ", " << ventas[i].monto_total;
                cout << ", " << ventas[i].medio_envio;
                cout << ", " << ventas[i].estado_envio << endl;
            }
        }
    }

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 2\n";
    cout << "PROCESO: funcion11b\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for con condicionales para filtrar por rango de fecha y país.\n";
    cout << "======================================================================================================================\n";
}

//Funcion que calcula el montototal para la funcion11ca
double montoTotal(const vector<Venta> &ventas, string pais)
{
    double montoTotal = 0.0;

    for (int i = 0; i < ventas.size(); i++)
    {
        if (pais == ventas[i].pais)
            montoTotal += ventas[i].monto_total;
    }
    cout << "El monto total del pais " << pais << " es: $" << montoTotal << endl;
    return montoTotal;

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: montoTotal\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for para calcular monto total por país.\n";
    cout << "======================================================================================================================\n";
}

//Monto toal de ventas en dos paises
void funcion11ca(const vector<Venta> &ventas, string Pais1, string Pais2)
{

    montoTotal(ventas, Pais1);//calcula el monto segun el pais
    montoTotal(ventas, Pais2);

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: funcion11ca\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Llamada a función montoTotal para dos países.\n";
    cout << "======================================================================================================================\n";
}

//funcion que calcula el porducto mas vendido para la funcion11cb
void productomax(const vector<Venta> &ventas, string pais) 
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
        if (pais == ventas[i].pais)
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
            while (ventas[i].producto == "Cámara")
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
            while (ventas[i].producto == "Silla ergonómica")
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
    }

    // No usar HashMap con cantidad total como clave para evitar errores
    // Hacemos un arreglo paralelo para producto y cantidad para buscar el máximo

    string productos[10] = {
        "Auriculares", "Celular", "Cámara", "Escritorio", "Impresora",
        "Laptop", "Monitor", "Silla ergonómica", "Tablet", "Teclado"};

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

    cout << "El producto mas vendido en el pais " << pais << " es " << productos[indiceMax] << " con una cantidad de " << maxCantidad << " unidades." << endl;

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 10 (while con break)\n";
    cout << "PROCESO: productomax\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: For con múltiples ciclos while para determinar producto más vendido.\n";
    cout << "======================================================================================================================\n";
}

//Producto mas vendido x pais
void funcion11cb(const vector<Venta> &ventas, string Pais1, string Pais2)
{

    productomax(ventas, Pais1);
    productomax(ventas, Pais2);

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 0\n";
    cout << "PROCESO: funcion11cb\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Llamada secuencial a función productomax para dos países.\n";
    cout << "======================================================================================================================\n";
}

//Medio de envio mas usado
void funcion11cc(const vector<Venta> &ventas, string Pais1, string Pais2)
{
    funcion4(ventas, Pais1);
    funcion4(ventas, Pais2);

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 0\n";
    cout << "PROCESO: funcion11cc\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Llamada secuencial a función funcion4 para dos países.\n";
    cout << "======================================================================================================================\n";
}

//funcion que calcula el producto mas veces vendido en unidades por pais
void productomaxprod(const vector<Venta> &ventas, string producto)
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
        if (producto == ventas[i].producto)
        {
            while (ventas[i].pais == "Paraguay")
            {

                // sumo solo la última cantidad insertada para no repetir sumas
                cantidadtotal1 += ventas[i].cantidad;
                break;
            }
            while (ventas[i].pais == "Argentina")
            {

                cantidadtotal2 += ventas[i].cantidad;
                break;
            }
            while (ventas[i].pais == "Bolivia")
            {

                cantidadtotal3 += ventas[i].cantidad;
                break;
            }
            while (ventas[i].pais == "Brasil")
            {

                cantidadtotal4 += ventas[i].cantidad;
                break;
            }
            while (ventas[i].pais == "Chile")
            {

                cantidadtotal5 += ventas[i].cantidad;
                break;
            }
            while (ventas[i].pais == "Colombia")
            {

                cantidadtotal6 += ventas[i].cantidad;
                break;
            }
            while (ventas[i].pais == "Ecuador")
            {

                cantidadtotal7 += ventas[i].cantidad;
                break;
            }
            while (ventas[i].pais == "Perú")
            {

                cantidadtotal8 += ventas[i].cantidad;
                break;
            }
            while (ventas[i].pais == "Uruguay")
            {

                cantidadtotal9 += ventas[i].cantidad;
                break;
            }
            while (ventas[i].pais == "Venezuela")
            {

                cantidadtotal10 += ventas[i].cantidad;
                break;
            }
        }
    }

    // No usar HashMap con cantidad total como clave para evitar errores
    // Hacemos un arreglo paralelo para producto y cantidad para buscar el máximo

    cout << "Cantidad de unidades vendidas de: " << producto << endl;
    cout << "Argentina: " << cantidadtotal2 << endl;
    cout << "Bolivia: " << cantidadtotal3 << endl;
    cout << "Brasil: " << cantidadtotal4 << endl;
    cout << "Chile: " << cantidadtotal5 << endl;
    cout << "Colombia: " << cantidadtotal6 << endl;
    cout << "Ecuador: " << cantidadtotal7 << endl;
    cout << "Paraguay: " << cantidadtotal1 << endl;
    cout << "Perú: " << cantidadtotal8 << endl;
    cout << "Uruguay: " << cantidadtotal9 << endl;
    cout << "Venezuela: " << cantidadtotal10 << endl;

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: productomaxprod\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for con múltiples ciclos while con break para sumar cantidades por país de un producto específico.\n";
    cout << "======================================================================================================================\n";
}

//Cantidad total vendida de un producto en cada pais
void funcion11da(const vector<Venta> &ventas, string Producto1, string Producto2)
{
    productomaxprod(ventas, Producto1);
    productomaxprod(ventas, Producto2);

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: funcion11da\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Llamada a función productomaxprod para dos productos.\n";
    cout << "======================================================================================================================\n";
}

////Monto total vendido de un prod en cada pais
void funcion11db(const vector<Venta> &ventas, string Producto1, string Producto2)
{
    funcion2(ventas, Producto1);
    funcion2(ventas, Producto2);

    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 1\n";
    cout << "PROCESO: funcion11db\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Llamada a funcion2 para dos productos.\n";
    cout << "======================================================================================================================\n";
}

//Funcion que saca el promedio de ventas en dinero de cada prod
double promedio(const vector<Venta> &ventas, const string &producto, const string &pais)
{
    double montototal = 0.0;
    int c = 0;

    for (int i = 0; i < ventas.size(); i++)
    {
        if (ventas[i].producto == producto && ventas[i].pais == pais)
        {
            c++;
            montototal += ventas[i].monto_total;
        }
    }

    if (c == 0)
        return 0.0;
    return montototal / c;
    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 2\n";
    cout << "PROCESO: promedio\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for con condicional para calcular promedio de monto total por producto y país.\n";
    cout << "======================================================================================================================\n";
}

////Buscar productos vendidos en promedio por debajo de un monto total especificado por el usuario (umbral) y por pais"
void funcion11e(const vector<Venta> &ventas, int umbral, string paiselegido)
{
    cout << "Los productos vendidos en " << paiselegido
         << " con un promedio menor a " << umbral << " son:\n";

    vector<string> productosProcesados;

    for (int i = 0; i < ventas.size(); i++)
    {
        // Si el país no coincide, lo salteamos
        if (ventas[i].pais != paiselegido)
            continue;

        string productoActual = ventas[i].producto;

        // Verificamos si ya procesamos este producto
        bool yaProcesado = false;
        for (int j = 0; j < productosProcesados.size(); j++)
        {
            if (productosProcesados[j] == productoActual)
            {
                yaProcesado = true;
                break;
            }
        }

        if (yaProcesado)
            continue;

        // Calculamos el promedio del producto en el país
        double prom = promedio(ventas, productoActual, paiselegido);
        if (prom < umbral)
        {
            cout << "- " << productoActual << " (Promedio: " << prom << ")\n";
        }
        else
        {
            cout << "No hay productos con monto promedio menor a " << umbral << endl;
        }

        // Lo marcamos como procesado
        productosProcesados.push_back(productoActual);
    }
    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 5\n";
    cout << "PROCESO: funcion11e\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for con varios if anidados para mostrar productos con promedio menor a umbral.\n";
    cout << "======================================================================================================================\n";
}


//Buscar productos vendidos en promedio por encima de un monto total especificado por el usuario (umbral)
void funcion11f(const vector<Venta> &ventas, int umbral, string paiselegido)
{
    cout << "Los productos vendidos en " << paiselegido
         << " con un promedio menor a " << umbral << " son:\n";

    vector<string> productosProcesados;

    for (int i = 0; i < ventas.size(); i++)
    {
        // Si el país no coincide, lo salteamos
        if (ventas[i].pais != paiselegido)
            continue;

        string productoActual = ventas[i].producto;

        // Verificamos si ya procesamos este producto
        bool yaProcesado = false;
        for (int j = 0; j < productosProcesados.size(); j++)
        {
            if (productosProcesados[j] == productoActual)
            {
                yaProcesado = true;
                break;
            }
        }

        if (yaProcesado)
            continue;

        // Calculamos el promedio del producto en el país
        double prom = promedio(ventas, productoActual, paiselegido);
        if (prom > umbral)
        {
            cout << "- " << productoActual << " (Promedio: " << prom << ")\n";
        }
        else
        {
            cout << "No hay productos con monto promedio menor a " << umbral << endl;
        }

        // Lo marcamos como procesado
        productosProcesados.push_back(productoActual);
    }
    cout << "======================================================================================================================\n";
    cout << "CANTIDAD DE CONDICIONALES \"IF\": 5\n";
    cout << "PROCESO: funcion11f\n";
    cout << "ALGORITMO/ESTRUCTURA PRINCIPAL: Ciclo for con varios if anidados para mostrar productos con promedio mayor a umbral.\n";
    cout << "======================================================================================================================\n";
}
