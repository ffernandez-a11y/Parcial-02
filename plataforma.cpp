// =====================================================================
//  plataforma.cpp -- PLANTILLA. Implementen aqui TODAS las funciones de plataforma.h.
//  * No modifiquen plataforma.h.
//  * Aqui NO se usa cin/cout (eso va en main.cpp).
//  * Al DEFINIR productosBajoStock NO repitan el valor por defecto del parametro.
// =====================================================================
// =====================================================================
// plataforma.cpp -- Lógica principal del parcial
// =====================================================================
// =====================================================================
// plataforma.cpp -- Lógica principal del parcial
// =====================================================================
#include "plataforma.h"
#include <cctype>
#include <sstream>

static std::string convertirAMayusculas(std::string texto) {
    for (size_t i = 0; i < texto.length(); i++) {
        texto[i] = std::toupper(static_cast<unsigned char>(texto[i]));
    }
    return texto;
}

struct Fecha {
    int dia = 0;
    int mes = 0;
    int anio = 0;
    bool esValida = false;
};

static Fecha parsearFecha(const std::string& strFecha) {
    Fecha f;
    char sep1 = 0, sep2 = 0;
    std::stringstream ss(strFecha);
   
    if (ss >> f.dia >> sep1 >> f.mes >> sep2 >> f.anio) {
        if (sep1 == '/' && sep2 == '/' && f.dia >= 1 && f.dia <= 31 &&
            f.mes >= 1 && f.mes <= 12 && f.anio > 0) {
            f.esValida = true;
        }
    }
    return f;
}

static bool esFechaMayorOIgual(const Fecha& f1, const Fecha& f2) {
    if (f1.anio != f2.anio) return f1.anio > f2.anio;
    if (f1.mes != f2.mes) return f1.mes > f2.mes;
    return f1.dia >= f2.dia;
}

std::vector<Usuario> cargarUsuarios() {
    return {
        {1, "Juan Pérez", "juan.perez@email.com", "Qwerty123", "Carrera 45 #10-20", "Tarjeta de crédito"},
        {2, "Ana Gómez", "ana.gomez@email.com", "Pass456", "Calle 21 #35-50", "PayPal"},
        {3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789", "Avenida Principal #100", "Transferencia bancaria"},
        {4, "Sofía Martínez", "sofia.martinez@email.com", "Clave987", "Calle 8 #20-30", "Efectivo"},
        {5, "Diego Fernández", "diego.fernandez@email.com", "Contra654", "Carrera 77 #40-60", "Tarjeta débito"}
    };
}

std::vector<Producto> cargarProductos() {
    return {
        {1, "Laptop", "Portátil con pantalla Full HD y SSD de 512GB", 89999.0, 10},
        {2, "Smartphone", "Teléfono con cámara de 108MP y carga rápida", 49950.0, 20},
        {3, "Tablet", "Dispositivo con pantalla táctil de 10 pulgadas", 29999.0, 15},
        {4, "Auriculares", "Audífonos inalámbricos con cancelación de ruido", 12999.0, 25},
        {5, "Teclado", "Teclado mecánico con iluminación RGB", 8999.0, 30},
        {6, "Mouse", "Ratón inalámbrico con sensor óptico de alta precisión", 5999.0, 50},
        {7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 49900.0, 12},
        {8, "Impresora", "Láser multifuncional con Wi-Fi", 17999.0, 18},
        {9, "Camara", "Cámara digital con lente profesional", 79999.0, 8},
        {10, "Smartwatch", "Reloj inteligente con GPS y monitoreo cardíaco", 19999.0, 22},
        {11, "Silla Gamer", "Silla ergonómica ajustable con soporte lumbar", 29999.0, 14},
        {12, "Microondas", "Horno microondas con múltiples funciones", 12999.0, 40},
        {13, "Refrigerador", "Frigorífico doble puerta con sistema No Frost", 119999.0, 5},
        {14, "Lavadora", "Lavadora automática con capacidad de 10kg", 59999.0, 7},
        {15, "Cafetera", "Cafetera express con vaporizador de leche", 14999.0, 35},
        {16, "Drone", "Drone con cámara 4K y estabilizador", 69999.0, 9},
        {17, "Bocina Bluetooth", "Altavoz portátil con sonido envolvente", 8999.0, 33},
        {18, "Videocamara", "Videocámara profesional con grabación en 4K", 99999.0, 6},
        {19, "TV LED", "Televisor inteligente de 55 pulgadas con HDR", 74999.0, 11},
        {20, "Batería Externa", "Batería de 20000mAh con carga rápida", 3999.0, 45},
        {21, "Disco Duro", "Disco duro externo de 2TB", 12999.0, 28},
        {22, "Memoria USB", "Pendrive de 128GB", 2999.0, 60},
        {23, "Router", "Router Wi-Fi 6 de alta velocidad", 19999.0, 16},
        {24, "Joystick", "Control inalámbrico para videojuegos", 7999.0, 20},
        {25, "Fuente de Poder", "Fuente de alimentación para PC de 750W", 8999.0, 17},
        {26, "SSD", "Unidad de almacenamiento SSD de 1TB", 14999.0, 32},
        {27, "Altavoces", "Par de bocinas estéreo con subwoofer", 13999.0, 23},
        {28, "Webcam", "Cámara web Full HD con micrófono integrado", 6999.0, 37},
        {29, "Procesador", "CPU Intel i7 de última generación", 34999.0, 9},
        {30, "Motherboard", "Placa base compatible con procesadores modernos", 19999.0, 13},
        {31, "Memoria RAM", "Módulo de RAM DDR4 de 16GB", 7999.0, 41},
        {32, "Fuente Solar", "Panel solar portátil con batería integrada", 24999.0, 4},
        {33, "Control Remoto", "Mando universal para TV y dispositivos", 2499.0, 50},
        {34, "Termostato", "Termostato digital programable", 9999.0, 22},
        {35, "Smart Lock", "Cerradura electrónica con huella digital", 19999.0, 6},
        {36, "Proyector", "Proyector LED con resolución Full HD", 29999.0, 12},
        {37, "Switch Ethernet", "Switch de red de 8 puertos", 5999.0, 38},
        {38, "Reloj Digital", "Reloj inteligente con pantalla AMOLED", 8999.0, 26},
        {39, "Luces LED", "Tiras LED RGB con control remoto", 3999.0, 55},
        {40, "Estabilizador", "Estabilizador de voltaje para dispositivos electrónicos", 15999.0, 10},
        {41, "Cargador Inalámbrico", "Base de carga inalámbrica rápida", 4999.0, 30},
        {42, "HDD Externo", "Disco duro portátil de 4TB", 17999.0, 15},
        {43, "Microfono", "Micrófono profesional para grabación", 14999.0, 7},
        {44, "Altavoz Inteligente", "Asistente de voz con altavoz integrado", 12999.0, 20},
        {45, "Antena Wi-Fi", "Amplificador de señal inalámbrico", 7999.0, 33},
        {46, "Climatizador", "Aire acondicionado portátil con control remoto", 29999.0, 5},
        {47, "Raspberry Pi", "Kit de desarrollo con Raspberry Pi 4", 12999.0, 19},
        {48, "Capturadora", "Placa de captura de video en alta resolución", 19999.0, 8},
        {49, "Smart Plug", "Enchufe inteligente compatible con asistentes virtuales", 3999.0, 42},
        {50, "Timbre Inteligente", "Timbre con cámara y conexión a Wi-Fi", 14999.0, 10}
    };
}

std::vector<Comentario> cargarComentarios() {
    return {
        {1, "Laptop", "Juan Pérez", "Excelente rendimiento; muy rápida. ¡Me encanta!", "1/05/2025"},
        {2, "Smartphone", "Ana Gómez", "Buena cámara pero la batería dura poco.", "3/05/2025"},
        {3, "Tablet", "Carlos Ruiz", "No me gustó; pantalla de baja calidad.", "5/05/2025"},
        {4, "Auriculares", "Sofía Martínez", "Sonido aceptable pero el material parece frágil.", "6/05/2025"},
        {5, "Teclado", "Diego Fernández", "Muy buen teclado mecánico; excelente respuesta.", "8/05/2025"},
        {6, "Mouse", "Ana Gómez", "El sensor no es tan preciso como esperaba.", "10/05/2025"},
        {7, "Monitor", "Carlos Ruiz", "Colores vibrantes y buena resolución. Muy satisfecho.", "12/05/2025"},
        {8, "Impresora", "Juan Pérez", "Tarda mucho en imprimir; no me convence.", "13/05/2025"},
        {9, "Cámara", "Sofía Martínez", "Increíble calidad de imagen; fotos súper nítidas.", "15/05/2025"},
        {10, "Smartwatch", "Diego Fernández", "Buena batería; pero la pantalla no es muy brillante.", "18/05/2025"},
        {11, "Silla Gamer", "Lucía Rodríguez", "Comodidad espectacular; perfecto para largas sesiones de juego.", "20/05/2025"},
        {12, "Microondas", "Andrés Ramírez", "Calienta bien pero hace mucho ruido.", "22/05/2025"},
        {13, "Refrigerador", "María García", "Espacioso y enfría rápido; muy recomendado.", "24/05/2025"},
        {14, "Lavadora", "Javier Martínez", "Lava bien pero el ciclo es muy largo.", "26/05/2025"},
        {15, "Cafetera", "Carolina López", "Hace café delicioso; fácil de usar.", "28/05/2025"},
        {16, "Drone", "Daniel Castro", "Muy divertido pero la batería dura poco.", "30/05/2025"},
        {17, "Bocina Bluetooth", "Paola Herrera", "Sonido potente y buena conexión Bluetooth.", "1/06/2025"},
        {18, "Videocámara", "Esteban Rojas", "Perfecta para grabaciones profesionales.", "3/06/2025"},
        {19, "TV LED", "Fernanda Sánchez", "Imagen excelente pero el sonido podría mejorar.", "5/06/2025"},
        {20, "Batería Externa", "Camilo Torres", "Carga bien pero es un poco pesada.", "7/06/2025"},
        {21, "Disco Duro", "Gabriela Suárez", "Gran capacidad de almacenamiento; funciona rápido.", "9/06/2025"},
        {22, "Memoria USB", "Raúl Espinosa", "Buen tamaño pero la velocidad de transferencia es baja.", "11/06/2025"},
        {23, "Router", "Verónica Mendoza", "Señal potente; cubre toda la casa.", "13/06/2025"},
        {24, "Joystick", "Fabio Jiménez", "Comodo y resistente; ideal para gaming.", "15/06/2025"},
        {25, "Fuente de Poder", "Ricardo Vargas", "Funciona bien pero los cables son muy cortos.", "17/07/2025"},
        {26, "SSD", "Silvia Gómez", "Velocidad increíble; mi PC va mucho más rápido ahora.", "19/06/2025"},
        {27, "Altavoces", "Martín Aguilar", "Sonido envolvente; muy buena compra.", "21/06/2025"},
        {28, "Webcam", "Valentina Pérez", "Imagen clara pero el micrófono es deficiente.", "23/06/2025"},
        {29, "Procesador", "José Ramírez", "Rendimiento impecable; ideal para gaming y diseño.", "25/06/2025"},
        {30, "Motherboard", "Natalia Correa", "Buenas prestaciones pero la instalación fue complicada.", "27/06/2025"},
        {31, "Memoria RAM", "Julio Fernández", "Expande muy bien el rendimiento del sistema.", "29/06/2025"},
        {32, "Fuente Solar", "Amanda Castro", "Energía confiable pero la batería es pequeña.", "1/07/2025"},
        {33, "Control Remoto", "Pedro Duarte", "Fácil de usar; reconoce muchos dispositivos.", "3/07/2025"},
        {34, "Termostato", "Isabela Medina", "Regula bien la temperatura; intuitivo de usar.", "5/07/2025"},
        {35, "Smart Lock", "Oscar Rodríguez", "Seguridad y tecnología en un solo dispositivo.", "7/07/2025"},
        {36, "Proyector", "Cristina Vargas", "Imagen nítida pero requiere una sala oscura.", "9/07/2025"},
        {37, "Switch Ethernet", "Mario Hernández", "Buena velocidad de conexión; estable.", "11/07/2025"},
        {38, "Reloj Digital", "Sofía Ramírez", "Pantalla atractiva pero la batería dura poco.", "13/07/2025"},
        {39, "Luces LED", "Andrea Gutiérrez", "Buenas opciones de colores; buen diseño.", "15/07/2025"},
        {40, "Estabilizador", "Pablo Medina", "Protege bien contra variaciones de voltaje.", "17/07/2025"},
        {41, "Cargador Inalámbrico", "Patricia López", "Carga rápido pero requiere posicionamiento preciso.", "19/07/2025"},
        {42, "HDD Externo", "Gonzalo Espinoza", "Mucho espacio; resistente y confiable.", "21/07/2025"},
        {43, "Micrófono", "Elena Herrera", "Calidad de sonido profesional; ideal para podcast.", "23/07/2025"},
        {44, "Altavoz Inteligente", "Diego Soto", "Responde bien a comandos de voz; útil en casa.", "25/07/2025"},
        {45, "Antena Wi-Fi", "Miguel Rojas", "Amplifica bien la señal pero el rango es limitado.", "27/07/2025"},
        {46, "Climatizador", "Estefanía Carrillo", "Enfría rápido pero es algo ruidoso.", "29/07/2025"},
        {47, "Raspberry Pi", "Manuel Vargas", "Perfecto para proyectos electrónicos y programación.", "31/07/2025"},
        {48, "Capturadora", "Luisa Mejía", "Ideal para streaming y grabaciones en alta calidad.", "2/08/2025"},
        {49, "Smart Plug", "Victoria Torres", "Muy práctico; fácil de conectar y configurar.", "4/08/2025"},
        {50, "Timbre Inteligente", "Federico Montoya", "Buena cámara; útil para seguridad.", "6/08/2025"}
    };
}

bool iniciarSesion(const std::vector<Usuario>& usuarios, const std::string& correo,
                   const std::string& contrasena, Usuario& usuarioOut) {
    for (size_t i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].correoElectronico == correo && usuarios[i].contrasena == contrasena) {
            usuarioOut = usuarios[i];
            return true;
        }
    }
    return false;
}

std::vector<Producto> productosBajoStock(const std::vector<Producto>& productos, int umbral) {
    std::vector<Producto> resultado;
    for (const auto& prod : productos) {
        if (prod.stock < umbral) {
            resultado.push_back(prod);
        }
    }
    return resultado;
}

std::vector<Comentario> comentariosDesde(const std::vector<Comentario>& comentarios, const std::string& fecha) {
    Fecha fLimite = parsearFecha(fecha);
    if (!fLimite.esValida) {
        return {};
    }

    std::vector<Comentario> resultado;
    for (const auto& com : comentarios) {
        Fecha fActual = parsearFecha(com.fecha);
        if (fActual.esValida && esFechaMayorOIgual(fActual, fLimite)) {
            resultado.push_back(com);
        }
    }
    return resultado;
}

std::vector<std::string> listarUsuariosFormateados(const std::vector<Usuario>& usuarios) {
    std::vector<std::string> lista;
    for (const auto& u : usuarios) {
        std::string usuarioFormateado = std::to_string(u.idUsuario) + " | " +
                                       convertirAMayusculas(u.nombre) + " | " +
                                       u.correoElectronico + " | " +
                                       u.direccion + " | " +
                                       u.metodoDePago;
        lista.push_back(usuarioFormateado);
    }
    return lista;
}

int siguienteIdCarrito(const std::vector<CarritoDeCompras>& carritos) {
    if (carritos.empty()) {
        return 1;
    }
    return carritos.back().idCarrito + 1;
}

ResultadoCarrito agregarAlCarrito(std::vector<CarritoDeCompras>& carritos, std::vector<Producto>& productos,
                                  const Usuario& usuario, int idProducto) {
    Producto* prodEncontrado = nullptr;
    for (auto& p : productos) {
        if (p.idProducto == idProducto) {
            prodEncontrado = &p;
            break;
        }
    }

    if (prodEncontrado == nullptr) {
        return CARRITO_PRODUCTO_INVALIDO;
    }

    if (prodEncontrado->stock <= 0) {
        return CARRITO_SIN_STOCK;
    }

    CarritoDeCompras* carritoUsuario = nullptr;
    for (auto& c : carritos) {
        if (c.usuario.idUsuario == usuario.idUsuario) {
            carritoUsuario = &c;
            break;
        }
    }

    if (carritoUsuario == nullptr) {
        CarritoDeCompras nuevoCart;
        nuevoCart.idCarrito = siguienteIdCarrito(carritos);
        nuevoCart.usuario = usuario;
        nuevoCart.subtotal = 0.0;
        nuevoCart.impuestos = 0.0;
        carritos.push_back(nuevoCart);
        carritoUsuario = &carritos.back();
    }

    prodEncontrado->stock -= 1;
    carritoUsuario->productos.push_back(*prodEncontrado);
   
    carritoUsuario->subtotal += prodEncontrado->precio;
    carritoUsuario->impuestos = carritoUsuario->subtotal * TASA_IVA;

    return CARRITO_OK;
}

std::vector<Producto> listarProductosCarrito(const std::vector<CarritoDeCompras>& carritos, int idCarrito) {
    for (const auto& cart : carritos) {
        if (cart.idCarrito == idCarrito) {
            return cart.productos;
        }
    }
    return {};
}

