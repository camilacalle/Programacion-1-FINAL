#include <iostream>
#include <stdexcept>
#include "Archivero.h"
#include "Autor.h"
#include "Noticia.h"
#include "Usuario.h"
#include "Comentarios.h"
#include "Persona.h"
using namespace std;

int main() {
    string titulo, descrip, medio, nombre, coment;
    int dia, mes, año, dni, edad, num;
    int ingreso1, ingreso2, com1;
    Persona persona;
    Autor autor;
    Usuario usuario;
    Noticia noticia[5];
    Comentarios comentario;
    Archivo archivo;

    do {
     try {
        cout << "\n\nBienvenido al portal de noticias MGC\n\n";
        cout << "Por favor, ingrese el numero del modo de acceso que desee!\n\n";
        cout << "1. Autor\n\n";
        cout << "2. Usuario - Lector\n\n";
        cout << "3. Eliminar noticias existentes\n\n";
        cout << "4. Salir del programa. \n\n";
        cin >> ingreso1;
        cin.ignore();
        switch (ingreso1) {
            case 1:
                cout << "Ingrese el nombre del autor: " << endl;
                getline(cin, nombre);
                cout << "Ingrese el DNI del autor: " << endl;
                cin >> dni;
                cin.ignore();
                cout << "Ingrese el medio al cual pertenece: " << endl;
                getline(cin, medio);
                autor.setNombre(nombre);
                autor.setDNI(dni);
                autor.setMedio(medio);

                for (int i = 0; i < 5; ++i) {
                    cout << "Ingrese el titulo de la noticia " << i << ": " << endl;
                    getline(cin, titulo);
                    cout << "Ingrese la descripcion de la noticia : " << endl;
                    getline(cin, descrip);
                    cout << "Ingrese el dia de la noticia : " << endl;
                    cin >> dia;
                        if (dia < 1 || dia > 31){
                            throw invalid_argument("Día inválido. Debe estar entre 1 y 31.");}
                    cout << "Ingrese el mes de la noticia : " << endl;
                    cin >> mes;
                        if (mes < 1 || mes > 12) {
                            throw invalid_argument("Mes inválido. Debe estar entre 1 y 12.");}
                    cout << "Ingrese el anio de la noticia : " << endl;
                    cin >> año;
                        if (año < 0 || año > 2024) {
                            throw invalid_argument("Año inválido. Debe estar entre 1900 y 2100.");}
                    cin.ignore();
                    noticia[i].setTitulo(titulo);
                    noticia[i].setDescripcion(descrip);
                    noticia[i].setDia(dia);
                    noticia[i].setMes(mes);
                    noticia[i].setAño(año);
                    noticia[i].setAutor(autor);}
                    archivo.grabarNoticias(noticia, 5);
                    break;
            case 2:
                    cout << "Ingrese el nombre del usuario: " << endl;
                    getline(cin, nombre);
                    cout << "Ingrese el DNI del usuario: " << endl;
                    cin >> dni;
                    cout << "Ingrese la edad del usuario: " << endl;
                    cin >> edad;
                    cin.ignore();
                    usuario.setNombre(nombre);
                    usuario.setDNI(dni);
                    usuario.setEdad(edad);
                    cout << "Por favor, ingrese el numero segun la accion que desee:\n\n";
                    cout << "1. Leer\n\n";
                    cout << "2. Comentar\n\n";
                    cin >> ingreso2;
                    cin.ignore();
                    switch (ingreso2) {
                        case 1:
                            archivo.leerNoticias();
                            break;
                        case 2:
                            for (int i = 0; i < 5; ++i) {
                                cout << "Titulo de la noticia " << i << ": " << endl;
                                cout << noticia[i].getTitulo() << endl;}
                            cout << "Ingrese la cantidad de comentarios que desea realizar: " << endl;
                            cin >> com1;
                            cin.ignore();
                            for (int i = 0; i < com1; ++i) {
                                cout << "Ingrese sobre que noticia desea realizar un comentario: " << endl;
                                cin >> num;
                                cin.ignore();
                                  if (num<0 || num>=5) {
                                    throw out_of_range("Indice de noticia fuera de rango.");}
                                cout << "Ingrese el comentario que desea realizar: " << endl;
                                getline(cin, coment);
                                comentario.setNumero(num);
                                comentario.setComentario(coment);
                                comentario.setUsuario(usuario);
                                noticia[num].setComentarios(comentario);}
                            archivo.grabarNoticias(noticia, 5);
                            break;
                        default:
                            cout << "Opción invalida, por favor intente nuevamente." << endl;
                            break;}
                    break;
            case 3:
                cout << "Eliminando noticias ..." << endl;
                archivo.eliminarNoticias();
                cout << "Noticias eliminadas." << endl;
                break;
            case 4:
                cout << "Cerrando el programa ..." << endl;
                break;
                default:
                cout << "Opcion invalida, por favor intente nuevamente." << endl;
                break;}
        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
            cin.clear();}
    } while (ingreso1 != 4);
    return 0;
}
