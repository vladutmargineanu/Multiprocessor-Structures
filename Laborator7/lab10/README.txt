Margineanu Vladut 341 C2
Laborator 10 MESI - Readme

				MESI

 Sa se scrie un program care simuleaza protocolul MESI de pastrare a coerentei
 memoriilor cache intr-un sistem multiprocesor bazat pe magistrala cu 4 procesoare.
 Programul primeste la intrare o secventa de operatii de citire si scriere efectuate de
 procesoare, referitoare la un acelasi bloc de memorie cache si determina starile succesive ale
 blocului la nivelul fiecarei memorii cache.

 Rezolvare:
 Se considera un sistem multiprocesor cu trei procesoare in care
 consistenta memoriei cache se asigura printr-un protocol MESI. Se executa o
 succesiune de operatii de citire si scriere referitoare la un acelasi bloc de memorie
 cache:
 P1Rd, P2Rd, P3Rd, P1Rd, P1Wr, P1Rd, P2Wr, P3Rd
 Initial nu exista copii ale blocului in nicio memorie cache. Sa se specifice succesiunea
 de stari corespunzatoare blocului la nivelul fiecarei memorii cache, actiunile pe
 magistrala si dispozitivul care furnizeaza datele.