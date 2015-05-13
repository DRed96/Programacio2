int factorial(int number){
	int ret = 1;
	for (int i = 1; i <= number; i++)
	{
		ret *= i;
	}

	return ret;
}
//D.Hernandez
int factorial2(int num){

	if (num > 1)
	{
		return num * factorial2(num - 1);
	}
	else{
		return 1;
	}
}
