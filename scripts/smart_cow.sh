#!/bin/bash

# Vérification d'un seul argument
if [ $# -ne 1 ]
then
  echo "Usage: $0 \"<expression>\""
  exit 1
fi

# On efface l'ecran de terminal avant de commencer
clear

expr=$1

# Évaluation silencieuse (en cas d'erreur, rien ne s'affiche)
# 1) On exécute les calculs dans un subshell
# 2) On redirige la sortie d'erreur (2) vers /dev/null
( 
    res=$(( $expr )) 
) 2> /dev/null
err=$?  # Capturer le code de retour

if [ $err -ne 0 ]
then
  # Si l'opération a échoué (code != 0 <=> syntaxe invalide, division par zéro, etc.)
  cowsay "Expression invalide : $expr"
  exit 1
fi

# À l'intérieur des parenthèses (subshell), la variable $res n'était valable
# que dans ce bloc temporaire. Une fois le bloc terminé, elle n'existe plus
# dans le reste du script. 
# Du coup, on refait simplement le calcul ici, sans contrôle supplémentaire
# puisque l'expression est forcément valide (on l'a déjà vérifiée).
res=$(( $expr ))
len=${#res}

if [ $len -eq 1 ]
then
  # 1 chiffre => un œil + œil fermé
  eyes="${res}-"
  msg="Le résultat de $expr est $res"
elif [ $len -eq 2 ]
then
  # 2 chiffres => deux yeux
  eyes="$res"
  msg="Le résultat de $expr est $res"
else
  # Plus de 2 chiffres => ?? et message d'excuse
  eyes="??"
  msg="Désolé, mes yeux sont trop petits pour afficher le résultat de $expr : $res"
fi

# Enfin, on affiche la vache
cowsay -e "$eyes" "$msg"