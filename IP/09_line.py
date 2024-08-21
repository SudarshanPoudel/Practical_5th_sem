# Practical 9
# python program to detect edge lines in an image using hough transform


import cv2
import numpy as np

image = cv2.imread('Images/gray_image.jpg')  

if image is None:
    print("Error: Image not found or unable to load.")
    exit()

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

blurred = cv2.GaussianBlur(gray, (5, 5), 0)
edges = cv2.Canny(blurred, 50, 150)

lines = cv2.HoughLines(edges, 1, np.pi / 180, 200)  

if lines is not None:
    for line in lines:
        rho, theta = line[0]
        a = np.cos(theta)
        b = np.sin(theta)
        x0 = a * rho
        y0 = b * rho
        x1 = int(x0 + 1000 * (-b))
        y1 = int(y0 + 1000 * (a))
        x2 = int(x0 - 1000 * (-b))
        y2 = int(y0 - 1000 * (a))
        cv2.line(image, (x1, y1), (x2, y2), (255, 255, 255), 2)  


cv2.imshow('Original Image', image)
cv2.imshow('Edges', edges)

cv2.waitKey(0)
cv2.destroyAllWindows()
