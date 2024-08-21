# Practical 3
# python program to do contract stretching of given image

import cv2
import numpy as np

def contrast_stretching(image, r1, s1, r2, s2):
    stretched_image = np.zeros_like(image)

    mask1 = (image <= r1)
    stretched_image[mask1] = ((image[mask1] / r1) * s1).astype(np.uint8)

    mask2 = (image > r1) & (image <= r2)
    stretched_image[mask2] = (((image[mask2] - r1) / (r2 - r1)) * (s2 - s1) + s1).astype(np.uint8)

    mask3 = (image > r2)
    stretched_image[mask3] = (((image[mask3] - r2) / (255 - r2)) * (255 - s2) + s2).astype(np.uint8)

    return stretched_image

image = cv2.imread('Images/bridge.png', cv2.IMREAD_GRAYSCALE)  # Replace with your image file

if image is None:
    print("Error: Image not found or unable to load.")
    exit()

# Define the contrast stretching parameters
r1, s1 = 50, 0    
r2, s2 = 150, 255 

# Apply contrast stretching
stretched_image = contrast_stretching(image, r1, s1, r2, s2)


cv2.imshow('Original Image', image)
cv2.imshow('Contrast Stretched Image', stretched_image)

cv2.waitKey(0)
cv2.destroyAllWindows()