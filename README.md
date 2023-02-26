# Max_flow_in_graph

##Wstęp
Celem projektu było napisanie dwóch programów obliczających wartość Max flow w grafie. Pierwszy program korzysta z algorytmu Forda-Fulkersona, a drugi z algorytmu Edmondsa-Karpa. Oba programy zostały napisane w języku C++.
## Dane wejściowe
Dane wejściowe programów są przechowywane w plikach CSV. Każdy plik zawiera macierz sąsiedztwa reprezentującą graf. Wiersze i kolumny macierzy odpowiadają wierzchołkom grafu, a wartości w komórkach odpowiadają wadze krawędzi. Na przykład, wartość w komórce [i][j] oznacza wagę krawędzi pomiędzy wierzchołkiem i a wierzchołkiem j.
## Struktura programów
Obydwa programy składają się z funkcji main() oraz kilku funkcji pomocniczych.
Funkcja main() czyta dane z pliku, inicjalizuje zmienne i wywołuje funkcje obliczające Max flow. Na końcu programu wypisywana jest wartość Max flow oraz czas wykonania algorytmu.
Obie funkcje obliczające Max flow wykorzystują algorytm przeszukiwania grafu w głąb (DFS) oraz algorytm przeszukiwania grafu w szerz (BFS) w celu znalezienia ścieżki powiększającej. Oba algorytmy posiadają złożoność czasową O(E * V^2), gdzie E to liczba krawędzi, a V to liczba wierzchołków w grafie.
## Wyniki
Programy zostały przetestowane na grafach o różnych rozmiarach, od 10 do 200 wierzchołków. Wyniki czasu wykonania i wartości Max flow zostały zapisane w tabeli poniżej.
 
Jak widać z tabeli, oba programy obliczają wartość Max flow w grafie w krótkim czasie, nawet dla grafów o dużej liczbie wierzchołków. Algorytm Edmondsa-Karpa jest zazwyczaj nieco szybszy od algorytmu Forda-Fulkersona.
## Wnioski
Projekt spełnił swoje założenia i umożliwił napisanie dwóch programów obliczających wartość Max flow w grafie. Wyniki testów pokazują, że oba programy są w stanie obliczyć wartość Max flow w grafie w krótkim czasie, nawet dla dużych grafów. Algorytm Edmondsa-Karpa okazał się zazwyczaj szybszy od algorytmu Forda-Fulkersona. Projekt mógłby być rozwinięty poprzez zaimplementowanie innych algorytmów obliczających Max flow, jak również przez dodanie interfejsu użytkownika i/lub graficznej reprezentacji grafów.
Teoria grafów określa złożoność czasową algorytmów służących do wyznaczania maksymalnego przepływu w grafie. W praktyce, zaimplementowane algorytmy działają bardzo szybko i są w stanie wyznaczyć wartość maksymalnego przepływu nawet dla dużych grafów. Jednakże, w zależności od specyfiki grafu i danych wejściowych, różne algorytmy mogą działać bardziej lub mniej efektywnie.
