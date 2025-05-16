#include <iostream>
#include <list.h>

using namespace std;

void Mostrar(Node *p){
    if(Existe(p)==false) return;
    while(p){
        cout<<"["<<p->value<<"]->";
        p=p->next;
    }
    cout<<endl;
};

int main(){

    return 0;
}