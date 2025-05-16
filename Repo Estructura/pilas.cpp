//PRIMITIVAS DE PILAS
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

//Comprobar si existe la pila
bool isVoid (Node*p) {
    if (!p) return true;
    return false;
}

//Apilar
void Push (Node**p, int value) {
    Node* newElement = new Node;
    newElement -> value = value;
    newElement -> next = *p;
    *p= newElement;
}

//Desapilar
int Pop (Node**p) {
    if (!(*p)) return 0;
    Node* aux = *p;
    int value = (*p) -> value;
    *p = (*p) -> next;
    delete aux;
    return value;
}

//Consultar la cabeza
int top (Node*p) {
    if (!p) return 0;
    else return p -> value;
}

//Desapilar por cola, desapila la cola
int PopBotton(Node **A){
    if (isVoid(*A)) return 0;
    int value=Pop(A); //primer elemento de la pila
    int botton=PopBotton(A);
    if (!botton) botton=value;
    else Push(A,value);
    return botton;
}

//Apilo por cola
void PushBotton(Node **A, int value){
    if (isVoid(*A)) return ;
    else{
        int topvalue=Pop(A);
        PushBotton(A,value);
        Push(A, topvalue);
    }
}

//Consultar la cabeza
int top (Node*p) {
    if (!p) return 0;
    else return p -> value;
}

//Contar elementos
int CountElement(Node **A){
    if (isVoid(*A)) return 0;
    int value=Pop(A);
    int count= CountElement(A);
    Push(A,value);
    return count++;
}

//Insertar elementos en una posicion especifica
void PushBottonPos(Node **A, int value, int position){
    if (isVoid(*A) || !position) Push(A,value);
    else{
        int currentvalue=Pop(A);
        PushBottonPos(A, value,position);
        Push(A,value);
    }
}

//Veces que se repite un elemento
int CountValue(Node **A, int value){
    if (isVoid(*A)) return 0;
    int currentvalue=Pop(A);
    int count=CountValue(A, value);
    if (value==currentvalue) count++;
    Push(A,currentvalue);
    return count;
}

//Te dice si este elemento esta o no esta
bool search(Node**A, int value){
    if (isVoid(*A)) return false;
    if (top(*A)==value) return true;
    int currentvalue=Pop(A);
    int count= Pop(A);
    bool result= search(A,value);
    Push(A, count);
    Push(A, currentvalue);
    return result;
}

int main(){
    Node *pilaprueba = nullptr;
    cout << isVoid(pilaprueba) << "->indica que la pila esta vacia" << endl; 

    Push(&pilaprueba, 12);
    Push(&pilaprueba, 2);
    Push(&pilaprueba, 22);

    cout << Pop(&pilaprueba) << "-> este deberia ser el ultimo numero que se inserto en la pila(22)" << endl;
    cout << isVoid(pilaprueba) << "->indica que la pila esta vacia" << endl; 
    cout << Pop(&pilaprueba) << "-> este deberia ser el penultimo numero que se inserto en la pila(2)" << endl;
    cout << isVoid(pilaprueba) << "->indica que la pila esta vacia" << endl; 
    cout << Pop(&pilaprueba) << "-> este deberia ser el primer numero que se inserto en la pila(12)" << endl;
    cout << isVoid(pilaprueba) << "->indica que la pila esta vacia" << endl; 

}
