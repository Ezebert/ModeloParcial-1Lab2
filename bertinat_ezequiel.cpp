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
void punto_8();
void punto_9();

int main()
{
    int v[5]={3,1,22,6,2};
    cout<<buscarPosMin(v,5);
    //ArchivoProveedores archi("proveedores.dat");
    Compra reg;

   // reg.Mostrar();
    /*
    int cont = archi.contarRegistros();
    for(int i = 0 ;i <= cont ; i++){
        reg=archi.leerRegistro(i);
        reg.Mostrar();
    }
    cout<<" ============"<<endl;
    punto_2();
    */
    }
///DAR LA BAJA LOGICA DELL AÑO 2020
bool modificarRegistro(Compra obj, int nroReg) {
        FILE* p = fopen("compras.dat", "rb+");
        if (p == NULL) {            return false;        }
        fseek(p, nroReg * sizeof(Compra), SEEK_SET);
        bool ok = fwrite(&obj, sizeof(Compra), 1, p);
        fclose(p);
        return ok;
}
void punto_6(){
    ArchivoCompras archi("compras.dat");
    Compra reg;
    int cont = archi.contarRegistros();
    for(int i = 0 ; i< cont;i++){
        reg= archi.leerRegistro(i);
        if(reg.getFechaCompra().getAnio()==2022)
            reg.setActivo(false);
            modificarRegistro(reg,i);
        }
}

bool grabarObrasEjecucion(Material reg){
    FILE *p;
    p=fopen("ObrasEjecucion.dat","RB+");
    //crequeo
    if(p==NULL) return false;
    bool resp = fwrite(&reg, sizeof (reg),1,p);
    fclose(p);
}
void punto_7(){
    ArchivoMateriales archi("materiales.dat");
    int cont = archi.contarRegistros();
    for(int i=0;i<cont;i++){
        if(archi.leerRegistro(i).getTipo()==3){
            archi.leerRegistro(i).setPU(archi.leerRegistro(i).getPU()*1.10);
            //grabarMaterias(archi.ArchivoMateriales(i));
        }
    }
}


///Generar un archivo con el código de obra,
/// la dirección y la provincia, de las obras cuyo
///estado de ejecución sea "en ejecución".
class ObraEjecucion{
private:
    char codigoObra[5];
    char direccion[30];
    int provincia;
    bool activo;
public:
    void setCodigoObra(const char *co){strcpy(codigoObra, co);}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setProvincia(int p){provincia=p;}
    void setActivo(bool a){activo=a;}
    };//Fin de clase ObraEjecucion

bool grabarObrasEjecucion(ObraEjecucion reg){
    FILE *p;
    p=fopen("ObrasEjecucion.dat","AB");
    //crequeo
    if(p==NULL) return false;
    bool resp = fwrite(&reg, sizeof (reg),1,p);
    fclose(p);
    return resp;
}
void punto_1(){
    ArchivoObras archi("obras.dat");
    Obra reg;
    //Obras en Ejecuccion
    ObraEjecucion aux;
    //ArchivoObrasEjecucion ("obrasEjecion.dat");

    for(int i=0;i<archi.contarRegistros();i++){//recorrer
        reg=archi.leerRegistro(i); //leer Registro
        if(reg.getEstadoEjecucion()==4){

            aux.setCodigoObra(reg.getCodigoObra());
            aux.setDireccion(reg.getDireccion());
            aux.setProvincia(reg.getProvincia());
            aux.setActivo(true);
            FILE *p;
            p=fopen("ObrasEjecucion.dat","AB");
            fwrite(&aux, sizeof (aux),1,p);
            fclose(p);

        }
    }

}
///La provincia con menos proveedores (ignorando las provincias sin proveedores).

/*  PROVEDOR
    int numeroProveedor;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    bool activo;
    */
int menorProveedores(int *v, int tam){
    int menor,posMin;
    for(int i =0;i<tam;i++){
        if(i==0){
            menor=v[i];
            posMin=i;
        }
        else if(v[i]<menor){
            menor = v[i];
            posMin=i;
        }

    }
    return posMin;
}

void punto_2(){

    ArchivoProveedores archi("proveedores.dat");
    int contProv[24]={0};
    for(int i=0;i<archi.contarRegistros();i++){
        contProv[archi.leerRegistro(i).getProvincia()-1]++;
    }
    cout<<"PROVINCIA CON MENOS PROVEDORES "<< menorProveedores(contProv,24)<<endl;;



}


