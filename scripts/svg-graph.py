#!/usr/bin/env python

from jf.topic.topic import Topic
from jf.topic.soup import Soup
from jf.topic.graph import build_worldgraph, graph_to_dot, dot_to_svg, svg_to_nodes

soup = Soup([
    Topic(title='Title A', id='a', docname='/some/where/a', dependencies=('b', 'c')),
    Topic(title='Title B', id='b', docname='/some/where/b', dependencies=('d')),
    Topic(title='Title C', id='c', docname='/some/where/c', dependencies=('d')),
    Topic(title='Title D', id='d', docname='/some/where/d', dependencies=()),
])

world = build_worldgraph(soup)

dot = graph_to_dot(world)
svg = dot_to_svg(dot)
nodelist = svg_to_nodes(svg, soup)

for i, n in enumerate(nodelist):
    print('-------', i, '\n', n)
