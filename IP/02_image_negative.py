# Practical 2
# Python program to read grayscale image and find it's image negative using opencv

import cv2
image = cv2.imread('Images/gray_image.jpg') 


if image is None:
    print("Error: Image not found or unable to load.")
    exit()

# Create the negative image by inverting pixel values
negative_image = cv2.bitwise_not(image)

cv2.imwrite('Images/negative_image.jpg', negative_image) 

cv2.imshow('Original Image', image)
cv2.imshow('Negative Image', negative_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
