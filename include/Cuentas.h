#ifndef CUENTAS_H
#define CUENTAS_H
#include "Fecha.h"


class Cuenta
{
    private:
        int ID;
        Fecha fechaEmision;
        char nombre[30];
        char apellido[30];
        float monto;
        bool estado;
    public:
        /// CONSRUCTOR
        Cuenta();
        /// METODOS
        bool cargar(int);
        void mostrar();
        /// SETS
        void setID(int);
        void setFechaEmision(Fecha);
        void setNombre(const char *);
        void setApellido(const char *);
        bool setMonto(float);
        void setEstado(bool);
        /// GETS
        int getID();
        Fecha getFechaEmision();
        const char *getNombre();
        const char *getApellido();
        float getMonto();
        bool getEstado();
        /// DESTRUCTOR
        ~Cuenta();
};

#endif // CUENTAS_H