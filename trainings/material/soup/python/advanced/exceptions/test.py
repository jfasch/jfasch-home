try:
    pass
finally: 
    pass


# -----------------------------------------------------
# exception Exception
# 
#     All built-in, non-system-exiting exceptions are derived from this class. All user-defined exceptions should also be derived from this class.

# -> better use that

# try:
#     f = open('file-that-does-not-exist.txt')
# except Exception as e:        # <--- this is sufficient
#     print('bad luck:', e)


# -----------------------------------------------------
# more specific: OSError -> errno

# try:
#     f = open('file-that-does-not-exist.txt')
# except OSError as e:
#     print('bad luck:', e, e.errno)


# -----------------------------------------------------
# even more specific: open raises FileNotFoundError

# file:///home/jfasch/Documents/python-3.11.0-docs-html/library/functions.html

# see also: oo/inheritance/topic

# try:
#     f = open('file-that-does-not-exist.txt')
# except FileNotFoundError as e:
#     print('bad luck:', e, type(e), e.errno)


# -----------------------------------------------------
# do more 

# attention: /etc/passwd

# try:
#     f = open('/etc/passwd')
#     print(blah)
# except FileNotFoundError as e:
#     print('bad luck:', e, type(e), e.errno)
# except Exception as e:
#     print('going weird:', e)

# -----------------------------------------------------

# attention: isinstance() is used to determine the match of the
# exception clause

print(issubclass(FileNotFoundError, Exception))

try:
    f = open('file-that-does-not-exist.txt')
    print(blah)
except Exception as e:
    print('going weird:', e)
except FileNotFoundError as e:
    print('bad luck:', e, type(e), e.errno)

