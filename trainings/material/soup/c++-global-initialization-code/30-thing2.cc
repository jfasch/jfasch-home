#include "thing.h"

extern Thing thing1;

Thing thing2(thing1.content() + " BUG!!");
