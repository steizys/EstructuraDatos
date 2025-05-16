/****** PRINCIPALES ***** */
struct Node{
    int value;
    Node* next;
};
Node *CrearNodo(int value){
    Node *nuevo= new Node;
    nuevo->value=value;
    nuevo->next=NULL;
    
    return nuevo;
};
bool Existe(Node *p){
    if (!(p)) {
        return false;
    }
    return true;
}
void InsertarxCabeza(Node **p, Node* nuevo){
    nuevo->next=*p;
    *p=nuevo;
};
void InsertarxCola(Node** p, Node* nodo) {
    if (Existe(*p)==false) {
        InsertarxCabeza(p, nodo);
        return;
    }
    Node* aux = *p;
    while (aux && aux->next) {
        aux = aux->next;
    }
    aux->next = nodo;
}

//Luego de un valor dado (si no existe no se inserta)
void InsertarDespValor(Node*p, Node*q, int value){
    if(!p) return;
    Node*aux= p;
    while(aux){
        if (aux->value==value){
            Node*aux2= aux->next;
            aux->next= q;
            q->next=aux2;
        }aux=aux->next;
    }
}
/********ORDENAMIENTOS****** */
//Creciente
void OrdenamientoCreciente(Node **p){
    // Si la lista está vacía o tiene un solo nodo, no se hace nada
    if (!(*p) || !(*p)->next){
        return;
    }

    bool swapped = true; // Variable booleana que indicara si hubo intercambio

    // Ciclo que repite mientras haya intercambios
    while (swapped){
        swapped = false;
        Node **actual = p; // Doble puntero para modificar enlaces

        // Bucle que recorre la lista enlazada comparando nodos seguidos (adyacentes)
        while ((*actual) && (*actual)->next){
            // Se crean dos punteros auxiliares para los nodos a comparar
            Node *aux1 = *actual;
            Node *aux2 = aux1->next;

            // Si el primer nodo es mayor que el segundo, se cambian de lugar
            if (aux1->value > aux2->value){

                aux1->next = aux2->next;
                aux2->next = aux1;
                *actual = aux2;

                swapped = true; // Indica que hubo un cambio
            }

            actual = &((*actual)->next); // Avanza al siguiente par
        }
    }
}
//Decreciente
void OrdenamientoDecreciente(Node **p){
// Si la lista está vacía o tiene un solo nodo, no se hace nada
    if (!(*p) || !(*p)->next){
        return;
    }

    bool swapped = true; // Variable booleana que indicara si hubo intercambio

    // Ciclo que repite mientras haya intercambios
    while (swapped){
        swapped = false;
        Node **actual = p; // Doble puntero para modificar enlaces

        // Bucle que recorre la lista enlazada comparando nodos seguidos (adyacentes)
        while ((*actual) && (*actual)->next){
            // Se crean dos punteros auxiliares para los nodos a comparar
            Node *aux1 = *actual;
            Node *aux2 = aux1->next;

            // Si el primer nodo es mayor que el segundo, se cambian de lugar
            if (aux1->value < aux2->value){

                aux1->next = aux2->next;
                aux2->next = aux1;
                *actual = aux2;

                swapped = true; // Indica que hubo un cambio
            }

            actual = &((*actual)->next); // Avanza al siguiente par
        }
    }
}

/********BUSQUEDAS ******** */

//devuelve TRUE si esta o FALSE si no
bool BuscaExiste(Node *p, int valor){
    if(Existe(p)==false) return p;
    Node *aux=p;
    while(aux->next){
        if(aux->value==valor){
            return true;
        }
        aux=aux->next;
    }
    return false;
};
//devuelve el nodo donde lo consigui[o]
Node *Busquedad(Node *p, int value){
    if (Existe(p)==false) return p;
   Node *aux=p;
   while (aux && aux->next){
       if (aux->value == value){
           return aux;
       }
       aux=aux->next;
   }
   return aux;
};
//devuelve la cantidad de veces que aparece el num
int BuscaCant(Node *p, int valor){
    int cant=0;
    if(Existe(p)==false) return 0;
    Node *aux=p;
    while(aux){
        if(aux->value==valor){
            cant+=1;
        }
        aux=aux->next;
    }
    return cant;
};

/*********ELIMINADOS************ */
//primera vez 
Node *EliminarP(Node **p, int valor){
    //if(Existe(*p)==false) return *p;
    Node *aux=*p;
    Node *aux1=*p;
    while(aux){
        if(aux->value==valor){
            if(aux==*p){
                *p=aux->next;
                delete aux;
                return *p;
                
            }else{
                aux1->next=aux->next;
                delete aux;
                return *p;
                
            }
        }
        aux1=aux;
        aux=aux->next;
    }
}
//ultima vez
void EliminarU(Node **p, int valor){
    //if(Existe(*p)==false) return *p;
    Node *actual=*p;
    Node *anterior=NULL;
    Node *antesultimo=NULL;
    Node *ultimo=NULL;
    while(actual){
        if(actual->value==valor){
            ultimo=actual;
            antesultimo=anterior;
        }
        anterior=actual;
        actual=actual->next;
    }
     if (ultimo) { // Solo si se encontró el valor
        if (antesultimo == nullptr) { // El último encontrado es la cabeza
            *p = ultimo->next;
        } else { // El último encontrado no es la cabeza
            antesultimo->next = ultimo->next;
        }
        delete ultimo;
    }
}
//todas las veces
void EliminarTodas(Node **p, int valor){
    Node *actual=*p;
    Node *anterior=NULL;
    while(actual){
        if(actual->value==valor){
            if (anterior == NULL) {
                *p = actual->next;
                delete actual;
                actual = *p;
            } else {
                anterior->next = actual->next;
                delete actual;
                actual = anterior->next;
            }
        }else{
           anterior=actual;
           actual=actual->next; 
        }
        
    }
}
//elimina los repetidos
void EliminarRep (Node*p){
    if(!p || !p->next) return;
    Node* aux= p;
    while (aux && aux->next){
        Node* aux2= aux->next;
        while(aux2){
            if (aux->value==aux2->value){
                Node* aux3=aux;
                while ((aux3->next)!=aux2) aux3= aux3->next;
                aux3->next= aux2->next;
                delete aux2;
                aux2=aux3;        
            }
            aux2=aux2->next;
        }
        aux=aux->next;
    }
}

/*********VALIDA ORDEN ********** */
int VerificarOrden(Node *lista){//Funcion para saber si una lista esta ordenada 1-Creciente 2-Decreciente 0-No esta ordenada o vacia 
    if (!lista || !(lista->next)){ // Verifica si la lista esta vacia o tiene un solo elemento
        return 0;
    }
    int orden;
    if (lista->value > lista->next->value) orden= 2; //Decreciente
    else if (lista->value < lista->next->value) orden= 1; //Creciente
    else return 0; //Si los dos primeros son iguales, no verfica
    Node *aux=lista;
    while (aux->next){
        if ((orden==2 && aux->value < aux->next->value) || (orden==1 && aux->value > aux->next->value)){//Condicional pa comprobar si no esta ordenada
            return 0;
        }
        aux=aux->next;
    }
    return orden;
};

//*******ORDENES ***********/
//inserta de ordenado por mayor
void InsertarOrdenadoMayor(Node **lista, Node *nodo){
    if (!(*lista)){
        InsertarxCabeza(lista, nodo);
        return;
    }   //Comprobar si esta vacia
    if (!(*lista)->next){ //Comprobar si tiene un solo elemento
        if (nodo>*lista){ //Si el nodo es mayor al unico elemento de la lista, se ingresa por cabeza
            InsertarxCabeza(lista, nodo);
            return;
        }else{ //Si es menor o igual
            InsertarxCola(lista, nodo);
            return;
        }
    }
    if (VerificarOrden(*lista)!=2) OrdenamientoDecreciente(lista);
    Node*aux=*lista; 
    if (nodo->value > (*lista)->value){
        InsertarxCabeza(lista, nodo);
        return;
    } //Si el nodo es mayor a la cabeza
    while (aux){
        if (aux->next ==NULL){
            InsertarxCola(lista, nodo);
            return;
        } 
        if (aux->value > nodo->value  && nodo->value > aux->next->value){
            nodo->next=aux->next;
            aux->next=nodo;
            return;
        }
        aux=aux->next;
    }
    delete nodo;
};

//insertado de menor 
void InsertarOrdenadoMenor(Node **lista, Node *nodo){
    if (!(*lista)){
        InsertarxCabeza(lista, nodo);
        return;
    }   //Comprobar si esta vacia
    if (!(*lista)->next){ //Comprobar si tiene un solo elemento
        if (nodo>*lista){ //Si el nodo es mayor al unico elemento de la lista, se ingresa por cabeza
            InsertarxCabeza(lista, nodo);
            return;
        }else{ //Si es menor o igual
            InsertarxCola(lista, nodo);
            return;
        }
    }
    if (VerificarOrden(*lista)!=1) OrdenamientoCreciente(lista);
    Node*aux=*lista; 
    if (nodo->value < (*lista)->value){
        InsertarxCabeza(lista, nodo);
        return;
    } //Si el nodo es mayor a la cabeza
    while (aux){
        if (aux->next ==NULL){
            InsertarxCola(lista, nodo);
            return;
        } 
        if (aux->value < nodo->value  && nodo->value < aux->next->value){
            nodo->next=aux->next;
            aux->next=nodo;
            return;
        }
        aux=aux->next;
    }
    delete nodo;
};

//---EXTRAS

//Eliminar numeros con cifras impares

bool toDelete (int value){
    while (value>0){
        int res = value%10;
        if (res%2) return true; //si el residuo de res existe, devuelve true ya que es impar
        value = value/10;  //aqui se devuelve el value eliminando la ultima cifra
    }
    return false; //devuelve false si es par
};

void deleteOdds (Node **p){
    if (!(*p)) return;
    Node * aux= *p;
    while (aux){
        if (toDelete (aux -> value)){
            if (aux==*p){
                *p= (*p)->next;
                delete aux;
                aux= *p;
            }else{
                Node *aux2= *p;
                while (aux2->next!=aux) aux= aux2->next;
                aux2->next= aux->next;
                delete aux;
                aux= aux2->next;
            }
        }else{
            aux= aux->next;
        }
    }

}

///mia de eliminar los numeros con cifras impares jeje
bool Par(int valor){
	if(valor%2==0){
		return true;
	}else{
		return false;
	}
};
//
bool Primo(int valor){
	int cant=0;
	for(int i=1; i<=valor; i++){
		if(valor%i==0){
			cant++;
		}
	}
	if(cant==2){
		return true;
	}else{
		return false;
	}
}
void sinDigiImpar(Node **p){
	//if(Existe(*p)==false) return;
	Node *aux=*p;
	Node *aux2=NULL;
	int digi=0;
	int numero=0;
	bool impar;
	while (aux){
		numero=aux->value;
		impar=false;
		while(numero>0){
			digi=(numero)%10;
			if(Par(digi)==true){
				impar=true;
			};
			numero=numero/10;
		};
		if(impar==false){
			if(aux==*p){
				*p=aux->next;
				 delete aux;
				 aux=*p;
			}else{
				aux2->next=aux->next;
				delete aux;
				aux=aux2;
			} 
				
		}else{
			aux2=aux;
			aux=aux->next;	
		}
		
	};
}
