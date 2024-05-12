#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///buscar La POSICION MAXIMA
    int buscarPosMax(int *v,int tam){
        int posMax=0;
        for(int i =0;i<tam;i++)
        {
//            if(i==0) posMax = i;
            if(v[i]>v[posMax]) posMax = i;
            }
            return posMax;
        }

///buscar Valor Max de un vector
    int buscarVecMax(int *v,int tam){
        int posMax;
        for(int i =0;i<tam;i++)
        {
            if(i==0) posMax = i;
            if(v[i]>v[posMax]) posMax = i;
            }
            return v[posMax];
        }

///buscar La POSICION MINIMA
    int buscarPosMin(int *v,int tam){
        int posMin;
        for(int i =0;i<tam;i++)
        {
            if(i==0) posMin = i;
            if(v[i]<v[posMin]) posMin = i;
            }
            return posMin;
        }

///buscar Valor MIN de un vector
    int buscarVecMin(int *v,int tam){
        int posMin;
        for(int i =0;i<tam;i++)
        {
            if(i==0) posMin = i;
            if(v[i]<v[posMin]) posMin = i;
            }
            return v[posMin];
        }

#endif // FUNCIONES_H_INCLUDED
