# Prüfung: „Einführung in die Softwareentwicklung“

## Instruktionen zum Bauen des Projektes
In Linux [Probiert mit Fedora 32 in WSL]

CMake sollte die Dateien, welche in copyme sind, bereits kopieren, sicherheitshalber habe Ich
sie dennoch in den copyme-Ordner reingemacht, damit sie manuell kopiert werden.
### First build
Vom obersten Projektordner aus
1. mkdir build
2. cmake -S . -B \build
3. cd build
4. make Klausur
5. ./Klausur

### Clean build (Falls notwendig)
Vom obersten Projektordner aus
1. rm -rf build
2. mkdir build
3. cmake -S . -B \build
4. cd build
5. make Klausur
6. ./Klausur

### Simple build 
Wenn an der CMake Datei nichts geändert wird ausführen

Vom obersten Projektordner aus
1. cd build
2. make Klausur
3. ./Klausur

### Simple run

Vom obersten Projektordner aus
1. cd build
2. ./Klausur

## Systemumgebung
### Entwicklungsumgebung
Ich habe mit einem HDPI-Bildschirm entwickelt und habe deshalb im Code
die HDPI-Option eingeschaltet. Ich habe auch probiert mit geringer Auflösung das
Programm auszuführen. Es sollte eigentlich keine Probleme geben, wenn doch die Zeile 8
in main.cpp kommentieren.

- Windows 10 20H2
  - CLion mit MSVC 2019 
  - CMake 3.17 
    - min. C++17
  - Qt 5.12.10

### Abgabetestumgebung 
Ich habe noch in WSL getestet es über den Terminal zu kompilieren für die Instruktionen.
- Fedora 12 in WSL (Fedora Remix)
  - gcc 10.2.1
  - CMake 3.17
    - min. C++17
  - QT 5.14.2
## Bedienungsanleitung

Zunächst trifft man auf ein Menü. 
Dort kann man einstellen, ob man im Classic-Modus spielen will mit "c" und dann kann mit 
"1","2" oder "3" das Spiel starten.

Im Spiel benutzt man die Pfeiltasten, um Pacman zu steuern. Mit "q" kann jederzeit das Spiel 
verlassen und man ist dann wieder im ursprünglichen Menü.

Wenn man verliert, kommt die Nachricht "Game over" und 
wenn man gewinnt, kommt die Nachricht "Victory!".

## Implementierte Features 
### Grundausbau 
  - Spielfeld laden und anzeigen
  - Steuerung von Pacman
  - Punkte sammeln und Spielende
  - Bewertung
### Ausbaustufe 1
  - Geister mit zufälliger Bewegung
  - Geister werden initialisiert
  - Kollision beendet Spiel
### Ausbaustufe 2
  - SmartGhost implementiert
  - SmartGhost wird getrennt von Ghost initialisiert
  - Menüsystem [3/5]
    - Level auswählen
    - Man kann das Spiel vorzeitig beenden mit "q"
    - Am Ende der Spielrunde neues Spiel starten
      - Man kann zurück ins Menü und dort ein neues Spiel auswählen
### Ausbaustufe 3
  - Es werden Bilder statt ASCII-Zeichen anzeigt
  - Die Ecken sind gerundet
### Extra-Features
- Invincibility pills
  - Sind gekennzeichnet mit "p". Zb.: level4.txt
  - Sie sehen wie Pacdots aus, sind aber rot.
  - Pacman ist grün, solang er unbesiegbar ist
  - Sie bringen 20 Punkte
  - Geister essen bringt 30 Punkte
    - Schlaue Geister sogar 40
  - Die maximale Punktzahl bleibt gleich
  - Kleines easter egg
      - Es wirkt sich aber auf [g]öttlicher Art aus!
### Eigene Ideen
  - Classic Mode
    - Man kann die Option im Menü auswählen
    - Pacman bewegt sich immer, die Pfeiltasten legen lediglich die Richtung fest  

## Quellen
[0] Abgabe Blatt 7 
  - Collision checks
  - Klassenstruktur
  - Position

[1] Qt Docs

[2] CPP reference

[3] https://stackoverflow.com/questions/18440727/how-to-pause-and-resume-a-qtimer-qt-5
  - Um die Zeit korrekt zu stoppen und nicht nach dem Spiel sie fortlaufen zu lassen.
    
[4] https://stackoverflow.com/questions/18959083/qpainter-drawimage-centeraligned
  - Um Pacman im Menü zu zentrieren

[5] ConsoleWindow API
  - wie Keypresses ermittlet wurden,
  - wie Ticks umgesetzt wurden
  - QTimer, ...
  - wie drawText() und FontMetrics benutzt werden

[6] https://qtcentre.org/threads/48211-How-to-change-QPixmap-color-from-black-to-red
  - Um PacPill und Pacman umzufärben
