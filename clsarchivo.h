#ifndef CLSARCHIVO_H
#define CLSARCHIVO_H
class clsArchivo{
private:
    char nombre[30];


public:
    clsArchivo() {///Constructor
        strcpy(nombre, "nomClase.dat");
    }
    bool escribirRegistro(clsArchivo reg) { ///GrabarArchivo
        FILE* p;
        p = fopen(nombre, "ab");
        if(p == NULL) return false;
        bool escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    clsArchivo leerRegistro(int pos) {///Leer Archivo
        clsArchivo reg;
        reg.setNumeroPasajero(-1);
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) return reg;
        fseek(p, sizeof(clsArchivo) * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() { ///Contar la cantidad de Registro
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) return -1;
        fseek(p, 0, 2);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(clsArchivo);
    }
    bool listarArchivo() { /// Muestra el contenido de un archivo
        clsArchivo reg;
        FILE* p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
            cout << endl;
        }
        fclose(p);
        return true;
    }
    bool modificarRegistro(clsArchivo obj, int nroReg) { /// MODIFICA un Registro
        FILE* p = fopen(nombre, "rb+");
        if (p == NULL) {
            return false;
        }
        fseek(p, nroReg * sizeof(clsArchivo), SEEK_SET);
        bool ok = fwrite(&obj, sizeof(clsArchivo), 1, p);
        fclose(p);
        return ok;
    }
    void vaciar(){ ///Vacia
        FILE *p = fopen(nombre, "wb");
        if (p == NULL){return ;}
        fclose(p);
    }


};

#endif // CLSARCHIVO_H
