import numpy as np
import matplotlib.pyplot as plt
from PIL import Image



filelist = ["data/playmobil 1/image%s.jpg" %i for i in range(67)] + ["data/playmobil 2/image%s.jpg" %i for i in range(79)] + ["data/playmobil 3/image%s.jpg" %i for i in range(77)] #a list containg the data names

X = np.array([np.array(Image.open(fname)) for fname in filelist]) # images
Y = np.array([1]*67 + 79*[2] + [3]*77) #labels


print(Y.shape)
print(X.shape)
plt.imshow(X[60,:,:,:])
plt.show()
