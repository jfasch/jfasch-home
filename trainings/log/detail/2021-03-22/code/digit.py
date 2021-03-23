import sys

lookup_table = {
    0: 'zero',
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
}

if len(sys.argv) != 2:
    print('gib eine parameter an  mich, depp!', file=sys.stderr)
    sys.exit(1)

digit = int(sys.argv[1])

word = lookup_table.get(digit)
if word == None:
    print('nix drin', file=sys.stderr)
    sys.exit(3)
else:
    print(word)
