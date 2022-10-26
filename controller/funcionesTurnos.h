#ifndef FUNCIONESTURNOS_H_INCLUDED
#define FUNCIONESTURNOS_H_INCLUDED

#include <iostream>
#include <ctime>

using namespace std;
//#include "Servicio.h"

/// PROTOTIPOS FUNCIONES GLOBALES TURNO

void borrarLista();

void agregarRegistroTurno();
    Turno cargarTurno();
        //bool validarCliente(int nD){
        bool validarTipoServicio(int tS);

void modificarFechaServicioTurno();
    int buscarIdTurno(int idT);

bool mostrarTurnoPorId();

void mostrarTunoDelDia();
    bool turnoHoy(Fecha f);

void bajaFisicaTurnoAuto();

/// DEFINICIONES FUNCIONES GLOBALES TURNO

void borrarLista(){
    int i, j;
    for(i = 0; i < 61; i++){
        for(j = 0; j < 41; j++){
            gotoxy(20 + i, 16 + j);
            cout << " ";
        }
    }
}

// 1 AGREGA REGISTROS TURNOS  AL ARCHIVO Turnos.dat
void agregarRegistroTurno(){
    Turno cita;
    Archivo archi;
    borrarLista();
    Cuadro cuadroTurnoCarga;
    cuadroTurnoCarga.setCoor({30,17});
    cuadroTurnoCarga.setalto(10);
    cuadroTurnoCarga.setlargo(40);
    cuadroTurnoCarga.dibujar();
    cita = cargarTurno();
    if(cita.getEstado() == false){ // ERROR EN FECHA O APERTURA DEL ARCHIVO
        gotoxy(42, 25);
        cout << "DATOS INVALIDOS";
        return;
    }
    if(archi.grabarEnDisco(cita)){ // GRABO EN DISCO
        gotoxy(42, 25);
        cout << "TURNO CARGADO";
        return;
    }
    gotoxy(42, 25);
    cout << "FALLO AL GRABAR EN EL DISCO";
    return; // FALLO GRABAR EN DISCO
}

Turno cargarTurno(){
    Turno cita;
    int idT, nD, tS;
    Fecha _fecha;
    Archivo archi;
    gotoxy(42, 18);
    cout << "DNI CLIENTE: ";
    cin >> nD;
    if(validarCliente(nD) == false){
        gotoxy(32, 20);
        cout << "EL CLIENTE INGERSADO ES INVALIDO";
        cita.setEstado(false);
        return cita;
    }
    gotoxy(42, 19);
    cout << "TIPO SERVICIO: ";
    cin >> tS;
    if(validarTipoServicio(tS) == false){
        gotoxy(32, 21);
        cout << "EL SERVICIO INGERSADO ES INVALIDO";
        cita.setEstado(false);
        return cita;
    }
    gotoxy(42, 20);
    cout << "INGRESE FECHA DE SERVICIO: ";
    if(_fecha.Cargar() == false){
        gotoxy(42, 24);
        cout << "FALLO CARGAR FECHA";
        cita.setEstado(false);
        return cita;
    }

    if(_fecha.validarFechaTurno(_fecha) == false){
        gotoxy(32, 24);
        cout << "LA FECHA INGRESADA ES INVALIDA";
        cita.setEstado(false);
        return cita;
    }
    idT = archi.contarRegistro(cita); // ESTE SERIA PK AUTOINCREMENTAL DE CLIENTE
    if(idT == -1){
        gotoxy(32, 24);
        cout << "FALLO APERTURA DEL ARCHIVO";
        cita.setEstado(false);
        return cita;
    }
    idT++;
    cita.Cargar(idT, _fecha, nD, tS);
    return cita;
}
/*
bool validarCliente(int nD){
    Cliente usuario;
    Archivo archi;
    int pos = 0;
    while(archi.leerDeDisco(pos, usuario)){
        if(nD == usuario.getDNI()){
            return usuario.getEstado();
        }
        pos++;
    }
    return false;
}*/

bool validarTipoServicio(int tS){
    Servicio servicio;
    Archivo archi;
    int pos = 0;
    while(archi.leerDeDisco(pos, servicio)){
        if(tS == servicio.getCodigo()){
            return servicio.getEstado();
        }
        pos++;
    }
    return false;
}

// 2 MODIFICA POR ID LOS REGISTROS DE TURNOS EN ARCHIVO Turnos.dat
void modificarFechaServicioTurno(){
    Archivo archi;
    Turno cita;
    int idT, pos;
    Fecha _fecha;
    borrarLista();
    Cuadro cuadroTurnoModificar;
    cuadroTurnoModificar.setCoor({28,17});
    cuadroTurnoModificar.setalto(10);
    cuadroTurnoModificar.setlargo(44);
    cuadroTurnoModificar.dibujar();
    // buscar el turno a modificar fecha de servicio
    gotoxy(30, 18);
    cout << "ID TURNO A MODIFICAR FECHA DE SERVICIO: ";
    cin >> idT;
    // leer si existe el turno
    pos = buscarIdTurno(idT);
    if(pos == -1){
        gotoxy(30, 20);
        cout << "NO EXISTE EL ID DE TURNO EN EL ARCHIVO" << endl;
        return;
    }
    archi.leerDeDisco(pos, cita);
    /// cambiar la fecha de servicio del turno
    gotoxy(32, 20);
    cout << "INGRESE LA NUEVA FECHA: " << endl;
    if(_fecha.Cargar() == false){
        gotoxy(42, 24);
        cout << "FALLO CARGAR FECHA" << endl;
        cita.setEstado(false);
        return;
    }
    if(_fecha.validarFechaTurno(_fecha) == false){
        gotoxy(32, 24);
        cout << "LA FECHA INGRESADA ES INVALIDA." << endl;
        return;
    }
    cita.setFechaServicio(_fecha);
    /// sobreescribir el registro
    if(archi.modificarEnDisco(pos, cita) == false){
        gotoxy(34, 23);
        cout << "ERROR AL MODIFICAR TURNO" << endl;
        return;
    }
    gotoxy(34, 23);
    cout << "TURNO MODIFICADO EXITOSAMENTE" << endl;
    return;
}

int buscarIdTurno(int idT){
    Archivo archi;
    Turno cita;
    int pos = 0;
    while(archi.leerDeDisco(pos, cita)){
        if(idT == cita.getIdTurno()){
            if(cita.getEstado()){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

// 3 MUESTRAR POR ID LOS REGISTROS DE TURNOS EN ARCHIVO Turnos.dat
bool mostrarTurnoPorId(){
    Archivo archi;
    Turno cita;
    int idT, pos;
    borrarLista();
    Cuadro cuadroTurnoMostarId;
    cuadroTurnoMostarId.setCoor({28,17});
    cuadroTurnoMostarId.setalto(10);
    cuadroTurnoMostarId.setlargo(44);
    cuadroTurnoMostarId.dibujar();
    /// buscar el turno a mostrar
    gotoxy(34, 18);
    cout << "ID DEL TURNO A MOSTRAR: ";
    cin >> idT;
    /// leer si existe el turno
    pos = buscarIdTurno(idT);
    if(pos == -1){
        gotoxy(30, 20);
        cout << "NO EXISTE EL ID DE TURNO EN EL ARCHIVO";
        return false;
    }
    archi.leerDeDisco(pos, cita);
    /// LISTAR EL TURNO FILTRADO
    cita.Mostrar();
    gotoxy(42, 26);
    cout << "TURNO LISTADO";
    return true;
}

// MOSTRAR TURNOS DEL DIA

void mostrarTunoDelDia(){
    Archivo archi;
    Turno _turno;
    Cliente usuario;
    Servicio servicio;
    int posT = 0, posC, posS, posY = 0;
    gotoxy(22, 17);
    cout << "HORA";
    gotoxy(30, 17);
    cout << "NOMBRE";
    gotoxy(52, 17);
    cout << "SERVICIO";
    gotoxy(72, 17);
    cout << "PRECIO";
    while(archi.leerDeDisco(posT, _turno)){
        if(turnoHoy(_turno.getFechaServicio()) == true){
            posC = buscarDNICliente(_turno.getDNI());
            archi.leerDeDisco(posC, usuario);
            if(_turno.getDNI() == usuario.getDNI() && usuario.getEstado()){
                posS = buscarCodigoServicio(_turno.getTipoServicio(), servicio);
                archi.leerDeDisco(posS, servicio);
                gotoxy(22, 19+(posY*2));
                if(_turno.getFechaServicio().getHora() < 10) cout << "0";
                cout << _turno.getFechaServicio().getHora() << ":";
                if(_turno.getFechaServicio().getMinuto() < 10) cout << "0" ;
                cout << _turno.getFechaServicio().getMinuto();
                gotoxy(30, 19+(posY*2));
                cout << usuario.getNombre();
                gotoxy(52, 19+(posY*2));
                cout << servicio.getDescripcion();
                gotoxy(72, 19+(posY*2));
                cout << "$ " << servicio.getPrecio();
                posY++;
            }
        }
        posT++;
    }
}

bool turnoHoy(Fecha f){
    time_t tiempo;
    struct tm *hoy;

    tiempo = time(NULL);
    hoy = localtime(&tiempo);
    if(f.getAnio() < (1900 + hoy -> tm_year)){
        return false;
    }
    else{
        if(f.getMes() < (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){

        return false;
        }
        else{
            if(f.getDia() < hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                return false;
            }
            else{
                if(f.getHora() < hoy -> tm_hour && f.getDia() == hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                    return false;
                }
                else{
                    if((f.getMinuto() + 30) < hoy -> tm_min && f.getHora() == hoy -> tm_hour && f.getDia() == hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void bajaFisicaTurnoAuto(){
    Archivo archi;
    Turno _turno;
    int pos = 0;
    FILE *pBakT, *pDatT;
    /// copia de seguridad del archivo
    pBakT = fopen("Turnos.bak", "wb"); /// vacio Turnos.bak
    if(pBakT == NULL) return;
    while(archi.leerDeDisco(pos, _turno)){
        fwrite(&_turno, sizeof(Turno), 1, pBakT);
        pos++;
    }
    /// comienza borrado fisico
    fclose(pBakT);
    pDatT = fopen("Turnos.dat", "wb"); /// vacio Turnos.dat
    if(pDatT == NULL) return;
    pBakT = fopen("Turnos.bak", "rb"); /// abre Turnos.bak
    if(pBakT == NULL){
        fclose(pDatT);
        return;
    }
    while(fread(&_turno, sizeof(Turno), 1, pBakT) == true){
        if(turnoHoy(_turno.getFechaServicio()) == true){
            fwrite(&_turno, sizeof(Turno), 1, pDatT); /// borrado fisico
        }
    }
    fclose(pBakT);
    fclose(pDatT);
}

#endif // FUNCIONESTURNOS_H_INCLUDED
