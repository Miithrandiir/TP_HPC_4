# HEBAN Simon

## TP4 HPC

1.5)

On peut en conclure que OpenMP se débrouille mieux tout seul que quand on donne des règles spécifiques (e.g `schedule`)

Question 1.6 et 1.7

L'implémentation de la question 1.2 reste la plus performante, elle est cependant suivie de très près par l'implémentation de la question 1.6, l'écart est d'environs : `0,01704336` secondes.

## Exercice 2

| Nombre de threads | Temps pour la somme | temps pour la racine carrée | temps pour la racine carrée * logarithme |
|-------------------|---------------------|-----------------------------|------------------------------------------|
| 1                 | 0.0252507s          | 0.269913s                   | 0.551369s                                |
| 2                 | 0.0143817s          | 0.610159s                   | 0.913941s                                |
| 3                 | 0.0103196s          | 0.675567s                   | 0.880364s                                |
| 4                 | 0.00927608s         | 0.892777s                   | 0.804051s                                |
| 5                 | 0.00825113s         | 0.863431s                   | 0.732126s                                |
| 6                 | 0.00720997s         | 0.878639s                   | 0.751211s                                |
| 7                 | 0.00557427s         | 0.832389s                   | 0.768132s                                |
| 8                 | 0.00636002s         | 0.869978s                   | 0.819484s                                |
| 9                 | 0.00586174s         | 0.831724s                   | 0.801101s                                |
| 10                | 0.00606128s         | 0.856708s                   | 0.804693s                                |
| 11                | 0.00526086s         | 0.841495s                   | 0.796697s                                |
| 12                | 0.00518663s         | 0.849531s                   | 0.808356s                                |
| 13                | 0.00461644s         | 0.846544s                   | 0.803273s                                |
| 14                | 0.00559983s         | 0.821967s                   | 0.817211s                                |
| 15                | 0.00507628s         | 0.811738s                   | 0.821112s                                |
| 16                | 0.00511728s         | 0.840626s                   | 0.817535s                                |


## Exercice 3

> Parallélisation statique de la boucle externe (sur 10 lancements)

2.82772s

> Parallélisation statique de la boucle interne (sur 10 lancements)

4.14996s

> Parallélisation statique des deux boucles (sur 10 lancements)

2.73705s

> Parallélisations dynamiques (sur 10 lancements)

2.17085s

À exécution équivalente, c'est-à-dire la même scène (scène 3) avec le même nombre de threads (16).
Les temps sont comparables pour la version du TP3 j'étais à `2.13285s` tandis qu'ici je suis à `2.17085s`.
On peut conclure que les directives OpenMP sont très performantes, et qui peuvent être équivalent à une distribution dynamique fait main.