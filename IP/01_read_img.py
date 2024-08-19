import cv2 as cv
import sys

img = cv.imread('Images/bird.jpg')

if img is None:
    print('Image not found')

else:
    cv.imshow("Bird", img)
    cv.waitKey(0)