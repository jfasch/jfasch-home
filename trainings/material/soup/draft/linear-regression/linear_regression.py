#!/usr/bin/env python

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as seabornInstance
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn import metrics

from sys import exit
from time import sleep


# https://www.zamg.ac.at/cms/de/klima/klimauebersichten/jahrbuch -> bullshit

# https://datasetsearch.research.google.com/ -> bullshit

# https://www.visualcrossing.com ...

# use libreoffice a lot to cut bullshit, and transpose

dataset = pd.read_csv('/home/jfasch/Downloads/visualcrossing/history_data.csv')
print(dataset.shape)
print(dataset.describe())


print(dataset[['Minimum Temperature', 'Maximum Temperature']])
# -------------------------------------------------------------
# jjj show shape, describe, and numpy as a whole
# -------------------------------------------------------------
#exit()

# dataset.plot(x='Minimum Temperature', y='Maximum Temperature', style='o')
# plt.title('Min/Max Temperature')
# plt.xlabel('Min')
# plt.ylabel('Max')
# plt.show()

# -------------------------------------------------------------
# jjj show matplotlib, steal from EVK
# -------------------------------------------------------------
#exit()

# plt.figure(figsize=(15,10))
# plt.tight_layout()
# seabornInstance.distplot(dataset['Maximum Temperature'])
# plt.show()
#exit()

# select input and output features. in this example, input and output
# are only one-dimensional.

# the algorithm that we use on the features ("linear regression",
# below) requires two-dimensional - multiple features on either side -
# input and output because this is the general case.

# either select columns by giving a list of column names (only one in
# our case) ...
X = dataset[['Minimum Temperature']]

# ... or select by single string; in this case we reshape the output
# array.
Y = dataset['Maximum Temperature']

# Reshaping has many faces. I prefer giving explicit tuples, because
# this is what a shape is.
Y_explicit_tuple = Y.values.reshape(Y.values.shape + (1,))
Y_automatic_tuple = Y.values.reshape((-1,1))
Y_wtf = Y.values.reshape(-1,1)

Y = Y_explicit_tuple

# data splicing: one part (here 80%) for the training, the rest to
# verify the quality of the outcome.
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=0)

# instantiate and train the model. model = algorithm (linear
# regression in our case) + training data.
model = LinearRegression()
model.fit(X_train, Y_train)

# this is the model. two parameters of a linear equation (this is why
# the algorithm is called "linear regression")
print('Intercept:', algorithm.intercept_)
print('Coefficient:', algorithm.coef_)

# test the model: predictions based on test data.
Y_pred = algorithm.predict(X_test)

df = pd.DataFrame({'Actual': Y_test.flatten(),
                   'Predicted': Y_pred.flatten()})

print('Verifying training data vs. test data')
print(df)

