#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicio, *fin;

class Pila{
    public:
        Pila(){
            inicio = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig= nullptr;
            //cout<<"push"<<n->dato<<endl;
            return n;
        }

        void push(int valor){
            Nodo *n= crearNodo(valor);
            cout<<"push"<<n->dato<<endl;
            n->sig=inicio;
            inicio=n;
            
        }
        
        void mostrar(){
            Nodo *n = inicio;
            while(n){
                cout<<n->dato<<endl;
                n=n->sig;
            }
        }
        
        void mostrarYLimpiar(){
            Nodo *n = pop();
            while(n){
                cout<<n->dato<<endl;
                free(n);
                n=pop();
            }
        }

        Nodo* pop(){
            Nodo* temp = inicio;
            inicio= inicio->sig;
            return temp;
        }

};

class Cola{
    public:
        Cola(){
            inicio = nullptr;
            fin = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig= nullptr;
            return n;
        }

        void push(int valor){
            Nodo *n= crearNodo(valor);
            if(!inicio){
                inicio=n;
                fin=n;
            }
            else{
                fin->sig=n;
                fin=n;
            }
        }

        void invertir(){
            Nodo *n = inicio;
            inicio = fin;
            inveritAux(n);
            fin->sig = nullptr;
        }

        void inveritAux(Nodo* n){
            if(n->sig && n->sig!=fin){
                inveritAux(n->sig);
            }
            fin->sig = n;
            fin=n;
        }

        void mostrar(){
            Nodo *n = inicio;
            while(n){
                cout<<n->dato<<endl;
                n=n->sig;
            }
        }

        void pop(){
            Nodo* temp = inicio;
            inicio= inicio->sig;
            free(temp);
        }

        void transformar(Pila p){
            Nodo *n = inicio;
            while(n){
                p.push(n->dato);
                //cout<<n->dato;
                n = n->sig;
            }
        }

};
int main(int argc, char** argv) {

    Cola c1;
    Pila p1;
    
    c1.push(1);
    c1.push(2);
    c1.push(3);
    c1.push(4);
    c1.push(5);
    c1.mostrar();
    cout<<"Invirtiendo-------------------------"<<endl;
    c1.invertir();
    c1.mostrar();
    cout<<"llenando pila-----------------------"<<endl;
    c1.transformar(p1);
    cout<<"mostarndo pila----------------------"<<endl;
    p1.mostrar();
    cout<<":'cv";
    return 0;
}

