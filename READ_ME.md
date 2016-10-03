# Newfillit
Fillit 2.0

<b><i>Résolution</i></b>


<i>ATTENTION : L'Algo utilise actuellement les pièces <b>NON TRIM</b> (impossible de connaitre le nombre de ligne une fois trim)</i>

Actuellement, la fonction <i>ft_resolve</i> marche conjointement avec <i>ft_prepare_algo</i> et <i>ft_map_creator</i> :

<i>prepare_algo</i> = Instancie les variables de la structure <i>t_coord</i>, appel de la fonction <i>ft_map_creator</i>

<i>ft_map_creator</i> = Crée la Map en fonction de la taille de <i>Cote</i> indiquée (toujours un carré)

L'algo tente actuellement de placer la piece sur la map, n'importe où en partant d'en haut à gauche. Il fait défiler les charactères de la Map, puis les remplacent par ceux de la piece s'il s'agit de # ou de \n. Il est censé tourner tant que toute la map n'a pas été testé (<i>X_M <= COTE et Y_M <= COTE</i>) ou tant que toutes les pieces n'ont pas été placé = trim entièrement lu (<i>Y_P / 4 <= NB_P où NB_P = Nbr de lignes / 4</i>).

Si la fonction parvient à placer tous les # d'une pièce (sous forme de lettre) et qu'on en a plusieurs, elle détecte la ligne vide, passe à la ligne et lettre suivante, puis <i>lance le récursif</i> pour placer la suite.
Si on a exploré toute la map sans finir le placement (<i>X_M == COTE && Y_M == COTE</i>) <b>MAUVAISE CONDITION</b>, on rappelle <i>prepare_algo</i> pour reprendre du début avec une map plus grande de 1. Ça, ça fonctionne.


<b><i>PROBLÈME</b></i> = Les conditions ne sont pas assez efficaces et provoquent <i>moults Segfaults</i>. La réponse en fonction de la condition d'arrêt (<i>Map finie? Pièces toutes placées?</i>) ne correspond pas, avec des return intempestifs, et des récursives inutiles. Le programme ne place les pièces <i>que dans leur ordre d'apparition</i>. Les pièces ne sont pas placées convenablement (<b>LA PLACE DES DIESES PAR RAPPORT AUX AUTRES N'EST PAS CONSERVÉE</b>).
Le mieux que j'ai pu faire actuellement et de placer deux pièces avec les bonnes lettres mais dont la forme n'avait pas été conservée.


BREF, ça commence à placer tout le bouzin, mais <i>n'importe comment</i> et pourtant <b>la norme a déjà été pulvérisée</b>. Bon courage!

(J'ai aussi tout mis à la norme, surtout les fonctions finies mais pas normée. De rien c'est cadeau 👏)
