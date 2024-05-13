#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#include "parcialm1.h"
//#include "clsarchivo.h"
#include "funciones.h"

void punto_1();
void punto_2();
void punto_3();
void punto_4();
void punto_5();
void punto_6();
void punto_7();
void punto_A();
void punto_B();

int main()
{
    ArchivoProveedores archi("proveedores.dat");
    Proveedor reg;
    int cont=archi.contarRegistros();
    for(int i=0;i<cont;i++){
        reg=archi.leerRegistro(i);
        reg.Mostrar();
        //cout<<" \n";
    }
//500 - 1500
    punto_5();
}
class clsObrasEnEjecucion{
public:
    char codigoObra[5];
    char direccion[30];
    int provincia;
    bool activo;
public:
    void setCodigoObra(const char *co){strcpy(codigoObra, co);}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setProvincia(int p){provincia=p;}
    void setActivo(bool a){activo=a;}
    void Mostrar(){
        cout<<" OBRAS EN EJECION" <<endl;
        cout<<codigoObra<<endl;
        cout<<direccion<<endl;
    }

    };//Fin de clase ObraEjecucion
bool grabarObrasEjecucion(clsObrasEnEjecucion reg) { ///GrabarArchivo
        FILE* p;
        p = fopen("obrasEjec", "ab");
        if(p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
void punto_A(){
    clsObrasEnEjecucion aux;

    Obra reg;
    ArchivoObras archi("obras.dat");
    int contadorReg = archi.contarRegistros();
    for(int i =0;i<contadorReg;i++){ //Recorrer Obras
        if(reg.getEstadoEjecucion()==3){//3 = Obras En Ejecucion
            //Guardamos los datos que necesitamos
            aux.setCodigoObra(reg.getCodigoObra());
            aux.setDireccion(reg.getDireccion());
            aux.setProvincia(reg.getProvincia());
            aux.setActivo(true);
            aux.Mostrar();
            grabarObrasEjecucion(aux);

        }
    }

}
///MOd Aberturas el precio*1.10
bool modificarRegistro(Material obj, int nroReg) { /// MODIFICA un Registro
        FILE* p = fopen("materiales.dat", "rb+");
        if (p == NULL) {            return false;        }
        fseek(p, nroReg * sizeof(Material), SEEK_SET);
        bool ok = fwrite(&obj, sizeof(Material), 1, p);
        fclose(p);
        return ok;
    }
void punto_7(){
    Material reg;
    ArchivoMateriales archi("materiales.dat");
    int contadorReg = archi.contarRegistros();
    for(int i =0;i<contadorReg;i++){ //Recorrer Obras
            reg=archi.leerRegistro(i);
            if(reg.getTipo()==3){//Abertura = 3
                reg.setPU(reg.getPU()*1.10);
                modificarRegistro(reg,i);
                cout<<"Registro Mod: "<<reg.getPU()<<endl;
            }
    }// Fin del For Leer Reg
}
///La/s provincia/s con más de 22 proveedore
void punto_5(){
    ArchivoProveedores archi("proveedores.dat");
    Proveedor reg;
    int cont=archi.contarRegistros();

    int contProv[24]={0};//Inicializo en cero

    for(int i=0;i<cont;i++){
        reg=archi.leerRegistro(i);
        contProv[reg.getProvincia()-1]++;// ++ = +1
    }
    for(int i=0;i<24;i++){
        //if(contProv[i]>1)
        if(contProv[i]>22)
            cout << "Prov tiene mas de 22 Prov: "<<i+1;
    }

}
