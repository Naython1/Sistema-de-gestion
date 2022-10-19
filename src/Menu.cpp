#include "Menu.h"
#include "../controller/funcionesTurnos.h"
Menu::Menu()
{
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
int Menu::principal()
{
            while (opc != 0){
                system("cls");
                setCuadro({42,10}, 15, 8, opc);
                rlutil::hidecursor();
                _cuadro.dibujar();
                _cuadro.mostrar_texto1();
                _cuadro.Resaltar1();
                    switch (rlutil::getkey()){
                    case 14:
                        if (opc == 1){
                            opc = 4;
                        }
                        else{
                            opc --;
                        }
                        break;
                    case 15:
                        if (opc == 4){
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

void Menu::Turnos()
{
        Archivo reg;
        Turno _turno;
        system("cls");
        mostrart();
        getch();
            rlutil::hidecursor();
            while (opc != 0)
            {
                setLista({20, 16}, 60, 40);
                setCuadro({42, 10}, 25, 4, opc);
                _lista.dibujarLista();
                _cuadro.dibujar();
                _cuadro.mostrar_texto2();
                _cuadro.Resaltar2();
                        int pos = 0;
                while (reg.leerDeDisco(pos++, _turno)){
                    gotoxy(22, 17+(pos*2));
                    _turno.Mostrar();
                }

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
                                system("cls");
                                        _turno.Cargar();
                                        reg.grabarEnDisco(_turno);
                                system("cls");
                                        break;
                                ///MODIFICAR///
                            case 2:
                                ///MOSTRAR///
                            case 3:
                                ///ELIMINAR///
                            case 4:
                                ///BUSCAR///
                            case 5:
                                ///VOLVER///
                            case 6:
                                opc = 1;
                                return;
                                }
                            break;
                            case 0:
                                break;

                                        }
                        }
}

void Menu::Clientes()
{
    Archivo reg;
    Cliente _cliente;
    int pos = 0;
    ///int valorAgregarCliente;
            rlutil::hidecursor();
            while (opc != 0)
            {
                system("cls");
                setCuadro({42, 10}, 25, 4, opc);
                _cuadro.dibujar();
                _cuadro.mostrar_texto3();
                _cuadro.Resaltar2();
                        gotoxy(1, 20);

                       while(reg.leerDeDisco(pos++, _cliente)){

                        _cliente.Mostrar();
                       }
                       pos = 0;
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
                            case 1: system("cls");
                                agregarRegistroCliente();
                                    break;
                                ///MODIFICAR///
                            case 2:
                                ///BUSCAR///
                            case 3:
                                ///ELIMINAR///
                            case 4:
                                ///VOLVER///
                                opc = 1;
                                return;
                                }
                            break;

                            case 0:
                                return;
                                system("pause");

                                        }
                        }

}
