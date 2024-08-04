#labprogram7
import cv2
import matplotlib.pyplot as plt

# Read the image
img = cv2.imread('faces4.jpeg')

# Convert BGR to RGB (OpenCV uses BGR by default)
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

# Get the height and width of the image
height, width = img.shape[:2]

quad1 = img[:height//2, :width//2]
quad2 = img[:height//2, width//2:]
quad3 = img[height//2:, :width//2]
quad4 = img[height//2:, width//2:]

# Plot the quadrants
plt.figure(figsize=(10, 10))

plt.subplot(2, 2, 1)
plt.imshow(quad1)
plt.title('Quadrant 1')
plt.axis('off')  

plt.subplot(2, 2, 2)
plt.imshow(quad2)
plt.title('Quadrant 2')
plt.axis('off')  

plt.subplot(2, 2, 3)
plt.imshow(quad3)
plt.title('Quadrant 3')
plt.axis('off')  

plt.subplot(2, 2, 4)
plt.imshow(quad4)
plt.title('Quadrant 4')
plt.axis('off')  

plt.tight_layout()
plt.show()

