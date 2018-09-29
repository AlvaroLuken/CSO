unsigned int f5(unsigned int x) {
	int z;
	int result;



	if(x > 5) {
		z = x;
		result = z;
		result = result + result;
		result = z + result;
		return result;
	}


	result = x;

	switch(x) {
		case 0:
		result = result >> 2;
		break;

		case 1:
		result = result << 2;
		break;

		case 2:
		z = 1+result;
		break;

		case 3:
		result = check(x);
		break;

		case 4:
		result = count(x);
		break;

		case 5:
		result = 7;
		break;

	}

	return result;
}


int check(int x) {
	int edx;
	int y = 1;
	int result;

	while(x != 0) {
		edx = y;
		result = x;
		result = edx + result;
		y = result;
		x = x-1;
	}
	result = y;
	return result;
}


int count(int x) {

	int z = 0;
	int result;
	int ecl;

	while (x != 0) {
		result = x;
		result = result & 1;
		ecl = result;
		z = z << ecl;
		x = x >> 1;

	}

	result = z;
	return result;




}
