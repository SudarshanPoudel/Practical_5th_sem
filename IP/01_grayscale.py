# Practical 1
# Python program to read colorful image and save it grayscale using open_cv library

import cv2

# Read the image from file
image = cv2.imread('Images/flower.jpeg')

if image is None:
    print("Error: Image not found or unable to load.")
    exit()

gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

cv2.imwrite('Images/gray_image.jpg', gray_image)  

cv2.imshow('Original Image', image)
cv2.imshow('Grayscale Image', gray_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
