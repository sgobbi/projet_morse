## Morse Encoder/Decoder (C++)

Description

Ce projet est un programme C++ qui encode et décode des messages en code Morse à partir d’une phrase ou d’un fichier audio WAV.

Le programme permet de :

Encoder une phrase en Morse (-- ..)

Vérifier que le décodage correspond à la phrase initiale

Générer un fichier .wav contenant le message Morse

Lire un fichier .wav et décoder la chaîne Morse

⚠️ Limitation : le décodage depuis un fichier WAV fonctionne uniquement si la phrase contient au moins un espace. Pour un mot seul, ajoutez un espace à la fin.

### Fonctionnalités

Texte → Morse → texte

Génération de fichier audio .wav

Décodage depuis fichier audio .wav

Vérification de la correspondance phrase initiale ↔ phrase décodée

### Exemple
```bash
Entrez la phrase à coder : Bonjour le monde
Nom du fichier WAV (ex: output.wav) : test.wav

Phrase en Morse : -... --- -. .--- --- ..- .-.  .-.. .  -- --- -. -.. .
Phrase décodée : Bonjour le monde
Fichier WAV créé : test.wav
Lecture du fichier WAV : -... --- -. .--- --- ..- .-.  .-.. .  -- --- -. -.. .

