#!/bin/bash

# On efface l'ecran de terminal avant de commencer
clear

# Salutation
cowsay Je vais compter
sleep 1
clear

for i in {1..10}
do
    # La vache prononce le chiffre 
    cowsay $i

    # On patiente 1 seconde
    sleep 1

    # On re-efface l'ecran avant la prochaine itération
    clear
done 

# À la fin, la vache tire la langue
cowsay -T U "J'ai terminé!"
