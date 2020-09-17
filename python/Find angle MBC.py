import math
AB = int(input())
BC = int(input())
angle = math.degrees(math.atan(AB/BC)) # atan = inverse tan returns radian angle
print (int(round(angle)),end='°')
