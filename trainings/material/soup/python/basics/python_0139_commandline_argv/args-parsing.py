import sys

# rudimentarily parsing the commandline: check for number of arguments
if len(sys.argv) != 3:
    print('Expecting two parameters:', sys.argv[0], '<firstname> <lastname>', 
          file=sys.stderr)   # stderr is where errors belong!
    
    # exit status != 0 for "terminated with an error"
    sys.exit(1)

print('sys.argv:', sys.argv)
print('sys.argv[0] (program name):', sys.argv[0])
print('sys.argv[1] (firstname):', sys.argv[1])
print('sys.argv[2] (lastname):', sys.argv[2])

# implicitly terminated with exit status 0 for "all fine"
