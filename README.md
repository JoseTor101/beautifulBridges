# SOLUCIÓN PROBLEMA B, BEATIFUL BRIDGES. ACM-ICPC 2019
# - JOSÉ ALEJANDRO TORDECILLA ZAPATA


### Objetivo:
Output the minimum cost of building a bridge from horizontal position x1 to xn at height h above sea
level. If it is impossible to build any such bridge, output impossible.

## Description:
What connects us all? Well, it is often bridges. Since ancient times, people have been building bridges for roads, for
trains, for pedestrians, and as aqueducts to transport water. It
is humanity’s way of not taking inconvenient geography for an
answer.

The first line of input contains four integers n, h, α, and β, where n (2 ≤ n ≤ 10^4) is the number of
points describing the ground profile, h (1 ≤ h ≤ 10^5) is the desired height of the bridge above sea level,and α, β (1 ≤ α, β ≤ 10^4) are the cost factors as described earlier. Then follow n lines, the i-th of which contains two integers xi, yi (0 ≤ x1 < x2 < . . . < xn ≤ 10^5 and 0 ≤ yi < h), describing the ground
profile.
