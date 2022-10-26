#include "Menu.h"

#include "../controller/funcionesPersona.h"
#include "../controller/funcionesServicios.h"
#include "../controller/funcionesCuentas.h"
#include "../controller/funcionesClientes.h"
#include "../controller/funcionesTurnos.h"

Menu::Menu(){
    opc = 1;
    _cuadro= {{42,10}, 15, 8, opc};
}

void Menu::setCuadro(origen coor, int largo, int alto, int opc){
    _cuadro.setCoor(coor);
    _cuadro.setlargo(largo);
    _cuadro.setalto(alto);
    _cuadro.setOpc(opc);
}

void Menu::setLista(origen coor, int largo, int alto){
    _lista.setCoor(coor);
    _lista.setlargo(largo);
    _lista.setalto(alto);
}

int Menu::principal(){
    while (opc != 0){
        system("cls");
        setCuadro({42,10}, 15, 12, opc);
        rlutil::hidecursor();
        _cuadro.dibujar();
        _cuadro.mostrar_texto1();
        _cuadro.Resaltar1();
        switch (rlutil::getkey()){
            case 14:
                if (opc == 1){
                    opc = 6;
                }
                else{
                    opc --;
                }
            break;
            case 15:
                if (opc == 6){
                    opc = 1;
                }
                else{
                    opc ++;
                }
            break;
            case 1:
                return opc;
            break;
            default:
                rlutil::nb_getch();
            break;
        }
    }
    return opc;
}

void Menu::Turnos(){
    rlutil::hidecursor();
    system("cls");
    while (opc != 0){
        setLista({20, 16}, 60, 40);
        setCuadro({36, 10}, 25, 4, opc);
        _lista.dibujarLista();
        _cuadro.dibujar();
        _cuadro.mostrar_texto2();
        _cuadro.Resaltar2();
        bajaFisicaTurnoAuto();
        mostrarTunoDelDia();
        switch (rlutil::getkey()){
            case 14:
                    if (opc < 3){
                        opc += 2;
                    }
                    else{

                    opc -=2;
                    }
                    break;
            case 15:
                    if (opc > 2){
                        opc -= 2;
                    }
                    else{

                    opc +=2;
                    }
                    break;
            case 16:
                    if (opc == 1 || opc == 3){
                        opc += 1;
                    }
                    else{
                    opc --;
                    }
                    break;
            case 17:
                    if (opc == 2 || opc == 4){
                        opc -= 1;
                    }
                    else{
                    opc ++;
                    }
                    break;
            case 1:
                ///ACA VAN LAS OPCIONES SEGUN DONDE SE PRESIONE ENTER
                switch (opc){
                    ///AGREGAR///
                    case 1:
                            agregarRegistroTurno();
                        break;
                        ///MODIFICAR///
                    case 2:
                            modificarFechaServicioTurno();
                        break;
                        ///MOSTRAR///
                    case 3:
                            mostrarTurnoPorId();
                        break;
                        ///VOLVER///
                    case 4:
                            opc = 1;
                            return;
                        break;
                }
            getch();
            system("cls");
        }
    }
}

void Menu::Clientes(){
    rlutil::hidecursor();
    system("cls");
    while (opc != 0){
        setCuadro({30, 10}, 40, 4, opc);
        _cuadro.dibujar();
        _cuadro.mostrar_texto3();
        _cuadro.Resaltar3();
        switch (rlutil::getkey()){
            case 14:
                    if (opc < 4){
                        opc += 3;
                    }
                    else{

                    opc -=3;
                    }
                    break;
            case 15:
                    if (opc > 3){
                        opc -= 3;
                    }
                    else{

                    opc +=3;
                    }
                    break;
            case 16:
                    if (opc == 1 || opc == 4){
                        opc += 2;
                    }
                    else{
                    opc --;
                    }
                    break;
            case 17:
                    if (opc == 3 || opc == 6){
                        opc -= 2;
                    }
                    else{
                    opc ++;
                    }
                    break;
            case 1:
                ///ACA VAN LAS OPCIONES SEGUN DONDE SE PRESIONE ENTER
                switch (opc){
                    ///AGREGAR///
                    case 1:
                            agregarRegistroCliente();

                        break;
                        ///MODIFICAR///
                    case 2:
                            modificarTelefonoCliente();

                        break;
                        ///MOSTRAR///
                    case 3:
                            mostrarClientes();
                        break;
                        ///ELIMINAR///
                    case 4: system("cls");
                            cout << "opcion 4 ELIMINAR" << endl;
                        break;
                        ///BUSCAR//
                    case 5:
                            mostrarClientePorDNI();
                        break;
                    case 6:
                            cout << "opcion 6" << endl;
                            opc = 1;
                            return;
                        break;
                }
            getch();
            system("cls");
        }
    }
}

void Menu::Persona(){
    rlutil::hidecursor();
    while (opc != 0){
        system("cls");
        setCuadro({30, 10}, 40, 4, opc);
        _cuadro.dibujar();
        _cuadro.mostrar_texto4();
        _cuadro.Resaltar4();
        _cuadro.Resaltar4();
        switch (rlutil::getkey()){
            case 14:
                if (opc < 4){
                    opc += 3;
                }
                else{
                    opc -=3;
                }
            break;
            case 15:
                    if (opc > 3){
                        opc -= 3;
                    }
                    else{
                        opc +=3;
                    }
            break;
            case 16:
                    if (opc == 1 || opc == 4){
                        opc += 2;
                    }
                    else{
                        opc --;
                    }
            break;
            case 17:
                if (opc == 3 || opc == 6){
                        opc -= 2;
                }
                else{
                    opc ++;
                }
            break;
            case 1:
                switch (opc){
                    case 1:
                        agregarRegistroPersona();
                    break;
                    case 2:
                        modificarPersona();
                    break;
                    case 3:
                        mostrarPersona();
                    break;
                    case 4:
                        eliminarPersona();
                    break;
                    case 5:
                        buscarPersona();
                    break;
                    case 6:
                        opc = 1;
                        return;
                    break;

                    }
            getch();
        }
    }
}

void Menu::Servicio(){
    rlutil::hidecursor();
    while (opc != 0){
        system("cls");
        setCuadro({30, 10}, 40, 4, opc);
        _cuadro.dibujar();
        _cuadro.mostrar_texto5();
        _cuadro.Resaltar5();
        _cuadro.Resaltar5();
        switch (rlutil::getkey()){
            case 14:
                if (opc < 4){
                    opc += 3;
                }
                else{
                    opc -=3;
                }
            break;
            case 15:
                    if (opc > 3){
                        opc -= 3;
                    }
                    else{
                        opc +=3;
                    }
            break;
            case 16:
                    if (opc == 1 || opc == 4){
                        opc += 2;
                    }
                    else{
                        opc --;
                    }
            break;
            case 17:
                if (opc == 3 || opc == 6){
                        opc -= 2;
                }
                else{
                    opc ++;
                }
            break;
            case 1:
                switch (opc){
                    case 1:
                        agregarRegistroServicio();
                    break;
                    case 2:
                        modificarServicio();
                    break;
                    case 3:
                        mostrarServicio();
                    break;
                    case 4:
                        eliminarServicio();
                    break;
                    case 5:
                        buscarServicio();
                    break;
                    case 6:
                        opc = 1;
                        return;
                    break;
                    }
            getch();
        }
    }
}

void Menu::Cuentas(){
    rlutil::hidecursor();
    while (opc != 0){
        system("cls");
        setCuadro({30, 10}, 40, 4, opc);
        _cuadro.dibujar();
        _cuadro.mostrar_texto6();
        _cuadro.Resaltar6();
        _cuadro.Resaltar6();
        switch (rlutil::getkey()){
            case 14:
                if (opc < 4){
                    opc += 3;
                }
                else{
                    opc -=3;
                }
            break;
            case 15:
                    if (opc > 3){
                        opc -= 3;
                    }
                    else{
                        opc +=3;
                    }
            break;
            case 16:
                    if (opc == 1 || opc == 4){
                        opc += 2;
                    }
                    else{
                        opc --;
                    }
            break;
            case 17:
                if (opc == 3 || opc == 6){
                        opc -= 2;
                }
                else{
                    opc ++;
                }
            break;
            case 1:
                switch (opc){
                    case 1:
                        agregarRegistroCuenta();
                    break;
                    case 2:
                        modificarCuenta();
                    break;
                    case 3:
                        mostrarCuenta();
                    break;
                    case 4:
                        eliminarCuenta();
                    break;
                    case 5:
                        buscarCuenta();
                    break;
                    case 6:
                        opc = 1;
                        return;
                    break;
                    }
            getch();
        }
    }
}

