/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gagyi;

import static java.lang.Thread.sleep;


/**
 *
 * @author tonor
 */
public class Gagyi {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException {
       Integer x = 127;
       Integer t = 127;
       
       System.out.println(x);
       System.out.println(t);
       
       while (x <= t && x >= t && t != x){
           System.out.println(1);
           //nem lép be a ciklusba
       }
       
       x = 128;
       t = 128;
       
       while (x <= t && x >= t && t != x){
           System.out.println("VÉGTELEEEEN");
           sleep(3000);
           //belép a ciklusba
       }
    
    }
    
}
