def create():
    intermediate = 1
    def assign():
        intermediate = 2
        print('assign: intermediate =', intermediate)
    def check():
        print('check: intermediate =', intermediate)
    return assign, check

assign, check = create()
assign()
check()
