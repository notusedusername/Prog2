/* 
 * File:   CYK.cpp
 * Author: tonor
 *
 * Created on 2019. február 13., 16:53
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CYK {
private:  
    vector<vector<string>> table;
    vector<string> ruleRight;
    vector<string> ruleLeft;
    string word;
    string startSymbol;
    vector<string> ladderRight;
    vector<string> ladderLeft;


public:

    void readRules(){
       cout<<"\n\n --------------------------------\n| CYK-ALGORITHM Cmd Program v1.0 |\n---------------------------------\n"<<endl;
       cout<<"Write the rules in \"Left side->Rigt side(|Right side|...|...)\" format,\n write \"end\" to the next step:\n(copy paste works)\n"<<endl;
       
       string buffer = "";
       
       while(buffer!="end"){
	       	
	       	string left, right = "";
	       	if(buffer.size() > 2){
	       		int arrow = buffer.find("->");
	       		int pipeline = buffer.find("|");
	       		if(arrow != std::string::npos){
	       			left=buffer.substr(0, arrow);
	       			
	       			if(pipeline != std::string::npos){
	       				ruleRight.push_back(buffer.substr(arrow+2, pipeline-3));
	       				ruleLeft.push_back(left);
	       				buffer.replace(0, pipeline, "");
	       				
	       				while(buffer.find("|") != std::string::npos){
	       					
	       					ruleLeft.push_back(left);
	       					buffer.replace(buffer.find("|"),buffer.find("|")+1, "");
	       					right = buffer.substr(0, buffer.find("|"));
	       					ruleRight.push_back(right);
	       					buffer.replace(0, right.size(), "");
	       				}
	       			}
	       		else{
	       			right=buffer.substr(arrow+2);
					ruleRight.push_back(right);
	       		
	       			ruleLeft.push_back(left);
	       		}
	       	}
	       	else{
	       		buffer="end";
	       		break;
	       	}
	       		
	       	}	

            buffer = "";
            cin>>buffer;
           
        }
        cout<<"---------------------------------------------\nWhat is the start symbol?"<<endl;
        cin>>buffer;
        if(buffer != ""){
        	startSymbol="S";
        }
        else {
        	startSymbol=buffer;
        }
        buffer="";
    }
    
    int readWord(){
        cout<<"--------------------------\nWord:";
        cin>>word;                                                //beolvassa a szó hosszát és visszatér az értékével
        cout<<'\n';
        return word.length();  //HIBAKEZELÉS!!!!!!!!    

    }
    void initTable(int len){
        cout<<"Initializing matrix...";
        if(len < 0){
            cout<<"ERROR!"<<endl;
        }
        for (int i = 0; i < len; i++){
            vector<string> temp;
            for (int j = 0; j <len; j++){
                temp.push_back("");
            }
            table.push_back(temp);
        }
        cout<<"done\n";
    }

    void drawMatrix(){
        cout<<"done"<<endl;//Starting the algoritm párja
        for(int i = 0; i < table.size(); i++){
            cout<<'\n';
            for(int j = 0; j < table.size(); j++){
            	if(table[i][j] != "")
                	cout<<table[i][j]<<" ";
                else if(i+j < table.size())
                	cout<<"- ";
        
            }
        }
        cout<<'\n';
    }
    
    void cyk(){
        /*2 for a háromszögmátrix átlóján, fontos hogy i oszlop j sor (fordított)
         az algoritmushoz szolgáló táblázat vektorok vektorjaként van letárolva, 
         csak a középátló feletti részt kell használnunk.
         1 1 1 1
         1 1 1 0
         1 1 0 0
         1 0 0 0
         ahol az 1 a releváns adat. */
        
        cout<<"Starting the algorithm...";
        
        int maxColumn = word.length()-1;    
        int col = maxColumn;
        
        for(int k = 0; k <= col; k++){

            for (int i = maxColumn; i >= 0; i--){


                    if(k == 0){
                        firstRow(i, col - i);
                    }
                    else {

                       notFirstRow(i, maxColumn - i, maxColumn);
                       //table[i][maxColumn-i] = std::to_string(k);
                    }

            }
            maxColumn--;    //sorlépés
        }

        drawMatrix();
    }
    
    void firstRow(int column, int row){

        for(int i = 0; i < ruleRight.size(); i++){

                
                int nonTerminal = ruleRight[i].find(word[column]);
                if (nonTerminal != std::string::npos)  
  
                    if(table[column][row] == " "){

                        table[column][row] = ruleLeft[i]; 
                   }
                    else if(table[column][row].find(ruleLeft[i]) == std::string::npos  ){
                        table[column][row] += ruleLeft[i];
                    }
                    else
                        continue;

            }
        

    }
    /*
    2 1 A
    1 A
    A
    */
    void makeLadder(int col, int row, int diagonal){
        int ladderSize = (word.length()-1) - diagonal;
        for(int i =col + ladderSize ; i > col; i--){
            ladderRight.push_back(table[i][row]);
            
        }

        for(int i = row+1; i <= ladderSize + row; i++){
            ladderLeft.push_back(table[col][i]);
        	
        }
        calcValue(col, row);
    }
    void calcValue(int col, int row){
        /*
         * bal oldalon felfelé, 
         * jobbon lefelé haladunk az indexekkel
        */ 

        string a,b, temp = "";
        for (int i = 0; i < ladderLeft.size(); i++){    //  i a létra foka
            for (int j = 0; j < ladderLeft[i].length(); j++){ // j a bal létrafokon lévő baloldal mérete
                for (int k = 0; k < ladderRight[i].length(); k++){ //k a jobb létrafokon lévő baloldal
                    for (int l = 0; l < ruleRight.size(); l++){ // l a szabályok száma
                        a = ladderLeft[i][j];
                        b = ladderRight[i][k];
                        temp=a+b;
                        if (temp == ruleRight[l]){
                            if(table[col][row].find(ruleLeft[l])== std::string::npos){
                                
                                table[col][row]+=ruleLeft[l];
                            }
                        }
                    }
                    
                }
            }
        }
        ladderLeft.erase(ladderLeft.begin(), ladderLeft.end());
        ladderRight.erase(ladderRight.begin(), ladderRight.end());
    }
    void notFirstRow(int col, int row, int diagonal){
        makeLadder(col, row, diagonal);
    }
   /* 
    void writeRules(){
        cout<<"Rules:"<<endl;
        for(int i = 0; i < ruleLeft.size(); i++){
            cout<<ruleLeft[i]<<"->"<<ruleRight[i]<<endl;
        }

        
    }
*/
    void analyze(){
    	cout<<"Analyzing...."<<endl;
    	for(int i = 0; i < table.size(); i++){
    		for(int j = 0; j < table.size(); j++){
    			if (i+j == table.size()-1){//átló, az első sor
    				
    				if(table[i][j] == ""){
    					cout<<"This word is not member of this language! There's not even such letter..."<<endl;
    					exit(-1);
    				}
    			}
    		}
    	}
    	if(table[0][0].find(startSymbol) != std::string::npos){
    		cout<<"This word is member of this language."<<endl;
    	}
    	else{
    		cout<<"This word is not member of this language! Can't find "<<startSymbol<<" in the top cell."<<endl;
    	}
    }

    void start(CYK algorithm){
    	algorithm.readRules();
    
    	int len = 0;
    	len = algorithm.readWord();
    	if(len <= 0){
    		cerr<<"Word error!";
    		exit(-1);
    	}

    	//algorithm.writeRules();
    
    	algorithm.initTable(len);
    
    	algorithm.cyk();

    	algorithm.analyze();
    }
    
};

int main(int argc, char** argv) {

    CYK algorithm;
    
    algorithm.start(algorithm);

    return 0;
}

