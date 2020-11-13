def create():
    intermediate = 1
    def assign():
        nonlocal intermediate
        intermediate = 2
        print('assign: intermediate =', intermediate)
    def check():
        print('check: intermediate =', intermediate)
    return assign, check

assign, check = create()
assign()
check()
