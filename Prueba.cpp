int num1, num2, num3;
printf("Numero 1: ");
scanf("%d", &num1);
printf("Numero 2: ");
scanf("%d", &num2);
printf("Numero 3: ");
scanf("%d", &num3);

if(num1 < num2){
	if(num2 < num3){
		printf(num1, "<", num2, "<", num3);
	}else{
		print(num1, "<", num3, "<", num2);
	}
}else if(num2 < num1){
	if(num1 < num3){
		printf(num2, "<", num1, "<", num3);
	}else{
		printf(num2, "<", num3, "<", num1);
	}
}else if(num3 < num1){
	if(num1 < num2){
		printf(num3, "<", num1, "<", num2);
	}else{
		printf(num3, "<", num2, "<", num1);
	}
}else{
	printf("ERROR");
}

