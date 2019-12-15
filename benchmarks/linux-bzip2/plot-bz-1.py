import matplotlib.pyplot as plt
import numpy as np

N = 9
ind = np.arange(N)

y1 = [0.089, 0.083, 0.093, 0.098, 0.105, 0.106, 0.105, 0.108, 0.114]

fig, ax = plt.subplots()

ax.plot(ind,y1, label="Linux")

ax.legend()
ax.plot()

ax.set(xlabel="Compression level", ylabel="Compression time (in s)",
	title="Bzip2 compression level vs. time for a 10 MB file")
ax.grid()

fig.savefig("bzip2-1.png")
plt.show()