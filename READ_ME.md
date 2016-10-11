# Newfillit
Fillit 2.0

<b><i>Résolution</i></b>

Déjà comme d'hab, j'ai rajouté la race de <i>#define</i> et de variables dans la structure <i>t_coord</i> donc si t'es paumé, jette un coup d'oeil dans le .h!

J'ai surtout rajouté une variable <i>nb_l</i> qu'on récupère dans la fonction <b>ft_bufcpy</b> et qui garde le nombre de lignes qu'il y a dans la chaîne une fois trim.

J'ai créé une fonction (<i>ft_place_tetri</i>) dans <b>ft_map_creator.c</b> qui choppe le premier # de la pièce et check derrière si on peut placer les # suivants. Si elle peut c'est good, elle copie les # et lâche le bouzin prêt à passer à la pièce suivante.
Si non, elle recopie la map telle qu'elle était quand elle est entrée dans la fonction et prête à faire un BiggerMap.

Pour ça, j'ai créé une fonction (<i>ft_cpy_tab</i>) qui est dans <b>ft_trim.c</b>. Elle copie la map au début dans une autre variable. Je l'ai fait parce que sinon y'avait des couilles avec les pointeurs et ça ne gardait pas la map du début.

Du coup, la fonction <i>ft_place_tetri</i> avance aussi dans la map donc j'ai pu supprimer plein de trucs dans <i>ft_resolve</i>, elle fait plus que <b>54 lignes</b>! Par contre, <i>ft_place_tetri</i> fait <b>37 lignes</b> donc faudra équilibrer!

Du coup faut trouver une méthode qui fait qu'on peut changer l'ordre des pièces et après on est good!

Profite bien :)
