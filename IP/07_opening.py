# Practical 7
# python program to apply opening morphological operation to an image

import cv2
import numpy as np

image = cv2.imread('Images/opening.png', cv2.IMREAD_GRAYSCALE) 

if image is None:
    print("Error: Image not found or unable to load.")
    exit()

# Define the structuring element (kernel) for the opening operation
kernel = np.ones((5, 5), np.uint8) 

# Perform the opening operation
opened_image = cv2.morphologyEx(image, cv2.MORPH_OPEN, kernel)

cv2.imshow('Original Image', image)
cv2.imshow('Opened Image', opened_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
