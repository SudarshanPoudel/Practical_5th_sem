# Practical 8
# python program to apply closing morphological operation to an image


import cv2
import numpy as np

image = cv2.imread('Images/closing.png', cv2.IMREAD_GRAYSCALE)  # Replace 'input_image.jpg' with the path to your image file

if image is None:
    print("Error: Image not found or unable to load.")
    exit()

kernel = np.ones((5, 5), np.uint8) 

closed_image = cv2.morphologyEx(image, cv2.MORPH_CLOSE, kernel)

cv2.imshow('Original Image', image)
cv2.imshow('Closed Image', closed_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
