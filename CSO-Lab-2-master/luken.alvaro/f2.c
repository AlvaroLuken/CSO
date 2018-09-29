long f2(int x) {

	long y = 17;


	int result = x;
	result = result << 3;
	result = result - x;
	x = result;


	int z = 0;


	result = z;


	while(result < x) {
		result = z;

		y = result + y;
		z++;

		result = z;
	}

	result = y;

	return result;

}