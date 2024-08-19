import numpy as np
import sys
import cv2 as cv

h = 480
w = 640

img = np.zeros((h, w, 3), np.uint8)

# cv.imshow("black img", img)
# cv.waitKey(0)

# print(img)

w_img = np.ones((h, w, 1), np.uint8) * 255
cv.imshow("White img", w_img)
cv.waitKey(0)

print(w_img)