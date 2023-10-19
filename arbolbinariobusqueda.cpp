#include <iostream>
using namespace std;

struct Nodo {
     int clave;
     Nodo* izq;
     Nodo* der;
};

void insertar(Nodo*& p,int v);
void inOrden(Nodo*);
Nodo* buscar(Nodo* p,int v);

int main() {   
    Nodo* arbol = NULL;
    insertar(arbol,6);
    insertar(arbol,10);
    insertar(arbol,4);
    insertar(arbol,8);
    inOrden(arbol);
    cout<<endl<<"Busco el 10: "<<buscar(arbol,10)<<endl;
    cout<<endl<<"Busco el 100: "<<buscar(arbol,100)<<endl;
    return 0;
}

void insertar(Nodo*& p,int v){
    if(p == NULL){ //Árbol vacío o Subárbol vacío
        Nodo* nuevo = new Nodo();
        nuevo->clave = v;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        p=nuevo;
    }else{
        if(v < p->clave){
            insertar(p->izq,v);
        }else{
            insertar(p->der,v);
        }
    }
}

void inOrden(Nodo* ptrArbol){
    if (ptrArbol != NULL) {
    inOrden(ptrArbol->izq); //va por la rama izquierda hasta agotarla
    cout<<ptrArbol->clave<<"-"; //muestra la información
    inOrden(ptrArbol->der); //recorre la rama derecha
    }
    return;
}

Nodo* buscar(Nodo* p,int v){
    if(p == NULL){
        return 0;
    }else{
    	if(v == p->clave){
            return p;
        }else{
            if(v < p->clave){
                return buscar(p->izq,v);
            }else{
                return buscar(p->der,v);
            } 
        }
    }
}


