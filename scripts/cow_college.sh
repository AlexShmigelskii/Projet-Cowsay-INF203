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
if [ $1 -le 1 ]
then
  cowsay "Hmmm..."
  sleep 2
  clear
  cowsay "Veuillez fournir un nombre entier positif supérieur à 1."
  exit 1
fi

# Salutation
cowsay "Je vais compter"
sleep 1
clear

# Récupération de l'argument
N=$1

# Initialisation de la suite de Fibonacci
FIB1=1   # premier terme
FIB2=1   # deuxième terme

# Affiche FIB1 si FIB1 < N
while [ $FIB1 -lt $N ]
do
  # La vache prononce le nombre courant de la suite
  cowsay $FIB1

  # Calcul du terme suivant
  NEW=$(($FIB1 + $FIB2))
  FIB1=$FIB2
  FIB2=$NEW

  # Pause 1 seconde
  sleep 1

  # Efface l'écran avant le prochain nombre
  clear
done

# À la fin, la vache tire la langue
cowsay -T U "J'ai terminé!"
