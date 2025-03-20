#!/bin/bash

# Vérification qu'un argument est fourni
if [ $# -ne 1 ]
then
  echo "Usage: $0 <nombre n>"
  # Abandonner l'exécution
  exit 1
fi

# On efface l'ecran de terminal avant de commencer
clear

# Salutation
cowsay Je vais compter
sleep 1
clear

# Initialisation du compteur et du nombre n
CMPT=1
N=$1

while [ $CMPT -le $N ]
do
    # La vache prononce le chiffre 
    cowsay $CMPT

    # Incrémentation du compteur
    CMPT=$((CMPT + 1))

    # On patiente 1 seconde
    sleep 1

    # On re-efface l'ecran avant la prochaine itération
    clear
done 

# À la fin, la vache tire la langue
cowsay -T U "J'ai terminé!"
