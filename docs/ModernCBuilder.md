# Nowoczesny C++ / C++Builder

1. Programowanie to praca zespołowa
	* Pracujemy razem
	* Uczymy się nowych rzeczy patrząc na kod innego programisty. 
	* Poznajemy dobre i sprawdzone praktyki. 
	* Ulepszamy kod i nie krytykujemy. 
	* Działający kod jest już dobry, ale może być lepszy (szczególnie w C++)
	* Repozytorium to podstawa
1. Czysty kod
	* Nazewnictwo i formatowanie kodu
	* Czysty kod a specyfika języka C++
	* Bezpieczny kod C++
	* Czysty kod w C++ - dokument `CppCleanCode.md` [zobacz](./CppCleanCode.md)
1. Kopiowanie jest ekstra, ale reużywanie kodu jest jeszcze lepsze
	* DRY
	* Reużywanie wymaga więcej wysiłku
	* Dostajemy sprawdzony i bezpieczny kod (bibliotekę kodu)
	* Kopiowanie zazwyczaj wymaga poprawienia i zmiany kodu
	* Rozwój skopiowanego kodu wymaga uciążliwej synchronizacji
	* Błędy regresji
1. Kod spaghetti
	* C++Builder i VCL promują pisanie kodu wymieszanego
	* Syndrom "OnClick Developer"
		* Przykład: w jednym zdarzeniu (metodzie) wykonujemy operacje dotyczące wielu w logicznych warstwy, np. składowanie danych, analiza spójności, algorytmy numeryczne, wizualizacja danych, logowanie procesu, komunikacja z urządzaniami, itp.
	* Kod powstaje szybko, ale jest trudny do utrzymania
	* Ogromny wysiłek programisty
	* Kodowanie staje się mało kreatywne
	* Separacja modułów danych i odcinanie zbędnych zależności
	* Architektura projektu
	* Architektura w C++ - dokument `CppArchitecture.md` [zobacz](./CppArchitecture.md)
1. Nowoczesny kod C++
	* Wykorzystanie biblioteki STD
	* Głębsze poznanie możliwości języka C++
	* C++ to nie jest Delphi zapisane w nowacji C++
	* Wykorzystanie nowych elementów języka
	
