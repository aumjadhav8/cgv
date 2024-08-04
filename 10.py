#labprogram10
import cv2
def blur_image(image, blur_radius):
    return cv2.GaussianBlur(image, (blur_radius, blur_radius), 0)
def smooth_image(image, kernel_size):
    return cv2.medianBlur(image, kernel_size)

image = cv2.imread('faces4.jpeg')

blur_radius = int(input("Enter blur radius (odd number): "))
kernel_size = int(input("Enter kernel size for smoothing (odd number): "))

blurred_img = blur_image(image, blur_radius)
smoothened_image = smooth_image(image, kernel_size)

cv2.imshow('Blurred Image', blurred_img)
cv2.imshow('Smoothened Image', smoothened_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

