import sys

line_count = 0
for line in sys.stdin:
    line_count += 1

print(line_count, file=sys.stdout)
print('fertig, und das hier kommt aud stderr', file=sys.stderr)
    
