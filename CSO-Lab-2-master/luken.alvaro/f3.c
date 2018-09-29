int f3(unsigned int i) {



	int rsp4 = 0;
	int eax;


	while(i != 0) {
		eax = i;


		if(eax&1) {
			rsp4++;
			i = i >> 1;
		} else {
			i = i >> 1;
		}
	}



	eax = rsp4;
	eax = eax*-1;

	return eax;
}
