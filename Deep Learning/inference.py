import tensorflow as tf
import numpy as np
import keras
from keras.models import load_model
from PIL import Image
import matplotlib.pyplot as plt
from keras.models import Sequential # We will obly be using sequencial models
from keras.layers import Dense, Dropout, Flatten, Conv2D, MaxPool2D

def arch():
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

    optimizer = keras.optimizers.SGD(lr=0.01, momentum=0.06, decay=0.05, nesterov=False)

    model.compile(optimizer = optimizer , loss = "categorical_crossentropy",metrics=["accuracy"])
    return model

x = np.array(Image.open("data/Playmobil 1/image0.jpg"))
x = x/255
x.reshape(1,475,473,3)
x=np.array([x])
print(x.shape)
model = arch()
model.load_weights("weights.h5")
label = model.predict(x,batch_size=None, verbose=1, steps=1)
print(np.argmax(label) + 1)
