pip install matplotlib


import matplotlib.pyplot as plt

# Set up the figure and axes
fig, ax = plt.subplots(figsize=(8, 6))
ax.set_xlim(0, 10)
ax.set_ylim(0, 8)

# Draw the central platform box
ax.text(5, 5, 'Central Platform', ha='center', va='center', 
        bbox=dict(boxstyle="round,pad=0.5", edgecolor='black', facecolor='lightblue'))

# Draw the WASRV boxes
legacy_services = ['WASRV1', 'WASRV2', 'WASRV3', 'WASRV4', 'WASRV5']
positions = [(2, 7), (1, 5), (2, 3), (8, 7), (9, 5)]

for pos, service in zip(positions, legacy_services):
    ax.text(pos[0], pos[1], service, ha='center', va='center', 
            bbox=dict(boxstyle="round,pad=0.5", edgecolor='black', facecolor='lightgreen'))
    ax.plot([pos[0], 5], [pos[1], 5], 'k--')  # Dashed line to central platform

# Draw the new service boxes
new_services = ['New Service 1', 'New Service 2']
new_positions = [(4, 1), (6, 1)]

for pos, service in zip(new_positions, new_services):
    ax.text(pos[0], pos[1], service, ha='center', va='center', 
            bbox=dict(boxstyle="round,pad=0.5", edgecolor='black', facecolor='lightcoral'))
    ax.plot([pos[0], 5], [pos[1], 5], 'k-')  # Solid line to central platform

# Adjust axis and remove ticks
ax.axis('off')

# Show the diagram
plt.show()
