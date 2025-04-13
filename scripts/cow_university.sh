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

# Boucle de 2 jusqu'à n-1
CMPT=2
while [ $CMPT -lt $N ]
do
    # Testons la primalité de CMPT
    isPrime=1    # On suppose que CMPT est premier, jusqu'à preuve du contraire

    # Test de divisibilité de 2 à CMPT-1
    i=2
    while [ $i -lt $CMPT ]
    do
        if [ $(($CMPT % $i)) -eq 0 ]
        then
            isPrime=0   # Trouvé un diviseur => pas premier
            break       # Pas besoin de continuer
        fi
        i=$((i + 1))
    done

    # Si isPrime vaut 1 => c'est un nombre premier
    if [ $isPrime -eq 1 ]
    then
        cowsay "$CMPT"
        sleep 1
        clear
    fi

    # Incrémentation
    CMPT=$((CMPT + 1))
done

# À la fin, la vache tire la langue
cowsay -T U "J'ai terminé!"
