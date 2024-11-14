#include <iostream>
using namespace std;
class persona{
    private:
    string nombre;
    int dni;
    public:
    persona();
    persona(int , string);
    void setDNI(int );
    int getDNI();
    void setNombre(string);
    string getNombre();
};
class Usuario : public persona {
private:
    int edad;
public:
    Usuario();
    Usuario(int , string , int);
    int getEdad();
    void setEdad(int );
    string getAutor();
    void mostrarUsuario();
};
class Autor : public persona {
private:
    string medio;
public: 
    Autor(int , string , string );
    Autor();
    ~Autor();// destructor 
    string getMedio();
    void setMedio(string );
    void mostrarAutor();
};
class Comentarios {
private:
    int numero;
    string texto;
    Usuario usuario;

public:
    Comentarios(int , string , Usuario );
    Comentarios();
    ~Comentarios();

    void setComentario(string );
    string getComentario() ;

    void setNumero(int );
    int getNumero() ;

    void setUsuario(Usuario );
    Usuario getUsuario() ;
};
class Noticia {
private:
    string titulo;
    string descripcion;
    int año;
    int mes;
    int dia;
    Autor autor;
    Comentarios comentarios;
    bool tieneComentario;
public:
    Noticia();

    Noticia(string , string , int , int , int , Autor , Comentarios );

    ~Noticia();

    void setTitulo(string );
    string getTitulo();

    void setDescripcion(string );
    string getDescripcion();

    void setDia(int );
    int getDia();

    void setAño(int );
    int getAño();

    void setMes(int );
    int getMes();

    void setAutor(Autor );
    Autor getAutor() ;

    void setComentarios(Comentarios );
    Comentarios getComentarios() ;

};
persona::persona(int _dni, string _nombre) {
    dni = _dni;
    nombre = _nombre;
}

persona::persona() {}

void persona::setDNI(int _dni) {
    dni = _dni;
}

int persona::getDNI() {
    return dni;
}

void persona::setNombre(string _nombre) {
    nombre = _nombre;
}

string persona::getNombre() {
    return nombre;
}

// Implementación de la clase usuario
Usuario::Usuario(int _dni, string _nombre, int _edad) : persona(_dni, _nombre) {
    edad = _edad;
}

Usuario::Usuario() {}

void Usuario::setEdad(int _edad) {
    edad = _edad;
}

int Usuario::getEdad() {
    return edad;
}

void Usuario::mostrarUsuario() {
    cout << "Datos del Usuario:" << endl;
    cout << "DNI: " << getDNI() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Edad: " << getEdad() << endl;
}

// Implementación de la clase autor
Autor::Autor(int _dni, string _nombre, string _medio) : persona(_dni, _nombre) {
    medio = _medio;
}

Autor::Autor() {}

Autor::~Autor() {}

void Autor::setMedio(string _medio) {
    medio = _medio;
}

string Autor::getMedio() {
    return medio;
}

void Autor::mostrarAutor() {
    cout << "Datos del Autor:" << endl;
    cout << "DNI: " << getDNI() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Medio: " << getMedio() << endl;
}
//
Comentarios::Comentarios(int _numero, string _texto, Usuario _usuario) {}

// Constructor por defecto
Comentarios::Comentarios() {}

// Destructor
Comentarios::~Comentarios() {}

// Métodos set y get
void Comentarios::setComentario(string _texto) {
    texto = _texto;
}

string Comentarios::getComentario()  {
    return texto;
}

void Comentarios::setNumero(int _numero) {
    numero = _numero;
}

int Comentarios::getNumero()  {
    return numero;
}

void Comentarios::setUsuario(Usuario _usuario) {
    usuario = _usuario;
}

Usuario Comentarios::getUsuario()  {
    return usuario;
}
//
Noticia::Noticia(string _titulo, string _descripcion, int _año, int _mes, int _dia, Autor _autor, Comentarios _comentarios) {}

// Constructor por defecto
Noticia::Noticia() {}

// Destructor
Noticia::~Noticia() {}

// Métodos set y get
void Noticia::setTitulo(string _titulo) {
    titulo = _titulo;
}

string Noticia::getTitulo()  {
    return titulo;
}

void Noticia::setDescripcion(string _descripcion) {
    descripcion = _descripcion;
}

string Noticia::getDescripcion()  {
    return descripcion;
}

void Noticia::setDia(int _dia) {
    dia = _dia;
}

int Noticia::getDia()  {
    return dia;
}

void Noticia::setMes(int _mes) {
    mes = _mes;
}

int Noticia::getMes()  {
    return mes;
}

void Noticia::setAño(int _año) {
    año = _año;
}

int Noticia::getAño()  {
    return año;
}

void Noticia::setAutor(Autor _autor) {
    autor = _autor;
}

Autor Noticia::getAutor()  {
    return autor;
}

void Noticia::setComentarios(Comentarios _comentarios) {
    comentarios = _comentarios;
}

Comentarios Noticia::getComentarios()  {
    return comentarios;
}
