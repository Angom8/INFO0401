#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Classe Point avec pour paramètres x et y
class Point(object):

	def __init__(self, x, y):
	
		self.x = x
		self.y = y
			
	def getY(self):
		return self.y
		
	def getX(self):
		return self.x

	def setY(self, y):
		self.y = y
		
	def setX(self, x):
		self.x = x

