from __future__ import annotations
from pathlib import Path
import operator as op
import subprocess

from matplotlib import pyplot as plt  # type: ignore[import]

from rangers.std import dataclass as dcls

subprocess.run(['g++', '-std=c++17', '-o', 'pendulum.exe', 'pendulum.cpp'], check=True)
subprocess.run(['pendulum.exe'], check=True)

data_obj = dcls.Pack(
    dcls.NamedSequence(
        t=dcls.Double,
        r=dcls.Pair(dcls.Double),
        v=dcls.Pair(dcls.Double),
        a=dcls.Pair(dcls.Double),
    )
)

data = data_obj.read_bytes(Path('./data.bin').read_bytes())

t = [*map(op.itemgetter('t'), data)]
r = [*map(op.itemgetter('r'), data)]
v = [*map(op.itemgetter('v'), data)]
a = [*map(op.itemgetter('a'), data)]
a = a[1:] + [a[-1]]

r_x = [*map(op.itemgetter(0), r)]
r_y = [*map(op.itemgetter(1), r)]

v_x = [*map(op.itemgetter(0), v)]
v_y = [*map(op.itemgetter(1), v)]

a_x = [*map(op.itemgetter(0), a)]
a_y = [*map(op.itemgetter(1), a)]


p = plt.subplot(2, 3, 1)
p.set_title('r_x(t)')
p.set_xlabel('t')
p.set_ylabel('r_x')
p.scatter(t, r_x)

p = plt.subplot(2, 3, 2)
p.set_title('v_x(t)')
p.set_xlabel('t')
p.set_ylabel('v_x')
p.scatter(t, v_x)

p = plt.subplot(2, 3, 3)
p.set_title('a_x(t)')
p.set_xlabel('t')
p.set_ylabel('a_x')
p.scatter(t, a_x)

p = plt.subplot(2, 3, 4)
p.set_title('r')
p.set_xlabel('r_x')
p.set_ylabel('r_y')
p.plot(0, 0, marker='o', color='red')
p.scatter(r_x, r_y)
p.axes.set_aspect(1)

p = plt.subplot(2, 3, 5)
p.set_title('v')
p.set_xlabel('v_x')
p.set_ylabel('v_y')
p.plot(0, 0, marker='o', color='red')
p.scatter(v_x, v_y)
p.axes.set_aspect(1)

p = plt.subplot(2, 3, 6)
p.set_title('a')
p.set_xlabel('a_x')
p.set_ylabel('a_y')
p.plot(0, 0, marker='o', color='red')
p.scatter(a_x, a_y)
p.axes.set_aspect(1)

mng = plt.get_current_fig_manager()
mng.window.state('zoomed')

plt.show()
