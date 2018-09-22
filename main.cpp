/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tonor
 *
 * Created on 2018. szeptember 18., 19:24
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
class Szulo {
public:
    int a = 0;
    int b = 0;
};

class Gyerek: public  Szulo {
public:
    int c = 0;
}; 

int main(int argc, char** argv) {
    Szulo* szulo = new Gyerek;
    szulo->a = 1;    //ezt szabad, mert el tudjuk érni
    
    //szulo.c = 1; ezt nem tudjuk elérni, hiába public változó a 'c'
    
    return 0;
}

