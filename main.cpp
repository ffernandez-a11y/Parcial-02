//// =====================================================================
//  main.cpp -- PLANTILLA. Único lugar donde se usa cin/cout.
//  Protocolo de entrada/salida: ver anexo_enunciado.md
//    1) Pedir correo y contraseña (cin >> ...). Si iniciarSesion falla -> imprimir
//       "Usuario invalido" y terminar.
//    2) Menú en ciclo hasta elegir 0:
//       1 Listar productos (stock < 15)      4 Adicionar producto al carrito (pide id)
//       2 Comentarios desde una fecha (pide fecha dd/mm/yyyy)   5 Listar productos del carrito
//       3 Listar usuarios                    0 Salir
// =====================================================================
#include <iostream>
#include <string>
#include <vector>
#include "plataforma.h"

using namespace std;

int main() {
  
    vector<Usuario> usuarios = cargarUsuarios();
    vector<Producto> productos = cargarProductos();
    vector<Comentario> comentarios = cargarComentarios();
    vector<CarritoDeCompras> carritos;

   
    string correo, contrasena;

    cout << "Ingrese su correo: ";
    if (!(cin >> correo)) {
        cout << "Usuario invalido" << endl;
        return 0;
    }

    cout << "Ingrese su contrasena: ";
    if (!(cin >> contrasena)) {
        cout << "Usuario invalido" << endl;
        return 0;
    }

    Usuario usuarioLogueado;
    if (!iniciarSesion(usuarios, correo, contrasena, usuarioLogueado)) {
        cout << "Usuario invalido" << endl;
        return 0;
    }

   
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n MENU PRODUCTOS " << endl;
        cout << "1. Listar productos con stock menor a 15" << endl;
        cout << "2. Listar comentarios desde una fecha" << endl;
        cout << "3. Listar usuarios" << endl;
        cout << "4. Adicionar producto al carrito" << endl;
        cout << "5. Listar productos del carrito" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            break;
        }

        switch (opcion) {
            case 1: {
                vector<Producto> productosBajos = productosBajoStock(productos);
                for (const auto& prod : productosBajos) {
                    cout << prod.idProducto << " | " << prod.nombre << " | " << prod.stock << " unidades | $" << prod.precio << endl;
                }
                break;
            }

            case 2: {
                string fecha;
                cout << "Ingrese la fecha (dd/mm/yyyy): ";
                if (cin >> fecha) {
                    vector<Comentario> comentariosFiltrados = comentariosDesde(comentarios, fecha);
                    for (const auto& com : comentariosFiltrados) {
                        cout << com.idComentario << " | " << com.producto << " | " << com.usuario << " | " << com.fecha << " | " << com.comentario << endl;
                    }
                }
                break;
            }

            case 3: {
                vector<string> listaUsuarios = listarUsuariosFormateados(usuarios);
                for (const auto& linea : listaUsuarios) {
                    cout << linea << endl;
                }
                break;
            }

            case 4: {
                int id;
                cout << "Ingrese el ID del producto: ";
                if (cin >> id) {
                    ResultadoCarrito resultado = agregarAlCarrito(carritos, productos, usuarioLogueado, id);
                    if (resultado == CARRITO_OK) {
                        cout << "Producto agregado al carrito." << endl;
                    } else if (resultado == CARRITO_SIN_STOCK) {
                        cout << "Producto sin stock." << endl;
                    } else {
                        cout << "Producto invalido." << endl;
                    }
                }
                break;
            }

            case 5: {
                int idCarritoUsuario = -1;
                for (const auto& c : carritos) {
                    if (c.usuario.idUsuario == usuarioLogueado.idUsuario) {
                        idCarritoUsuario = c.idCarrito;
                        break;
                    }
                }

                if (idCarritoUsuario != -1) {
                    vector<Producto> productosEnCarrito = listarProductosCarrito(carritos, idCarritoUsuario);
                    for (const auto& prod : productosEnCarrito) {
                        cout << prod.idProducto << " | " << prod.nombre << " | $" << prod.precio << endl;
                    }

                    for (const auto& c : carritos) {
                        if (c.idCarrito == idCarritoUsuario) {
                            cout << "Subtotal: $" << c.subtotal << endl;
                            cout << "Impuestos: $" << c.impuestos << endl;
                            break;
                        }
                    }
                } else {
                    cout << "El carrito esta vacio." << endl;
                }
                break;
            }

            case 0:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    }

    return 0;
}
