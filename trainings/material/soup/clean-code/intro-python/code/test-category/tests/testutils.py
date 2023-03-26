def write_csv(csvname, lines):
    with open(csvname, 'w', encoding='iso-8859-1') as csv:
        csv.writelines([l+'\n' for l in lines])

