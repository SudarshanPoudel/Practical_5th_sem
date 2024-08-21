# Practical 6
# Python program to apply highpass filter to an image

import cv2
import numpy as np

image = cv2.imread('Images/gray_image.jpg') 

if image is None:
    print("Error: Image not found or unable to load.")
    exit()

blurred_image = cv2.GaussianBlur(image, (25, 25), 0)

highpass_image = cv2.subtract(image, blurred_image)

cv2.imshow('Original Image', image)
cv2.imshow('High-Pass Filtered Image', highpass_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
