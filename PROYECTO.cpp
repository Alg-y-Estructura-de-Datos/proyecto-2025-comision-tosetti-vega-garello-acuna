#include <iostream>
#include <fstream> //libreria para separar cada linea del texto csv
#include <sstream> //libreria para separar cada campo del csv
#include "ventas.h"
#include <vector>
#include "Lista.h"
#include "ArbolBinario.h"
#include "HashMap.h"
#include <algorithm>
#include <chrono>//funcion del temporizador
#include <windows.h>

using namespace std;
using namespace std::chrono;//funcion temporizador

int main()
{
    auto inicio_total = high_resolution_clock::now();

    SetConsoleOutputCP(CP_UTF8); // Configura salida de consola a UTF-8 (codifiacion p. leer caract. especiales)
    SetConsoleCP(CP_UTF8);       // Configura entrada de consola a UTF-8 (codifiacion p. leer caract. especiales)

    Venta ultimaVenta; //creamos un objeto UltimaVenta para AGREGAR una nueva linea (venta) al final de la estrctura Venta

    ifstream archivo("ventas_sudamerica.csv"); // Separa el archivo de texto en lineas de caracteres
    string linea;                              // Declaramos cada "renglon" como string y lo llamamos linea

    char delimitador = ','; // Declaramos el divisor de cada campo de las diferentes lineas

    vector<Venta> ventas; // Creamos un objeto de la estructura venta

    getline(archivo, linea);

    while (getline(archivo, linea)) // Bucle que lee el archivo "ventas_sudamerica.csv"
    {

        stringstream ss(linea);// Separa las lineas de caracteres en campos
        string id_venta, fecha, pais, ciudad, cliente, producto, categoria, cantidad, precio_unitario, monto_total, medio_envio, estado_envio; // campos
        Venta v;                                                                                                                               // Objeto "venta" vacio
        string campo;
        // Separamos cada campo teniendo en cuenta el delimitador ',' y lo asignamos a cada atributo

        getline(ss, id_venta, delimitador);
        v.id_venta = stoi(id_venta);
        getline(ss, fecha, delimitador);
        v.fecha = (fecha);
        getline(ss, pais, delimitador);
        v.pais = (pais);
        getline(ss, ciudad, delimitador);
        v.ciudad = (ciudad);
        getline(ss, cliente, delimitador);
        v.cliente = (cliente);
        getline(ss, producto, delimitador);
        v.producto = (producto);
        getline(ss, categoria, delimitador);
        v.categoria = (categoria);
        getline(ss, cantidad, delimitador);
        v.cantidad = stoi(cantidad);
        getline(ss, precio_unitario, delimitador);
        v.precio_unitario = stod(precio_unitario);
        getline(ss, monto_total, delimitador);
        v.monto_total = stod(monto_total);
        getline(ss, medio_envio, delimitador);
        v.medio_envio = (medio_envio);
        getline(ss, estado_envio, delimitador);
        v.estado_envio = (estado_envio);

        /*LECTOR EN PANTALLA DEL ARCHIVO CSV auxiliar
        cout << "==============================" << endl;
        cout << "id venta: " << id_venta << endl;
        cout << "fecha: " << fecha << endl;
        cout << "pais: " << pais << endl;
        cout << "ciudad: " << ciudad << endl;
        cout << "cliente: " << cliente << endl;
        cout << "categoria: " << categoria << endl;
        cout << "cantidad: " << cantidad << endl;
        cout << "precio unitario: " << precio_unitario << endl;
        cout << "monto total: " << monto_total << endl;
        cout << "Medio de envio: " << medio_envio << endl;
        cout << "estado de envio: " << estado_envio << endl;*/

        ventas.push_back(v);//inserta la ultima venta a la estructura
    }
    archivo.close();//cierra el archivp

    // Menu para que el usuario opere
    int opcion;
    do
    {
        cout << "-----------------------------------------------------------------------------------------------------------------------";
        cout << "\n  MENU: \n";
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "1. El top 5 de ciudades con mayor monto de VENTAS por PAIS \n";
        cout << "2. Monto TOTAL vendido por PRODUCTO discriminado por PAIS \n";
        cout << "3. Promedio de ventas por CATEGORIA en cada PAIS \n";
        cout << "4. Medio de envio mas utilizado por pais \n";
        cout << "5. Medio de envio mas utilizado por categoria\n";
        cout << "6. Dia con mayor cantidad de ventas (por monto de dinero) en TODA la base de datos\n";
        cout << "7. Estado de envio mas frecuente por pais\n";
        cout << "8. Producto mas vendido en cantidad total (en unidades)\n";
        cout << "9. Producto menos vendido en cantidad total (unidades)\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "10. Modificar la base de datos\n";
        cout << "11. Realizar consultas dinamicas" << endl;
        cout << "Para salir del menu presione 0" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Indique el numero de la opcion " << endl;

        cin >> opcion;//guarda la opcion elegida

        switch (opcion)
        {
        case 1:  //El top 5 de ciudades con mayor monto de VENTAS por PAIS
            int opcion1;
            do
            {
                cout << "SELECCIONA EL PAIS" << endl;
                lectorpais(); //funcion que lee los paises 
                cin >> opcion1;
                cout << endl;

                string Paiselegido;
                string Ciudad1, Ciudad2, Ciudad3;
                switch (opcion1)
                {
                case 1:
                {

                    auto inicio = high_resolution_clock::now();//inicio de la funcion cronometro

                    funcion1(ventas, Paiselegido = "Argentina", Ciudad1 = "Buenos Aires", Ciudad2 = "Cordoba", Ciudad3 = "Rosario");// Inicializa las ciudades cuando se elije Argentina

                    auto fin = high_resolution_clock::now();// fin de la funcion cronometro
                    auto duracion = duration_cast<milliseconds>(fin - inicio);// calculo de la duracion de ejecucion
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n" 
                         << endl;//imprime el tiempo de ejecucion

                    break;
                }

                case 2:
                {

                    auto inicio = high_resolution_clock::now(); //inicio de la funcion cronometro

                    funcion1(ventas, Paiselegido = "Bolivia", Ciudad1 = "Cochabamba", Ciudad2 = "Santa Cruz", Ciudad3 = "La Paz");// Inicializa las ciudades cuando se elije Bolivia

                    auto fin = high_resolution_clock::now(); //fin de la funcion cronometro
                    auto duracion = duration_cast<milliseconds>(fin - inicio); //calculo del tiempo de ejecucion
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n" 
                         << endl;//imprimer el tiempo de ejecucion

                    break;
                }

                case 3:
                {
                    auto inicio = high_resolution_clock::now();// inicio reloj

                    funcion1(ventas, Paiselegido = "Brasil", Ciudad1 = "Sao Paulo", Ciudad2 = "Rio de Janeiro", Ciudad3 = "Brasília");// Inicializa las ciudades cuando se elije Brasil
                    auto fin = high_resolution_clock::now();// fin reloj
                    auto duracion = duration_cast<milliseconds>(fin - inicio);// calculo tiempo de ejecucion
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n" 
                         << endl;//imprime el tiempo de ejecucion

                    break;
                }

                case 4:

                {
                    auto inicio = high_resolution_clock::now();//inicio reloj

                    funcion1(ventas, Paiselegido = "Chile", Ciudad1 = "Valparaíso", Ciudad2 = "Santiago", Ciudad3 = "Concepción");// Inicializa las ciudades cuando se elije Chile

                    auto fin = high_resolution_clock::now();//fin reloj
                    auto duracion = duration_cast<milliseconds>(fin - inicio); //calculo tiempo de ejecucion
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n" 
                         << endl;//imprime el tiempo de ejecucion

                    break;
                }

                case 5:

                {
                    auto inicio = high_resolution_clock::now();// inicia a contar el tiempo de ejecucion

                    funcion1(ventas, Paiselegido = "Colombia", Ciudad1 = "Medellín", Ciudad2 = "Bogotá", Ciudad3 = "Cali");// Inicializa las ciudades cuando se elije Colombia

                    auto fin = high_resolution_clock::now();//termina de contar el tiempo de ejecucion
                    auto duracion = duration_cast<milliseconds>(fin - inicio);//calcula el tiempo de ejecucion
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n" 
                         << endl;// imprime el tiempo de ejecucion

                    break;
                }

                case 6: //Dia con mayor cantidad de ventas (por monto de dinero) en TODA la base de datos

                {
                    auto inicio = high_resolution_clock::now();//incia a contar el tiempo de ejecucion

                    funcion1(ventas, Paiselegido = "Ecuador", Ciudad1 = "Quito", Ciudad2 = "Guayaquil", Ciudad3 = "Cuenca");// Inicializa las ciudades cuando se elije Ecuador

                    auto fin = high_resolution_clock::now();//termina de contar el tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio);//calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;//imprime el tiempo de ejcucion

                    break;
                }

                case 7:

                {
                    auto inicio = high_resolution_clock::now(); //empieza a contar el tiempo de ejecucion

                    funcion1(ventas, Paiselegido = "Paraguay", Ciudad1 = "Quito", Ciudad2 = "Guayaquil", Ciudad3 = "Cuenca");// Inicializa las ciudades cuando se elije Paraguay

                    auto fin = high_resolution_clock::now(); //termina de contar el tiempo de ejecucion
                    auto duracion = duration_cast<milliseconds>(fin - inicio); //calcula el tiempo de ejecucion
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo de ejecucion

                    break;
                }

                case 8:
                {
                    auto inicio = high_resolution_clock::now();// empieza a contar el tiempo de ejecucion

                    funcion1(ventas, Paiselegido = "Perú", Ciudad1 = "Arequipa", Ciudad2 = "Cusco", Ciudad3 = "Lima");// Inicializa las ciudades cuando se elije Peru

                    auto fin = high_resolution_clock::now();//finaliza el tiempo de ejecucion
                    auto duracion = duration_cast<milliseconds>(fin - inicio); //calcula el tiempo de ejecucion
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n" 
                         << endl;// imprimer el tiempo de ejecucion

                    break;
                }

                case 9:
                {
                    auto inicio = high_resolution_clock::now();// empieza a contar el tiempo de ejecucion

                    funcion1(ventas, Paiselegido = "Uruguay", Ciudad1 = "Montevideo", Ciudad2 = "Salto", Ciudad3 = "Paysandú");// Inicializa las ciudades cuando se elije Uruguay

                    auto fin = high_resolution_clock::now();//finaliza el tiempo de ejecucion
                    auto duracion = duration_cast<milliseconds>(fin - inicio);//calcula el tiempo de ejecucion
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprimer el tiempo de ejecucion

                    break;
                }

                case 10:

                {
                    auto inicio = high_resolution_clock::now();// empieza a contar el tiempo de ejecucion

                    funcion1(ventas, Paiselegido = "Venezuela", Ciudad1 = "Caracas", Ciudad2 = "Maracaibo", Ciudad3 = "Valencia");// Inicializa las ciudades cuando se elije Uruguay

                    auto fin = high_resolution_clock::now();//finaliza el tiempo de ejecucion
                    auto duracion = duration_cast<milliseconds>(fin - inicio);//calcula el tiempo de ejecucion
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprimer el tiempo de ejecucion

                    break;
                }
                }
                break;

            } while (opcion1 != 0);
            break;

        case 2: //Monto TOTAL vendido por PRODUCTO discriminado por PAIS
            int opcion2;
            do
            {
                cout << "SELECCIONA EL PRODUCTO: " << endl;
                lectorproducto(); //lee la lista de productos
                cin >> opcion2;

                string Productoelegido;

                switch (opcion2)
                {
                case 1:

                {
                    Productoelegido = "Auriculares";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion2(ventas, Productoelegido);// llama a la funcion que calcula el monto toal del producto elegido

                    auto fin = high_resolution_clock::now();// finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio); // calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl; // imprime el tiempo

                    break;
                }

                case 2:

                {
                    Productoelegido = "Celular";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion2(ventas, Productoelegido);// llama a la funcion que calcula el monto toal del producto elegido

                    auto fin = high_resolution_clock::now();// finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio); // calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }

                case 3:

                {
                    Productoelegido = "Cámara";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion2(ventas, Productoelegido);// llama a la funcion que calcula el monto toal del producto elegido

                    auto fin = high_resolution_clock::now();// finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio); // calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }

                case 4:

                {
                    Productoelegido = "Escritorio";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion2(ventas, Productoelegido);// llama a la funcion que calcula el monto toal del producto elegido

                    auto fin = high_resolution_clock::now(); // finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio); // calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }

                case 5:

                {
                    Productoelegido = "Impresora";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion2(ventas, Productoelegido);// llama a la funcion que calcula el monto toal del producto elegido

                    auto fin = high_resolution_clock::now(); // finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio); // calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }

                case 6:

                {
                    Productoelegido = "Laptop";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion2(ventas, Productoelegido);// llama a la funcion que calcula el monto toal del producto elegido

                    auto fin = high_resolution_clock::now(); // finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio); // calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }

                case 7:

                {
                    Productoelegido = "Monitor";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion2(ventas, Productoelegido);// llama a la funcion que calcula el monto toal del producto elegido

                    auto fin = high_resolution_clock::now(); // finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio); // calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }

                case 8:

                {
                    Productoelegido = "Silla ergonomica";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion2(ventas, Productoelegido);// llama a la funcion que calcula el monto toal del producto elegido

                    auto fin = high_resolution_clock::now();// finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio); // calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }

                case 9:

                {
                    Productoelegido = "Tablet";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion2(ventas, Productoelegido);// llama a la funcion que calcula el monto toal del producto elegido

                    auto fin = high_resolution_clock::now(); // finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio); // calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }

                case 10:

                {
                    Productoelegido = "Teclado";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion2(ventas, Productoelegido);// llama a la funcion que calcula el monto toal del producto elegido

                    auto fin = high_resolution_clock::now(); // finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio); // calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }

                default:
                    cout << "Opción inválida." << endl;
                    break;
                }

                break;

            } while (opcion2 != 0);

            break;
        case 3: // Promedio de ventas por CATEGORIA en cada PAIS
            int opcion3;
            do
            {
                cout << "SELECCIONA LA CATEGORIA" << endl;
                cout << "1. Accesorios" << endl;
                cout << "2. Electrónica" << endl;
                cout << "3. Muebles" << endl;
                cout << "4. Oficina" << endl;

                cin >> opcion3;
                cout << endl;
                string Categoriaelegida;
                switch (opcion3)
                {
                case 1:

                {
                    Categoriaelegida = "Accesorios";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion3(ventas, Categoriaelegida);

                    auto fin = high_resolution_clock::now();// finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio);// calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }

                case 2:
                {
                    Categoriaelegida = "Electrónica";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion3(ventas, Categoriaelegida);

                    auto fin = high_resolution_clock::now();// finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio);// calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }
                case 3:
                {
                    Categoriaelegida = "Muebles";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion3(ventas, Categoriaelegida);

                    auto fin = high_resolution_clock::now();// finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio);// calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }
                case 4: 
                {
                    Categoriaelegida = "Oficina";
                    auto inicio = high_resolution_clock::now();//inicia a contar el tiempo de ejecucion

                    funcion3(ventas, Categoriaelegida);

                    auto fin = high_resolution_clock::now();// finaliza la cuenta del tiempo
                    auto duracion = duration_cast<milliseconds>(fin - inicio);// calcula el tiempo
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;// imprime el tiempo

                    break;
                }
                }
                break;

            } while (opcion3 != 0);
            break;
        case 4://Medio de envio mas utilizado por pais 
            int opcion4;
            do
            {
                cout << "SELECCIONA EL PAIS" << endl;
                lectorpais();
                cin >> opcion4;
                cout << endl;

                string Paiselegido;
                switch (opcion4)
                {

                case 1:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion4(ventas, Paiselegido = "Argentina");
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 2:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion4(ventas, Paiselegido = "Bolivia");
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 3:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion4(ventas, Paiselegido = "Brasil");
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 4:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion4(ventas, Paiselegido = "Chile");
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 5:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion4(ventas, Paiselegido = "Colombia");
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 6:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion4(ventas, Paiselegido = "Ecuador");
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 7:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion4(ventas, Paiselegido = "Paraguay");
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 8:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion4(ventas, Paiselegido = "Perú");
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 9:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion4(ventas, Paiselegido = "Uruguay");
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 10:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion4(ventas, Paiselegido = "Venezuela");
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                }
                break;

            } while (opcion4 != 0);
            break;
        case 5: //Medio de envio mas utilizado por categoria
            int opcion5;
            do
            {
                cout << "SELECCIONA LA CATEGORIA" << endl;
                cout << "1. Accesorios" << endl;
                cout << "2. Electrónica" << endl;
                cout << "3. Muebles" << endl;
                cout << "4. Oficina" << endl;

                cin >> opcion5;
                cout << endl;

                string Categoriaelegida;
                switch (opcion5)
                {

                case 1:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion5(ventas, Categoriaelegida = "Accesorios"); //llama a la funcion que calcula el medio de envio mas utilizad
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 2:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion5(ventas, Categoriaelegida = "Electrónica"); //llama a la funcion que calcula el medio de envio mas utilizad
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 3:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion5(ventas, Categoriaelegida = "Muebles"); //llama a la funcion que calcula el medio de envio mas utilizad
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }

                case 4:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion5(ventas, Categoriaelegida = "Oficina"); //llama a la funcion que calcula el medio de envio mas utilizad
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                }
                break;
            } while (opcion5 != 0);
            break;
        case 6://Dia con mayor cantidad de ventas (por monto de dinero) en TODA la base de datos
        {
            auto inicio = high_resolution_clock::now();
            funcion6(ventas); //llama  a la funcion que calcula el dia con mas ventas
            auto fin = high_resolution_clock::now();
            auto duracion = duration_cast<milliseconds>(fin - inicio);
            cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                 << endl;

            break;
        }

        case 7: //Estado de envio mas frecuente por pais
            int opcion7;
            do
            {
                cout << "SELECCIONA EL PAIS" << endl;
                lectorpais();
                cin >> opcion7;
                cout << endl;

                string Paiselegido;
                switch (opcion7)
                {

                case 1:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion7(ventas, Paiselegido = "Argentina"); //calcula cual es el estado de envio mas frecuente en el pais elegido
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 2:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion7(ventas, Paiselegido = "Bolivia"); //calcula cual es el estado de envio mas frecuente en el pais elegido
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 3:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion7(ventas, Paiselegido = "Brasil"); //calcula cual es el estado de envio mas frecuente en el pais elegido
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 4:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion7(ventas, Paiselegido = "Chile"); //calcula cual es el estado de envio mas frecuente en el pais elegido
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 5:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion7(ventas, Paiselegido = "Colombia"); //calcula cual es el estado de envio mas frecuente en el pais elegido
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 6:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion7(ventas, Paiselegido = "Ecuador"); //calcula cual es el estado de envio mas frecuente en el pais elegido
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 7:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion7(ventas, Paiselegido = "Paraguay"); //calcula cual es el estado de envio mas frecuente en el pais elegido
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 8:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion7(ventas, Paiselegido = "Perú"); //calcula cual es el estado de envio mas frecuente en el pais elegido
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 9:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion7(ventas, Paiselegido = "Uruguay"); //calcula cual es el estado de envio mas frecuente en el pais elegido
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 10:
                {
                    auto inicio = high_resolution_clock::now();
                    funcion7(ventas, Paiselegido = "Venezuela"); //calcula cual es el estado de envio mas frecuente en el pais elegido
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                }
                break;

            } while (opcion7 != 0);
            break;
        case 8: //Producto mas vendido en cantidad total (en unidades)
        {
            auto inicio = high_resolution_clock::now();
            funcion8(ventas); //llama a la funcion que calcula el prod q  mas se vendio en cantidad
            auto fin = high_resolution_clock::now();
            auto duracion = duration_cast<milliseconds>(fin - inicio);
            cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                 << endl;

            break;
        }

        case 9: //Producto menos vendido en cantidad total (unidades)
        {
            auto inicio = high_resolution_clock::now();
            funcion9(ventas); 
            auto fin = high_resolution_clock::now();
            auto duracion = duration_cast<milliseconds>(fin - inicio);
            cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                 << endl;

            break;
        }
        case 10: //Modificar la base de datos

            int opcion10;

            do
            {
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "\nMODIFICAR BASE DE DATOS:\n";
                cout << "1. Agregar una venta\n";
                cout << "2. Ver última venta ingresada\n";
                cout << "3. Eliminar una venta por ciudad o pais\n";
                cout << "4. Modificar una venta\n";
                cout << "0. Volver al menú principal\n";
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "Seleccione una opción: ";
                cin >> opcion10;
                cin.ignore();

                switch (opcion10)
                {
                case 0:
                    cout << "Volviendo al menú principal...\n";
                    break;

                case 1: //Agregar una venta
                {
                    cout << "\n--- Ingreso de nueva venta ---\n";
                    Venta nuevaVenta; //crea un nuevo objeto nuevaVenta en la estructura venta

                    cout << "Ingrese ID de venta: "; 
                    cin >> nuevaVenta.id_venta;
                    cin.ignore();

                    cout << "Ingrese fecha (formato AAAA-MM-DD): ";
                    getline(cin, nuevaVenta.fecha);

                    cout << "Ingrese país: ";
                    getline(cin, nuevaVenta.pais);

                    cout << "Ingrese ciudad: ";
                    getline(cin, nuevaVenta.ciudad);

                    cout << "Ingrese cliente (Nombre Apellido): ";
                    getline(cin, nuevaVenta.cliente);

                    cout << "Ingrese producto: ";
                    getline(cin, nuevaVenta.producto);

                    cout << "Ingrese categoría: ";
                    getline(cin, nuevaVenta.categoria);

                    cout << "Ingrese cantidad vendida: ";
                    cin >> nuevaVenta.cantidad;

                    cout << "Ingrese precio unitario: ";
                    cin >> nuevaVenta.precio_unitario;

                    nuevaVenta.monto_total = nuevaVenta.cantidad * nuevaVenta.precio_unitario; //calcula el monto total de la nueva venta

                    cin.ignore(); // limpiar '\n' antes del siguiente getline

                    cout << "Ingrese medio de envío: ";
                    getline(cin, nuevaVenta.medio_envio);

                    cout << "Ingrese estado de envío: ";
                    getline(cin, nuevaVenta.estado_envio);

                    ventas.push_back(nuevaVenta); //ingresa una linea con los datos de la nueva venta
                    ultimaVenta = nuevaVenta; //hace q si elejimos la opcion de ultimaVenta en el menu, muestre esta.

                    cout << "Venta agregada con éxito.\n";
                    break;
                }
                case 2:
                {
                    cout << "\nÚltima venta ingresada:\n"; //lee la ultima venta ingresada
                    cout << "ID Venta: " << ultimaVenta.id_venta << endl;
                    cout << "Fecha: " << ultimaVenta.fecha << endl;
                    cout << "País: " << ultimaVenta.pais << endl;
                    cout << "Ciudad: " << ultimaVenta.ciudad << endl;
                    cout << "Cliente: " << ultimaVenta.cliente << endl;
                    cout << "Producto: " << ultimaVenta.producto << endl;
                    cout << "Categoría: " << ultimaVenta.categoria << endl;
                    cout << "Cantidad: " << ultimaVenta.cantidad << endl;
                    cout << "Precio Unitario: " << ultimaVenta.precio_unitario << endl;
                    cout << "Monto Total: " << ultimaVenta.monto_total << endl;
                    cout << "Medio de Envío: " << ultimaVenta.medio_envio << endl;
                    cout << "Estado de Envío: " << ultimaVenta.estado_envio << endl;
                    break;
                }
                case 3: //Eliminar venta
                {
                    int opcion3;
                    cout << "Ingrese por que criterio desea eliminar la venta: " << endl;
                    cout << "1. Ciudad" << endl;
                    cout << "2. Pais" << endl;
                    cin >> opcion3;

                    string ciudad;
                    string pais;
                    int id;

                    switch (opcion3)
                    {
                    case 1: //eliminar venta por ciudad
                    {
                        auto inicio = high_resolution_clock::now();

                        lectorciudad();

                        cout << "Escribe la ciudad tal cual aparece (con mayúsculas y tildes):" << endl;
                        cin.ignore(); // Importante para limpiar el '\n' si viene después de cin >>
                        getline(cin, ciudad);

                        funcion103b(ventas, ciudad); // muestra ventas por ciudad

                        cout << "Ingrese el ID de la venta que desea eliminar: ";
                        cin >> id;
                        FuncionEliminar(ventas, id); //llama a la funcion que elimina la venta por el id

                        auto fin = high_resolution_clock::now();
                        auto duracion = duration_cast<milliseconds>(fin - inicio);
                        cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                             << endl;

                        break;
                    }

                    case 2://eliminar venta por pais
                    {
                        auto inicio = high_resolution_clock::now();

                        lectorpais();
                        cout << "Escribe el pais tal cual" << endl
                             << endl;
                        cin >> pais;

                        funcion103a(ventas, pais); // muestra ventas por pais
                        cout << "Ingrese el ID de la venta que desea eliminar " << endl;
                        cin >> id;
                        cout << "Eliminando venta..." << endl;
                        FuncionEliminar(ventas, id);

                        auto fin = high_resolution_clock::now();
                        auto duracion = duration_cast<milliseconds>(fin - inicio);
                        cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                             << endl;

                        break;
                    }
                    }

                    break;
                }
                case 4: //Modificar una venta existente
                {
                    auto inicio = high_resolution_clock::now();
                    Venta modifVenta;
                    int id;
                    cout << "Ingrese el ID de la venta que quiere modificar: " << endl;
                    cin >> id;
                    FuncionVer(ventas, id); //muestra todas las ventas 
                    cout << "Modifiques los campos que desee, los que no quiere modificar copielos igual. " << endl;

                    cout << "Ingrese ID de venta: ";
                    cin >> modifVenta.id_venta;
                    cin.ignore();

                    cout << "Ingrese fecha (formato AAAA-MM-DD): ";
                    getline(cin, modifVenta.fecha);

                    cout << "Ingrese país: ";
                    getline(cin, modifVenta.pais);

                    cout << "Ingrese ciudad: ";
                    getline(cin, modifVenta.ciudad);

                    cout << "Ingrese cliente (Nombre Apellido): ";
                    getline(cin, modifVenta.cliente);

                    cout << "Ingrese producto: ";
                    getline(cin, modifVenta.producto);

                    cout << "Ingrese categoría: ";
                    getline(cin, modifVenta.categoria);

                    cout << "Ingrese cantidad vendida: ";
                    cin >> modifVenta.cantidad;

                    cout << "Ingrese precio unitario: ";
                    cin >> modifVenta.precio_unitario;

                    modifVenta.monto_total = modifVenta.cantidad * modifVenta.precio_unitario;

                    cin.ignore();
                    cout << "Ingrese medio de envío: ";
                    getline(cin, modifVenta.medio_envio);

                    cout << "Ingrese estado de envío: ";
                    getline(cin, modifVenta.estado_envio);

                    ventas.push_back(modifVenta);

                    ofstream archivoCSV("ventas_sudamerica.csv", ios::app); // ayuda con la lectura y manipulacion del archivo csv
                    switch (archivoCSV.is_open())
                    {
                    case true: // si el archivo se pudo abrir, modifica la venta con lo ingresado x el usuario
                        archivoCSV << modifVenta.id_venta << ","
                                   << modifVenta.fecha << ","
                                   << modifVenta.pais << ","
                                   << modifVenta.ciudad << ","
                                   << modifVenta.cliente << ","
                                   << modifVenta.producto << ","
                                   << modifVenta.categoria << ","
                                   << modifVenta.cantidad << ","
                                   << modifVenta.precio_unitario << ","
                                   << modifVenta.monto_total << ","
                                   << modifVenta.medio_envio << ","
                                   << modifVenta.estado_envio << "\n";

                        archivoCSV.close();
                        cout << "Venta modificada correctamente.\n";
                    }
                    break;
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;
                }
                }
                break;
            } while (opcion10 != 0);
            break;
        case 11: //Consultas dinamicas

            int opcion11;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "1. Listado de ventas realizadas por ciudad" << endl;
            cout << "2. Listado de ventas realizadas en un rango de fechas por pais" << endl;
            cout << "3. Comparacion entre dos paises" << endl;
            cout << "4. Comparacion entre dos productos discriminados por todos los paises" << endl;
            cout << "5. Buscar productos vendidos en promedio por debajo de un monto total especificado por el usuario (umbral) y por pais" << endl;
            cout << "6. Buscar productos vendidos en promedio por debajo de un monto total especificado por el usuario (umbral)" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Ingrese opcion: " << endl;
            cin >> opcion11;

            string ciudadingresada, paisingresado, diainicio, mesinicio, anoinicio, diafin, mesfin, anofin, fechainicio, fechafin, pais1, pais2, producto1, producto2, paiselegido;
            int umbral;

            switch (opcion11)
            {
            case 1: //Lista de ventas realizadas  x ciudad
            {
                auto inicio = high_resolution_clock::now();

                lectorciudad();

                cout << "Escribe la ciudad tal cual aparece (con mayúsculas y tildes):" << endl;
                cin.ignore(); // Importante para limpiar el '\n' si viene después de cin >>
                getline(cin, ciudadingresada);

                funcion103b(ventas, ciudadingresada); //llama a la funcion q muestra las ventas realizadas segun la ciudad elegida

                auto fin = high_resolution_clock::now();
                auto duracion = duration_cast<milliseconds>(fin - inicio);
                cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                     << endl;

                break;
            }
            case 2: //lista de ventas en un rango de fecha y por pais 
            {
                auto inicio = high_resolution_clock::now();

                cout << "Ingrese la fecha de inicio " << endl;
                cout << "Dia (DD): ";
                cin >> diainicio;
                cout << "Mes (MM): ";
                cin >> mesinicio;
                cout << "Año (AAAA): ";
                cin >> anoinicio;

                fechainicio = anoinicio + mesinicio + diainicio; //convierte la fecha que se ingreso en un string basico

                cout << "Ingrese la fecha de finalizacion " << endl;
                cout << "Dia (DD): ";
                cin >> diafin;
                cout << "Mes (MM): ";
                cin >> mesfin;
                cout << "Año (AAAA): ";
                cin >> anofin;

                fechafin = anofin + mesfin + diafin; //convierte la fecha que se ingreso en un solo string

                cout << "Ingrese el pais" << endl;
                cin >> paisingresado;

                funcion11b(ventas, fechainicio, fechafin, paisingresado); //llama a la funcin que filtra por rango de fechas y por pais

                auto fin = high_resolution_clock::now();
                auto duracion = duration_cast<milliseconds>(fin - inicio);
                cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                     << endl;

                break;
            }
            case 3: //Comparacion entre dos paises
                int opcion113;
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "INDIQUE LO QUE DESEA REALIZAR" << endl;
                cout << "1. Monto total de ventas" << endl;
                cout << "2. Productos mas vendidos" << endl;
                cout << "3. Medio de envio mas usado" << endl;
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                cin >> opcion113;

                lectorpais();
                cout << "Escriba el pais 1: ";
                cin >> pais1;
                cout << "Escriba el pais 2: ";
                cin >> pais2;

                switch (opcion113)
                {
                case 1: //Monto toal de ventas
                {
                    auto inicio = high_resolution_clock::now();

                    funcion11ca(ventas, pais1, pais2); //llamado a la funcion
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 2: //Producto mas vendido x pais
                {
                    auto inicio = high_resolution_clock::now();

                    funcion11cb(ventas, pais1, pais2); //llamado a la funcion
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 3: //Medio de envio mas usado
                {
                    auto inicio = high_resolution_clock::now();

                    funcion11cc(ventas, pais1, pais2); //llama a la funcion
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                }
            case 4: //Comparacion entre dos productos discriminados por todos los paises
                int opcion114;
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "INDIQUE LO QUE DESEA REALIZAR" << endl;
                cout << "1. Cantidad total vendida" << endl;
                cout << "2. Monto total" << endl;
                cin >> opcion114;
                cin.ignore();
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                
                lectorproducto();
                cout << "Escriba el producto 1: ";
                getline(cin,producto1);

                cout << "Escriba el producto 2: ";
                getline(cin,producto2);

                switch (opcion114)
                {
                case 1: //Canidad total vendida
                {
                    auto inicio = high_resolution_clock::now();
                    funcion11da(ventas, producto1, producto2); //llama  a la funcion
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                case 2: //Monto toal vendido
                {
                    auto inicio = high_resolution_clock::now();
                    funcion11db(ventas, producto1, producto2); //llama a la funcion
                    auto fin = high_resolution_clock::now();
                    auto duracion = duration_cast<milliseconds>(fin - inicio);
                    cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                         << endl;

                    break;
                }
                }
                break;

            case 5: //Buscar productos vendidos en promedio por debajo de un monto total especificado por el usuario (umbral) y por pais"
            {
                auto inicio = high_resolution_clock::now();
                lectorpais();
                cout << "Ingrese el pais: ";
                cin >> paiselegido;
                cout << "Ingrese el umbral de busqueda: ";
                cin >> umbral;

                funcion11e(ventas, umbral, paiselegido); //llama a la funcion
                auto fin = high_resolution_clock::now();
                auto duracion = duration_cast<milliseconds>(fin - inicio);
                cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                     << endl;
                break;
            }
            case 6: //Buscar productos vendidos en promedio por encima de un monto total especificado por el usuario (umbral)
            {
                auto inicio = high_resolution_clock::now();
                lectorpais();
                cout << "Ingrese el pais: ";
                cin >> paiselegido;
                cout << "Ingrese el umbral de busqueda: "; //llama a la funcion
                cin >> umbral;

                funcion11f(ventas, umbral, paiselegido);
                auto fin = high_resolution_clock::now();
                auto duracion = duration_cast<milliseconds>(fin - inicio);
                cout << "Tiempo de ejecución: " << duracion.count() << " ms\n"
                     << endl;
            }
            break;
            }
            break;
        }

    } while (opcion != 0);

    auto fin_total = high_resolution_clock::now();
    auto duracion_total = duration_cast<milliseconds>(fin_total - inicio_total);
    cout << "\nTiempo total de ejecución del programa: " << duracion_total.count() << " ms" << endl;

    return 0;
}