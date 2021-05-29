# Grafy_projekt

## Część analityczna:
  - w folderze *Część analityczna* znajduje się pdf z rozwiązaniami pierwszej części projektu;
  - indeks chromatyczny został podany obok grafu pokolorowanego krawędziowo;
  - liczba chromatyczna została podana obok grafu pokolorowanego wierzchołkowo.
  
  
## Część programistyczna
  - w folderze *Część programistyczna* znajdują się:
      - plik main.cpp;
      - 3 pliki tekstowe z przykładowymi macierzami i listami incydencji;
      - plik pdf z analizą algorytmu Forda-Fulkersona.
      
  - aby uruchomić program należy **umieścić plik main.cpp oraz plik tekstowy zawierający macierz lub listę incydencji w tym samym folderze**. Przykładowe pliki tekstowe znajdują się w folderze *Część programistyczna*. Po uruchomieniu pliku main.cpp **konieczne jest podanie liczby wierzchołków badanego grafu**; 
  - algorytm bada przepływ **zaczynając od wierzchołka 0, a kończąc na ostatnim podanym** (czyli przy V = 6, gdzie V jest liczbą wierzchołków grafu, ostatnim wierzchołkiem będzie wierzchołek 5);
 ### Format plików:
  -**macierz sąsiedztwa**, np:
  ```
    0 5 3 0 0 0
    0 0 8 6 0 0
    0 4 0 0 1 0
    0 0 9 0 0 2
    0 0 0 7 0 4
    0 0 0 0 0 0 
  ```
  gdzie każdy nowy wiersz oznacza kolejny wierzchołek, a liczby różne od zera oznaczają przepustowości krawędzi łączącej dane dwa wierzchołki (np. w pierwszym wierszu krawędź łącząca wierzchołek 0 z wierzchołkiem 1 ma przepustowość równą 5).
  
  -**lista sąsiedztwa**, np:
  ```
  0 1 16
  0 2 13
  1 2 10
  1 3 12
  2 1 4
  2 4 14
  3 2 9
  3 5 20
  4 3 7
  4 5 4
  ```
  gdzie w każdym wierszu pierwsza liczba oznacza wierzchołek z którego wychodzi krawędź, druga liczba to numer wierzchołka w którym kończy się krawędź, a trzecia liczba oznacza przepustowość danej krawędzi (np. w pierwszym wierszu krawędź łącząca wierzchołek 0 z wierzchołkiem 1 ma przepustowość 16).
        
