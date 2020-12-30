Margineanu Vladut 341 C2
Laborator saptamana 4 - Readme

				Reteaua Benes

 Sa se proiecteze o retea Benes cu 8 intrari si 8 iesiri utilizand OrCAD. Sa se proiecteze
unitatea de control a retelei, care primeste lista de conexiuni de realizat si furnizeaza
semnalele de comanda pentru comutatoarele elementare 2*2 (unitatea de comanda poate sa
dispuna de un set de 8 registre pe 3 biti fiecare corespunzatoare celor 8 intrari in care se
inscriu codurile iesirilor la care sunt conectate intarile respective).
 Varianta: simulare software.  
 
 Rezolvare:

 Se trateaza in functie de etaje, astfel:
 - primul si ultimul etaj => shuffle si intershuffle
 - in mijloc - 2 separate, butterfly (nu pe general)
 - in interior mereu un Benes de ordin n/2 plus inca un Benes ordin n/2
 - le leg sus + jos