#!/usr/bin/env python
# -*- coding: utf-8 -*-
from Point import *
import matplotlib.pyplot as plt
import os
import random

#Algorithme permettant d'afficher des courbes de béziers jusqu'à la puissance 3

global eps#précision
global r#valeur d'entrée
global s#valeur de sortie
global af#paramètre pour la définition du module d'affichage

#Fonction principale récursive
def bezier(p) :#Point[] p

	# Point q[], r[]
	#Si les points sont colinéaires (selon la précision p), on dessine la droite les regroupant
	if(colinear(p)):
		draw_line(p[0],p[3])
	else:
	#Sinon, on sépare les points en deux tableaux
		q, r = split(p)
		bezier(q)
		bezier(r)

#Fonction de test de colinéarité des points
def colinear(p):#Point p[]
	i = 1
	check = False
	while i < len(p)-2 and check !=  True:
		x1, y1 = p[i].getX() - p[0].getX(), p[i].getY() - p[0].getY()
		x2, y2 = p[len(p)-1].getX() - p[0].getX(), p[len(p)-1].getY() - p[0].getY()
		check = abs(x1 * y2 - x2 * y1) <= eps
		i += 1
	return check
	
#Fonction de dessin des droites
def draw_line(p0, p3):#Point p0, p3

    	af.plot((p0.getX(), p3.getX()), (p0.getY(), p3.getY()))
    	
#Fonction de séparation en plusieurs tableaux
def split(p):

	u = len(p)
	holder = [0]*u
	holder[0] = p


	print(holder[0][3].getX())

	for k in range(1, u):
		s = [0]*(u-k)
		for l in range(u-k):
			s[l] = Point((holder[k-1][l].getX()+ holder[k-1][l+1].getX())/2.0, (holder[k-1][l].getY()+holder[k-1][l+1].getY())/2.0)
		holder[k] = s
	
	q = [0]*u
	r = [0]*u

	for k in range(u):
		q[k]=holder[k][0]
		r[k]=holder[k][u-k-1]

	return(q, r)

#Fonction d'appel si des points de controle sont directement fournis
def withcontrolpoints(p):
	
	bezier(p)
	plt.show()
    
#Fonction d'appel si un polynome (ax3+bx2+cx+d) est fourni

def withpolynom():
	
	print("x(t)")
	a = float(input("a (puissance 0)"))
	b = float(input("b (puissance 1)"))
	c = float(input("c (puissance 2)"))
	d = float(input("d (puissance 3)"))

	b = b/3.0
	c = c/3.0

	p = [Point(0,0),Point(0,0) , Point(0,0), Point(0,0)]

	p[0].setX(a + b*(r + r + r) + c*(r*r + r*r + r*r) + d*(r*r*r))

	
	p[1].setX(a + b*(r + r + s) + c*(r*r + r*s + r*s) + d*(r*r*s))
	
	p[2].setX(a + b*(r + s + s) + c*(r*r + r*s + s*s) + d*(r*s*s))
	
	p[3].setX(a + b*(s + s + s) + c*(s*s + s*s + s*s) + d*(s*s*s))
	


	print("y(t)")

	a = float(input("a (puissance 0)"))
	b = float(input("b (puissance 1)"))
	c = float(input("c (puissance 2)"))
	d = float(input("d (puissance 3)"))

	b = b/3.0
	c = c/3.0

	p[0].setY(a + b*(r + r + r) + c*(r*r + r*r + r*r) + d*(r*r*r))
	
	p[1].setY(a + b*(r + r + s) + c*(r*r + r*s + r*s) + d*(r*r*s))
	
	p[2].setY(a + b*(r + s + s) + c*(r*r + r*s + s*s) + d*(r*s*s))
	
	p[3].setY(a + b*(s + s + s) + c*(s*s + s*s + s*s) + d*(s*s*s))

	af.plot((p[0].getX(), p[1].getX()), (p[0].getY(), p[1].getY()), color='green', marker='o', linestyle='dashed', linewidth=2, markersize=12)
	af.plot((p[1].getX(), p[2].getX()), (p[1].getY(), p[2].getY()), color='green', marker='o', linestyle='dashed', linewidth=2, markersize=2)
	af.plot((p[2].getX(), p[3].getX()), (p[2].getY(), p[3].getY()), color='green', marker='o', linestyle='dashed', linewidth=2, markersize=12)

	bezier(p)
	plt.show()
    

#Main appelé
eps = 0.00001
r = 0
s = 1

p = [Point(1, 1),Point(1, 2) ,Point(2, 3) ,Point(3, 3)]#Points de controle de P

f, af = plt.subplots()#Définition du module d'affichage

ask = str(input("Avec ou sans points de controle ?"))
if str(ask) == 'avec' or str(ask) == 'Avec' or str(ask) == 'a':
	withcontrolpoints(p)
elif str(ask) == 'sans' or str(ask) =='Sans' or str(ask) == 's':
	withpolynom()
else:
	print("Au revoir")
