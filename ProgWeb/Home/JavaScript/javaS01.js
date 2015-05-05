// JavaScript Document

function askNumber()
{
	var number = 0;

	while(number <= 0 || number > 999)
	{
		number = parseInt(prompt('Enter a number'));
	}

	return number;
}

function getDigits(number)
{
	var digits = [];
	
	while(number != 0)
	{
		digits.push(number % 10);
		number = (number - number%10)/10;
	}
	
	return digits;
}

function toUnit(number)
{
	switch(number)
	{
		case 0:
			break;
		case 1:
			return "un";
			break;
		case 2:
			return "deux";
			break;
		case 3:
			return "trois";
			break;
		case 4:
			return "quatre";
			break;
	}
}

function convert(digits)
{

}

getDigits(askNumber());
