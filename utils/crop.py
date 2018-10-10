from PIL import Image
import os
 
def crop(image_path, coords, saved_location):
    """
    @param image_path: The path to the image to edit
    @param coords: A tuple of x/y coordinates (x1, y1, x2, y2)
    @param saved_location: Path to save the cropped image
    """
    image_obj = Image.open(image_path)
    cropped_image = image_obj.crop(coords)
    cropped_image.save(saved_location)
    #cropped_image.show()
 
 
if __name__ == '__main__':
    i=0
    for filename in os.listdir("c3"):
        path = "c3/" + filename
        x=315
        y=50
        crop(path, (x, y, x+473, y+475), 'a3/croppedw%s.jpg' % i )
        i=i+1

