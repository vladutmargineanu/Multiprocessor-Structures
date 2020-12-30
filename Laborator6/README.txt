Margineanu Vladut 341 C2
Laborator saptamana 06 - Readme

				OpenMP

 Sa se scrie o aplicatie de complexitate medie cu OpenMP sub Windows NT/XP


Se calculeaza numarul PI, cu algoritmul Monte Carlo.

Algoritmul
1. Se inițializeaza punctele cerc, punctele pătrate și intervalul la 0.
2. Se genereaza punctul aleatoriu x.
3. Se genereaza punctul aleatoriu y.
4. Se calculeaza d = x * x + y * y.
5. Dacă d <= 1, se cresc punctele cercului.
6. Incrementarea punctelor pătrate.
7. Interval de creștere.
8. Dacă incrementul este mai mic ca numarul de iteratii, se repeta de la 2.
9. Se calculeaza pi = 4 * (cerc_puncte / pătrat_puncte).
10. Termină.