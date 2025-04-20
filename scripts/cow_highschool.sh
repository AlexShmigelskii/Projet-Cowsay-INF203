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

# Vérification que N est un entier positif
if [ $1 -le 0 ]
then
  cowsay "Hmmm..."
  sleep 2
  clear
  cowsay "Veuillez fournir un nombre entier positif supérieur à 0."
  exit 1
fi

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
  cowsay $(($CMPT * $CMPT))

  # Incrémentation du compteur
  CMPT=$(($CMPT + 1))

  # On patiente 1 seconde
  sleep 1

  # On re-efface l'ecran avant la prochaine itération
  clear
done 

# À la fin, la vache tire la langue
cowsay -T U "J'ai terminé!"
