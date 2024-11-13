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

