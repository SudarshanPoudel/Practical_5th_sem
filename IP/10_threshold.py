
# Practical 10
# python program to segment an image using threshing technique

import cv2

image = cv2.imread('Images/gray_image.jpg', cv2.IMREAD_GRAYSCALE)  # Replace with your image file

if image is None:
    print("Error: Image not found or unable to load.")
    exit()

threshold_value = 100  

_, segmented_image = cv2.threshold(image, threshold_value, 255, cv2.THRESH_BINARY)

cv2.imshow('Original Image', image)
cv2.imshow('Segmented Image', segmented_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
