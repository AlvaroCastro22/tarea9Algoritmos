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

class Nodo {

    Post data;   
    Nodo *sig;     
    

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


Nodo::Nodo(Post e) {
    data = e;
    sig = NULL;
    res = NULL;
}


Nodo::Nodo(Post e, Nodo *s) {
    data = e;
    sig = s;
}


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
            cout << "\nPost encontrado:" << endl;
            cout << "Ciudad: " << e.ciudad << endl;
            cout << "Distrito: " << e.distrito << endl;
            cout << "Fecha Colecta: " << e.fechaColecta << endl;
            cout << "ID: " << e.idAirbnb << endl;
            cout<<"Numero Reviews: "<<e.nReviews<<endl;
            cout<<"Alias: "<<e.alias<<endl;
            cout<<"Url: "<<e.url<<endl;
            cout<<"Titulo: "<<e.titulo<<endl;
            cout << "Titulo Propiedad: " << e.tituloPropiedad << endl;
            cout << "Resumen: " << e.resumen << endl;
            cout << "Reconocimiento: " << e.reconocimiento << endl;
            cout << "Acerca de: " << e.acercaDe << endl;
            cout << "Es Super Host: " << e.esSuperHost << endl;
            cout << "Tiempo Host: " << e.tiempoHost << endl;
            cout << "Identidad Host: " << e.identidadHost << endl;
            cout << "Foto del Host: " << e.hostfoto << endl;
            cout << "Ubicacion Exacta: " << e.ubicacionExacta << endl;
            cout << "Tipo de Cama: " << e.tipoCama << endl;
            cout << "Numero de Cuartos: " << e.nCuartos << endl;
            cout << "Tipo de Alojamiento: " << e.tipoAlojamiento << endl;
            cout << "Numero de Servicios: " << e.numeroServicios << endl;
            cout << "Promedio de Reviews: " << e.promedioReviews << endl;
            cout << "Precio por Noche: " << e.precioPorNoche << endl;
            cout << "Instant Bookable: " << e.instantBookable << endl;
            cout << "Politica de Cancelacion: " << e.politicaCancelacion << endl;
            cout << "Verificar Telefono: " << e.verificarTelefono << endl;
            cout << "Disponibilidad Mayor a 90 dias: " << e.DisponibilidadMayor90 << endl;
            return;
        }
        aux = aux->get_sig();
    }
    cout << "Evento no encontrado." << endl;
}





void reportarLista(Nodo *head) {
    if (head == NULL) {
        cout << "Lista vacia." << endl;
        return;
    }
    Nodo *aux = head;
    cout << "\nEventos en la lista:" << endl;
    while (aux != NULL) {
        Post e = aux->get_data();
        cout<<endl<<"Id post:"<<e.idAirbnb<<endl;
        cout << "Ciudad: " << e.ciudad << endl;
        cout << "Distrito: " << e.distrito << endl;
        cout << "Titulo Propiedad: " << e.titulo << endl;
        cout<<"Resumen: "<<e.resumen<<endl;
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
    cout << "Review no encontrado." << endl;
}

#endif
