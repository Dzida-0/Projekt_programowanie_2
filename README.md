Dokumentacja projektu:

● Arkusz wstępny
Mini gra polegająca na sprawdzaniu poprawności dokumentów osoby
przekraczającej granicę. Dane osobowe do dokumentu będą importowane z baz
danych, wyświetlają się w okienku. Zadaniem użytkownika jest porównać dane i
zdecydować czy są one prawidłowe. Przy odrzuceniu nie dostaje się żadnych
punktów, przy przepuszczeniu mogą wydarzyć się dwa scenariusze: jeśli osoba jest
słusznie przepuszczona –
dostaje punkty, jeśli niesłusznie – traci się jedno życie, których w sumie jest trzy.
Język: C++; Środowisko Visual Studio 2019; Biblioteki: SFML, SOCI i standardowe
biblioteki

● Arkusz zmian
Podczas realizacji projektu została zmieniona biblioteka przetwarzająca dane
na SQLite3, z powodu występowania dużej ilości błędów i jej
problematycznego działania.
● Lista wymagań

Wymagania projektu:

● Stworzenie bazy danych

● Stworzenie przycisków, które będą powodować zmienianie okien

● Badanie położenia elementów w konsoli

● Generowanie dokumentów z danych

● Sprawdzanie poprawności dokumentów i konsekwencje na podstawie

wyboru użytkownika

● Instrukcja użytkownika

1. Wybranie opcji z menu: Play, Instructions, Authors (trzeba wybrać play
jeśli celem jest gra)
2. Po wybraniu play, kliknięcie “Document”, by został wyświetlony
document, kliknięcie “How”, aby zostały wyświetlone wytyczne
3. Sprawdzenie zgodności dokumentu i zdecydowanie czy zostanie
zaakceptowany czy nie. Dzieje się to poprzez najechanie na ikonę
dokumentu zielonym lub czerwonym przyciskiem.
4. Jeśli użytkownik prawidłowo zidentyfikuje dokument to dostaje punkty,
jeśli nieprawidłowo - traci życie.

● Rozbudowa projektu
W przyszłości myśleliśmy nad rozbudowaniem projektu o następne poziomy
trudności (dodanie dokumentów, ilości znajdujących się na niej danych) i
wprowadzenie presji czasowej na podejmowanie decyzji oraz dodanie
efektów dźwiękowych w ramach Audio SFML.

● Podsumowanie
Udało nam się zrealizować, większość początkowych założeń. Głównymi
trudnościami okazało się utrzymanie stabilnego okna gry oraz
skonfigurowanie w prawidłowy sposób bazy danych.
Aby aplikacja działała i prawidłowo się otwierała należy skonfigurować
ustawienia kompilatora.
Aby prawidłowo to zrobić, można posłużyć się przykładową pomocą na
oficjalnej stronie, z której można pobrać SFML.
link do strony: https://www.sfml-dev.org/tutorials/2.6/start-vc.php
