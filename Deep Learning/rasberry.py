import numpy as np
import tensorflow as tf
import keras
import RPi.GPIO as GPIO
from keras.models import load_model
from PIL import Image
import matplotlib.pyplot as plt
from keras.models import Sequential # We will obly be using sequencial models
from keras.layers import Dense, Dropout, Flatten, Conv2D, MaxPool2D
from picamera import PiCamera
from gpiozero import LED

comm=18
path_w = ""
path_image="/home/pi/Desktop/image.jpg"
out = 10
mec = 1

signal=LED(out)

GPIO.setmode(GPIO.BCM)
GPIO.setup(comm, GPIO.IN)
camera = PiCamera()

def capture:
    camera.start_preview()
    sleep(0.1)
    camera.capture(path_image)
    camera.stop_preview()



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

model = arch()
model.load_weights(path)

while True:
    while True:
        input_state = GPIO.input(comm)
        if input_state == 1:
            break;
        capture()
        x = np.array(Image.open(path_image))
        x = x/255
        x.reshape(1,475,473,3)
        label = model.predict(x,batch_size=None, verbose=1, steps=1)
        playmobil = np.argmax(label) + 1
        if playmobil == mec:
            signal.on()
            sleep(1)
            signal.off()































        
