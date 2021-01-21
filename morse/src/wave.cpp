#include "../include/wave.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

namespace little_endian_io
{
  template <typename Word>
  std::ostream& write_word( std::ostream& outs, Word value, unsigned size = sizeof( Word ) )
  {
    for (; size; --size, value >>= 8)
      outs.put( static_cast <char> (value & 0xFF) );
    return outs;
  }
}
using namespace little_endian_io;

void wave::EncodeMorseCodesAsSound(const std::string &filename, std::string &morse){
  ofstream f( filename, ios::binary );

  // Write the file headers
  f << "RIFF----WAVEfmt ";     // (chunk size to be filled in later)
  write_word( f,     16, 4 );  // no extension data
  write_word( f,      1, 2 );  // PCM - integer samples
  write_word( f,      2, 2 );  // two channels (stereo file)
  write_word( f,  44100, 4 );  // samples per second (Hz)
  write_word( f, 176400, 4 );  // (Sample Rate * BitsPerSample * Channels) / 8
  write_word( f,      4, 2 );  // data block size (size of two integer samples, one for each channel, in bytes)
  write_word( f,     16, 2 );  // number of bits per sample (use a multiple of 8)

  // Write the data chunk header
  size_t data_chunk_pos = f.tellp();
  f << "data----";  // (chunk size to be filled in later)
  
  // Write the audio samples
  // (We'll generate a single C4 note with a sine wave, fading from left to right)
  const double two_pi = 6.283185307179586476925286766559;
  const double max_amplitude = 32760;  // "volume"

  double hz        = 44100;    // samples per second
  double frequency = 261.626;  // middle C
        // time

    // total number of samples

int longueur = morse.length();
//std::cout << "longueur = " <<  longueur << std::endl;
int echantillons = 0;

for (int i = 0; i <= longueur; i++)
  {
    if(morse[i] == '.')
    {
        double seconds   = 0.2;
        int N = hz * seconds;
        //std::cout << "N = " << N << std::endl;

        double pause   = 0.2;
        int N2 = hz * pause;
        //std::cout << "N2 = " << N2 << std::endl;

        echantillons = echantillons + N + N2;
        //std::cout << "echantillons = " <<  echantillons << std::endl;
    }
    if(morse[i] == '-')
    {   
        double seconds   = 0.6 ;
        int N = hz * seconds;
        //std::cout << "N = " << N << std::endl;
        
        double pause   = 0.2;
        int N2 = hz * pause;
        //std::cout << "N2 = " << N2 << std::endl;

        echantillons = echantillons + N + N2;
        //std::cout << "echantillons = " <<  echantillons << std::endl;
        
    }
    if(morse[i] == ' ')
    { 
        double pause   = 0.2;
        int N2 = hz * pause;
        //std::cout << "N2 = " << N2 << std::endl;

        echantillons = echantillons + N2;
        //std::cout << "echantillons = " <<  echantillons << std::endl;
    }
    
      //std::cout << "i = " <<  i << std::endl;
  } 


int compteur = 0;
for (int i = 0; i < longueur; i++)
  {
    
    //std::cout << "compteur = " << compteur << std::endl;

    if(morse[i] == '.')
    {
        double seconds   = 0.2;
        int N = hz * seconds;
        
        for (int n = compteur ; n < compteur + N; n++)
        {
            double amplitude = (double)n / echantillons * max_amplitude;
            double value     = sin( (two_pi * n * frequency) / hz );
            write_word( f, (int)(                 amplitude  * value), 2 ); // remplacer deuxieme agrument par zero su les deux lignes pour faire des blancs
            write_word( f, (int)((max_amplitude - amplitude) * value), 2 );
      
        }
        compteur = compteur + N;
        //std::cout << "compteur = " << compteur << std::endl;

        double pause   = 0.2;
        int N2 = hz * pause;
        for (int n = compteur; n < N2 + compteur; n++)
        {
            double amplitude = (double)n / echantillons* max_amplitude;
            double value     = sin( (two_pi * n * frequency) / hz );
            write_word( f, 0, 2 ); // remplacer deuxieme agrument par zero su les deux lignes pour faire des blancs
            write_word( f, 0, 2 );
      
        }
        compteur = compteur + N2;
        //std::cout << "compteur = " << compteur << std::endl;
    }
    if(morse[i] == '-')
    {   
        double seconds   = 0.6 ;
        int N = hz * seconds;
        for (int n = compteur; n < N + compteur; n++)
        {
            double amplitude = (double)n / echantillons * max_amplitude;
            double value     = sin( (two_pi * n * frequency) / hz );
            write_word( f, (int)(                 amplitude  * value), 2 ); // remplacer deuxieme agrument par zero su les deux lignes pour faire des blancs
            write_word( f, (int)((max_amplitude - amplitude) * value), 2 );
      
        }
        compteur = compteur + N;
        //std::cout << "compteur = " << compteur << std::endl;

        double pause   = 0.2;
        int N2 = hz * pause;
        for (int n = compteur; n < N2 + compteur ; n++)
        {
            double amplitude = (double)n / echantillons* max_amplitude;
            double value     = sin( (two_pi * n * frequency) / hz );
            write_word( f, 0, 2 ); // remplacer deuxieme agrument par zero su les deux lignes pour faire des blancs
            write_word( f, 0, 2 );
      
        }
        compteur  = compteur + N2;
        //std::cout << "compteur = " << compteur << std::endl;
        
    }
    if(morse[i] == ' ')
    {

        double pause   = 0.2;
        int N = hz * pause;
        for (int n = compteur; n < N + compteur ; n++)
        {
            double amplitude = (double)n / echantillons* max_amplitude;
            double value     = sin( (two_pi * n * frequency) / hz );
            write_word( f, 0, 2 ); // remplacer deuxieme agrument par zero su les deux lignes pour faire des blancs
            write_word( f, 0, 2 );
      
        }
        compteur  = compteur + N;
        if(morse[i+1] != ' ')
        {

        }
        else
        {
            double pause   = 0.2;
            int N2 = hz * pause;
            for (int n = compteur; n < N2 + compteur; n++)
            {
                double amplitude = (double)n / echantillons* max_amplitude;
                double value     = sin( (two_pi * n * frequency) / hz );
                write_word( f, 0, 2 ); // remplacer deuxieme agrument par zero su les deux lignes pour faire des blancs
                write_word( f, 0, 2 );
      
            }
            compteur = compteur + N2;
            //std::cout << "compteur = " << compteur << std::endl;
        }
        

        
    }
    
      
  }

  // (We'll need the final file size to fix the chunk sizes above)
  size_t file_length = f.tellp();

  // Fix the data chunk header to contain the data size
  f.seekp( data_chunk_pos + 4 );
  write_word( f, file_length - data_chunk_pos + 8 );

  // Fix the file header to contain the proper RIFF chunk size, which is (file size - 8) bytes
  f.seekp( 0 + 4 );
  write_word( f, file_length - 8, 4 ); 

}




std::string wave::DecodeMorseWavFile(std::string file_name)
{
    std::string morse ="";
    ifstream f(file_name, ios::binary );
    

    int taille = 0;

    if (f.is_open())
    {
        f.ignore(40);
        //std::cout << "pos = " << f.tellg() << std::endl;
        uint32_t taille_fichier;
        
        f.read(reinterpret_cast<char *>(&taille_fichier), sizeof (taille_fichier));
        //std::cout << "taille fichier= " << taille_fichier << std::endl;
        uint32_t var = 1;
        bool boucle = true;
        int c = 0;
        
        while(f.tellg() < taille_fichier)
        {
            while (boucle && f.tellg() < taille_fichier)
            {
                f.read(reinterpret_cast<char *>(&var), sizeof (var));
                //cout<<var<<" "<<endl;
                c++;
                if (var == 0 && f.tellg() < taille_fichier)
                {
                    f.read(reinterpret_cast<char *>(&var), sizeof (var));
                    //cout<<var<<" "<<endl;
                    c++;
                    if (var == 0 && f.tellg() < taille_fichier)
                    {
                        boucle = false;
                    }
                }
            }
            boucle = true ;
            //cout<<"1 : "<<c<<endl;
            c = 0;
            //taille++;
            while ( var == 0 && f.tellg() < taille_fichier)
            {
                f.read(reinterpret_cast<char *>(&var), sizeof (var));
                //cout<<var<<" "<<endl;
                c++;
            }
            //cout<<"0 : "<<c<<endl;
            c = 0;
            taille++;
        }
        
    }

    const int taille_tableau = taille;
    //std::cout<< "taille = " << taille_tableau << std::endl;

    ifstream g(file_name, ios::binary );
    int table_1[taille_tableau-1] ;
    int table_0[taille_tableau-1] ;
    //std::cout << "size de 1 " << sizeof(table_1) << std::endl;
    int max_1 = 0;
    int min_1 = 1000000;
    int max_0 = 0;
    int min_0 = 1000000; 

    if (g.is_open())
    {
        g.ignore(40);
        //std::cout << "pos = " << g.tellg() << std::endl;
        uint32_t taille_fichier2;
        
        g.read(reinterpret_cast<char *>(&taille_fichier2), sizeof (taille_fichier2));
        //std::cout << "taille fichier= " << taille_fichier2 << std::endl;
        uint32_t var = 1;
        bool boucle = true;
        int c = 0;

        for(int j = 0; g.tellg() <= taille_fichier2; j++)
        {
            
            while (boucle && g.tellg() <= taille_fichier2)
                {
                    g.read(reinterpret_cast<char *>(&var), sizeof (var));
                    //cout<<var<<" "<<endl;
                    c++;
                    if (var == 0)
                    {
                        g.read(reinterpret_cast<char *>(&var), sizeof (var));
                        //cout<<var<<" "<<endl;
                        c++;
                        if (var == 0)
                        {
                            boucle = false;
                        }
                    }
                }
            boucle = true ;
            table_1[j] = c;

            /*if (c < min_1)
                {
                    min_1 = c;
                }
            if( c > max_1)
                {
                    max_1 = c;
                }
            */

            min_1 = std::min(c, min_1);
            max_1= std::max(c, max_1);


            c = 0;
            
            while ( var == 0 && g.tellg() <= taille_fichier2)
                {
                    g.read(reinterpret_cast<char *>(&var), sizeof (var));
                    //cout<<var<<" "<<endl;
                    c++;
                }
            
            table_0[j]= c;
           
           /* if (c < min_0)
                {
                    min_0 = c;
                }
            else if( c > max_0)
                {
                    max_0 = c;
                }

                 */

            min_0 = std::min(c, min_0);
            max_0 = std::max(c, max_0);

            c = 0;

            //std::cout << "j = " << j << std::endl;
            //std::cout << "taille = " << taille_fichier2 << std::endl;
            //std::cout << "pos = " << g.tellg() << std::endl;
                
        }
        
        

    }
    

    /*for(int n=0; n< taille_tableau; n++)
    {
        //std::cout << "coucou" << std::endl;
        //std::cout << "1 " << " = " << table_1[n] << std::endl;
        
    }
     for(int k=0; k< taille_tableau ; k++)
    {
        std::cout << "0 " << " = " << table_0[k] << std::endl;
    } 
 */
    //if( condition de debut en son)
        //{
             for( int i =0; i< taille_tableau; i++)
                {
                    if(table_1[i] <= 1.10*max_1 && table_1[i]>= 0.9*max_1)
                    {
                        morse.push_back('-');
                    }
                    else
                    {
                        morse.push_back('.');
                    }
                    if(table_0[i]<= 1.10*max_0 && table_0[i]>= 0.9*max_0)
                    {
                        morse.push_back(' ');
                        morse.push_back(' ');
                    }
                    else if(table_0[i]<= 1.10*min_0 && table_0[i]>= 0.9*min_0)
                    {
                        
                    }
                    else
                    {
                        morse.push_back(' ');
                    }

                }
        //}

   /* else
    {
         {
             for( int i =0; i< taille_tableau; i++)
                {
                    
                    if(table_0[i]<= 1.10*max_0 && table_0[i]>= 0.9*max_0)
                    {
                        morse.push_back(' ');
                        morse.push_back(' ');
                    }
                    else if(table_0[i]<= 1.10*min_0 && table_0[i]>= 0.9*min_0)
                    {
                        
                    }
                    else
                    {
                        morse.push_back(' ');
                    }

                    if(table_1[i] <= 1.10*max_1 && table_1[i]>= 0.9*max_1)
                    {
                        morse.push_back('-');
                    }
                    else
                    {
                        morse.push_back('.');
                    }

                }
        }
    }
   */

    //std::cout << "size de 1 " << sizeof(table_1) << std::endl;
    //std::cout << "min de 1 : " << min_1 <<std ::endl;
    //std::cout << "max de 1 : " << max_1 <<std ::endl;
    //std::cout << "min de 0 : " << min_0 <<std ::endl;
    //std::cout << "max de 0 : " << max_0 <<std ::endl;

    /*std::cout << "min de 1 avec func = " << std::min(table_1) << std::endl;
    std::cout << "max de 1 avec func = " << std::max(table_1) << std::endl;
    std::cout << "min de 0 avec func = " << std::min(table_0) << std::endl;
    std::cout << "max de 0 avec func = " << std::max(table_0) << std::endl; */
    //std::cout << "morse = " << morse << std::endl;

    return morse;

}


/*
void wave::test_write_binary(std::uint32_t v)
{
    std::ofstream wav;

    wav.open("test.bin", std::ofstream::out | std::ofstream::binary);
    if (wav.is_open())
    {
        wav.write(reinterpret_cast<char *>(&v), sizeof(v));
        wav.close();
    }
}

std::uint32_t wave::test_read_binary()
{
    std::uint32_t ret = 0;
    std::ifstream wav;

    wav.open("test.bin", std::ifstream::in | std::ifstream::binary);
    if (wav.is_open())
    {
        wav.read(reinterpret_cast<char *>(&ret), sizeof(ret));
        wav.close();
    }

    return ret;
}

*/