pref[x][y][z] = pref[x - 1][y][z] + pref[x][y - 1][z] + pref[x][y][z - 1] - pref[x - 1][y - 1][z] - pref[x - 1][y][z - 1] - pref[x][y - 1][z - 1] + pref[x - 1][y - 1][z - 1] + arr[x][y][z];
// from x1 to x2, y1 to y2, z1 to z2
ans = pref[x2][y2][z2] - pref[x1 - 1][y2][z2] - pref[x2][y1 - 1][z2] - pref[x2][y2][z1 - 1] + pref[x1 - 1][y1 - 1][z] + pref[x1 - 1][y][z1 - 1] + pref[x2][y1 - 1][z1 - 1] - pref[x1 - 1][y1 - 1][z1 - 1];
