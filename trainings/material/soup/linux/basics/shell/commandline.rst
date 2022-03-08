.. ot-topic:: linux.basics.shell.commandline
   :dependencies: linux.basics.intro.overview

.. include:: <mmlalias.txt>


Commandline
===========

.. contents:: 
   :local:

Shape (1)
---------
  
Consists of three parts ... well mostly, this is just convention.

* Command: executable program, or script, shell alias (see below),
  oder shell builtin (like ``cd``)
* Options: e.g. ``-i`` ("short option"), oder ``--interactive`` ("long option")
* Arguments: file names, mostly

Shape (2)
---------
  
.. code-block:: console
   :caption: Example: ``cp`` - "Copy"

   $ cp -i -r /etc ~/tmp
   $ cp -ir /etc ~/tmp

* Command: ``cp``
* Options: ``-i`` and ``-r``
* Arguments: ``/etc`` and ``/tmp``

Options
-------
  
..   Alternativ: ``Long Options''; z.B. bei \texttt{cp}
..   \begin{itemize}
..     \item \texttt{--interactive} statt \texttt{-i}
..     \item \texttt{--recursive} statt \texttt{-r}
..   \end{itemize}
.. 
..   ``Standard'' Optionen:
..   \begin{itemize}
..     \item \texttt{-h} oder \texttt{--help}: kurze Erläuterung des
..       Commands
..     \item \texttt{-v} oder \texttt{--verbose}: Ausführliche Meldungen
..     \item \texttt{--version}: Version des Commands
..   \end{itemize}
.. 
..   Ausreisser:
..   \begin{block}{\texttt{dd}}
.. \begin{verbatim}
.. $ dd if=/dev/zero of=/dev/null count=20 bs=1024
.. \end{verbatim}
..   \end{block}
.. 
.. \end{frame}
.. 
.. % --------------------------------------------------------------------
.. \begin{frame}[fragile]
..   \frametitle{Hilfe und Manual (1)}
..   
..   Befehl erklärt seine Optionen mit \texttt{--help}
..   \begin{block}{\texttt{--help}}
.. \begin{verbatim}
.. $ cp --help
.. \end{verbatim}
..   \end{block}
..   Vollständige Beschreibung in der Manual Page (``Man-Page'')
..   \begin{block}{\texttt{Manual Pages}}
.. \begin{verbatim}
.. $ man cp
.. \end{verbatim}
..   \end{block}
.. \end{frame}
.. 
.. % --------------------------------------------------------------------
.. \begin{frame}[fragile]
..   \frametitle{Hilfe und Manual (2)}
.. 
..   Navigation in der Anzeige von Man-Pages
.. 
..   \begin{block}{}
..     \begin{tabular}{|l|l|}
..       \hline
..       \keystroke{h} & Hilfe von \texttt{man} \\
..       \keystroke{q} & Beendet \texttt{man} (oder die Hilfe) \\
..       \keystroke{g} & Springt zum Anfang \\
..       \keystroke{G} & Springt zum Ende \\
..       \keystroke{/} & Sucht vorwärts im Text \\
..       \keystroke{?} & Sucht rückwärts im Text \\
..       \keystroke{n} & Springt zur nächsten Fundstelle \\
..       \keystroke{N} & Springt zur vorherigen Fundstelle \\
..       \hline
..     \end{tabular}
..   \end{block}
.. 
..   \begin{block}{Hilfe für \texttt{man} selbst}
.. \begin{verbatim}
.. $ man man
.. \end{verbatim}
..   \end{block}
.. 
.. \end{frame}
.. 
.. % --------------------------------------------------------------------
.. \begin{frame}
..   \frametitle{Line Editing (1)}
.. 
..   Geniale Editiermöglichkeiten (Emacs-Keys!)
..   
..   \begin{block}{}
..     \begin{tabular}{|l|l|}
..       \hline
..       \LArrow, \RArrow & Cursor links, rechts \\
..       \BSpace (Backspace) & Löscht das Zeichen links vom Cursor \\
..       \Del, \Ctrl+\keystroke{d} & Löscht das Zeichen unter dem Cursor \\
..       \Home, \Ctrl+\keystroke{a} & Springt zum Zeilenanfang \\
..       \End, \Ctrl+\keystroke{e} & Springt zum Zeilenende \\
..       \Ctrl+\keystroke{k} & Löscht vom Cursor bis zum Zeilenende \\
..       \Ctrl+\keystroke{u} & Löscht vom Cursor bis zum Zeilenanfang \\
..       \Ctrl+\keystroke{l} & Löscht den Bildschirm bis auf die aktuelle Zeile \\
..       \hline
..     \end{tabular}
..   \end{block}
.. 
.. \end{frame}
.. 
.. % --------------------------------------------------------------------
.. \begin{frame}
..   \frametitle{Line Editing (2)}
.. 
..   Wortweises Editieren
..   \linebreak
.. 
..   \begin{block}{}
..     \begin{tabular}{|l|l|}
..       \hline
..       \Ctrl+\LArrow, \Alt+\keystroke{b} & Springt ein Wort nach links \\
..       \Ctrl+\RArrow, \Alt+\keystroke{f} & Springt ein Wort nach rechts \\
..       \Alt+\keystroke{d} & Löscht Wort rechts vom Cursor \\
..       \Alt+\BSpace & Löscht Wort links vom Cursor \\
..       \hline
..     \end{tabular}
..   \end{block}
.. 
..   Anmerkungen
..   \linebreak
.. 
..   \begin{itemize}
..   \item \Ctrl+\LArrow und \Ctrl+\RArrow funktionieren nicht auf der
..     virtuellen Konsole (belegt mit Konsolen-Switch)
..   \item Sollte \Alt nicht belegt sein, nimmt man \Esc
..   \end{itemize}
.. 
.. \end{frame}
.. 
.. % --------------------------------------------------------------------
.. \begin{frame}
..   \frametitle{Line Editing (3)}
.. 
..   Keys für Kenner, Liebhaber und Emacs-Benutzer
..   \linebreak
.. 
..   \begin{block}{}
..     \begin{tabular}{|l|l|}
..       \hline
..       \Ctrl+\keystroke{y}, \Alt+\keystroke{y} & Einfügen aus dem ``Kill-Ring'' \\
..       \Ctrl+\keystroke{\_} (Underline) & Undo \\
..       \Ctrl+\keystroke{t} & Zeichen tauschen (``transpose'') \\
..       \Alt+\keystroke{t} & Wörter tauschen \\
..       \Alt+\keystroke{u} & Wort in Uppercase wandeln \\
..       \Alt+\keystroke{l} & Wort in Lowercase wandeln \\
..       \Alt+\keystroke{c} & 1. Buchstabe groß (``capitalize'') \\
..       \hline
..     \end{tabular}
..   \end{block}
.. 
.. \end{frame}
.. 
.. % --------------------------------------------------------------------
.. \begin{frame}[fragile]
..   \frametitle{Tabulatortaste (1)}
.. 
..   \begin{itemize}
..     \item Tabulatortaste Spart Tastendrücke (kein Mensch kann Maschinschreiben)
..     \item Commandvervollständigung
..   \end{itemize}
.. 
..   \begin{block}{Alle Commands, die mit \texttt{git} beginnen}
.. \begin{alltt}
.. $ git\Tab
.. git                 git-p4              git-resurrect       git-upload-archive  gitk
.. git-cvsserver       git-receive-pack    git-shell           git-upload-pack     gitview
.. \end{alltt}
..   \end{block}
.. 
.. \end{frame}
.. 
.. % --------------------------------------------------------------------
.. \begin{frame}[fragile]
..   \frametitle{Tabulatortaste (2)}
.. 
..   \begin{itemize}
..   \item Filenamenvervollständigung
..   \end{itemize}
.. 
..   \begin{block}{Piepen, falls nicht eindeutig}
..     \begin{alltt}
.. $ less /var/log/emerge-log/emerge\Tab
..     \end{alltt}
..   \end{block}
.. 
..   \begin{block}{Zwei Tabs $\to$ Liste}
..     \begin{alltt}
.. $ less /var/log/emerge-log/emerge\Tab\Tab
.. emerge-fetch.log  emerge.log        
..     \end{alltt}
..   \end{block}
.. 
.. \end{frame}
.. 
.. % --------------------------------------------------------------------
.. \begin{frame}[fragile]
..   \frametitle{Tabulatortaste (3)}
.. 
..   \begin{itemize}
..   \item Eigene Vervollständigungen mit \texttt{complete}
..   \end{itemize}
.. 
..   \begin{block}{Eigene Vervollständigungen}
..     \begin{alltt}
.. $ complete -W "server laptop" ssh
.. $ ssh s\Tab
..     \end{alltt}
..   \end{block}
.. 
..   Wird zu "\texttt{ssh server}"
..   \linebreak
..   Dauerhaft eingetragen in \texttt{\textasciitilde/.bashrc}
.. 
.. \end{frame}
.. 
