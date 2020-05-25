#!/usr/bin/env python

import networkx as nx
from networkx.drawing.nx_pydot import pydot_layout
import matplotlib.pyplot as plt

import io


g = nx.DiGraph()
g.add_edge(1,2)
g.add_edge(1,3)
g.add_edge(2,3)
g.add_edge(3,4)

#a = to_agraph(g)


pos = pydot_layout(g, prog='dot')
nx.draw_networkx(g, pos=pos)

#nx.draw(g)

data = io.StringIO()
plt.savefig(data, format='svg')

print(data.getvalue())

# s = data.getvalue()
# print(s[s.find('<svg'):])
