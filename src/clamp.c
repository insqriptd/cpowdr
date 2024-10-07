int clampInt (int v, int min, int max) {
	if (v > max)
		return max;
	if (v < min)
		return min;

	return v;
}
