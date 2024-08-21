# Practical 5
# Python program to apply lowpass filter to an image

import cv2

# Read the image from file
image = cv2.imread('Images/gray_image.jpg') 


if image is None:
    print("Error: Image not found or unable to load.")
    exit()

blurred_image = cv2.GaussianBlur(src=image, ksize=(15, 15), sigmaX=0)

cv2.imshow('Original Image', image)
cv2.imshow('Blurred Image', blurred_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
