/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package l33t;

/**
 *
 * @author tonor
 */
public class L33t {

    String[] abc;
    
    String[] leet;
    
     public L33t() {
        this.abc = new String[]{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y",  "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}; 
        this.leet = new String[]{"4", "|3", "<", "|)", "3", "|=", "[+", "|-|", "1", "_|", "|<", "|_", "^^", "|\\|", "0", "|0", "O_", "|2", "5", "7", "|_|", "\\/", "\\/\\/", "%", "'/", "2", "D", "L", "Z", "E", "h", "S", "b", "T", "x", "g" };
    }
    
     /**
         * Ez a függvény egy tetszőleges String típusú változó tartalmát fordítja leet nyelvre, 
         * majd kiírja a terminálba.
         */
     
    public void translate(String source){
        
        source = source.toLowerCase();          // a bemenetet kisbetűre írjuk így minden betűt felismer
        String translated = "";
        for (int i = 0; i < source.length(); i++ ){
            int j = 0;
            while (source.charAt(i) != abc[j].charAt(0) && j < abc.length-1){   //kikeressük a betűket, ha nincs találat if
                j++;
            }
            if (j != abc.length-1){                                     //ha talált kikeressük 
                translated += leet[j];
            }
            else
                translated += source.charAt(i);                         //ha nem talált visszaadjuk a karaktert
        }
        System.out.print(translated + " ");
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        L33t leet = new L33t();
        for(int i = 0; i < args.length; i++){
            System.out.print(args[i] + " ");
        }
        for(int i = 0; i < args.length; i++){
            leet.translate(args[i]);
            
        }
        
    }


    
}
