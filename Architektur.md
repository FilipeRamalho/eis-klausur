# Architektur

Die Datei wird mithilfe von ifstream geladen.
Dann werden alle Zeichen in der Datei in Vektoren gespeichert.
Jede Zeile hat ein Vektor. Und alle Zeilen sind nochmals in einem Vektor.
Dann wird drübergegangen und entsprechend des Chars das entsprechende Objekt konstruiert im Heap.
Dann wird der Timer gestartet.

Pro Tick wird nun der paintEvent ausgelöst, indem entsprechend der Position der Objekte die
Bilder mithilfe von QPainter hineingemalt werden.

Die Pacdots überprüfen jedem Tick, ob ein Spieler auf ihnen ist.
Wenn Ja, dann löschen sie sich noch nicht, da dies Probleme bereiten könnte, sondern sagen dem Game,
das sie gelöscht werden sollen zum Ende des Ticks. 

Die Geister wählen einer der freien Richtungen aus und bewegt sich dort hin.
Wichtig hier anzumerken ist, dass sie nicht zufällig für alle 4 Richtungen eine Richtung entscheiden,
sondern damit es gleichförmig zufällig ist, zunächst bestimmt wird, welche Richtungen frei sind und dann erst wird von
dieser Anzahl eine Richtung bestimmt. Bei 2 freien Richtung wird also eine Zahl zwischen 0 und 1 bestimmt.

Die schlauen Geister versuchen zunächst in x-Richtung sich anzunähern und dann in y-Richtung.
Sie bewegen sich jeden zweiten tick, indem eine boolesche Variable jeden Tick geändert wird von true auf
false, nur wenn sie false ist bewegen sie sich.

Jedem Tick wird auch überprüft, ob das Spiel zu Ende ist.
Die Überprüfung findet sowohl durch die Geister und Spieler statt, als auch vor und nach dem alle 
Objekte ihre Aktion machen.

Das Spiel wird alternativ sofort beendet, wenn man "q" drückt, man wechselt dann direkt ins Menü.

Wenn das Spiel zu Ende ist, wird der ENDGAME Modus eingeschaltet, wo ein Menü angezeigt wird mit Score, Zeit und Nachricht.
Sollte man wieder zurück ins Menü, dann wird der MENU Modus eingeschaltet. Dort kann man die Levels
auswählen.

Man hätte Knöpfe und Mausinteraktion implementieren können, 
doch bei Pacman ist das Arcade-Feeling ein wichtiges Feature, also ist es wichtig alles über die
Tastatur steuern zu können. Ein Wechseln zwischen Modi ermöglicht es zum Beispiel das Spielendemenü
über den letzten Spielstand zu "rendern". Die vielen Klassen ermöglichen eine einfache Übersicht über
welche Objekte implementiert wurden und ermöglichen Wiederwertung von Code.