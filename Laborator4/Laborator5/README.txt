Margineanu Vladut 341 C2
Laborator saptamana 3 - Readme

		Reteaua Omega 

 Sa se proiecteze o retea Omega cu 8 intrari si 8 iesiri utilizand OrCAD. Sa se
 proiecteze unitatea de control a retelei, care primeste lista de conexiuni de realizat si
 furnizeaza semnalele de comanda pentru comutatoarele elementare 2*2 (unitatea de comanda
 poate sa dispuna de un set de 8 registre pe 3 biti fiecare corespunzatoare celor 8 intrari
 in care se inscriu codurile iesirilor la care sunt conectate intarile respective).
 Varianta: simulare software. 
 
 Rezolvare:

 Se interconecteaza module elementare de interschimb, pe etaje. Intre etaje se pune conexiunea shuffle
 log2 n etaje -> 8 intrari iesiri => 3 etaje
 Operatiile la nivelul fiecarui etaj sunt urmatoarele:
  - interconectez intratrea 2 cu iesirea 3 si simultan intrarea 3 si iesirea 4 si intrarea 4 su iesirea 7.
 Pentru test: lista intrari, iesiri.
 Pentru fiecre in-out, care sunt blocurile de interschimb implicate si ce operatii face fiecare:

 001 la 000: direct direct invers + etaj, bloc
 Dimensiunea retelei este n = 2 ^ k
 La modul general, doar cu conexiuni directe + inverse.