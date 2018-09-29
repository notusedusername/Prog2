/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fwdeng;

/**
 *
 * @author tonor
 */
public class Fwdeng {

    /**
     * @param args the command line arguments
     */
    
    class Animal{
        
        private String name;
        private int weight;
        
        void setName(String set){
            name = set;
        }
        
        void getName(){
            System.out.println(name);
        }

        void setWeight(int set){
            weight = set;
        }
        
        void getWeight(){
            System.out.println(weight);
        }
    }
    
    class Dog extends Animal {
        void bark(){
            System.out.println("Bark!");
        }
    }
    
    class Cat extends Animal {
        void purr(){
            System.out.println("Purr.");
        }
    }
    
    class Human {
        private String name;
        private String sex;
        
        void setName(String set){
            name = set;
        }
        
        void getName(){
            System.out.println(name);
        }

        void setSex(String set){
            sex = set;
        }
        
        void getSex(){
            System.out.println(sex);
        }

    }
    
    public static void main(String[] args) {
        // TODO code application logic here
    }
    
}
