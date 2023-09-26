#define SIZE 30
#define BOTTOM -1

int stack[SIZE];
int top;


void init()
{
	top = BOTTOM;	
}

int isempty()
{
	if(top==BOTTOM)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isfull()
{       
	if(top==SIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(char item)
{
	if( isfull())
	{
		printf("STACK IS FULL-OVERFLOW \n");
	}
	else
	{
		top++;
		stack[top] = item;
	}

}

int pop()
{
	char temp;

	if(isempty())
	{
		printf("STACK IS EMPTY \n");
		return -1;
	}
	else
	{
		temp = stack[top];
		top--;
		return temp;
			
	}
}


int peek()
{
	if(isempty())
	{
		printf("STACK IS EMPTY \n");
		return -1;
	}
	else
	{
		return stack[top];
	}
}
