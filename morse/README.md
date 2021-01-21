# Morse

## CMake
Le fichier CMakeLists.txt prend en charge tous les fichiers .cpp du sous-répertoire ./src
et tous les fichiers .h du sous-répertoire ./include
=> vous n'avez plus a y toucher si vous respectez cette organisation.
Lorsque vous ajoutez des fichiers .cpp et .h a votre projet il faut parfois ouvrir le fichier CMakeLists.txt et de le sauvagarder sans rien changer pour que le makefile soit re-généré automatiquement en prenant en compte les nouveaux fichiers. C'est tout.


## Utilisation d'un graphe
Il semble que cette indication concerne l'utilisation d'un arbre pour le décodage morse.
Un arbre étant un certain type de graphe.


## Lib encodage/decodage
Exemple de génération et relecture de fichier .wav contenant du morse suivant les hypothèses suivantes :
1)
    dot_duration : quelconque
    dash_duration = 3*_dot_duration
    intra_letter_duration : quelconque
    inter_letter_duration = 3*_intra_letter_duration
    inter_word_duration = 7*_intra_letter_duration

Un peu de marge a été prise lors du décodage.

2)
L'absence de signal morse est codé avec une valeur de signal = 0 => pas de bruit

3)
Dans la chaine de caractères passée en argument de l'encodeur : 
- un espace représente la séparation entre 2 caractères
- deux espaces représente la séparation entre 2 mots.

La fréquence du signal morse ne devrait pas poser de problème pour le décodage.
Les encodages 8 et 16 bits sont supportés pour le décodage.
La fréqence d'échantillonnage ne devrait pas poser de problème pour le décodage.

Toutes les varaiations possibles n'ont pas été testées.

En exemple de fichier .wav est présent dans le répertoire wave_examples.






