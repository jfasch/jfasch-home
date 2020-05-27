#!/usr/bin/env python

import networkx as nx
from networkx.drawing.nx_pydot import pydot_layout
from networkx import DiGraph, draw_networkx
import matplotlib.pyplot as plt

import io, re


g = nx.DiGraph()
g.add_edge(1,2)
g.add_edge(1,3)
g.add_edge(2,3)
g.add_edge(3,4)

pos = pydot_layout(g, prog='dot')
draw_networkx(g, pos=pos)

data = io.StringIO()
plt.savefig(data, format='svg')
plt.clf()
plt.cla()
plt.close()

re_svg_begin_and_rest = re.compile(r'^.*?(<svg .*?>)(.*)', re.MULTILINE|re.DOTALL)
re_width = re.compile('^(<svg.*?)(width=".*?")(.*)', re.MULTILINE|re.DOTALL)
re_height = re.compile('^(<svg.*?)(height=".*?")(.*)', re.MULTILINE|re.DOTALL)

m = re_svg_begin_and_rest.search(data.getvalue())

svg_begin = m.group(1)
rest = m.group(2)

m = re_width.search(svg_begin)
svg_begin = m.group(1) + m.group(3)

m = re_height.search(svg_begin)
svg_begin = m.group(1) + m.group(3)


print(svg_begin + rest)
