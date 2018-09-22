
package liskov;


public class Program {

    public static class Amd extends Processor{
        
    }
    
    public static class Intel extends Processor{
        
    }
    
    public static void main(String[] args){
        Program program;
        Processor processor = new Processor();
       // processor.heating(); // minden processzor képes fűtésre és leolvasztja az alaplapot
        System.out.print("amd: ");
        Amd amd = new Amd();
        amd.heating(); // az AMD képes fűtésre leolvasztja az alaplapot
        
        System.out.print("intel: ");
        Intel intel = new Intel();
        intel.heating(); // az ős szerint az Intel is képes fűtésre és olvasztásra, pedig tudjuk hogy nem.... 
        
        
        
    }
}
