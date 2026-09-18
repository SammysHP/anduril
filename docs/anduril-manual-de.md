# Anduril Benutzerhandbuch

Anduril ist eine Open-Source-Firmware für Taschenlampen, die unter den
Bedingungen der GPL v3 verbreitet wird. Die Quellcodes können hier abgerufen werden:

  - https://toykeeper.net/anduril

Die obige URL leitet auf die eigentliche Projektseite weiter. Selbst wenn das Projekt
erneut umgezogen werden muss, sollte sie weiterhin funktionieren. Seit Ende 2023
leitet sie hierher weiter:

  - https://github.com/ToyKeeper/anduril


## Schnellstart

Nachdem ein Akku in die Lampe eingelegt und die Teile zusammengeschraubt wurden,
sollte die Lampe einmal kurz blinken, um zu bestätigen, dass sie Strom hat und nun
betriebsbereit ist. Danach ist die grundlegende Bedienung einfach:

  - **Klick**: Lampe ein- oder ausschalten.
  - **Gedrückt halten**: Helligkeit ändern.
  - **Loslassen und erneut gedrückt halten**: Helligkeit schnell in die andere Richtung ändern.

Das ist alles, was du für die grundlegende Nutzung wissen musst, aber es stehen noch viele
weitere Modi und Funktionen für diejenigen zur Verfügung, die mehr möchten.

Eine vollständige Liste der Tastenbelegungen findest du weiter unten in der
[UI-Referenztabelle](#ui-reference-table) am Ende dieser Datei.

Wenn du eine spezifische Frage hast, wird diese möglicherweise in den [FAQ](#faq) behandelt.


## Tastendrücke

Tastendrücke werden mit einer einfachen Notation abgekürzt:

  - `1C`: **Ein Klick.** Drücke die Taste und lasse sie schnell wieder los.
  - `1H`: **Gedrückt halten.** Drücke die Taste, halte sie aber gedrückt.
  - `2C`: **Zwei Klicks.** Zweimal schnell drücken und loslassen.
  - `2H`: **Klick, gedrückt halten.** Zweimal klicken, aber den zweiten Druck gedrückt halten.
  - `3C`: **Drei Klicks.** Dreimal schnell drücken und loslassen.
  - `3H`: **Klick, Klick, gedrückt halten.** Dreimal klicken, aber den letzten Druck gedrückt halten.

Dasselbe Muster wird auch mit höheren Zahlen verwendet. Zum Beispiel bedeutet `10C`
zehn Klicks... und `10H` bedeutet zehn Klicks, aber den letzten Druck gedrückt halten.

Die *Zahl* gibt an, wie oft die Taste gedrückt werden muss. Der *Buchstabe* gibt an,
ob der letzte Druck losgelassen (C) oder gedrückt gehalten werden soll (H).


## Werksreset

Wenn du den Überblick verlierst oder den Temperatursensor automatisiert kalibrieren möchtest,
führe einen Werksreset durch. Es ist eine gute Idee, dies zu tun, sobald du eine neue Lampe
zum ersten Mal einschaltest, um eine vernünftige Konfiguration zu gewährleisten.

Der Ablauf hierfür ist:

  - Endkappe **lösen**
  - Taste **gedrückt halten**
  - Endkappe **festziehen**
  - Taste für ca. 4 Sekunden **weiter gedrückt halten**

Oder:

  - `13H` im "Aus"-Modus und für ca. 4 Sekunden weiter gedrückt halten

Die Lampe sollte flackern, während sie heller wird, und dann kurz auf voller Leistung
aufleuchten. Halte die Taste gedrückt, bis sie die volle Leistung erreicht, um einen Reset
durchzuführen, oder lasse die Taste frühzeitig los, um abzubrechen.

Bei einigen Lampen, bei denen die Endkappen-Methode unmöglich ist, verwende `13H` aus dem
Aus-Zustand für einen Werksreset. Wenn dies schwierig ist, versuche es wie ein Lied
zu zählen, um es einfacher zu machen:

```
  1 2 3 4
  2 2 3 4
  3 2 3 4
  HALTEN
```

Das Simple UI ist nach jedem Werksreset aktiviert.


## Simple UI

Standardmäßig verwendet die Lampe ein Simple UI. Dies ist nützlich, wenn du die Lampe
an jemand anderen verleihst oder dich einfach nicht mit verrückten Disco-Modi herumschlagen willst.

Das Simple UI verfügt über alle Grundfunktionen, die für die Nutzung als Taschenlampe benötigt werden,
jedoch sind die minimale und maximale Helligkeit standardmäßig begrenzt um die Nutzung sicherer zu machen
und alle komplexen oder fortgeschrittenen Funktionen sind blockiert.

### Nutzung

Zu den im Simple UI verfügbaren Funktionen gehören:

  - `1C`: Ein / Aus
  - `1H`: Hochrampen (oder herunter, falls die Taste vor weniger als einer Sekunde losgelassen wurde)
  - `2H`: Wenn die Lampe an ist: Herunterrampen  
          Wenn die Lampe aus ist: Momentaner High-Modus
  - `2C`: Doppelklick, um zur / von der höchsten sicheren Stufe zu wechseln
  - `4C`: [Einschaltsperren-Modus (Lockout)](#lockout-mode).

Einige andere Modi und Funktionen sind ebenfalls verfügbar.
Wenn die Lampe aus ist, gibt es folgende Optionen:

  - `3C`: [Akku-Prüfmodus](#battery-check) (zeigt die Spannung einmal an und schaltet sich dann aus)
  - `4C`: [Einschaltsperren-Modus (Lockout)](#lockout-mode)
  - `10H`: Wechsel zum [Advanced UI](#advanced-ui)
  - `15C` oder mehr: [Versionsprüfung](#version-check-mode)

Im Lockout-Modus des Simple UI gibt es einige Funktionen:

  - `1H`: Momentanes Moon
  - `2H`: Momentanes Low
  - `3C`: Entsperren und ausschalten
  - `4C`: Entsperren und einschalten
  - `4H`: Entsperren und auf niedriger Stufe einschalten
  - `5C`: Entsperren und auf hoher Stufe einschalten

Um zwischen Simple UI und Advanced UI zu wechseln, schalte die Lampe aus und führe dann
eine dieser Aktionen aus:

Im Simple UI:

  - `10H`: Gehe zum [Advanced UI](#advanced-ui).

Im Advanced UI:

  - `10C`: Gehe zum Simple UI.

### Erweitertes Simple UI

Bei einigen Lampen sind auf Wunsch des Herstellers zusätzliche Funktionen im Simple UI aktiviert. Dies umfasst typischerweise:

  - `Ramp -> 3C`: Stufenlose oder gestufte [Ramp-Form](#ramping--stepped-ramping-modes) umschalten.
  - `Ramp -> 5H`: [Sonnenuntergangs-Timer](#sunset-timer).
  - `Aus -> 7C/7H`: Das [Aux LED-Muster](#aux-leds--button-leds) ändern.
  - `Lockout -> 7C/7H`: Das [Aux LED-Muster](#aux-leds--button-leds) ändern.

Ältere Versionen (vor 2024-08) erlaubten auch den Zugriff auf Strobe-/Stimmungsmodi, was
gefährlich sein kann; falls du eine solche Version hast, *überlege es dir gut, bevor du Kinder damit spielen lässt*.
Diese Modi waren nie als kindersicher gedacht und können die volle Leistung ohne thermische Regelung erreichen.

### Konfiguration des Simple UI

Das Simple UI kann auf verschiedene Arten konfiguriert werden, jedoch nicht, während das Simple UI
aktiv ist. Gehe also ins Advanced UI, konfiguriere die Einstellungen und kehre dann zum Simple UI zurück.

Im "Aus"-Modus des [Advanced UI](#advanced-ui):

  - `10H`: Simple UI konfigurieren.

Zu den konfigurierbaren Optionen gehören:

  - Floor-Stufe (Minimum)
  - Ceiling-Stufe (Maximum)
  - Anzahl der Stufen (beim gestuften Rampen)
  - Turbo-Stil

Andere Optionen werden vom Advanced UI geerbt; ändere diese Optionen ganz normal,
und sie werden für das Simple UI übernommen:

  - Ramp-Stil (stufenlos / gestuft)
  - Geschwindigkeit des stufenlosen Rampens
  - Rampen-nach-Moon-Stil
  - Weiche Stufen (Smooth Steps)
  - Speicher-Einstellungen (Memory)
  - Automatische Sperr-Einstellungen (Auto-Lock)
  - Aux LEDs-Einstellungen
  - Kalibrierung der Spannung
  - Spannungsanzeige nach dem Ausschalten
  - Niedrige und hohe Ramp-Stufen für Aux LEDs
  - Einstellungen der thermischen Regelung
  - Hardwarespezifische "Misc Menu"-Einstellungen
  - Kanalmodi
  - Kanalmodus für das Zahlenblinken

## Advanced UI

Der größte Teil der folgenden Informationen bezieht sich auf das Advanced UI. Alles, was
oben noch nicht erwähnt wurde, ist im Simple UI gesperrt.

Um zu überprüfen, in welchem UI du dich befindest (Simple UI oder Advanced UI), rufe den Akku-Prüfmodus
mit `3C` aus dem Aus-Zustand auf. Im Simple UI wird die Akkuspannung nur einmal angezeigt,
im Advanced UI wird die Akkuspannung jedoch wiederholt geprüft und angezeigt.

Um vom Advanced UI zum Simple UI zurückzukehren, gib `10C` ein, während die Lampe aus ist.


## Stufenlose / Gestufte Ramping-Modi

Der Ramping-Modus von Anduril verwendet ein stufenloses oder gestuftes Rampen, je nachdem,
welcher Stil bevorzugt wird.

Jedes Rampen hat seine eigenen Einstellungen – Floor (niedrigste Stufe), Ceiling (höchste
Stufe), und das gestufte Rampen kann auch eine konfigurierbare Anzahl von Stufen haben.

Zusätzlich hat das Simple UI eigene Ramp-Einstellungen für Floor, Ceiling und die
Anzahl der Stufen. Der stufenlose/gestufte Stil wird vom Rampen des Advanced UI geerbt.

Es gibt vier Möglichkeiten, den Ramping-Modus aufzurufen, wenn die Lampe aus ist:

  - `1C`: Einschalten mit der gespeicherten Helligkeit.
          (siehe unten für Details dazu, was "gespeichert" bedeutet)

  - `1H`: Einschalten auf Floor-Stufe. Nach dem Einschalten der Lampe loslassen, um
          auf der Floor-Stufe zu bleiben, oder gedrückt halten, um hochzurampen.

  - `2C`: Einschalten auf Ceiling-Stufe.

  - `2H`: Einschalten mit voller Leistung, beim Loslassen ausschalten. (Momentary Turbo)  
          (im Simple UI wird hierbei die Ceiling-Stufe anstelle von Turbo verwendet)

Während die Lampe eingeschaltet ist, stehen einige Aktionen zur Verfügung:

  - `1C`: Ausschalten.
  - `2C`: Zur Turbo-Stufe wechseln oder davon zurückkehren.  
          (oder falls runtergeregelt wurde, wieder auf Turbo "hochschieben")  
          (Turbo-Stufe / Verhalten ist konfigurierbar)
  - `1H`: Helligkeit ändern (nach oben).  
          Wenn die Taste vor weniger als einer Sekunde losgelassen wurde  
          oder wenn sie sich bereits auf der Ceiling-Stufe befindet, geht es stattdessen nach unten.
  - `2H`: Helligkeit ändern (nach unten).

  - `3C`: Zum anderen [Ramp-Stil](#ramping--stepped-ramping-modes) wechseln.
          (stufenlos / gestuft)  
          (oder den nächsten [Kanalmodus](#channel-modes) aktivieren,
          wenn mehr als einer aktiviert ist)  
          (in diesem Fall stattdessen `6C` zum Umschalten zwischen stufenlos / gestuft verwenden)
  - `6C`: Zum anderen Ramp-Stil wechseln. (wenn `3C` dem nächsten Kanal zugewiesen ist)

  - `3H`: Momentary Turbo (wenn der aktuelle Kanal kein Tint-Ramping hat).
  - `3H`: [Tint Ramping](#channel-modes)
          (nur wenn der aktuelle Kanal einen einstellbaren Tint hat).

  - `4H`: Momentary Turbo, wenn `3H` dem Tint zugewiesen ist.

  - `4C`: In den [Lockout-Modus](#lockout-mode) wechseln.

  - `5C`: In den [Momentary Mode](#momentary-mode) wechseln.
  - `5H`: Einen [Sonnenuntergangs-Timer](#sunset-timer) starten.

  - `7H`: [Ramp-Konfigurationsmenü](#ramp-config-menu).
    - Eintrag 1: Floor-Stufe.
    - Eintrag 2: Ceiling-Stufe.
    - Eintrag 3:  
      Gestuftes Rampen: Anzahl der Stufen. Kann 1 bis 150 sein.  
      Stufenloses Rampen: Ramp-Geschwindigkeit.  
        1 = Volle Geschwindigkeit, ~2,5 s von Ende zu Ende.  
        2 = Halbe Geschwindigkeit, ~5 s von Ende zu Ende.  
        3 = Drittel Geschwindigkeit, ~7,5 s.  
        4 = Viertel Geschwindigkeit, ~10 s.

  - `10C`: Manuellen Speicher aktivieren und die aktuelle Helligkeit speichern.
           Speichert bei mehrkanaligen Lampen auch den aktuellen Kanalmodus.
  - `10H`: Konfigurationsmenü für Ramp-Extras.
    - Eintrag 1: Manuellen Speicher deaktivieren und zum automatischen Speicher zurückkehren.  
                 (egal, welchen Wert du bei der Aufforderung eingibst)
    - Eintrag 2: Den Timer für den manuellen Speicher konfigurieren.  
                 Setzt den Timer auf N Minuten, wobei N die Anzahl der  
                 Klicks ist. Ein Wert von 0 (keine Klicks) schaltet den Timer aus.
    - Eintrag 3: Konfigurieren, ob nach `Aus -> 1H` hochgerampt werden soll.  
                 0: Nach Moon hochrampen.  
                 1: Nicht hochrampen, einfach auf Floor-Stufe bleiben.
    - Eintrag 4: Turbo-Stil des Advanced UI konfigurieren:  
                 0: Kein Turbo, nur Ceiling.  
                 1: Anduril 1-Stil. `Ramp -> 2C` geht auf volle Leistung.  
                 2: Anduril 2-Stil. `Ramp -> 2C` geht auf Ceiling,
                 oder auf volle Leistung, wenn zuvor auf Ceiling hochgerampt wurde.
                 Dieser Wert betrifft auch den Momentary Turbo in den Ramp- und Aus-Modi.
    - Eintrag 5: "Smooth Steps" (weiche Stufen) konfigurieren.  
                 0: Smooth Steps deaktivieren.  
                 1: Smooth Steps aktivieren.

Der Speicher (Memory) bestimmt, auf welche Helligkeitsstufe die Lampe mit 1 Klick
aus dem Aus-Zustand wechselt. Es stehen drei Arten von Helligkeitsspeichern zur Auswahl:

  - Automatisch: Verwendet immer die zuletzt gerampte Helligkeit.
    (speichert keine Stufen, die über ein Kürzel aufgerufen wurden,
    wie Turbo, `2C` für Ceiling oder `1H-aus-dem-Aus-Zustand` für Floor)

  - Manuell: Verwendet immer die vom Benutzer gespeicherte Helligkeit.

  - Hybrid: Verwendet die automatische Speicherhelligkeit, wenn die Lampe nur
    für kurze Zeit aus war, oder setzt auf die manuelle Speicherstufe zurück, wenn sie
    für längere Zeit aus war.
    Der Timer hierfür ist von 0 bis ~140 Minuten konfigurierbar.

Eine andere Betrachtungsweise ist: Es gibt drei Stile des Speichers für die
zuletzt gerampte Helligkeitsstufe...

  - Immer merken          (automatisch)
  - Für N Minuten merken  (hybrid)
  - Nie merken            (manuell)

Um einen Speicherstil zu wählen, stelle die Konfiguration entsprechend ein:

| Speichertyp | manueller Speich. | manueller Speich.-Timer |
| ----------- | ----------------- | ----------------------- |
| automatisch | aus               | beliebig                |
| manuell     | ein               | null                    |
| hybrid      | ein               | ungleich null           |

Wenn "Smooth Steps" aktiviert ist, verwendet das gestufte Rampen eine weiche Animation
zwischen den Stufen, und beim Ein-/Ausschalten der Lampe werden die Übergänge
ebenfalls geglättet. Wenn "Smooth Steps" ausgeschaltet ist, erfolgen diese
Helligkeitsänderungen sofort.


## Sonnenuntergangs-Timer (Sunset Timer)

Im Ramp-Modus oder Kerzen-Modus ist es möglich, die Lampe so einzustellen, dass sie
sich nach einer Weile selbst ausschaltet.

Um den Timer zu aktivieren, gehe zur gewünschten Helligkeit und nutze dann die Aktion
`5H`. Halte die Taste gedrückt; die Lampe sollte einmal pro Sekunde blinken.
Jedes Blinken fügt dem Timer 5 Minuten hinzu.

Im Ramp-Modus dimmt sie langsam herunter, bis sie auf der niedrigsten Stufe ist, und schaltet
sich dann aus. Im Kerzen-Modus bleibt sie bis zur letzten Minute bei der gleichen Helligkeit,
woraufhin sie dimmt und erlischt.

Die Helligkeit kann geändert werden, während der Timer aktiv ist. Wenn dies
in den letzten Minuten geschieht, hebt es den Timer wieder auf ein Minimum von 3 Minuten an.
Wenn sie also sehr dunkel wird und du etwas mehr Zeit benötigst, kannst du ein `5H` ausführen,
um 5 Minuten hinzuzufügen, oder einfach auf die gewünschte Helligkeit hochrampen.


## Andere Modi

Anduril verfügt auch über mehrere andere Modi. Um auf diese zuzugreifen, drücke die Taste
mehr als 2 Mal, wenn die Lampe aus ist:

  - `3C`: [Blink- / Hilfsmodi](#blinky--utility-modes), beginnend mit der Akku-Prüfung.
  - `3H`: [Strobe-Modi](#strobe--mood-modes), beginnend mit dem zuletzt verwendeten Strobe.
  - `4C`: [Lockout-Modus](#lockout-mode).
  - `5C`: [Momentary Mode](#momentary-mode).
  - `6C`: [Tactical Mode](#tactical-mode).
  - `7C` / `7H`: [Aux LED-Konfiguration](#aux-leds--button-leds).
  - `9H`: [Misc Config-Menü](#misc-config-menu) (nur bei einigen Lampen).
  - `10H`: [Simple UI](#simple-ui)-Konfigurationsmenü.
  - `13H`: [Werksreset](#factory-reset) (bei einigen Lampen).
  - `15C` oder mehr: [Versionsprüfung](#version-check-mode).


## Lockout-Modus (Einschaltsperre)

Klicke 4 Mal aus dem Aus-Zustand, um in den Lockout-Modus zu gelangen. Oder 4 Mal aus dem Ramp-Modus.
Dadurch kann die Lampe sicher in einer Tasche, einem Rucksack oder an jedem anderen Ort getragen werden,
an dem die Taste versehentlich gedrückt werden könnte.

Um den Lockout-Modus zu verlassen, klicke 4 Mal. Die Lampe sollte kurz blinken und
dann mit der gespeicherten Stufe einschalten. Oder halte den letzten Druck gedrückt, um stattdessen
auf der Floor-Stufe einzuschalten:

  - `3C`: Entsperren und in den "Aus"-Modus wechseln

  - `4C`: In den Ramp-Modus wechseln (gespeicherte Stufe).  
          (verwendet die manuelle Speicherstufe, falls vorhanden)

  - `4H`: In den Ramp-Modus wechseln (Floor-Stufe).

  - `5C`: In den Ramp-Modus wechseln (Ceiling-Stufe).

Der Lockout-Modus dient auch als momentaner Moon-Modus, sodass schnelle
Aufgaben erledigt werden können, ohne die Lampe entsperren zu müssen. Die Helligkeit im
Lockout-Modus hat zwei Stufen:

  - `1H`: Auf der niedrigsten Floor-Stufe leuchten.

  - `2H`: Auf der höchsten Floor-Stufe leuchten.
          (oder der manuellen Speicherstufe, falls vorhanden)

  - `3H`: Nächster Kanalmodus (falls mehr als einer aktiviert ist).

<a id="autolock-config"></a>
Es ist auch möglich, die Lampe nach dem Ausschalten automatisch sperren zu lassen.
Um dies zu aktivieren, gehe in den Lockout-Modus und nutze die Aktion `10H`, um das
Auto-Lock-Konfigurationsmenü aufzurufen. Lasse die Taste nach dem ersten Blinken los.
Klicke dann bei der Aufforderung N-mal, um das Auto-Lock-Timeout auf N Minuten einzustellen.

  - `10H`: Auto-Lock-Konfigurationsmenü. Klicke N-mal, um das Timeout auf N Minuten einzustellen.
           Ein Wert von Null deaktiviert die Auto-Lock-Funktion.
           Um Auto-Lock auszuschalten, klicke also gar nicht.

Bei Lampen, die über Aux LEDs verfügen, gibt es möglicherweise zusätzliche Funktionen:

  - `7C` / `7H`: Das [Aux LEDs-Muster](#aux-leds--button-leds) des Lockout-Modus ändern.


## Blink- / Hilfsmodi

Klicke 3 Mal aus dem Aus-Zustand, um auf die Blink- / Hilfsmodi von Anduril zuzugreifen. Dies
startet immer bei der Akku-Prüfung, und es kann zu anderen Blink-Modi weitergegangen
werden, wenn das Advanced UI aktiviert ist. Die Reihenfolge ist:

  - [Akku-Prüfung](#battery-check).
  - [Temperatur-Prüfung](#temperature-check) (falls die Lampe einen Temperatursensor hat).
  - [Baken-Modus (Beacon)](#beacon-mode).
  - [SOS-Modus](#sos-mode) (falls aktiviert).

In all diesen Modi stehen einige grundlegende Aktionen zur Verfügung:

  - Klick: Ausschalten.
  - 2 Klicks: Nächster Blink-Modus.

Zusätzlich in den Modi Akku-Prüfung und Temperatur-Prüfung:

  - `7H`: Zum Spannungs- oder Thermokonfigurationsmenü wechseln.

Im Detail macht jeder Blink- / Hilfsmodus Folgendes:

### Akku-Prüfung:

Blinkt die Akkuspannung pro Zelle aus. Voll ist 4,20 V, leer ist
etwa 3,00 V. Die Lampe blinkt zuerst die Ganzzahl-Ziffer, macht eine Pause,
blinkt dann die "Zehntel"-Ziffer, macht eine Pause und blinkt dann die "Hundertstel"-Ziffer
in 0,01-V-Schritten. Für 4,16 V wären das also "4 Blinker, 1 Blinker,
6 Blinker". Wenn sie sich im Advanced UI befindet, macht sie eine etwas längere Pause
und wiederholt dies. Im Simple UI schaltet sie sich nach einem Durchlauf aus.

Eine "Null"-Ziffer wird durch ein sehr kurzes Blinken dargestellt.

Das Format der Akku-Prüfung hat sich mehrmals geändert:

  - Für Anduril 2 ab 2026-09 oder neuer beträgt die Auflösung der Akkuspannung
    0,01-V-Schritte.

  - Für Anduril 2 ab 2024-04 oder neuer beträgt die Auflösung der Akkuspannung
    0,02-V-Schritte (die letzte Ziffer kann 0, 2, 4, 6 oder 8 sein).

  - Für Anduril 2 ab 2023-12 oder neuer beträgt die Auflösung der Akkuspannung
    0,025-V-Schritte (die letzte Ziffer kann 0, 2, 5 oder 7 sein).

  - Für Anduril 2 ab 2023-12 oder älter beträgt die Auflösung der Akkuspannung
    0,1 V; die Lampe blinkt also zuerst die Ganzzahl-Ziffer, macht eine Pause und blinkt
    dann die "Zehntel"-Ziffer aus. Dann eine längere Pause, und es wiederholt sich.

  - Auf alten ATtiny85-Lampen mit nur 8 KiB ROM beträgt die Auflösung der Akkuspannung
    auch bei neueren Anduril-Versionen 0,1 V.

Einige Lampen verfügen auch über einen "Batt Color"-Modus. Drücke `1H` im Akku-Prüfmodus,
um diesen umzuschalten. Anstatt zu blinken, zeigt er den Akkuladezustand durch Farben an. Er
aktualisiert die Farbe rasch für Echtzeit-Informationen.

Einige Lampen verfügen über einen "Powerbank Host"-Modus. Drücke `2H` im Akku-Prüfmodus,
um zwischen Powerbank-Host oder -Guest umzuschalten. Dies steuert, ob die Taschenlampe
geladen wird, wenn ein USB C-zu-C-Kabel zu einem anderen Gerät verwendet wird, oder ob das
andere Gerät geladen wird.

Bei Lampen mit mehr als einem LED-Set kann durch Drücken von `3C` während des Akku-Prüfmodus
ausgewählt werden, welches LED-Set (welcher Kanalmodus) zum Ausblinken der Zahlen
verwendet wird.

Das Spannungs-Konfigurationsmenü bietet folgende Einstellungen:

  1. Spannungskorrekturfaktor. Dies passt den Akkumesssensor
     an, sodass der Benutzer bis zu 0,20 V in 0,01-V-Schritten hinzufügen
     oder abziehen kann. Klicke N-mal, um einen Wert einzugeben:

     ...  
     `17`: -0,03 V  
     `18`: -0,02 V  
     `19`: -0,01 V  
     `20`: +0,00 V (Standard)  
     `21`: +0,01 V  
     `22`: +0,02 V  
     `23`: +0,03 V  
     ...

     Es wird empfohlen, `1H` zu verwenden, um 10 hinzuzufügen, und dann `1C` für 1.
     Wenn du beispielsweise +0,03 V haben möchtest, führe zweimal `1H` und dann dreimal `1C` aus.


  2. Anzeige-Timeout für die Spannung nach dem Ausschalten. (nur bei Lampen mit RGB-Aux)
     Diese Einstellung bestimmt, wie viele Sekunden die RGB-Aux-LEDs
     die Spannungsfarbe anzeigen, nachdem die Lampe in den Ruhemodus wechselt. Klicke
     einmal pro gewünschter Sekunde oder null Mal, um diese Funktion auszuschalten.
     Der Standardwert beträgt 4 Sekunden.


  3. Aux Low Ramp Level. Steuert das Verhalten der Aux-Tasten-LEDs, während die Haupt-LEDs
     eingeschaltet sind. Unterhalb dieser Ramp-Stufe leuchten die Tasten-LEDs nicht,
     während die Haupt-LEDs an sind. Auf oder über dieser Stufe leuchten die Tasten-LEDs mit
     "niedriger" Helligkeit. Eine Einstellung auf 0 hält die Tasten-LEDs komplett aus,
     während die Haupt-LEDs an sind.  
     Steuert auch die Helligkeit der Spannungsanzeige nach dem Ausschalten.

  4. Aux High Ramp Level. Auf oder über dieser Ramp-Stufe leuchten die Tasten-LEDs mit
     "hoher" Helligkeit. Eine Einstellung auf 0 deaktiviert den hohen Aux-Modus der Taste,
     während die Haupt-LEDs an sind.  
     Steuert auch die Helligkeit der Spannungsanzeige nach dem Ausschalten.

  5. Aux während "An". Bestimmt, welche Aux LEDs leuchten, während die Haupt-LEDs
     eingeschaltet sind, wie etwa im Ramping-Modus:  
     0 = keine, 1 = nur einfarbige Aux, 2 = nur RGB-Aux, 3 = beide.

### Temperatur-Prüfung:

Blinkt die aktuelle Temperatur in Grad C aus. Diese Zahl sollte
ziemlich nah an dem liegen, was ein echtes Thermometer anzeigt. Wenn nicht,
wäre es eine gute Idee, das Thermokonfigurationsmenü aufzurufen und den Sensor
zu kalibrieren. Oder lasse die Lampe auf Raumtemperatur abkühlen und nutze
den Werksreset, um den Sensor automatisch zu kalibrieren.

Das Thermokonfigurationsmenü hat zwei Einstellungen:

  - Aktuelle Temperatur. Klicke einmal pro Grad C, um den Sensor zu kalibrieren.
    Wenn die Umgebungstemperatur beispielsweise 21 °C beträgt, klicke 21-mal.

  - Temperaturlimit. Dies legt die maximale Temperatur fest, die die Lampe
    erreichen kann, bevor sie mit der thermischen Regelung beginnt, um ein Überhitzen zu verhindern.
    Klicke einmal pro Grad C über 30. Um das Limit beispielsweise auf 50 °C einzustellen,
    klicke 20-mal. Der Standardwert ist 45 °C, und der höchste zulässige Wert ist 70 °C.

### Baken-Modus (Beacon):

Blinkt mit langsamer Geschwindigkeit. Die Lampe bleibt für 100 ms eingeschaltet und
bleibt dann bis zum nächsten Blinken ausgeschaltet. Die Helligkeit und die Anzahl der
Sekunden zwischen den Impulsen sind konfigurierbar:

  - Die Helligkeit entspricht der gespeicherten Ramp-Stufe, stelle diese also vor dem
    Aktivieren des Baken-Modus im Ramping-Modus ein. Folgt denselben
    Speicherregeln wie das Rampen – automatisch, manuell oder hybrid.

  - Die Geschwindigkeit wird durch Gedrückthalten der Taste konfiguriert. Die Lampe sollte
    während des Gedrückthaltens einmal pro Sekunde blinken. Lasse sie
    nach Verstreichen der gewünschten Zeitspanne los, um eine neue Baken-Geschwindigkeit
    einzustellen.  
    Um beispielsweise eine 10-Sekunden-Alpinbake einzustellen, halte die Taste 10 Sekunden lang gedrückt.

Wenn "Smooth Steps" aktiviert ist, rampt die Bake schnell hoch und blendet dann
allmählich aus. Dies simuliert das Verhalten einer analogen Glühbirne,
die Zeit zum Aufheizen und Abkühlen benötigt.

### SOS-Modus:

Blinkt ein Notsignal aus. Drei kurz, drei lang, drei kurz.
Wiederholt sich, bis die Lampe ausgeschaltet wird oder der Akku fast leer ist.

Die gespeicherte Ramp-Stufe bestimmt die Helligkeit des SOS-Modus.


## Strobe- / Stimmungsmodi

Anduril enthält einige zusätzliche Modi für verschiedene Zwecke:

  - Kerzen-Modus (Candle)
  - Fahrrad-Blinker (Bike flasher)
  - Party-Strobe
  - Tactical Strobe
  - Gewitter-Modus (Lightning storm)

Klicke 3 Mal aus dem Aus-Zustand, um auf diese zuzugreifen, aber halte den dritten Klick einen
Moment lang gedrückt. Klick, Klick, gedrückt halten. Der zuletzt verwendete Strobe-Modus wird gespeichert,
sodass die Lampe zu dem Modus zurückkehrt, den du zuletzt verwendet hast.

In all diesen Modi stehen einige Aktionen zur Verfügung:

  - `1C`: Ausschalten.
  - `2C`: Nächster Strobe- / Stimmungsmodus.
  - `1H`: Helligkeit erhöhen oder schneller blinken. (außer Gewitter)
  - `2H`: Helligkeit verringern oder langsamer blinken. (außer Gewitter)
  - `4C`: Vorheriger Strobe- / Stimmungsmodus.
  - `5C`: In den [Momentary Mode](#momentary-mode) für einen momentanen Strobe wechseln.
          (dies ist nützlich für Lichtmalerei / Light Painting)

Zusätzlich bietet der Kerzen-Modus eine weitere Aktion:

  - `5H`: Den [Sonnenuntergangs-Timer](#sunset-timer) aktivieren und/oder 5 Minuten zum Timer hinzufügen.

Im Detail macht jeder Modus Folgendes:

  - Kerzen-Modus

    Die Helligkeit ändert sich zufällig nach einem Muster, das einer Kerzenflamme ähnelt.
    Wenn ein Timer eingestellt ist, läuft dieser ab, danach wird das Licht eine
    Minute lang dunkler, flackert schließlich und schaltet sich aus. Ohne
    Timer läuft der Kerzen-Modus, bis der Benutzer ihn ausschaltet. Die Helligkeit ist
    konfigurierbar.

  - Fahrrad-Blinker

    Läuft auf mittlerer Stufe, zuckt aber einmal pro Sekunde auf eine hellere Stufe auf.
    Entworfen, um auffälliger als ein normaler Ramping-Modus zu sein, funktioniert
    ansonsten aber weitgehend genauso. Die Helligkeit ist konfigurierbar.

  - Party-Strobe

    Bewegung einfrierendes Stroboskoplicht. Kann verwendet werden, um rotierende Ventilatoren
    und fallendes Wasser optisch einzufrieren. Die Geschwindigkeit ist konfigurierbar.

  - Tactical Strobe

    Desorientierendes Stroboskoplicht. Kann verwendet werden, um Personen zu irritieren.
    Die Geschwindigkeit ist konfigurierbar, und das Tastverhältnis beträgt immer 33 %.

    Achte in diesem Modus auf Wärmeentwicklung, wenn du ihn für längere Zeit verwendest.

  - Polizei-Strobe (bei einigen Lampen)

    2-farbiger Strobe im Polizeistil. Funktioniert nur bei Lampen mit 2 oder mehr
    Farben.

  - Gewitter-Modus

    Blitzt mit zufälliger Helligkeit und zufälliger Geschwindigkeit, um Blitzeinschläge
    während eines starken Gewitters zu simulieren. Schaue nicht direkt in die
    Taschenlampe, wenn dieser Modus läuft, da sie plötzlich ohne Vorwarnung auf
    volle Leistung schalten kann.


## Momentary Mode

Klicke 5 Mal aus dem Aus-Zustand, um in den Momentary Mode zu gelangen. Oder 5 Mal aus dem Ramp-Modus,
oder 5 Mal aus einem Strobe-Modus.

Dies sperrt die Taschenlampe in eine Einzelmodus-Bedienoberfläche, bei der die LEDs
nur leuchten, während die Taste gedrückt gehalten wird. Dies ist für Morescodes,
Lichtmalerei (Light Painting) und andere Aufgaben gedacht, bei denen das Licht nur für kurze Zeit
und wahrscheinlich in einem bestimmten Muster leuchten soll.

Der Momentary Mode erzeugt entweder eine gleichbleibende Helligkeitsstufe oder ein Strobe,
je nachdem, was vor dem Wechsel in den Momentary Mode aktiv war. Um auszuwählen,
welches Verhalten verwendet werden soll, gehe in den gewünschten Modus, passe Helligkeit, Geschwindigkeit
und andere Einstellungen an und klicke dann 5 Mal, um den Momentary Mode aufzurufen.

Im Dauerlicht-Modus entspricht die Helligkeit der gespeicherten Ramp-Stufe; passe diese also im
Ramp-Modus an, bevor du den Momentary Mode aufrufst.

Im momentanen Strobe-Modus werden die Einstellungen aus dem zuletzt verwendeten
Strobe-Modus übernommen, z. B. Party-Strobe, Tactical Strobe oder Gewitter.

**Um den Momentary Mode zu verlassen, trenne die Stromversorgung physisch**, indem du die
Endkappe oder das Akkurohr abschraubst.


## Tactical Mode

Klicke 6 Mal aus dem Aus-Zustand, um den Tactical Mode aufzurufen, oder 6 Mal im
Tactical Mode, um ihn zu verlassen und zum "Aus"-Zustand zurückzukehren.

Der Tactical Mode bietet sofortigen, momentanen Zugriff auf High, Low und
Strobe, wobei jeder dieser Plätze konfigurierbar ist. Die Eingaben sind:

  - `1H`: High
  - `2H`: Low
  - `3H`: Strobe

Jeder dieser Modi leuchtet nur so lange, wie du die Taste gedrückt hältst.

Weitere Befehle im Tactical Mode sind:

  - `6C`: Beenden (zurück zum Aus-Modus)
  - `7H`: Konfigurationsmenü für den Tactical Mode
    - 1. Blinken: Taktischen Platz 1 konfigurieren
    - 2. Blinken: Taktischen Platz 2 konfigurieren
    - 3. Blinken: Taktischen Platz 3 konfigurieren

Um den Inhalt eines taktischen Platzes zu ändern, drücke `7H` und lasse die Taste
nach dem 1., 2. oder 3. Blinken los. Gib dann eine Zahl ein. Jeder Klick addiert
1, und jedes Halten addiert 10. Die Zahl kann sein:

  - 1 bis 150: Helligkeitsstufe einstellen
  - 0: zuletzt verwendeter Strobe-Modus
  - 151+: direkt zu einem bestimmten Strobe-Modus wechseln  
    151 = Party-Strobe  
    152 = Tactical Strobe  
    153+ = andere Strobes, in derselben Reihenfolge wie in der Strobe-Gruppe bei `Aus -> 3H`

Dies setzt voraus, dass die Lampe ein Ramp von 150 Stufen Länge hat. Strobe-Modi beginnen
bei der Ramp-Größe plus 1, daher kann es abweichen, wenn eine Lampe eine
andere Ramp-Größe hat.

Im Tactical Mode werden die Aux LEDs-Einstellungen aus dem Lockout-Modus geerbt.


## Konfigurationsmenüs

Jedes Konfigurationsmenü hat dieselbe Bedienoberfläche. Es verfügt über eine oder mehrere Optionen,
die der Benutzer konfigurieren kann, und geht diese der Reihe nach durch. Für jeden
Menüpunkt folgt die Lampe demselben Muster:

  - Einmal blinken, dann auf eine niedrigere Helligkeit schalten. Du kannst die Taste
    weiter gedrückt halten, um diesen Menüpunkt zu überspringen, oder die Taste loslassen, um
    einzusteigen und einen neuen Wert einzugeben.

  - Wenn du die Taste losgelassen hast:

    - Für einige Sekunden schnell zwischen zwei Helligkeitsstufen flackern oder "summen".
      Dies zeigt an, dass ein- oder mehrmals geklickt werden kann, um eine Zahl einzugeben.
      Sie summt weiter, bis nicht mehr geklickt wird, sodass keine Eile geboten ist.

      Die Aktionen hierbei sind:
        - Klick: 1 hinzufügen
        - Gedrückt halten: 10 hinzufügen (nur in Versionen ab 2021-09)
        - Warten: Beenden

Nach Eingabe einer Zahl oder nach dem Überspringen jedes Menüpunkts wartet sie,
bis die Taste losgelassen wird, und verlässt dann das Menü. Sie sollte in den Modus
zurückkehren, in dem sich die Lampe vor dem Aufrufen des Konfigurationsmenüs befand.


## Ramp-Konfigurationsmenü

Während die Lampe in einem Ramping-Modus eingeschaltet ist, klicke 7 Mal (halte jedoch den
letzten Klick gedrückt), um auf das Konfigurationsmenü für das aktuelle Rampen zuzugreifen.

Oder stelle für den Zugriff auf die Ramp-Konfiguration des Simple UI sicher, dass das Simple UI
nicht aktiv ist, und führe dann aus dem Aus-Zustand eine `10H`-Aktion aus.

Für den stufenlosen Ramping-Modus gibt es drei Menüoptionen:

  1. Floor.  
     (Standard = 1/150)
  2. Ceiling.  
     (Standard = 120/150)
  3. Ramp-Geschwindigkeit.  
     (Standard = 1, schnellste Geschwindigkeit)

Für den gestuften Ramping-Modus gibt es drei Menüoptionen:

  1. Floor.  
     (Standard = 20/150)
  2. Ceiling.  
     (Standard = 120/150)
  3. Anzahl der Stufen.  
     (Standard = 7)

Für das Simple UI gibt es vier Menüoptionen. Die ersten drei
sind dieselben wie beim gestuften Ramping-Modus.

  1. Floor.  
     (Standard = 20/150)
  2. Ceiling.  
     (Standard = 120/150)
  3. Anzahl der Stufen.  
     (Standard = 5)
  4. Turbo-Stil.  
     (Standard = 0, kein Turbo)

**Die Standardwerte sind für jedes Taschenlampenmodell unterschiedlich. Die obigen
Zahlen sind nur Beispiele.**

Um die Floor-Stufe zu konfigurieren, klicke die Taste entsprechend der Anzahl der
Ramp-Stufen (von 150), auf der Floor liegen soll. Um die niedrigstmögliche
Stufe einzustellen, klicke einmal.

Um die Ceiling-Stufe zu konfigurieren, geht jeder Klick eine Stufe tiefer. 1 Klick
stellt also die höchstmögliche Stufe ein, 2 Klicks die zweithöchste, 3 Klicks die dritthöchste
Stufe usw. Um den Standardwert von 120/150 einzustellen, klicke 31-mal.

Beim Konfigurieren der Stufenanzahl kann der Wert zwischen 1 und 150 liegen. Ein Wert
von 1 ist ein Sonderfall. Er platziert die Stufe auf der Hälfte des Weges zwischen Floor-
und Ceiling-Stufen.


## Versionsprüfungs-Modus

Dies ermöglicht es zu sehen, welche Firmware-Version auf der Lampe installiert ist. Das
Format hierfür ist gewöhnlich eine Modellnummer und ein Datum.
`MODEL.YYYY-MM-DD`

  - `MODEL`: Modellnummer  
    (normalerweise `BBPP`, wobei BB die Hersteller-ID und PP die Produkt-ID ist)
  - `YYYY`: Jahr
  - `MM`: Monat
  - `DD`: Tag

Das Format der Versionsnummer hat sich mehrmals geändert, schreibe dir also die Versionsinformationen auf
und vergleiche sie mit den unten stehenden Formaten.

Die Modellnummer ist beim Flashen einer neuen Firmware sehr wichtig. Stelle sicher,
dass die neue Firmware dieselbe Modellnummer wie die alte Firmware hat. Weitere Details
hierzu finden sich in [Which Hex File](which-hex-file.md). Verwende die Datei
[MODELS](../MODELS), um eine Modellnummer dem Namen einer .hex-Datei zuzuordnen.


### Formate der Versionsprüfung

Die Funktion zur Versionsprüfung sollte eine Reihe von Zahlen in einem der folgenden
Formate ausblinken:

  - `MODEL-YYYY-MM-DD-SINCE-DIRTY`
    Anduril 2 ab 2023-12 oder neuer. "SINCE" und "DIRTY" können weggelassen werden.
    Satzzeichen erzeugen ein "Summen" zwischen den Abschnitten.
    - `MODEL`: Modellnummer
    - `YYYY-MM-DD`: Jahr, Monat, Tag. Dies verwendet den neuesten Release-Tag
      aus Git, nicht das Erstellungsdatum (Build-Date).
    - `SINCE`: Wie viele Commits seit dem letzten offiziellen Release-Tag?
    - `DIRTY`: Fügt am Ende eine "-1" hinzu, wenn das Repository lokal verändert wurde,
      ohne die Änderungen zu committen.

  - `NNNN-YYYY-MM-DD`
    Anduril 2 ab 2023-05 oder neuer.  
    Es ist eine Modellnummer und ein Erstellungsdatum (Build-Date)
    mit "Summ"-Blinkern zwischen den Abschnitten.
    - `NNNN`: Modellnummer
    - `YYYY`: Jahr
    - `MM`: Monat
    - `DD`: Tag

  - `YYYYMMDDNNNN`
    Anduril 2 bis 2023-05 oder älter.  
    Es ist ein Erstellungsdatum und eine Modellnummer.

  - `YYYYMMDD`
    Dies ist eine alte Anduril 1-Version. Es ist nur ein Erstellungsdatum.  
    Wenn der Modellname nicht offensichtlich ist, versuche ihn in der Datei PRODUCTS nachzuschlagen.

  - `1969-07-20`
    Das Datum des ersten menschlichen Kontakts mit dem Mond. Dieser Wert zeigt an,
    dass die Person, die die Firmware erstellt hat, wahrscheinlich irgendeinen Fehler gemacht hat.

Wenn die Version keine Modellnummer enthält, kannst du das Modell möglicherweise in der
Datei PRODUCTS finden, um zu sehen, welche Firmware das Modell wahrscheinlich verwendet:

  https://toykeeper.net/torches/PRODUCTS


## Schutzfunktionen

Anduril beinhaltet einen Niederspannungsschutz (LVP) und eine thermische Regelung.

Der LVP sorgt dafür, dass die Lampe auf eine niedrigere Stufe herunterschaltet, wenn der Akku fast leer ist,
und wenn sich die Lampe bereits auf der niedrigsten Stufe befindet, schaltet sie sich selbst aus.
Dies aktiviert sich bei 2,8 V. LVP-Anpassungen erfolgen plötzlich in großen
Schritten.

Die thermische Regelung versucht, die Lampe vor dem Überhitzen zu bewahren, und
passt die Leistung ansonsten so an, dass sie so nah wie möglich an dem vom Benutzer
konfigurierten Temperaturlimit bleibt. Thermische Anpassungen erfolgen schrittweise
in so kleinen Schritten, dass sie für Menschen schwer wahrnehmbar sind.


## Aux LEDs / Button LEDs

Einige Lampen verfügen über Aux LEDs oder Button LEDs (Tasten-LEDs). Diese können so konfiguriert werden,
dass sie verschiedene Dinge tun, während die Haupt-LEDs ausgeschaltet sind. Es gibt einen Aux LED-Modus
für den regulären "Aus"-Modus und einen weiteren Aux LED-Modus für den "Lockout"-Modus.
Dadurch kann der Benutzer auf einen Blick sehen, ob die Lampe gesperrt ist.

Zu den Aux LED-Modi gehören typischerweise:

  - Aus
  - Low (Niedrig)
  - High (Hoch)
  - Blinken

Um die Aux LEDs zu konfigurieren, gehe in den Modus, den du konfigurieren möchtest, und klicke
die Taste 7 Mal. Dies sollte die Aux LEDs in den nächsten Modus schalten, der auf
dieser Lampe unterstützt wird.

  - `7C`: Nächster Aux LED-Modus.

Wenn die Aux LEDs die Farbe ändern können, gibt es zusätzliche Aktionen zum Ändern
der Farbe. Es ist dasselbe wie oben, halte jedoch die Taste beim letzten Klick
gedrückt und lasse sie los, wenn die gewünschte Farbe erreicht ist.

  - `7H`: Nächste Aux LED-Farbe.

Bei den meisten Lampen folgen die Farben dieser Reihenfolge:

  - Rot
  - Gelb (Rot+Grün)
  - Grün
  - Cyan (Grün+Blau)
  - Blau
  - Violett (Blau+Rot)
  - Weiß (Rot+Grün+Blau)
  - Disco (schnelle zufällige Farben)
  - Regenbogen (durchläuft alle Farben der Reihe nach)
  - Spannung (verwendet die Farbe zur Anzeige der Akkuladung)

Im Spannungsmodus folgen die Farben derselben Reihenfolge wie bei einem
Regenbogen... wobei Rot einen leeren Akku und Violett einen vollen Akku
anzeigt.

![battery charge colors](battery-rainbow.png)

Bei Lampen mit einer Button LED bleibt die Tasten-LED typischerweise eingeschaltet,
während die Haupt-LEDs an sind. Ihre Helligkeitsstufe ist auf eine Weise eingestellt, die
die Haupt-LED spiegelt – Aus, Low oder High.

Bei Lampen mit einer RGB Button LED zeigt die Tasten-LED während der Nutzung die
Akkuladung auf dieselbe Weise an wie der Aux LED-Spannungsmodus.

Bei Lampen mit nach vorne gerichteten Aux LEDs bleiben die Aux LEDs typischerweise aus,
wenn die Haupt-LEDs an sind und wenn die Lampe ansonsten aktiv ist.
Die Aux LEDs schalten sich bei den meisten Lampen nur ein, wenn die Lampe im Ruhemodus ist.

Wenn eine Lampe eine einfarbige Aux LED und kein RGB hat, blinkt sie die Aux LED in
den "Aus"-Modi schnell, wenn die Spannung niedrig ist.

Bei Lampen mit einem Aux-RGB-Steuerchip kann die Helligkeit der Modi "Low" und
"High" konfiguriert werden. Gehe dazu in den Aus-Modus, stelle das Muster
auf "Low" oder "High" ein und nutze dann `8H`, um die Helligkeit zu ändern. Dies funktioniert nur
auf spezifischen Modellen ab 2026, die über einen dedizierten Chip zur Steuerung
der RGB-Aux-LEDs verfügen.

Das Verhalten der Aux LEDs kann weiter konfiguriert werden, indem das Spannungs-Konfigurationsmenü
innerhalb des Akku-Prüfmodus aufgerufen wird.


## Spannungsanzeige nach dem Ausschalten (Post-Off Voltage Display / POVD)

Viele Lampen mit RGB-Aux-LEDs zeigen die Akkuspannung nach dem Wechsel in den "Aus"-Modus
für einige Sekunden durch Farben an. Dies bietet eine schnelle und einfache Möglichkeit,
den Akkuladezustand ohne zusätzliche Tastendrücke im Auge zu behalten.

Das typische und vorgesehene Nutzungsmuster ist: Schalte die Lampe aus, woraufhin die Farbe
für einige Sekunden den Akkuzustand anzeigt, und danach wechseln die Aux LEDs zu ihrem
konfigurierten Standby-Muster (standardmäßig meist niedrige Helligkeit im Spannungsmodus). Dies erleichtert das Erkennen der Farbe, da die Farben in der Hardware entsprechend ihrer Erscheinung im High-Modus ausbalanciert sind und im Low-Modus schwerer zu unterscheiden sein können. Es dauert jedoch nur wenige Sekunden, da ein dauerhaft helles Belassen den Akku viel, viel schneller entladen würde.

Die POVD-Helligkeit wird durch deine Konfigurationseinstellungen und die vorherige Ramp-Stufe der Haupt-LEDs
bestimmt. Es verwendet die *erste* zutreffende Bedingung:

  - Wenn die Standby-Aux-Helligkeit hoch ist, verwendet POVD ebenfalls High Aux.
  - Wenn die Haupt-LEDs über dem "Aux High Ramp Level" lagen, verwendet POVD High Aux.
  - Wenn die Haupt-LEDs über dem "Aux Low Ramp Level" lagen, verwendet POVD Low Aux.
  - Wenn die Haupt-LEDs unter dem "Aux Low Ramp Level" lagen, bleibt POVD dunkel/schwarz.

Die Aux High/Low Ramp Levels sind bei den meisten Lampen mit RGB über das
Spannungs-Konfigurationsmenü im Akku-Prüfmodus konfigurierbar.

Hinweis: Die Spannung wird während POVD kontinuierlich überwacht und aktualisiert, sodass sich die Farbe
ändern kann. Dies passiert insbesondere beim Ausschalten aus einem High- oder Turbo-Modus,
da die hohe Last einen starken Einbruch der Akkuspannung verursacht... und sich der Akku
in den ersten Sekunden nach Entfernen der Last schnell erholt. Es ist normal, dass die
Akkuspannung während und unmittelbar nach dem Turbo niedrig gemessen wird, sie sollte sich jedoch kurz darauf wieder erholen.


## Smooth POVD

Einige Lampen haben die Möglichkeit, die RGB-Aux-LEDs über das bloße High/Low/Aus hinaus
zu dimmen. Bei diesen Lampen blendet der POVD-Modus ein, zeigt die Spannung durch
Farben mit einer viel höheren Auflösung an und blendet dann wieder aus. Die zusätzliche
Farbauflösung wird auch verwendet, während die Haupt-LEDs an sind, wenn "RGB-Aux während An" aktiviert ist.

Der ursprüngliche / passive POVD-Modus hat bei normalem Gebrauch nur 6 Farben: Rot,
Gelb, Grün, Cyan, Blau und Violett. Diese werden durch Ein- und Ausschalten der
roten/grünen/blauen LEDs erzeugt. Smooth POVD bietet einen vollständigen Regenbogen mit
einer unterschiedlichen Schattierung für jeden möglichen Spannungswert. Die Farben verlaufen
in derselben Reihenfolge und zeigen dieselben Spannungsbereiche an, aber anstelle von 6 Hauptschattierungen
gibt es eher 60 Schattierungen. (von 3,00 V bis 4,20 V in 0,02-V-Schritten ergibt das ~60 verschiedene Farben) Nach einer gewissen Eingewöhnung kann der Benutzer die Akkuspannung daher allein anhand der Farbe, die der POVD-Modus anzeigt, auf 0,02 V oder 0,04 V genau bestimmen.

Nachdem die Haupt-POVD-Anzeige endet, nehmen die Aux LEDs ihren konfigurierten
Standby-Modus wieder auf und können bei Lampen mit passiven Aux LEDs die Farbe ändern,
wenn der "Spannungs"-Modus verwendet wird. Typischerweise pendelt es sich auf die nächstgelegene der 6 Hauptschattierungen ein, dies hängt jedoch vom exakten Hardwaremodell ab. Es hängt davon ab, ob die Hardware das RGB-PWM über den Haupt-MCU-Chip erzeugt oder ob sie einen externen Aux-Steuerchip besitzt.

Die Helligkeit des Smooth POVD-Modus verwendet dieselbe Konfiguration wie der reguläre
POVD-Modus. Das "Aux Low Ramp Level" und das "Aux High Ramp Level" funktionieren größtenteils genauso,
außer dass die Helligkeit zwischen den beiden stufenlos übergeht. Derselbe Helligkeitsverlauf
gilt in diesem Bereich während der regulären "An"-Modi, falls aktiviert.

Bei einigen Modellen kann die POVD-Helligkeit weiter angepasst werden. Rufen Sie dazu den
"Batt Color"-Modus auf und nutze dann `8H`. Dies stellt die Spitzenhelligkeit für POVD ein.


## Misc Config-Menü (Sonstiges-Konfigurationsmenü)

Einige Modelle verfügen möglicherweise über ein zusätzliches Konfigurationsmenü für Einstellungen, die anderswo
nicht hineinpassen. Dieses Menü befindet sich im Advanced UI unter "Aus -> 9H".

Diese Einstellungen sind in folgender Reihenfolge:

  - Tint Ramp-Stil: (bei einigen Lampen)  
    0 : Stufenloses Rampen (Kanäle in beliebiger Proportion mischen)  
    1 : Nur mittlerer Tint  
    2 : Nur extreme Tints (nur ein Kanal gleichzeitig aktiv)  
    3+: Gestuftes Rampen mit 3+ Stufen

  - Jump Start-Stufe: (bei einigen Lampen)

    Einige Lampen neigen dazu, auf niedrigen Stufen langsam zu starten; daher bieten sie
    die Option zum "Jump Start" der Elektronik, indem beim Wechsel von Aus auf eine
    niedrige Stufe für einige Millisekunden ein höherer Leistungsimpuls abgegeben wird.
    Diese Einstellung legt fest, wie hell dieser Impuls sein soll.

    Der Wert kann von 1 bis 150 reichen, liegt jedoch normalerweise zwischen 20 und 50.

Diese Einstellungen sind hardwarespezifisch und möglicherweise nicht auf allen
Lampen vorhanden. Die Anzahl der Einstellungen im Misc Config-Menü hängt vom
Hardwaremodell und der Firmware-Version ab.


<a id="channel-modes"></a>
## Kanalmodi (auch bekannt als Tint Ramping oder Multi-Channel-Steuerung)

Einige Lampen verfügen über mehr als ein Set von LEDs, die angepasst werden können, um
Lichtfarbe, Strahlform oder andere Eigenschaften zu verändern. Diese Lampen bieten
Funktionen wie Tint Ramping und Kanalmodi.

Bei diesen Modellen gibt es einige globale Tastenbelegungen, die jederzeit funktionieren,
sofern sie nicht durch den Modus, in dem sich die Lampe befindet, überschrieben werden:

  - `3C`: Nächster Kanalmodus
  - `3H`: Aktuellen Kanalmodus anpassen (z. B. Tint rampen)
  - `8H`: Aux-RGB-Helligkeit anpassen (nur Aux-Kanäle, auf spezifischer Hardware)
  - `9H`: Kanalmodus-Konfigurationsmenü

Die Details hängen vom exakten Typ der verwendeten Lampe ab. Wenn eine Lampe beispielsweise
über LEDs in Kaltweiß, Warmweiß und Rot verfügt... könnte diese Lampe über einige
Kanalmodi verfügen:

  - Weiß-Mischung (einstellbare CCT / Tint Ramping)
  - Nur Rot
  - Auto-Tint

Bei einer solchen Lampe könnte der Benutzer 3C drücken, um durch diese verschiedenen
Kanalmodi zu rotieren... Weiß, dann Rot, dann Auto, dann zurück zu Weiß.

Zusätzlich könnte der Benutzer im "Weiß-Mischung"-Modus 3H drücken, um
die Balance zwischen Warmweiß und Kaltweiß manuell anzupassen.

Wenn der Benutzer schließlich entscheidet, dass er nicht alle Modi möchte, kann er
einige ausschalten. Drücke `9H` (während die Lampe an ist), um das Kanalmodus-
Konfigurationsmenü zu starten. Um beispielsweise den Auto-Tint-Modus zu deaktivieren – dies ist
der 3. Modus –, warte auf das 3. Blinken und lasse dann die Taste los. Gib dann bei der
Aufforderung den Wert 0 ein (warte, bis die Aufforderung abläuft, ohne etwas anzuklicken).
Danach sollte sich der Auto-Tint-Modus nicht mehr in der Kanalmodus-Rotation
befinden. Um den Modus später wieder einzuschalten, gehe genauso vor, gib jedoch
einen Wert von 1 ein (klicke 1-mal bei der Aufforderung).

Eine Lampe kann viele verschiedene Kanalmodi haben; scheue dich also nicht,
Modi auszuschalten, die du nicht verwendest. Das macht alle anderen einfacher zu
erreichen.

Wenn du Kanalmodi ausschaltest, bis nur noch 1 übrig bleibt, schaltet die Aktion
`Ramp -> 3C` auf ihr Einkanal-Verhalten zurück – das Umschalten zwischen einem
stufenlosen oder gestuften Helligkeits-Rampen. Wenn ein Kanalmodus
nichts hat, was mit `3H` angepasst werden könnte, kehrt die Aktion `3H` ebenfalls zu ihrem
Einkanal-Verhalten zurück – dem Momentary Turbo.

Das [Misc Config-Menü](#misc-config-menu) (`Aus -> 9H`) bietet möglicherweise auch
eine Einstellung zur Auswahl eines Tint Ramp-Stils. Es stehen verschiedene Stile
zur Verfügung, indem unterschiedliche Zahlen in dieses Konfigurationsmenü eingegeben werden:

  0: Stufenloses Rampen  
  1: Nur mittlerer Tint  
  2: Nur extreme Tints  
  3+: Gestuftes Rampen mit 3+ Stufen

Diese Einstellung gilt nur für Modi mit Kanal-Rampen (d. h. Tint Ramping)
und nur dann, wenn dieser Modus den Standard-Event-Handler für `3H` verwendet.
Benutzerdefinierte Kanalmodi können anders funktionieren.

Bei Lampen mit Kanalmodi speichert der manuelle Speicher (`Ramp -> 10C`) die
aktuelle Helligkeit *und* den Kanalmodus.

Bei Lampen mit einem Aux-RGB-Steuerchip kann die Helligkeit der Aux-RGB-Modi
konfiguriert werden. Gehe dazu in einen Modus wie Ramp oder Strobe, aktiviere einen Aux-
Kanalmodus und nutze dann `8H`, um die Helligkeit zu ändern. Dies funktioniert nur auf
spezifischen Modellen ab 2026, die über einen dedizierten Chip zur Steuerung
der RGB-Aux-LEDs verfügen.


## FAQ

  - F: Warum schalten sich die Aux LEDs immer ein, wenn ich die Lampe ausschalte, unabhängig von den Aux-Einstellungen?
  - A: Dies ist die Funktion zur Spannungsanzeige nach dem Ausschalten (Post-Off Voltage Display). Sie kann im [Akku-Prüfmodus](#battery-check) konfiguriert oder deaktiviert werden.


  - F: Was kann ich tun, um zur Entwicklung von Anduril beizutragen?
  - A: Siehe [Contributing](https://github.com/ToyKeeper/anduril#contributing).


## UI-Referenztabelle

Dies ist eine Tabelle aller Tastenbelegungen in Anduril an einem Ort:

### "Aus"-Modus

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| Aus             | Alle   | `1C`      | An (Ramp-Modus, gespeicherte Stufe)
| Aus             | Alle   | `1H`      | An (Ramp-Modus, Floor-Stufe)
| Aus             | Alle   | `2C`      | An (Ramp-Modus, Ceiling-Stufe)
| Aus             | Simple | `2H`      | An (momentane Ceiling-Stufe)
| Aus             | Full   | `2H`      | An (Momentary Turbo)
| Aus             | Alle   | `3C`      | Akku-Prüfmodus
| Aus             | Full   | `3H`      | Strobe-Modus (der zuletzt verwendete)
| Aus             | Alle   | `4C`      | Lockout-Modus
| Aus             | Full   | `5C`      | Momentary Mode
| Aus             | Full   | `6C`      | Tactical Mode
| Aus             | Full   | `7C`      | Aux LEDs: Nächstes Muster
| Aus             | Full   | `7H`      | Aux LEDs: Nächste Farbe
| Aus             | Full   | `8H`      | Aux LEDs: Nächste Helligkeit (einige Modelle)
|                 |        |           | (zuerst Muster auf "Low" oder "High" stellen,
|                 |        |           | um die Helligkeit dieses Musters anzupassen)
| Aus             | Full   | `9H`      | Misc Config-Menü (variiert je nach Lampe):
|                 |        |           | ?1: Tint Ramp-Stil
|                 |        |           | ?2: Jump Start-Stufe
| Aus             | Full   | `10C`     | Simple UI aktivieren
| Aus             | Simple | `10H`     | Simple UI deaktivieren
| Aus             | Full   | `10H`     | Simple UI Ramp-Konfigurationsmenü:
|                 |        |           | 1: Floor
|                 |        |           | 2: Ceiling
|                 |        |           | 3: Stufen
|                 |        |           | 4: Turbo-Stil
| Aus             | Alle   | `13H`     | Werksreset (bei einigen Lampen)
| Aus             | Alle   | `15+C`    | Versionsprüfung

### Ramp-Modus

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| Ramp            | Alle   | `1C`      | Aus
| Ramp            | Alle   | `1H`      | Rampen (nach oben, mit Richtungsumkehr)
| Ramp            | Alle   | `2H`      | Rampen (nach unten)
| Ramp            | Alle   | `2C`      | Zu/von Ceiling oder Turbo wechseln (konfigurierbar)
| Ramp            | Full   | `3C`      | Ramp-Stil ändern (stufenlos / gestuft)
| Ramp            | Full   | `6C`      | (wie oben, aber bei mehrkanaligen Lampen)
| Ramp            | Full   | `3H`      | Momentary Turbo (wenn kein Tint Ramping)
| Ramp            | Full   | `4H`      | Momentary Turbo (bei mehrkanaligen Lampen)
| Ramp            | Alle   | `4C`      | Lockout-Modus
| Ramp            | Full   | `5C`      | Momentary Mode
| Ramp            | Full   | `5H`      | Sonnenuntergangs-Timer an, und 5 Minuten hinzufügen
| Ramp            | Full   | `7H`      | Ramp-Konfigurationsmenü: (für aktuelles Rampen)
|                 |        |           | 1: Floor
|                 |        |           | 2: Ceiling
|                 |        |           | 3: Geschwindigkeit / Stufen
| Ramp            | Full   | `10C`     | Manuellen Speicher einschalten & aktuelle Helligkeit
|                 |        |           | (und aktuellen Kanalmodus) speichern
| Ramp            | Full   | `10H`     | Ramp-Extras-Konfigurationsmenü:
|                 |        |           | 1: zu automatischem Speich. wechseln, nicht manuell
|                 |        |           | 2: manuelles Speich.-Timeout einstellen
|                 |        |           | 3: nach Moon hochrampen oder nicht
|                 |        |           | 4: Advanced UI Turbo-Stil
|                 |        |           | 5: Smooth Steps (weiche Stufen)

### Mehrkanalige Lampen

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| Alle            | Alle   | `3C`      | Nächster Kanalmodus (d. h. nächster Farbmodus)
| Alle            | Alle   | `3H`      | Tint rampen (falls in diesem Modus möglich)
| Alle            | Full   | `8H`      | Aux-RGB-Helligkeit ändern (falls Hardware möglich)
|                 |        |           | (für die "An"-Modi wie Ramp und Strobe)
| Alle            | Full   | `9H`      | Kanalmodus Aktivieren/Deaktivieren-Menü:
|                 |        |           | N: klicken (oder nicht), um Modus N zu aktivieren (deaktivieren)

### Lockout-Modus (Einschaltsperre)

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| Lockout         | Alle   | `1C`/`1H` | Momentanes Moon (niedrigster Floor)
| Lockout         | Alle   | `2C`/`2H` | Momentanes Moon (höchster Floor oder manuelle Speich.-Stufe)
| Lockout         | Alle   | `3C`      | Entsperren (in den "Aus"-Modus wechseln)
| Lockout         | Alle   | `3H`      | Nächster Kanalmodus (falls mehr als einer aktiviert ist)
| Lockout         | Alle   | `4C`      | An (Ramp-Modus, gespeicherte Stufe)
| Lockout         | Alle   | `4H`      | An (Ramp-Modus, Floor-Stufe)
| Lockout         | Alle   | `5C`      | An (Ramp-Modus, Ceiling-Stufe)
| Lockout         | Full   | `7C`      | Aux LEDs: Nächstes Muster
| Lockout         | Full   | `7H`      | Aux LEDs: Nächste Farbe
| Lockout         | Full   | `10H`     | Auto-Lock-Konfigurationsmenü:
|                 |        |           | 1: Timeout in Minuten einstellen (0 = kein Auto-Lock)

### Strobe-Gruppe-Modi

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| Strobe (jeder)  | Full   | `1C`      | Aus
| Strobe (jeder)  | Full   | `2C`      | Nächster Strobe-Modus
| Strobe (jeder)  | Full   | `3C`      | Nächster Kanalmodus (gespeichert pro Strobe-Modus)
| Strobe (jeder)  | Full   | `4C`      | Vorheriger Strobe-Modus
| Strobe (jeder)  | Full   | `5C`      | Momentary Mode (mit aktuellem Strobe)
| Party Strobe    | Full   | `1H`/`2H` | Schneller / langsamer
| Tactical Strobe | Full   | `1H`/`2H` | Schneller / langsamer
| Polizei Strobe  | -      | -         | Keines (Helligkeit ist die zuletzt genutzte Stufe des Ramp-Modus)
| Gewitter        | Full   | `1H`      | Aktuellen Blitz unterbrechen oder neuen starten
| Kerze           | Full   | `1H`/`2H` | Heller / dunkler
| Kerze           | Full   | `5H`      | Sonnenuntergangs-Timer an, 5 Minuten hinzufügen
| Fahrrad         | Full   | `1H`/`2H` | Heller / dunkler

### Blink-Modi

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| Akku-Prüfung    | Alle   | `1C`      | Aus
| Akku-Prüfung    | Alle   | `1H`      | Batt Color-Modus umschalten (bei einigen Modellen)
| Akku-Prüfung    | Alle   | `2H`      | Powerbank Host-Modus umschalten (bei einigen Modellen)
| Akku-Prüfung    | Full   | `2C`      | Nächster Blink-Modus (Temp.-Prüfung, Beacon, SOS)
| Akku-Prüfung    | Full   | `3C`      | Nächster Kanalmodus (nur für das Zahlenblinken)
| Akku-Prüfung    | Full   | `7H`      | Spannungs-Konfigurationsmenü
|                 |        |           | 1: Spannungskorrekturfaktor
|                 |        |           | ... 18: -0,02 V
|                 |        |           | ... 19: -0,01 V
|                 |        |           | ... 20: keine Korrektur
|                 |        |           | ... 21: +0,01 V
|                 |        |           | ... 22: +0,02 V
|                 |        |           | 2: Anzeige-Sekunden für Spannung nach dem Ausschalten
|                 |        |           | 3: Aux Low Ramp Level
|                 |        |           | ... 0: deaktiviert
|                 |        |           | ... 1+: leuchtet ab dieser Ramp-Stufe
|                 |        |           | 4: Aux High Ramp Level
|                 |        |           | ... 0: deaktiviert
|                 |        |           | ... 1+: heller ab dieser Ramp-Stufe
|                 |        |           | 5: Aux während An
|                 |        |           | ... 0: deaktiviert
|                 |        |           | ... 1: nur einfarbige Aux
|                 |        |           | ... 2: nur RGB-Aux
|                 |        |           | ... 3: beide
| Batt Color      | Full   | `8H`      | POVD-Helligkeit ändern (falls Hardware möglich)

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| Temp.-Prüfung   | Full   | `1C`      | Aus
| Temp.-Prüfung   | Full   | `2C`      | Nächster Blink-Modus (Beacon, SOS, Akku-Prüfung)
| Temp.-Prüfung   | Full   | `7H`      | Thermokonfigurationsmenü
|                 |        |           | 1: aktuelle Temperatur einstellen
|                 |        |           | 2: Temperaturlimit einstellen

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| Beacon          | Full   | `1C`      | Aus
| Beacon          | Full   | `1H`      | Beacon-Timing konfigurieren
| Beacon          | Full   | `2C`      | Nächster Blink-Modus (SOS, Akku-Prüfung, Temp.-Prüfung)

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| SOS             | Full   | `1C`      | Aus
| SOS             | Full   | `2C`      | Nächster Blink-Modus (Akku-Prüfung, Temp.-Prüfung, Beacon)

### Momentary Mode

| Modus           | UI     | Taste                       | Aktion
| :----           | :----- | -----:                      | :-----
| Momentary       | Full   | Alle                        | An (bis die Taste losgelassen wird)
| Momentary       | Full   | **Stromversorgung trennen** | Momentary Mode beenden

### Tactical Mode

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| Tactical        | Full   | `1H`      | High (taktischer Platz 1)
| Tactical        | Full   | `2H`      | Low (taktischer Platz 2)
| Tactical        | Full   | `3H`      | Strobe (taktischer Platz 3)
| Tactical        | Full   | `6C`      | Beenden (zurück zum Aus-Modus)
| Tactical        | Full   | `7H`      | Tactical Mode Konfigurationsmenü:
|                 |        |           | 1: taktischer Platz 1
|                 |        |           | 2: taktischer Platz 2
|                 |        |           | 3: taktischer Platz 3

### Konfigurationsmenüs

| Modus           | UI     | Taste     | Aktion
| :----           | :----- | -----:    | :-----
| Konfig.-Menüs   | Full   | Halten    | Aktuellen Punkt ohne Änderungen überspringen
| Konfig.-Menüs   | Full   | Loslass.  | Aktuellen Punkt konfigurieren
|                 |        |           | (wechselt zum Zahleneingabe-Menü)
| Zahleneingabe   | Full   | Klick     | 1 zum Wert für den aktuellen Punkt hinzufügen
| Zahleneingabe   | Full   | Halten    | 10 zum Wert für den aktuellen Punkt hinzufügen
