<h1 align="center"> lab-04: Stive & Cozi </h1>



### Cerinta:

<p align="justify"> Cititi dintr-un fisier o serie de cuvinte (pana la intalnirea cuvantului „stop” sau pana la finalul fisierului). 
Adaugati cuvintele citite intr-o coada folosind functia <strong>en</strong> adaptata pentru a adauga informatie de tip sir de caractere (lungime variabila).
Procesati coada si inserati cuvintele citite initial in stiva <strong>results – <em>inversandu-le caracterele</em>.</strong></p?>

  + ***Ex: Se citeste:***
    ``` 
    Ana are mere stop
    ```
  + ***Stiva va contine(de la stanga la drepata):***
    ```
    anAeraerem
    ```

### Hint:

<p align="justify">
 Pentru a inversa literele unui cuvant folositi o structura de date de tip stiva (implementata cu lista). Adaptati stiva (functiile push si pop) astfel incat sa stocheze si manipuleze informatie de tip caracter. Pentru a inversa literele unui cuvant implementati functia <strong>processInput</strong> care primeste ca parametru coada de cuvinte si pune in pune in stiva de rezultate literele cuvantului inversat si proceseaza sirul astfel: incepand cu primul caracter, se adauga toate caracterele pana la ‘/0’ in stiva cu functia push. Apoi, cat timp stiva nu este goala, se extrag caractere din stiva cu pop si se adauga incepand cu prima pozitie in sirul de returnat.  
Extrageti elemente din coada – folosind functia deQueue adaptata pentru a returna informatie de tip sir de caractere.
*inversarea caracterelor dintr-un cuvant se poate face, fie cand e adaugat cuvantul in coada, fie cand este extras si afisat.
</p?>

#### Puteti afla mai multe legat de modul de lucru [aici](https://github.com/sda-ab/student-setup#indicatii-rezolvare-laborator)

### Observatii 

* **teste:**
  + Comanda **make test** va rula toate testele.
  + Comanda **make test-task** va testa implementarea functiilor de rezolvare a cerintei.
  + Comanda **make test-stack** va testa implementarea metodelor asociate cu stiva
  + Comanda **make test-queue** va testa implementarea  metodelor asociate cu coada
* **implementare:**
  + se va incepe cu implementarea ***metodelor asociate cu stive si cozi*** pentru a putea implementa ***cerinta propriu zisa***
  + structurile de date de tip **stiva** si **coada** au fost deja create se vor adapta functiile din curs pentru a se potrivi in cazul de fata in scheletul de laborator.(urmatiti TODO-urile din cod)
