/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package orokles;

/**
 *
 * @author tonor
 */
public class Szulo {

    int a = 0;
    int b = 0;




    public static void main(String[] args) {
        
        Szulo szulo;
        szulo = new Gyerek();
        szulo.a = 1;
        szulo.b = 1;//ezek mennek mert a Szülőnek is van a és b változója
        //szulo.c = 1; kapásból hibát dob, mert Szülő típusú objektumnak nincs c változója
        
        
    }
    
}
