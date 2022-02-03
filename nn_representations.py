#new_presentation.py

import sys #for arguments 
import numpy as np
import pandas as pd
import sklearn
import csv
#pandas reads csv files

#predict.py
len(sys.argv) #how many arguments we have (3 arguments)
listofargs=sys.argv #return the arguments inside a list(['predict.py','-i','<input_file>'])
print(listofargs)
if listofargs[1] =='-i':
    print("second argument is -i")
    input_file=listofargs[2]
    print("third argument is ",input_file)
else:
    print("wrong input")

#if our input is correct, proceed to open the file
df_actual=pd.read_csv('actual.csv', header=None, names=None)
df_represent = pd.read_csv(input_file, header=None, names=None)

num=df_represent.shape[1]
list_head=[]
for i in range(num-1):
	headers = list_head.append(i)
df_actual=pd.read_csv('actual.csv', header=None, names=headers)
#print(df_actual)
#df_represent = pd.read_csv('nn_representations.csv', header=None, names=headers)
df_represent = pd.read_csv(input_file, header=None, names=headers)
#print(df_represent)

vector_coordinates=df_represent.loc[:,1:]
#print(vector_coordinates)

vector_coordinates_ac=df_actual.loc[:,1:]


#name the vector ids appropriately for later use
item_list=[]
for i in range(df_actual.shape[0]):
	i2=str(i)
	item_list.append(i2)
iteml=[]
for i in range(df_actual.shape[0]):
	iteml.append("item")
"""
itemlfin=[]
for i in range(df_actual.shape[0]):
	itemlfin.append(iteml[i]+item_list[i])
print(itemlfin)
#df_represent.insert(0,"0",itemlfin,True) #insert column at the start of dataframe
"""
from string import punctuation
itemlfin2=[]
for i in range(df_actual.shape[0]):
	stringw=iteml[i]+item_list[i]+df_represent.loc[i,0]
	#print('stringw:',stringw)
	stringw=stringw.replace(':','_')
	stringw=stringw.replace(' ','_')
	stringw=stringw.replace('-','_')
	itemlfin2.append(stringw)
	itemlfin2[i]=itemlfin2[i].strip(punctuation)
#print(itemlfin2)
vector_coordinates.insert(0,"0",itemlfin2,True) #insert column at the start of dataframe
print("date")
print(vector_coordinates.loc[:,])


#export as csv, according to the template
with open('new_representation_128.csv','w',newline='') as file:
	writer=csv.writer(file)
	writer.writerow(['vectors'])
vector_coordinates.to_csv('new_representation_128.csv',sep='\t',index=False,mode='a',header=None)

print("csv created! Check new_representation_128.csv")