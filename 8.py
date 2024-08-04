#labprogram8
import cv2
import numpy as np

def transform_image(image, angle, scale, tx, ty):
    # Get image dimensions
    height, width = image.shape[:2]
    # Calculate the center of the image
    center = (width // 2, height // 2)
    # Rotation matrix
    rotation_matrix = cv2.getRotationMatrix2D(center, angle, scale)
    # Apply rotation
    rotated_image = cv2.warpAffine(image, rotation_matrix, (width, height))
    # Translation matrix
    translation_matrix = np.float32([[1, 0, tx], [0, 1, ty]])
    # Apply translation
    transformed_image = cv2.warpAffine(rotated_image, translation_matrix, (width, height))
    return transformed_image

image = cv2.imread('faces4.jpeg')
angle = float(input("Enter rotation angle (degrees): "))
scale = float(input("Enter scaling factor: "))
tx = float(input("Enter horizontal translation (pixels): "))
ty = float(input("Enter vertical translation (pixels): "))
final_image = transform_image(image, angle, scale, tx, ty)
cv2.imwrite('Final_image.png', final_image)
cv2.imshow("Transformed Image", final_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

