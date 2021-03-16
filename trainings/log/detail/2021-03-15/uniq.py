#!/usr/bin/python3


def uniq(inliste):
    outliste = []
    have = set()
    for element in inliste:
        if not element in have:
            have.add(element)
            outliste.append(element)
    return outliste

input_liste = [2,5,2,3,5,1]

output_liste = uniq(input_liste)
print(output_liste)
