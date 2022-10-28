#ifndef FUNCIONESSERVICIOS_H_INCLUDED
#define FUNCIONESSERVICIOS_H_INCLUDED

#include <iostream>

using namespace std;

/// DECLARACION DE FUNCIONES

void agregarRegistroServicio();

void mostrarServicio();

void modificarServicio();
    int buscarCodigoServicio(int, Servicio);

void buscarServicio();

void eliminarServicio();

///////////// DEFINICION DE AGREGAR REGISTRO SERVICIO

void agregarRegistroServicio(){
    Cuadro cuadro;
    cuadro.setCoor({30,16});
    cuadro.setalto(8);
    cuadro.setlargo(40);
    cuadro.dibujar();
    int var;
    Archivo archivo;
    Servicio servicio;
    var = archivo.contarRegistro(servicio);
    if(var == -1){
        gotoxy (41, 22);
        cout << "FALLO AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    var += 1;
    if(servicio.cargar(var)==false){
        gotoxy (35, 22);
        cout << "EL PRECIO NO PUEDE SER NEGATIVO" << endl;
        return;
    }
    if(archivo.grabarEnDisco(servicio)==false){
        gotoxy (39, 22);
        cout << "FALLO AL GUARDAR EL REGISTRO" << endl;
        return;
    }
    gotoxy (42, 22);
    cout << "REGISTRO GUARDADO" << endl;
}

///////////// DEFINICION DE MOSTRAR SERVICIO

void mostrarServicio(){
    Cuadro cuadro;
    cuadro.setCoor({30,16});
    cuadro.setalto(12);
    cuadro.setlargo(40);
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio;
    int pos = 0;
    int cont = 0;
    if(archivo.contarRegistro(servicio)==0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS" << endl;
        return;
    }
    while(archivo.leerDeDisco(pos, servicio)){
        gotoxy(38, cont+18);
        if(servicio.mostrar()==true){
            cont++;
        }
        cout << endl;
        pos++;
    }
    if(cont == 0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS" << endl;
    }
}

///////////// DEFINICION DE MODIFICAR SERVICIO

void modificarServicio(){
    Cuadro cuadro;
    cuadro.setCoor({24,16});
    cuadro.setalto(8);
    cuadro.setlargo(52);
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio;
    int cod, pos;
    float pre;
    gotoxy (27, 18);
    cout << "INGRESAR EL CODIGO DEL SERVICIO A MODIFICAR: ";
    cin >> cod;
    pos = buscarCodigoServicio(cod,servicio);
    if(pos == -1){
        gotoxy (28, 21);
        cout << "NO EXISTE EL CODIGO DEL SERVICO EN EL ARCHIVO" << endl;
        return;
    }
    archivo.leerDeDisco(pos,servicio);
    gotoxy (36, 20);
    cout << "INGRESAR NUEVO PRECIO: " << endl;
    gotoxy(59, 20);
    cin >> pre;
    if(servicio.setPrecio(pre)==false){
        gotoxy (34, 22);
        cout << "EL PRECIO NO PUEDE SER NEGATIVO" << endl;
        return;
    }
    if(archivo.modificarEnDisco(pos,servicio)==false){
        gotoxy (34, 22);
        cout << "ERROR AL MODIFICAR EL PERSONAL" << endl;
        return;
    }
    gotoxy (34, 22);
    cout << "REGISTO MODIFICADO EXISTOSAMENTE" << endl;
}

int buscarCodigoServicio(int var, Servicio obj){
    Archivo archivo;
    int pos = 0;
    while(archivo.leerDeDisco(pos,obj)){
        if(var == obj.getCodigo()){
            if(obj.getEstado()==true){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

///////////// DEFINICION DE BUSCAR SERVICIO

void buscarServicio(){
    Cuadro cuadro;
    cuadro.setCoor({24,16});
    cuadro.setalto(8);
    cuadro.setlargo(52);
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio;
    int pos,cod;
    gotoxy(29, 18);
    cout << "INGRESE EL NUMERO CODIGO DEL SERVICIO: ";
    cin >> cod;
    pos = buscarCodigoServicio(cod,servicio);
    if(pos == -1){
        gotoxy(28, 21);
        cout << "NO EXISTE EL CODIGO DE SERVICIO EN EL ARCHIVO" << endl;
        return;
    }
    archivo.leerDeDisco(pos,servicio);
    gotoxy(38, 21);
    servicio.mostrar();
    cout << endl;
}

///////////// DEFINICION DE ELIMINAR SERVICIO

void eliminarServicio(){
    Cuadro cuadro;
    cuadro.setCoor({24,16});
    cuadro.setalto(8);
    cuadro.setlargo(52);
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio;
    int cod, pos;
    gotoxy (28, 18);
    cout << "INGRESAR EL CODIGO DE SERVICIO A ELIMINAR: ";
    cin >> cod;
    pos = buscarCodigoServicio(cod,servicio);
    if(pos == -1){
        gotoxy (28, 21);
        cout << "NO EXISTE EL CODIGO DE SERVICIO EN EL ARCHIVO" << endl;
        return;
    }
    if(archivo.modificarEnDisco(pos,servicio)==false){
        gotoxy (32, 21);
        cout << "ERROR AL BORRAR EL SERVICIO" << endl;
        return;
    }
    gotoxy (36, 21);
    cout << "REGISTO BORRADO EXISTOSAMENTE" << endl;
}

#endif // FUNCIONESSERVICIOS_H_INCLUDED
