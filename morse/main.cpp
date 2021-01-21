#include <iostream>
#include "./include/morse.h"
#include "./include/wave.h"
#include <string>


int main(int, char**) {
    morse m;

    // 1) Structure du code encodage/décodage de texte tel qu'il pourrait-être attendu

    std::cout << "Donnez moi une phrase svp" << std::endl;
    std::string ascii_string_ori;
    getline( std::cin, ascii_string_ori);
    //std::cin >> ascii_string_ori;
    std::string ascii_string = ascii_string_ori;
    std::string morse_string;

    std::cout << "Donnez moi le nom du fichier dans lequel vous voulez mettre votre son (sous la forme nom.wav)" << std::endl;
    std::string nom_fichier;
    getline( std::cin, nom_fichier);


    // Affichage valeur de départ.
    std::cout << "ascii : " << ascii_string_ori << std::endl;

    // Encodage
    morse_string = m.encode(ascii_string);
    //int l = morse_string.length();
    std::cout << "encodage morse : " << morse_string << std::endl;
    //std::cout << "l= " << l << std::endl;

    // Décodage
    ascii_string = m.decode(morse_string);
    
    int l1 = ascii_string_ori.length();
    int l2 = ascii_string.length();
    std::cout<< "l1 = " << l1 << std::endl;
    std::cout<< "l2 = " << l2 << std::endl;
    std::cout << "ascii : " << ascii_string_ori << std::endl;
    std::cout << "decodage morse : " << ascii_string<< std::endl;

    /*std::string sos = "... --- ...  ... --- ... ";
    std::string decodee = m.decode(sos);
    std::cout<< "decodee: " << decodee << std::endl; */

    /*for(int i = 0; i<=l1; i++)
    {
        std::cout <<"i = "<<i<< std::endl;
        std::cout<< "originale[i]= " << int(ascii_string_ori[i])<< std::endl;
        std::cout<< "decodee[i]= " << int(ascii_string[i]) <<std::endl;

        if(ascii_string_ori[i] != ascii_string[i])
        {
            std::cout<< "c'est pas bon" << std::endl;
        
        }
    }  */
//std::cout << "originale[6]= " << ascii_string_ori[6]<< "decodee[6]= " << ascii_string[6] <<std::endl;


    //std::string tests = m.decode(".... . .-.. .-.. ---  .-- --- .-. .-.. -.. ");
    //std::cout << "decodage morse : " << tests << std::endl;

    
    

    // Tests a enrichir.
    
 
   


    if (ascii_string == ascii_string_ori)
    {
        std::cout << "peut être ok..." << std::endl;
    }
    else
    {
        std::cout << "nok" << std::endl;
    } 
    

    // 2) Exemple d'utilisation de la librairie d'aide pour la création et la lectiure de fichier .wav.
    // Cette librairie ne doit pas être utilisée dans votre code défintif.
    // L'exercice consiste aussi a re-coder l'équivalent de cette librairie.
    // La mise à disposition sous-forme de librairie a pour unique but de "cacher" le code => il n'est pas utile de mettre
    // votre code sous forme de librairie.
    wave w;

    //w.EncodeMorseCodesAsSound("../wave_examples/first.wav", morse_string);

    w.EncodeMorseCodesAsSound(nom_fichier, morse_string);

    std::string morse_decode =  w.DecodeMorseWavFile(nom_fichier);
    std::string phrase = m.decode(morse_decode);
    std::cout << "phrase decodee a paertir du fichier audio: " << phrase << std::endl;
    //std::cout << std::endl;

    // 3) Exemple d'écriture et lecture au format "binaire" dans un fichier d'un mot de 32 bits
    //w.test_write_binary(42);
    //std::uint32_t v = w.test_read_binary();

    //std::cout << v << std::endl; */

    return 0;
}


