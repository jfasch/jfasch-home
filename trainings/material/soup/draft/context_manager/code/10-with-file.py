with open('/etc/passwd') as f:
    for line in f:
        if line.find('jfasch') >= 0:
            print(line)
            break
    else:
        print('no')
