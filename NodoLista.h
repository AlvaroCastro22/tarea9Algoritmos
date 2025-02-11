#ifndef NODOLISTA_H
#define NODOLISTA_H

#include <iostream>
#include <string>

using namespace std;

// Estructura para almacenar los datos del evento
struct Post {
    string ciudad;    // Nombre del evento
    string distrito;      // Tipo de evento
    string fechaColecta;     // Fecha del evento
    string idAirbnb;        // ID del evento 
    string nReviews;
    string alias;
    string url;
    string titulo;
    string tituloPropiedad;
    string resumen;
    string reconocimiento;
    string acercaDe;
    string esSuperHost;
    string tiempoHost;
    string identidadHost;
    string hostfoto;
    string ubicacionExacta;
    string tipoCama;
    string nCuartos;
    string tipoAlojamiento;
    string numeroServicios;
    string promedioReviews;
    string precioPorNoche;
    string instantBookable;
    string politicaCancelacion;
    string verificarTelefono;
    string DisponibilidadMayor90;
};

struct Review{
string fechaColecta;
string idAirbnb;
string nReview;
string reseña;
Review *sigReview=NULL;
Review(string fecha, string id, string nRev, string res)
        : fechaColecta(fecha), idAirbnb(id), nReview(nRev), reseña(res), sigReview(nullptr) {}
};
// Clase Nodo
class Nodo {

    Post data;   // Datos del Post
    Nodo *sig;     // Apuntador al siguiente nodo
    

public:
    Review *res;
    Nodo() {}
    Nodo(Post e);
    Nodo(Post e, Nodo *s);

    ~Nodo() {}

    // Getters y setters
    Post get_data();
    void set_data(Post e);

    Nodo *get_sig();
    void set_sig(Nodo *p);
};

// Constructor Nodo (sin siguiente nodo)
Nodo::Nodo(Post e) {
    data = e;
    sig = NULL;
    res = NULL;
}

// Constructor Nodo (con siguiente nodo)
Nodo::Nodo(Post e, Nodo *s) {
    data = e;
    sig = s;
}

// Métodos Get y Set
Post Nodo::get_data() { return data; }
void Nodo::set_data(Post e) { data = e; }

Nodo *Nodo::get_sig() { return sig; }
void Nodo::set_sig(Nodo *p) { sig = p; }



void addNodo(Nodo *&head, Post e) {
    Nodo *nuevo = new Nodo(e);
    if (head == NULL) {
        head = nuevo; 
    } else {
        Nodo *aux = head;
        while (aux->get_sig() != NULL) {
            aux = aux->get_sig();
        }
        aux->set_sig(nuevo);
    }
}


void eliminarNodo(Nodo *&head, const string &id) {
    if (head == NULL) {
        cout << "Lista vacía." << endl;
        return;
    }
    Nodo *aux = head;
    Nodo *prev = NULL;

    while (aux != NULL && aux->get_data().idAirbnb != id) {
        prev = aux;
        aux = aux->get_sig();
    }

    if (aux == NULL) {
        cout << "Evento no encontrado." << endl;
    } else {
        if (prev == NULL) {
            head = aux->get_sig();
        } else {
            prev->set_sig(aux->get_sig());
        }
        delete aux;
        cout << "Evento eliminado con éxito." << endl;
    }
}

void asignarReview(Nodo *&head,Review r){
    Nodo *aux = head;
    while (aux != NULL) {
        if (aux->get_data().idAirbnb==r.idAirbnb)
        {
            Review *headReview = new Review(r);
            
            if (aux->res == NULL) {
                aux->res = headReview;
            } else {
                Review *aux2 = aux->res;
                while (aux2->sigReview != NULL) {
                    aux2 = aux2->sigReview;
                }
                aux2->sigReview=headReview;
            }
            //cout<<aux->res<<endl;
            //cout<<aux->res->sigReview<<endl;
            return;
        }
        

        aux = aux->get_sig();
    }
    cout << "Id no coincide." << endl;
}

void buscarNodo(Nodo *head, const string &id) {
    Nodo *aux = head;
    while (aux != NULL) {
        if (aux->get_data().idAirbnb == id) {
            Post e = aux->get_data();
            cout << "\nEvento encontrado:" << endl;
            cout << "Nombre: " << e.ciudad << endl;
            cout << "Tipo: " << e.distrito << endl;
            cout << "Fecha: " << e.fechaColecta << endl;
            cout << "ID: " << e.idAirbnb << endl;
            return;
        }
        aux = aux->get_sig();
    }
    cout << "Evento no encontrado." << endl;
}


void modificarNodo(Nodo *head, const string &id) {
    Nodo *aux = head;
    while (aux != NULL) {
        if (aux->get_data().idAirbnb == id) {
            Post e = aux->get_data();
            cout << "\nIngrese nuevo nombre: ";
            cin.ignore();
            getline(cin, e.ciudad);

            cout << "Ingrese nuevo tipo: ";
            getline(cin, e.distrito);

            cout << "Ingrese nueva fecha: ";
            getline(cin, e.fechaColecta);

            aux->set_data(e);
            cout << "Evento modificado con éxito." << endl;
            return;
        }
        aux = aux->get_sig();
    }
    cout << "Evento no encontrado." << endl;
}


void reportarLista(Nodo *head) {
    if (head == NULL) {
        cout << "Lista vacía." << endl;
        return;
    }
    Nodo *aux = head;
    cout << "\nEventos en la lista:" << endl;
    while (aux != NULL) {
        Post e = aux->get_data();
        cout<<endl<<"Id post:"<<e.idAirbnb<<endl;
        cout << "Nombre: " << e.ciudad << endl;
        cout << "Tipo: " << e.distrito << endl;
        cout << "Fecha: " << e.fechaColecta << endl;
        cout<<"Alias: "<<e.alias<<endl;
        //cout<<"puntero review"<<aux->res<<endl;
        
        aux = aux->get_sig();
    }
}

void reportarReviewPost(Nodo *head,string id){
    Nodo *aux = head;
    
    while (aux != NULL) {
        if (aux->get_data().idAirbnb == id) {
            cout<<endl<<"Reviews del post con id "<<id<<endl;
            Post e = aux->get_data();
            
            Review *aux2 = aux->res;
            while (aux2 !=NULL)
            {
                cout<<endl<<aux2->nReview<<endl;
                cout<<aux2->fechaColecta<<endl;
                cout<<aux2->reseña<<endl;
                cout<<"----"<<endl;
                aux2 = aux2->sigReview;
            }
            
            return;
        }
        aux = aux->get_sig();
    }
    cout << "Evento no encontrado." << endl;
}

#endif
