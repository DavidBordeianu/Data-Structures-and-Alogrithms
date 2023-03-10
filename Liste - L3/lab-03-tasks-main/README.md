<h2 align="center">
 lab-03: Liste
</h2>

<h4>Cerințe:</h4>

1. Creati o lista - direct in forma ordonata, datele (valori intregi) sunt citite din fisier, pentru deschiderea oricarui fisier se vor folosi macro-urile definite in utils.h. Afisati elementele in ordine inversa! **Elementul este citit din fisier si adaugat in lista imediat!**
2. Creati o functie pentru eliminarea elementelor care se repeta intr-o lista de intregi si afisati lista rezultata. Care e complexitatea solutiei pe care ati propus-o ? (exemplu:  lista initiala 1 2 3 1 1 4 3 2 5 1 devine dupa eliminari: 1 2 3 4 5 )
3. Jocul lui Joseph: mai multi copii sunt asezati in cerc (un copil are un numar(varsta) si un nume asociat). Primul copil alege un numar p si incepand cu el se numara pana la p, copilul p e eliminat.  Incapand cu p+1 se reia procedura, pana sunt eliminati toti copii. Afisati numele copiilor in ordinea in care sunt dati afara. Se implementeaza cu lista circulara.

#### Puteti afla mai multe legat de modul de lucru [aici](https://github.com/sda-ab/student-setup#indicatii-rezolvare-laborator)

### Observatii 
- **teste:**
  - Comanda **make test** va rula toate testele.
  - Comanda **make test-cX** (unde **X** e nr cerintei: **1,2,3**) va rula doar testele pentru cerinta **X**
- **implementare:**
  - elementele in toate listele vor fi adaugate la inceputul acesteia
