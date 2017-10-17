import math

s = "+------------------------+\n" \
    "|#.#.#.#.#.#.#.#.#.#.#.|D|)\n" \
    "|#.#.#.#.#.#.#.#.#.#.#.|.|\n" \
    "|#.......................|\n" \
    "|#.#.#.#.#.#.#.#.#.#.#.|.|)\n" \
    "+------------------------+\n"
index = 0
for i in range(int(raw_input())):
  while s[index] != "#":
    index = (index + 1) % len(s)
  s = s[:index] + "O" + s[index + 1:]
  while s[index] != "\n":
    index = (index + 1) % len(s)

print s
