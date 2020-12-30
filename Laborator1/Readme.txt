Margineanu Vladut 341 C2
Laborator 01 - Readme

Modele teoretice de calculatoare paralele

CRCW - PRAM
 Etapa 1:
Fiecare procesor Pi,j,k calculeaza in paralel produsul a[i][k]*b[k][j].
- Se initializeaza c pentru i si j;
- Se calculeaza c[i][j] pentru k in for;
Etapa 2: 
Se face scrierea concurenta a procesoarelor Pi,j,0 ; Pi,j,1 ; Pi,j,2 ; .... ;
Pi,j,n-1 in
locatia c[i][j] a termenilor a[i][0]*b[0][j], a[i][1]*b[1][j], a[i][2]*b[2][j],
 ... , a[i][n1]*b[n-1][j], care astfel se insumeaza. 
- Calculam suma in variabila sum si afisam;
- Atribuim valoarea lui sum, elementul matricei c[i][j], corespunzator.
Timpul de executie paralela Tp = O(1). Rezulta accelerarea S = O(n3) si 
eficienta E = 1. 

CREW - PRAM
Se realizeaza pe etape:
1. Etapa 1:
Fiecare procesor Pi,j,k calculeaza in paralel produsul a[i][k]*b[k][j] si 
inscrie rezultatul in v[i[j[k].
Calculam si scriem v[i][j][k];
2. Etapa 2:
Reducerea prin insumarea a n elemente ale fiecarui vector din tabloul 2D
v[i][j] (in total n la patrat vectori), folosind n procesoare pentru fiecare
vector: Pi,j,0; Pi,j,1; Pi,j,2; .... ;
Pi,j,n-1, obtinand rezultatul in v[i][j][0].
Scriem in v[i][j][k] pentru  m;