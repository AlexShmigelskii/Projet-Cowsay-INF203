#!/bin/bash

# Vérification basique du nombre d'arguments
# Il faut au moins 1 argument (un nombre initial)
if [ $# -lt 1 ]
then
    echo "Usage : $0 <nombre_initial> [<opérateur> <nombre>] ..."
    echo "Exemple : $0 5 + 2 - 3 \* 10"
    exit 1
fi

clear

# Premier nombre
result=$1
shift

# Salutation
cowsay "Salut ! Partons de $result."
sleep 1
clear

# Seuil de dépassement
THRESHOLD=100

while [ $# -ge 2 ]
do
    op=$1
    val=$2
    shift 2

    # Vérification de l'opérateur et de la valeur
    if [ "$op" != "+" ] && [ "$op" != "-" ] && \
       [ "$op" != "*" ] && [ "$op" != "/" ] && [ "$op" != "%" ]
    then
        cowsay -w "Opérateur invalide : $op"
        exit 1
    fi

    # On essaie de faire un calcul dans un sous-shell, rediriger les erreurs, et voir si $? = 0
    ( dummy=$(( $val + 0 )) ) 2> /dev/null
    if [ $? -ne 0 ]
    then
        cowsay -w "Nombre invalide : $val"
        exit 1
    fi

    # Verification d'expression
    (new_result=$(( result $op $val ))) 2>/dev/null
    err=$?

    if [ $err -ne 0 ]
    then
        cowsay "Oups, impossible de calculer : $result $op $val"
        exit 1
    fi
    
    # Calcul
    new_result=$(( result $op $val ))


    # Vérification de l'overflow
    if [ $new_result -gt $THRESHOLD ]
    then
        # La vache "perd la tête" : on va spammer plusieurs phrases de délire,
        # puis elle "meurt"

        cowsay -e "??" "Le résultat $new_result dépasse $THRESHOLD ! Je deviens complètement folle !"
        sleep 2
        clear

        cowsay -e "@@" "8%@gh... aaaaah... 42 !\nZorglub ???\nJe... suis... puissante !"
        sleep 2
        clear

        cowsay "!!!!! /++** ???"
        sleep 2
        clear

        # Et enfin, la vache "décède" (dead mode : -d)
        cowsay -d "Aaaaarg, c'en est trop ! Je meurs..."
        exit 0
    fi

    # Sinon, affichage normal
    eyes="oo"
    message="Résultat après $result $op $val : $new_result"

    if [ $new_result -lt 0 ]
    then
        eyes="XX"

    elif [ $new_result -eq 0 ]
    then
        eyes="??"
    fi

    result=$new_result

    cowsay -e "$eyes" "$message"
    sleep 2
    clear
done

# Résultat final
cowsay "Terminé ! Le résultat final est $result. À bientôt !"
