#lab program 9
import cv2
import numpy as np
image_path = "faces4.jpeg"
img = cv2.imread(image_path)
edges = cv2.Canny(img, 100, 200)
kernel = 11
texture = cv2.medianBlur(img, kernel) 
cv2.imshow("Original Image", img)
cv2.imshow("Edges", edges)
cv2.imshow("Texture", texture)
cv2.waitKey(0)
