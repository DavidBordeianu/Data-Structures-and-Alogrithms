<h1 align="center">
 lab-02: Sortari si complexitate
</h1>

<h3>Cerinte:</h3>

1. Implementati metodele de sortare: MergeSort si QuickSort (vezi exemple si pseudocod in suportul de curs). Analizati metodele implementate si specificati daca sunt metode de sortare stabile sau instabile. <b>(MergeSort - 5p, QuickSort - 5p)</b>
2. (<b>Bonus</b>) Exista algoritmi de sortare care nu se bazeaza pe comparatii (ca cei de la punctul 1). Acestia se numesc algoritmi de tip "counting sort" si au complexitate temporala redusa <O(nlogn). Implementat! Care este complexitatea spatiala si cea temporala? De ce nu este mai folosit? <b>(2p)</b>

<b>Counting sort pe scurt</b> 

- algoritm ce se bazeaza pe faptul ca valorile de sortat se gasesc intr-un anumit domeniu.  

- functioneaza bazandu-se pe ideea de a numara de cate ori apare fiecare valoare din domeniul admisibil de valori in vector 

- pe baza frecventei de aparitie se calculeaza pozitiile elementelor in cadrul vectorului de ieisire (sortat)  

 Exemplu: Fie domeniul admisibil 0...9. Vectorul de sortat e v (n=7): 1 9 4 1 1 9 6. 

Se foloseste un vector de frecvente - vf (contine numarul de aparitii al fiecarei valori din vectorul de sortat), initial  vf are toate elementele 0. Dimensiunea lui vf e egala cu cea a domeniului admisibil de valori: 

  vf - index:   0 0 0 0 0 0 0 0 0 0  

  continut:  0 0 0 0 0 0 0 0 0 0 

Se analizeaza numarul de aparitii pentru fiecare valoare din v. vf devine: 

  vf - index:   0 0 0 0 0 0 0 0 0 0  

  continut:  0 3 0 0 1 0 1 0 0 2 

Se modifica v astfel incat sa stocheze valorile in ordine: 1 1 1 4 6 9 9.  

<h3>Observatii teste:</h3>

- Comanda <b>make test</b> va rula doar testele corespunzatoare cerintei 1.
- Comanda <b>make test-bonus</b> va rula testele corespunzatoare bonusului (cerinta 2).
