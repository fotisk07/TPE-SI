from picamera import PiCamera
from time import sleep

camera = PiCamera()
camera.start_preview()
sleep(5)

for i in range(10):
    sleep(0.001)
    camera.capture('/home/pi/Desktop/2/image7%s.jpg' % +i)

camera.stop_preview()
