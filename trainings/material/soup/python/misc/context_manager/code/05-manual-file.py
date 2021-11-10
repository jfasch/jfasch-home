f = open('/etc/passwd', 'br')   # binary!
for line in f:
    if line.find('jfasch') >= 0: # exception!
        print(line)
        break
else:
    print('no')

# won't get here
f.close()
print('file closed')
