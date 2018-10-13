import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from PIL import Image
np.random.seed(2)

import keras
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder
from keras.utils import to_categorical
from keras.models import Sequential # We will obly be using sequencial models
from keras.layers import Dense, Dropout, Flatten, Conv2D, MaxPool2D
from keras import optimizers
from keras import losses
from keras.preprocessing.image import ImageDataGenerator
from keras.callbacks import ReduceLROnPlateau

random_seed = 2

# Get the data
filelist = ["data/playmobil 1/image%s.jpg" %i for i in range(67)] + ["data/playmobil 2/image%s.jpg" %i for i in range(79)] + ["data/playmobil 3/image%s.jpg" %i for i in range(77)] #a list containg the data names

X = np.array([np.array(Image.open(fname)) for fname in filelist]) # images
Y = np.array([0]*67 + 79*[1] + [2]*77) #labels
print(X.shape)
# Normalize the data
X = (X - np.mean(X)/np.std(X))
print(Y.shape)
#one hot encode the labels
Y = to_categorical(Y,3)


#split train and validation set
X_train, X_val, Y_train, Y_val = train_test_split(X, Y, test_size = 0.1, random_state=random_seed)

#plt.imshow(X_train[0][:,:,0])
#plt.show()

#Define the model
model = Sequential()

model.add(Conv2D(filters = 20, kernel_size = (5,5),padding = 'Same',
                 activation ='relu', input_shape = (475,473,3)))
model.add(MaxPool2D(pool_size=(2,2)))
model.add(Dropout(0.50))
model.add(Flatten())
model.add(Dense(256, activation = "relu"))
model.add(Dropout(0.5))
model.add(Dense(150, activation = "relu"))
model.add(Dropout(0.25))
model.add(Dense(3, activation = "softmax"))

optimizer = keras.optimizers.SGD(lr=0.01, momentum=0.0, decay=0.0, nesterov=False)


model.compile(loss=losses.categorical_crossentropy,
              optimizer=optimizer)

model.fit(X_train, Y_train, epochs=5, batch_size=32)
