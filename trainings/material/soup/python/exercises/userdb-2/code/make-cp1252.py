import sys

open(sys.argv[1], 'w', encoding='cp1252').writelines([
    '666:Jörg:Faschingbauer:1966-06-19\n',
    '42:Caro:Faschingbauer:1997-04-25\n',
    '7:Johanna:Faschingbauer:1995-06-11\n',
    '1024:Philipp:Lichtenberger:1986-04-06\n',
])
