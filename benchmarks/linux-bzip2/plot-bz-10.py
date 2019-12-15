import matplotlib.pyplot as plt
import numpy as np

N = 9
ind = np.arange(N)

y10 = [0.73, 0.751, 0.799, 0.825, 0.861, 0.89, 0.919, 0.959, 0.966]

fig, ax = plt.subplots()

ax.plot(ind,y10, label="Linux")

ax.legend()
ax.plot()

ax.set(xlabel="Compression level", ylabel="Compression time (in s)",
	title="Bzip2 compression level vs. time for a 10 MB file")
ax.grid()

fig.savefig("bzip2-10.png")
plt.show()