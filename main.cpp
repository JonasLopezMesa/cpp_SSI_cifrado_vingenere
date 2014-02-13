//
//  main.cpp
//  Cifrado_Vingenere
//
//  Created by jonas on 18/02/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{    
    char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char clave[100], texto_original[100], texto_cifrado[100], texto_descifrado[100];
    
    cout << "introduce la clave: " << endl;
    gets(clave);
    cout << "introduce el texto original" << endl;
    gets(texto_original);
    
    for(int j = 0; texto_original[j]; j++){
        texto_original[j] = tolower(texto_original[j]); //<--convierte a minusculas la cadena
    }
    for(int j = 0; clave[j]; j++){
        clave[j] = tolower(clave[j]); //<--convierte a minusculas la cadena
    }
    
    
    
    cout << "CIFRADO: " << endl;  //Cifrado de Vingenere////////////////////////////
    int a = 0;
    for (int i = 0; i < strlen(texto_original); i++) { //recorre todos los caracteres del texto original
        if (texto_original[i] == ' ') { //si el caracter es espacio, inserta espacio
            texto_cifrado[i] = ' ';
        } else {
            int temp, temp1, temp2;
            for (int j = 0; j <= 26; j++) {  //si no es espacio, recorre todo el alfabeto y busca coincidencias entre
                if (alfabeto[j] == texto_original[i]) {  //el caracter del texto original 
                    temp1 = j;
                }
                if (alfabeto[j] == clave[a%strlen(clave)]) { //y el caracter de la clave
                    temp2 = j;
                } //y almacena las posiciones en temp1 y temp2
            }
            temp = (temp1 + temp2)%26; //suma las posiciones y hace el módulo de 26 y
            texto_cifrado[i] = alfabeto[temp]; //pone en el texto cifrado la letra del alfabeto que corresponda
            a++;
        }
    }
    ///////////////////////////////////////////////////////////////////////////////
    for (int a = 0; a < strlen(texto_cifrado); a++) { //Muestra resultado
        cout << texto_cifrado[a];
    }
    
    
    
    cout << endl << "DESCIFRADO: " << endl; //Descifrado de Vingenere//////////////
    int b = 0;
    for (int i = 0; i < strlen(texto_original); i++) { //recorre todas las letras del texto cifrado
        if (texto_original[i] == ' ') { //si es espacio, inserta un espacio en el texto descifrado
            texto_descifrado[i] = ' ';
        } else {
            int temp, temp1, temp2, ext;
            for (int j = 0; j <= 26; j++) { //busca coincidencias entre la letra que corresponda del texto cifrado
                if (alfabeto[j] == texto_cifrado[i]) {
                    temp1 = j;
                }
                if (alfabeto[j] == clave[b%strlen(clave)]) { // y la clave 
                    temp2 = j;
                } //con el alfabeto y lo almacena en temp1 y temp2
            }
            temp = (temp1 - temp2); //resta las posiciones
            if (temp < 0) { // si esa resta da menos de 0 
                ext = (26-abs(temp))%26; //
                temp = ext;
            }
            texto_descifrado[i] = alfabeto[temp];
            b++;
        }
    }
    ///////////////////////////////////////////////////////////////////////////////
    for (int a = 0; a < strlen(texto_descifrado); a++) { //Muestra resultado
        cout << texto_descifrado[a];
    }
}

