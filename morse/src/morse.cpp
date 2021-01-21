#include "../include/morse.h"
#include<map>
#include<string>
#include <cstdlib>
#include <iostream>

// Constructeur
morse::morse()
{

}

// Destructeur
morse::~morse()
{

}

// Encode une chaine asscii francais en caractÃ¨res morses
std::string morse::encode(std::string  ascii_string){
    
    std::map<int, std::string> map1 ; //dictionnaire 

    map1[65]=".-";          //lettres majuscules
    map1[66]="-...";
    map1[67]="-.-.";
    map1[68]="-..";
    map1[69]=".";
    map1[70]="..-.";
    map1[71]="--.";
    map1[72]="....";
    map1[73]="..";
    map1[74]=".---";
    map1[75]="-.-";
    map1[76]=".-..";
    map1[77]="--";
    map1[78]="-.";
    map1[79]="---";
    map1[80]=".--.";
    map1[81]="--.-";
    map1[82]=".-.";
    map1[83]="...";
    map1[84]="-";
    map1[85]="..-";
    map1[86]="...-";
    map1[87]=".--";
    map1[88]="-..-";
    map1[89]="-.--";
    map1[90]="--..";

    map1[97]=".-";          //lettres minuscules
    map1[98]="-...";
    map1[99]="-.-.";
    map1[100]="-..";
    map1[101]=".";
    map1[102]="..-.";
    map1[103]="--.";
    map1[104]="....";
    map1[105]="..";
    map1[106]=".---";
    map1[107]="-.-";
    map1[108]=".-..";
    map1[109]="--";
    map1[110]="-.";
    map1[111]="---";
    map1[112]=".--.";
    map1[113]="--.-";
    map1[114]=".-.";
    map1[115]="...";
    map1[116]="-";
    map1[117]="..-";
    map1[118]="...-";
    map1[119]=".--";
    map1[120]="-..-";
    map1[121]="-.--";
    map1[122]="--..";
    map1[32]=""; 
     
    int longueur = ascii_string.length(); 
    std::string ret = "";

    for(int i=0; i<longueur; i++)
    {
    char ascii_char = ascii_string[i];  //on prend une lettre

    

    int ascii = int(ascii_char);  // on prend son equivalent de la table ascii
    
    std::string code = map1[ascii];  // on prend son code associe en morse 
    
    int l = code.length();
    for(int n=0; n<l ; n++)  //on append caractere par caractere au string final
    {
        ret.push_back(code[n]);
        
        //std::cout<<"retour" << ret<<std::endl;
    }
    ret.push_back(' ');   // espace entre les lettres 

    }


    return ret;
}


// Decode une chaine de caracteres morse en caracteres ascii franÃ§ais.
std::string morse::decode(std::string morse_string){ 
    std::map<std::string, int> map2 ; //dictionnaire
    map2[".-"] = 97;
    map2["-..."] = 98;
    map2["-.-."] = 99;
    map2["-.."] = 100;
    map2["."] = 101;
    map2["..-."] = 102;
    map2["--."] = 103;
    map2["...."] = 104;
    map2[".."] = 105;
    map2[".---"] = 106;
    map2["-.-"] = 107;
    map2[".-.."] = 108;
    map2["--"] = 109;
    map2["-."] = 110;
    map2["---"] = 111;
    map2[".--."] = 112;
    map2["--.-"] = 113;
    map2[".-."] = 114;
    map2["..."] = 115;
    map2["-"] = 116;
    map2["..-"] = 117;
    map2["...-"] = 118;
    map2[".--"] = 119;
    map2["-..-"] = 120;
    map2["-.--"] = 121;
    map2["--.."] = 122;
    map2[" "] = 32;
    //map2["  "] = 32;

    std::string ret = "";
    
    int l = morse_string.length();  //longueur de la chaine en morse

    //std::cout << "longueur: " << l << std::endl;

    int compteur_total = 0; //compteur de la boucle while

    while(compteur_total < l)  //on parcoure la string
    {
        std::string code = "";
        while(morse_string[compteur_total] != ' ') //on cherche les espaces separant les lettres 
        {   
            
            code.push_back(morse_string[compteur_total]); //tant que c'est pas un espace, on remplit une string qui sera une lettre entiere 
            compteur_total = compteur_total + 1;
            //std::cout << "compteur= " << compteur_total << std::endl;
        }
        

        char lettre = (char)map2[code]; //on transforme le code morse d'une lettre en cette lettre 
        if(map2[code] != 0)   //cette boucle if evite de mettre un "vide" (de code ascii 0) qui fosse le test a la fin 
        {
            ret.push_back(lettre);   //on append cette lettre a la string de fin
        }
          
        code = ""; // on remet la lettre a 0

        if(morse_string[compteur_total+1]==' ' && morse_string[compteur_total]==' ') //on verifie si l'espace auquel on est arrive est un espace entre 2 lettres ou entre 2 mots
        { 
            ret.push_back(' '); // 2 espaces en morse separe un mot donc un espace en francais
            //std::cout<< "coucou y a un espace"<< std::endl;
            //std::cout<< "compteur: " << compteur_total << std::endl;
            
        } 
        
        
        compteur_total = compteur_total + 1;
        //std::cout << "compteur: " << compteur_total << std::endl;
    
    }
    
    
    return ret;
}



