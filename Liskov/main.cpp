
#include <cstdlib>
#include <iostream>

using namespace std;

class Processor {
public:
    void heating(){
        cout<<"Motherboard meltdown!"<<endl;
    }
};

class Program {
public:
    void function(Processor &processor){
        processor.heating();
    }
};

class Intel: public Processor {
    
};

class Amd: public Processor{};

int main(int argc, char** argv) {

    Program program;
    Processor processor;
    //program.function(processor);
    cout<<"amd:";
    Amd amd;
    program.function(amd);
    
    cout<<"intel:";
    Intel intel;
    program.function(intel);
    return 0;
}

