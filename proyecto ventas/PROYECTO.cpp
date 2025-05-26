#include <iostream>
#include <fstream> //libreria para separar cada linea del texto csv
#include <sstream> //libreria para separar cada campo del csv
#include "ventas.h"
#include <vector>
#include "Lista.h"
#include "ArbolBinario.h"
#include "HashMap.h"
#include <algorithm>

using namespace std;

int main()
{

    cout << " " << endl;

    ifstream archivo("ventas_sudamerica.csv"); // Separa el archivo de texto en lineas de caracteres
    string linea;                              // Declaramos cada "renglon" como string y lo llamamos linea

    char delimitador = ','; // Declaramos el divisor de cada campo de las diferentes lineas

    vector<Venta> ventas; // Creamos un objeto de la estructura venta

    getline(archivo, linea);

    while (getline(archivo, linea)) // Bucle que lee el archivo "ventas_sudamerica.csv"
    {

        stringstream ss(linea);                                                                                                                // Separa las lineas de caracteres en campos
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

        /*LECTOR EN PANTALLA DEL ARCHIVO CSV
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

        ventas.push_back(v);
    }
    archivo.close();

    // Menu para que el usuario opere
    int opcion;
    do
    {

        cout << "\n  MENU: \n";
        cout << "1. El top 5 de ciudades con mayor monto de VENTAS por PAIS \n";
        cout << "2. Monto TOTAL vendido por PRODUCTO discriminado por PAIS \n";
        cout << "3. Promedio de ventas por CATEGORIA en cada PAIS \n";
        cout << "4. Medio de envio mas utilizado por pais \n";
        cout << "5. Medio de envio mas utilizado por categoria\n";
        cout << "6. Dia con mayor cantidad de ventas (por monto de dinero) en TODA la base de datos\n";
        cout << "7. Estado de envio mas frecuente por pais\n";
        cout << "8. Producto mas vendido en cantidad total (en unidades)\n";
        cout << "9. Producto menos vendido en cantidad total (unidades)\n";
        cout << "Para salir del menu presione cualquier letra\n";
        cout << " indique el numero de la opcion " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            int opcion1;
            do
            {
                cout << "SELECCIONA EL PAIS" << endl;
                cout << "1. Argentina" << endl;
                cout << "2. Bolivia" << endl;
                cout << "3. Brasil" << endl;
                cout << "4. Chile" << endl;
                cout << "5. Colombia" << endl;
                cout << "6. Ecuador" << endl;
                cout << "7. Paraguay" << endl;
                cout << "8. Peru" << endl;
                cout << "9. Uruguay" << endl;
                cout << "10. Venezuela" << endl;
                cin >> opcion1;
                cout << endl;

                string Paiselegido;
                string Ciudad1, Ciudad2, Ciudad3;
                switch (opcion1)
                {
                case 1:
                    funcion1(ventas, Paiselegido = "Argentina", Ciudad1 = "Buenos Aires", Ciudad2 = "Cordoba", Ciudad3 = "Rosario");
                    break;

                case 2:
                    funcion1(ventas, Paiselegido = "Bolivia", Ciudad1 = "Cochabamba", Ciudad2 = "Santa Cruz", Ciudad3 = "La Paz");
                    break;

                case 3:
                    funcion1(ventas, Paiselegido = "Brasil", Ciudad1 = "S�o Paulo", Ciudad2 = "Rio de Janeiro", Ciudad3 = "Bras�lia");
                    break;

                case 4:
                    funcion1(ventas, Paiselegido = "Chile", Ciudad1 = "Valpara�so", Ciudad2 = "Santiago", Ciudad3 = "Concepci�n");
                    break;

                case 5:
                    funcion1(ventas, Paiselegido = "Colombia", Ciudad1 = "Medell�n", Ciudad2 = "Bogot�", Ciudad3 = "Cali");
                    break;

                case 6:
                    funcion1(ventas, Paiselegido = "Ecuador", Ciudad1 = "Quito", Ciudad2 = "Guayaquil", Ciudad3 = "Cuenca");
                    break;

                case 7:
                    funcion1(ventas, Paiselegido = "Paraguay", Ciudad1 = "Ciudad del Este", Ciudad2 = "Asunci�n", Ciudad3 = "Encarnaci�n");
                    break;

                case 8:
                    funcion1(ventas, Paiselegido = "Per�", Ciudad1 = "Arequipa", Ciudad2 = "Cusco", Ciudad3 = "Lima");
                    break;

                case 9:
                    funcion1(ventas, Paiselegido = "Uruguay", Ciudad1 = "Montevideo", Ciudad2 = "Salto", Ciudad3 = "Paysand�");
                    break;

                case 10:
                    funcion1(ventas, Paiselegido = "Venezuela", Ciudad1 = "Caracas", Ciudad2 = "Maracaibo", Ciudad3 = "Valencia");
                    break;
                }
                break;

            } while (opcion1 != 0);
        case 2:
            int opcion2;
            do
            {
                cout << "SELECCIONA EL PRODUCTO: " << endl;
                cout << "1. Auriculares" << endl;
                cout << "2. Celular" << endl;
                cout << "3. Camara" << endl;
                cout << "4. Escritorio" << endl;
                cout << "5. Impresora" << endl;
                cout << "6. Laptop" << endl;
                cout << "7. Monitor" << endl;
                cout << "8. Sila ergonomica" << endl;
                cout << "9. Tablet" << endl;
                cout << "10. Teclado" << endl;
                cin >> opcion2;

                string Productoelegido;

                switch (opcion2)
                {
                case 1:
                    Productoelegido = "Auriculares";
                    funcion2(ventas, Productoelegido);
                    break;
                case 2:
                    Productoelegido = "Celular";
                    funcion2(ventas, Productoelegido);
                    break;
                case 3:
                    Productoelegido = "Camara";
                    funcion2(ventas, Productoelegido);
                    break;
                case 4:
                    Productoelegido = "Escritorio";
                    funcion2(ventas, Productoelegido);
                    break;
                case 5:
                    Productoelegido = "Impresora";
                    funcion2(ventas, Productoelegido);
                    break;
                case 6:
                    Productoelegido = "Laptop";
                    funcion2(ventas, Productoelegido);
                    break;
                case 7:
                    Productoelegido = "Monitor";
                    funcion2(ventas, Productoelegido);
                    break;
                case 8:
                    Productoelegido = "Silla ergonomica";
                    funcion2(ventas, Productoelegido);
                    break;
                case 9:
                    Productoelegido = "Tablet";
                    funcion2(ventas, Productoelegido);
                    break;
                case 10:
                    Productoelegido = "Teclado";
                    funcion2(ventas, Productoelegido);
                    break;
                default:
                    cout << "Opción inválida." << endl;
                    break;
                }

                break;

            } while (opcion2 != 0);

        case 4:
            int opcion4;
            do
            {
                cout << "SELECCIONA EL PAIS" << endl;
                cout << "1. Argentina" << endl;
                cout << "2. Bolivia" << endl;
                cout << "3. Brasil" << endl;
                cout << "4. Chile" << endl;
                cout << "5. Colombia" << endl;
                cout << "6. Ecuador" << endl;
                cout << "7. Paraguay" << endl;
                cout << "8. Peru" << endl;
                cout << "9. Uruguay" << endl;
                cout << "10. Venezuela" << endl;
                cin >> opcion4;
                cout << endl;

                string Paiselegido;
                switch (opcion4)
                {

                case 1:
                    funcion4(ventas, Paiselegido = "Argentina");
                    break;
                case 2:
                    funcion4(ventas, Paiselegido = "Bolivia");
                    break;
                case 3:
                    funcion4(ventas, Paiselegido = "Brasil");
                    break;
                case 4:
                    funcion4(ventas, Paiselegido = "Chile");
                    break;
                case 5:
                    funcion4(ventas, Paiselegido = "Colombia");
                    break;
                case 6:
                    funcion4(ventas, Paiselegido = "Ecuador");
                    break;
                case 7:
                    funcion4(ventas, Paiselegido = "Paraguay");
                    break;
                case 8:
                    funcion4(ventas, Paiselegido = "Peru");
                    break;
                case 9:
                    funcion4(ventas, Paiselegido = "Uruguay");
                    break;
                case 10:
                    funcion4(ventas, Paiselegido = "Venezuela");
                    break;
                }

            } while (opcion4 != 0);
        case 5:
            int opcion5;
            do
            {
                cout << "SELECCIONA EL PAIS" << endl;
                cout << "1. Accesorios" << endl;
                cout << "2. Electronica" << endl;
                cout << "3. Muebles" << endl;
                cout << "4. Oficina" << endl;

                cin >> opcion5;
                cout << endl;

                string Categoriaelegida;
                switch (opcion5)
                {

                case 1:
                    funcion5(ventas, Categoriaelegida = "Accesorios");
                    break;
                case 2:
                    funcion5(ventas, Categoriaelegida = "Electr�nica");
                    break;
                case 3:
                    funcion5(ventas, Categoriaelegida = "Muebles");
                    break;
                case 4:
                    funcion5(ventas, Categoriaelegida = "Oficina");
                    break;
                }

            } while (opcion5 != 0);
        case 6:
            funcion6(ventas);
        case 7:
            int opcion7;
            do
            {
                cout << "SELECCIONA EL PAIS" << endl;
                cout << "1. Argentina" << endl;
                cout << "2. Bolivia" << endl;
                cout << "3. Brasil" << endl;
                cout << "4. Chile" << endl;
                cout << "5. Colombia" << endl;
                cout << "6. Ecuador" << endl;
                cout << "7. Paraguay" << endl;
                cout << "8. Peru" << endl;
                cout << "9. Uruguay" << endl;
                cout << "10. Venezuela" << endl;
                cin >> opcion7;
                cout << endl;

                string Paiselegido;
                switch (opcion7)
                {

                case 1:
                    funcion7(ventas, Paiselegido = "Argentina");
                    break;
                case 2:
                    funcion7(ventas, Paiselegido = "Bolivia");
                    break;
                case 3:
                    funcion7(ventas, Paiselegido = "Brasil");
                    break;
                case 4:
                    funcion7(ventas, Paiselegido = "Chile");
                    break;
                case 5:
                    funcion7(ventas, Paiselegido = "Colombia");
                    break;
                case 6:
                    funcion7(ventas, Paiselegido = "Ecuador");
                    break;
                case 7:
                    funcion7(ventas, Paiselegido = "Paraguay");
                    break;
                case 8:
                    funcion7(ventas, Paiselegido = "Peru");
                    break;
                case 9:
                    funcion7(ventas, Paiselegido = "Uruguay");
                    break;
                case 10:
                    funcion7(ventas, Paiselegido = "Venezuela");
                    break;
                }

            } while (opcion7 != 0);
        case 8:
            funcion8(ventas);
            break;
        case 9:
            funcion9(ventas);
            break;
        }
    } while (opcion != 0);
}
