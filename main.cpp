#include <iostream>
#include<fstream>
#include<sstream>
#include "NodoLista.h"
#include <vector>
using namespace std;    

int main(){
    Nodo *head = NULL;
    ifstream lecturaF;
    string linea;
    string palabra;
    string nombre = "datos.csv";
    lecturaF.open(nombre,ios::in);
    if(lecturaF.fail()){
        cout<<"No se puede abrir el archivo";
    }else
        {
            while (!lecturaF.eof())
            {
                Post p;
                vector<string> arr;
                int i = 0;
                string valor;
                bool entreComillas = false;
                getline(lecturaF,linea);
                for (size_t i = 0; i < linea.length(); i++)
                        {
                            char c = linea[i];
                            if (c=='"')
                            {
                                entreComillas = !entreComillas;
                            }else if (c==',' && !entreComillas)
                            {
                                arr.push_back(valor);
                                valor="";
                            }else{
                                valor += c;
                            }
                            
                            
                        }
                        arr.push_back(valor);


                        p = {arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19],arr[20],arr[21],arr[22],arr[23],arr[24],arr[25],arr[26]};
                        addNodo(head,p);
            }
            
            lecturaF.close();
            reportarLista(head);
        }
        
    return 0;
}
