import numpy as np
import matplotlib.pyplot as plt

# Define the equations
def circle(x):
    return np.sqrt(9/4 - x**2)

def parabola(x):
    return x**2 / 4

# Set up the range for x
x_vals = np.linspace(-1.5, 1.5, 400)

# Calculate y values for the circle and parabola
y_circle_upper = circle(x_vals)
y_circle_lower = -circle(x_vals)
y_parabola = parabola(x_vals)

# Plot the circle
plt.plot(x_vals, y_circle_upper, label=r'$x^2 + y^2 = \frac{9}{4}$', color='blue')
plt.plot(x_vals, y_circle_lower, color='blue')

# Plot the parabola
plt.plot(x_vals, y_parabola, label=r'$x^2 = 4y$', color='red')

# Fill the region between the curves
plt.fill_between(x_vals, y_parabola, y_circle_upper, where=(y_parabola <= y_circle_upper), color='gray', alpha=0.5, label='Shaded Region')

# Set up labels and title
plt.axhline(0, color='black',linewidth=1)
plt.axvline(0, color='black',linewidth=1)
plt.xlim(-1.5, 1.5)
plt.ylim(-2, 2)
plt.gca().set_aspect('equal', adjustable='box')
plt.legend()

# Show the plot
plt.show()

