import pandas as pd
import numpy as np
from PIL import Image


filelist = ["data/playmobil 1/image%s.jpg" %i for i in range(67)] + ["data/playmobil 2/image%s.jpg" %i for i in range(79)] + ["data/playmobil 3/image%s.jpg" %i for i in range(77)] #a list containg the data names

X = np.array([np.array(Image.open(fname)) for fname in filelist]) # images
Y = np.array([0]*67 + 79*[1] + [2]*77) #labels
pixels = X.flatten().reshape(223, 674025)
df = pd.DataFrame(data=pixels)
df.to_csv('data.csv')
