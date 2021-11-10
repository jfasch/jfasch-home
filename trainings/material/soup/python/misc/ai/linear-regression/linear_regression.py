#!/usr/bin/env python

# see the jupyter notebook that accompanies this topic for
# explanations.

import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression


# create dataframe from CSV dataset
dataset = pd.read_csv('./history_data.csv')

# select input and output features
inputfeatures = dataset[['Minimum Temperature']]
outputfeatures = dataset[['Maximum Temperature']]

input_train, input_test, output_train, output_test = \
    train_test_split(inputfeatures, outputfeatures, 
                     test_size=0.2,
                     random_state=0)

# instantiate and train model
model = LinearRegression()
model.fit(input_train, output_train)

# verify the model (well, rudimentarily)
output_predicted = model.predict(input_test)
print(pd.DataFrame({'Actual': output_test.values.reshape((15,)),
                    'Predicted': output_predicted.reshape((15,))}))

# use a number of "real-life" input data lines to predict their
# output.
predicted = model.predict(np.array([[1], [2], [3]]))
print(predicted)
