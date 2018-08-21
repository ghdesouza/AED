#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug 11 21:03:38 2018

@author: gabrielbmiranda
"""

#Process p = Runtime.getRuntime().exec("python plotCaminho.py");

import networkx as nx
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('Grafo.csv',names = ['no1','no2','peso'])

#import sys
#s = sys.argv
#v = s[1].split(" ")

D = nx.DiGraph()

num_nos = 6
    
for i in range(df.shape[0]):
    D.add_edge(df.astype(int).at[i,'no1'], df.astype(int).at[i,'no2'], peso=0.1, cor='b')

df = pd.read_csv('Caminho.csv', names = ['no'])

caminho = []
for i in range(df.shape[0]-1):
    caminho.append( [df.astype(int).at[i,'no'],df.astype(int).at[i+1,'no']] )

#for u in D.nodes():
#    D[u]['cor'] = 'b'

for e in caminho:
    D.edges[e[0],e[1]]['cor']='r'
    D.edges.get((e[0],e[1]))['peso']= 3

D.nodes.data('cor', default='b') 

edges  = D.edges()
cores  = [D[u][v]['cor' ] for u,v in edges]
pesos  = [D[u][v]['peso'] for u,v in edges]
cornos = ['b' for i in range(len(D.nodes))]

inicial = 1
final = 6
cornos[inicial-1] = 'g'
cornos[final-1] = 'r'

nx.draw(D, edges=edges, edge_color=cores , node_color=cornos , with_labels=True , width=pesos)
plt.draw()
plt.show()
