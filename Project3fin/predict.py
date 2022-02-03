#!/usr/bin/python3.7.2


################################
# OUTPUT FILE: VALUES FROM MAE #
# FIT parameter  ->  actual.csv#
################################

import sys #for arguments 
import numpy as np
import pandas as pd
import sklearn
#pandas reads csv files

#predict.py
len(sys.argv) #how many arguments we have (3 arguments)
listofargs=sys.argv #return the arguments inside a list(['predict.py','-i','<input_file>'])
#print(listofargs)
if listofargs[1] =='-i':
    print("second argument is -i")
    input_file=listofargs[2]
    print("third argument is ",input_file)
else:
    print("wrong input")


df_actual=pd.read_csv('actual.csv', header=None, names=None)
df_represent = pd.read_csv(input_file, header=None, names=None)

num=df_represent.shape[1]
#print(num)
#if our input is correct, proceed to open the file
list_head=[]
for i in range(num-1):
	headers = list_head.append(i)
df_actual=pd.read_csv('actual.csv', header=None, names=headers)
#print(df_actual)
#df_represent = pd.read_csv('nn_representations.csv', header=None, names=headers)
df_represent = pd.read_csv(input_file, header=None, names=headers)
#print(df_represent)

#take the coordinates of the vectors to do the calculations
vector_coordinates=df_represent.loc[:,1:]
#print(vector_coordinates)

vector_coordinates_ac=df_actual.loc[:,1:]


#Build the NN

import keras
from keras import layers, optimizers, losses, metrics
from keras.models import load_model

# Initializes the model
model = load_model('WindDenseNN.h5')
print("model loaded")
model.summary()
#print(model.layers[1].get_weights())

data=vector_coordinates[1:]
labels=vector_coordinates_ac[1:]


#MAE
model.compile(optimizer='Adam',loss='mae',metrics=[metrics.CategoricalAccuracy()])
#activation='relu'
history1=model.fit(data,labels,epochs=10, batch_size=50) #epochs=150 && batch_size=20
mae_loss=history1.history['loss'][-1]
#print(mae_loss)
model.evaluate(data, labels, batch_size=32)
# Get a random data set for prediction
#test_data = np.random.random((1000, 128))
result = model.predict(data, batch_size=32)
print("MAE")
print(result.shape)
print(result)

#MSE
model.compile(optimizer='Adam',loss='mse',metrics=[metrics.CategoricalAccuracy()])
history2=model.fit(data,labels,epochs=10, batch_size=100) #epochs=150 && batch_size=20

mse_loss=history2.history['loss'][-1]
#print(mse_loss)
model.evaluate(data, labels, batch_size=32)
print("MSE")
# Get a random data set for prediction
#test_data = np.random.random((1000, 128))
result = model.predict(data, batch_size=32)
###print(result.shape)
print(result)

#MAPE
model.compile(optimizer='Adam',loss='mape',metrics=[metrics.CategoricalAccuracy()])
history3=model.fit(data,labels,epochs=100, batch_size=10) #epochs=150 && batch_size=20
mape_loss=history3.history['loss'][-1]
#print(mape_loss)
model.evaluate(data, labels, batch_size=32)
# Get a random data set for prediction
#test_data = np.random.random((1000, 128))
result = model.predict(data, batch_size=32)
###print(result.shape)
print("MAPE")
print(result)

print("our losses are: ",mae_loss,mse_loss,mape_loss)
########
#STEP1:# CONVERT result(numpy) to dataframe(result_df)
########
result_df=pd.DataFrame(data=result[0:,0:],index=[i for i in range(result.shape[0])],columns=[str(i+1) for i in range(result.shape[1])])
#print(result_df)
########
#STEP2:# ADD COLUMN to dataframe Timestampe from actual.csv first column
########
result_df.insert(0,"0",df_actual.loc[:,0],True) #insert column at the start of dataframe
#result_df['0'] = df_actual.loc[:,0] #insert column at the end of dataframe
print(result_df)
########
#STEP3:# datframe to csv
result_df.to_csv('predicted.csv',index=False,header=['MAE: ',mae_loss,'MAPE: ',mse_loss,'MSE: ',mape_loss,' ',' '])
########


print("csv created! Check predicted.csv")
#newpresentation.py




