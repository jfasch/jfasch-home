#!/usr/bin/python

import networkx as nx
import matplotlib.pyplot as plt

import io


g = nx.DiGraph()
g.add_edge(1,2)
nx.draw(g)

data = io.StringIO()
plt.savefig(data, format='svg')

s = data.getvalue()
print(s[s.find('<svg'):])
