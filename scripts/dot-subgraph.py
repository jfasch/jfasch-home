import networkx as nx
from networkx.algorithms.dag import descendants
import sys

dot_in = sys.argv[1]
dot_out = sys.argv[2]
entry = sys.argv[3]

g = nx.nx_pydot.read_dot(dot_in)


subgraph_nodes = set()

entry = '"' + entry + '"'
for n in g.nodes:
    label = g.nodes[n]['label']
    if label == entry:
        subgraph_nodes.add(n)
        subgraph_nodes.update(descendants(g, n))
        break
else:
    print(entry, 'not found', file=sys.stderr)
    sys.exit(1)

subgraph = nx.subgraph(g, subgraph_nodes)
for n in subgraph.nodes:
    print(subgraph.nodes[n])

nx.nx_pydot.write_dot(subgraph, open(dot_out, 'w'))
